### Building Project

  * First of all, set path for make.exe. The **make.exe** is inside **nacl_sdk\pepper_{version_number}\tools**.
  For example: my path is **D:\0.PNaCl\nacl_sdk\pepper_49\tools**
  
  * Open cmd in current location, then run:
  
    ```
	make
	```
	
	* Result: folder **glibc** is created.
	
### Testing

  * I will copy all library files (libbar_arm.so, libbar_x86_32.so and libbar_x86_64.so) in **deps/Release** to project [dlopen-load-class-2] for testing.
  
