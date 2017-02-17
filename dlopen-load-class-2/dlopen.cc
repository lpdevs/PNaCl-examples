// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <dlfcn.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mount.h>

#include <ppapi/cpp/completion_callback.h>
#include <ppapi/cpp/instance.h>
#include <ppapi/cpp/module.h>
#include <ppapi/cpp/var.h>

#include "plugin.h"
#include "nacl_io/nacl_io.h"

#if defined(NACL_SDK_DEBUG)
#define CONFIG_NAME "Debug"
#else
#define CONFIG_NAME "Release"
#endif

#if defined __arm__
#define NACL_ARCH "arm"
#elif defined __i686__
#define NACL_ARCH "x86_32"
#elif defined __x86_64__
#define NACL_ARCH "x86_64"
#else
#error "Unknown arch"
#endif

class DlOpenInstance : public pp::Instance {
 public:
  explicit DlOpenInstance(PP_Instance instance)
      : pp::Instance(instance),
        fooHandle(NULL),
        fooFactory(NULL),
        fooPlugin(NULL),
		barHandle(NULL),
        barFactory(NULL),
        barPlugin(NULL){}

  virtual ~DlOpenInstance() {}

  // Helper function to post a message back to the JS and stdout functions.
  void logmsg(const char* pStr) {
    PostMessage(pp::Var(std::string("log:") + pStr));
    fprintf(stdout, pStr);
    fprintf(stdout, "\n");
  }

  // Initialize the module, staring a worker thread to load the shared object.
  virtual bool Init(uint32_t argc, const char* argn[], const char* argv[]) {
    nacl_io_init_ppapi(pp_instance(),
                       pp::Module::Get()->get_browser_interface());
    // Mount a HTTP mount at /http. All reads from /http/* will read from the
    // server.
    mount("", "/http", "httpfs", 0, "");

    pthread_t thread;
    logmsg("Spawning thread to cache .so files...");
    int rtn = pthread_create(&thread, NULL, LoadLibrariesOnWorker, this);
    if (rtn != 0) {
      logmsg("ERROR; pthread_create() failed.");
      return false;
    }
    rtn = pthread_detach(thread);
    if (rtn != 0) {
      logmsg("ERROR; pthread_detach() failed.");
      return false;
    }
    return true;
  }

  // This function is called on a worker thread, and will call dlopen to load
  // the shared object.  In addition, note that this function does NOT call
  // dlclose, which would close the shared object and unload it from memory.
  void LoadLibrary() {
    // Getting foo
	const char foo_so_path[] =
        "/http/glibc/" CONFIG_NAME "/libfoo_" NACL_ARCH ".so";	
    if (!(fooHandle = dlopen(foo_so_path, RTLD_LAZY)))
    {  
		logmsg("Could not open library");  
        return;		
    }
	if (!( fooFactory = (PluginFactory *)dlsym(fooHandle, "gFooFactory")))
    {  
		logmsg("Could not find Factory");  
		return;  
    }
    
	fooPlugin = fooFactory->getInstance();
	logmsg("fooFactory->getInstance())");
   	fooPlugin->test();
	logmsg("fooPlugin->test()");
    delete fooPlugin;
	logmsg("delete fooPlugin");
	dlclose(fooHandle);
	
	// Getting bar
	const char bar_so_path[] =
        "/http/deps/" CONFIG_NAME "/libbar_" NACL_ARCH ".so";	
    if (!(barHandle = dlopen(bar_so_path, RTLD_LAZY)))
    {  
		logmsg("Could not open library");  
        return;		
    }
	if (!( barFactory = (PluginFactory *)dlsym(barHandle, "gBarFactory")))
    {  
		logmsg("Could not find Factory");  
		return;  
    }
    
	barPlugin = barFactory->getInstance();
	logmsg("barFactory->getInstance())");
   	barPlugin->test();
	logmsg("barPlugin->test()");
    delete barPlugin;
	logmsg("delete barPlugin");
    dlclose(barHandle);
  }

  // Called by the browser to handle the postMessage() call in Javascript.
  virtual void HandleMessage(const pp::Var& var_message) {
     
  }

  static void* LoadLibrariesOnWorker(void* pInst) {
    DlOpenInstance* inst = static_cast<DlOpenInstance*>(pInst);
    inst->LoadLibrary();
    return NULL;
  }

 private:
    void * fooHandle;
	PluginFactory * fooFactory;
   	Plugin * fooPlugin;
	
    void * barHandle;
	PluginFactory * barFactory;
   	Plugin * barPlugin;
};

class DlOpenModule : public pp::Module {
 public:
  DlOpenModule() : pp::Module() {}
  virtual ~DlOpenModule() {}

  // Create and return a DlOpenInstance object.
  virtual pp::Instance* CreateInstance(PP_Instance instance) {
    return new DlOpenInstance(instance);
  }
};

namespace pp {
Module* CreateModule() { return new DlOpenModule(); }
}  // namespace pp

