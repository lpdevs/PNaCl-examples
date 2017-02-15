### PNaCl examples

  * Some examples of PNacl to run the Native Client module directly from a web page.
  * These examples is for Windows.
 
### Setting enviroment

  * Download [Python 2.7](https://www.python.org/downloads/) and then set up the PATH environment variable for it.
  * Download [NaCl SDK](https://storage.googleapis.com/nativeclient-mirror/nacl/nacl_sdk/nacl_sdk.zip), then unzip the file.
  * Installing the stable bundle:
    
    * To see the SDK bundles that are available for download:
      
      ```
      cd nacl_sdk
      naclsdk list
      ```
      
    * Run naclsdk with the update command to download recommended bundles, including the current “stable” bundle:
    
      ```
      naclsdk update
      ```
      
      To download the specific bundle (such as: pepper_49,...) you must ask for it explicitly:
      
      ```
      naclsdk update pepper_49
      ```      
    
  * References
    * [Download the Native Client SDK](https://developer.chrome.com/native-client/sdk/download)

### Tutorials

  * [C++ Tutorial: Getting Started (Part 1)](https://developer.chrome.com/native-client/devguide/tutorial/tutorial-part1)
  * [C++ Tutorial: Getting Started (Part 2)](https://developer.chrome.com/native-client/devguide/tutorial/tutorial-part2)
  * [Aplication Structure](https://developer.chrome.com/native-client/devguide/coding/application-structure)
  * [Native client Visual Studio Addin](https://developer.chrome.com/native-client/devguide/devcycle/vs-addin)
