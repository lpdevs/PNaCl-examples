(Similar to hello-world example)

### Creating project

  * Assumming that you set up all prerequisites, include nacl_sdk, pepper (I use pepper_49), vs_addin and Visual Studio 2012
  * Creating new empty project.
  * Right click on solution, click **Configuration Manager**.
  * In **Active solution platform**, click **<New...>**, then choose **PNacl** platform, OK
  * Add new file **hello_world_2.cc** and write the code.
  
### Building project

  * Choose **BUILD/Build Solution**
  * Then you see some files and folders created, like below:
  
    newlib
	  newlib
	    Debug
		  hello-world-2_32.nexe
		  hello-world-2_64.nexe
		  hello-world-2_arm.nexe
    PNacl
	  newlib
	    Debug
		  hello-world-2.pexe
		  hello-world-2_32.nexe
		  hello-world-2_64.nexe
		  hello-world-2_arm.nexe
		  ...
	  hello-world-2.nmf
	  
  * I am going to use **hello-world-2.pexe**
  
### Testing
  
  * Modify hello-world.nmf
    * From:
    
	```
	{
		"files": {},
		"program": {
			"x86-64": {
				"url": "newlib/Debug/hello-world-2_64.nexe"
			},
			"arm": {
				"url": "newlib/Debug/hello-world-2_arm.nexe"
			},
			"x86-32": {
				"url": "newlib/Debug/hello-world-2_32.nexe"
			}
		}
	}

    ```
	
	* To:
	
	```
	{
		"files": {},
		"program": {
			"portable": {
				"pnacl-translate": {
				"url": "newLib/Debug/hello-world-2.pexe"
				}
			},
			"x86-64": {
				"url": "newlib/Debug/hello-world-2_64.nexe"
			},
			"arm": {
				"url": "newlib/Debug/hello-world-2_arm.nexe"
			},
			"x86-32": {
				"url": "newlib/Debug/hello-world-2_32.nexe"
			}
		}
	}
	```
	
  * Inside **PNacl**, creating new files: **index.html**, **common.js** and then write the code
  * Open cmd, then create server by using python
  
    ```
	python -m SimpleHTTPServer 8001	
	```
	
  * Access at **http://localhost:8001/** in Chrome. Then check the result.
