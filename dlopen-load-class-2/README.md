### Building Project

  * First of all, set path for make.exe. The **make.exe** is inside **nacl_sdk\pepper_{version_number}\tools**.
  For example: my path is **D:\0.PNaCl\nacl_sdk\pepper_49\tools**
  
  * Open cmd in current location, then run:
  
    ```
	make
	```
	
	* Result: folder **glibc** is created.
 
  * Build project [build-dynamic-library](https://github.com/phamvanlam/PNaCl-examples/tree/master/build-dynamic-library) 
  * Get library files (libbar_arm.so, libbar_x86_32.so and libbar_x86_64.so) in **glibc/Release** of project [build-dynamic-library](https://github.com/phamvanlam/PNaCl-examples/tree/master/build-dynamic-library) 
  to **deps/Release** of this project.
	
### Testing

  * Open chrome
  * Access at **chrome://flags/**, then enable **Native Client**
  * Inside **dlopen-load-class-2** directory, open cmd then run the following command to run sever:
    
	```
	python -m SimpleHTTPServer 8001
	```
   
   * Access at [http://localhost:8001/](http://localhost:8001/) then check out the result.
   
