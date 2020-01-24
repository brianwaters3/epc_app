This application is a sample that utilizes EpcTools.  Features of EpcTools that it demonstrates include

   * Event Threads
   * freeDiameter wrappers
   * Command line argument handling
   * JSON configuration file
   * REST server with custom handlers (intended to service CLI requests)
   * Interface statistics (peers and messages for SWm diameter interface)
   * Logging
   
To run this sample:

   * Download, configure, build and install EpcTools per https://github.com/brianwaters3/epctools
   * Download this project
   * Build this project
   
      cd epc_app
      make
   
   * Edit epc_app/conf/epc_app_server.json and set the "peerip" to the IP address of this machine.
   * Edit epc_app/conf/epc_app_client.json and set the "peerip" to the IP address of this machine.
   * Open a terminal and run the following commands to run the server
   
      cd epc_app
      ./bin/epc_app -f conf/epc_app_server.json
   
   * Open another terminal and run the following commands to run the client
   
      cd epc_app
      ./bin/epc_app -f conf/epc_app_client.json
      
   * Execute the menu commands on the client and server applications as desired.

      
