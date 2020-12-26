# LViewLoL
External memory reader for league of legends

### What is this
LView aims to be as much of an undetectable scripting platform for league of legends as possible. There is no DLL injection into leagues process, everything is read externally from the process without writing to leagues memory. LView makes a snapshot of all game objects in each iteration and provides that snapshot aswell as an interface with usefull methods to a list of scripts.

### Building

Dependencies:
  1. python39 (already installed in project)
  2. directx9 (already installed in project)
  3. aws-lambda (already installed in project)
  4. boost::python (only dll installed on project). Due to the size of the boost libraries you must compile boost::python separately and add the libs/includes yourself, if you install boost in LView/boost, visual studio will automatically pick the libs/includes
  
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
