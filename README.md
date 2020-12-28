# LViewLoL

### What is this
LView is an external memory reader for League of Legends, it uses a python scripting front end for automated gameplay and different overlays. There is no DLL injection into leagues process, everything is read externally from the process without writing to leagues memory. LView makes a snapshot of all game objects in each iteration and provides that snapshot aswell as an interface with usefull methods to a list of scripts.

### Building

Dependencies:
  1. python39 (already installed in project, also install python 3.9 and add it to path)
  3. aws-lambda (already installed in project)
  3. directx 11: Must install directx runtime: https://www.microsoft.com/en-us/download/details.aspx?id=35
  4. boost::python (only dll installed on project). Due to the size of the boost libraries you must compile boost::python separately and add the libs/includes yourself, if you install boost in LView/boost, visual studio will automatically pick the libs/includes. Download boost 1.75.0 run boostrap.bat then run "b2 --with-python link=shared toolset=msvc-14.1 address-model=32 variant=release"
  
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
