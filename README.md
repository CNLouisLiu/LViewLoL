# LViewLoL

### What is this
LView is a python based scripting platform for League of Legends. The engine is external that means it is not injected into leagues process. The engine is running in a separate process and reads the games state using ReadProcessMemory.

Key features of LView:
  1. Ability to create overlays and automatize gameplay using python scripts
  2. Performant ingame overlays/menus using a combination of directx, direct composition and dear imgui 
  3. Static game data available at runtime. Data is unpacked directly from the game files. Taken from https://www.communitydragon.org/ .
  4. Undetectability. Since LView reads the game state externally the ban probability is close to 0. Currently since the start of the development there is no recorded case of a ban.
 

### Building

Dependencies:
  1. python39: dlls and includes are already in project. You may have to install python39 and make sure you add it to PATH
  3. aws-lambda: dlls and includes are already in project
  3. directx 11: Must install directx runtime: https://www.microsoft.com/en-us/download/details.aspx?id=35
  4. boost::python. Due to the size of the boost libraries you must compile boost::python yourself:
      1. Download boost 1.75.0 
      2. Unarchive it in LView/boost
      3. Go into LView/boost
      4. Run `bootstrap.bat`
      5. Run `b2 --with-python link=shared toolset=msvc-14.1 address-model=32 variant=release`
  
 ### Setup
 All LView & LView python scripts configurations reside in config.ini file. First you must set the path to the scripts folder with the following config:
 
  `::scriptsFolder=\<folder\>`

Next you need credentials for authentication with the server and you must provide the following configs (these are configs for the current admin account):

  ```
  auth::access_key=AKIAU6GDVTT2N774MGVZ
  auth::region=eu-north-1
  auth::secret_key=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
  auth::user=admin
  ```
The above credentials are AWS IAM user credentials which have the necessary permissions to call the AWS auth lambda 

Alternatively you can just comment out the authentication code.
