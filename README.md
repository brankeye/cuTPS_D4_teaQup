# COMP3004A: cuTPS Project
==========================

**Fall 2014 (September - December)**

### Authors
- Analee Chicot, ID: 100822791
- Remy Gratwohl, ID: 100891970
- Brandon Keyes, ID: 100897196
- Bernard Llanos, ID: 100793648

## Building and Operating Instructions

This project will build and run in the COMP3004A virtual machine
(Ubuntu 12.04 LTS, 32-bit).

Note that the build steps must be repeated on each host
on which the server and client processes are to be run.

1. Open `COMP3004A_project_teaQup.pro` with Qt Creator.
   1. If this is the first time that the project has been opened with Qt Creator,
      Qt Creator will provide a configuration screen.
      Qt Creator's automatic project configuration should not need to be adjusted;
      Simply navigate to the 'Edit' mode of the IDE.
   2. Note that development was carried out using Qt 5.0.2
2. Build the project to be run on the host (`client` or `server`) using Qt Creator.
3. Start the server process by choosing to run the `server` project.
4. If the client process will be run on a different host
   from the server process, configure the IP address and port number
   to which the client will attempt to connect, as described below.
4. Start the client process(es) by choosing to run the `client` project.

## Port Configuration

If you wish to change the server's port, you can do so in the generated
server port configuration file, ServerPortFile.txt, located in the build path
of the server.

If you change the port on the server, you'll also have to change which port
the client attempts to connect to, which can be changed in a file with the same name, 
but located in the build path of the client.

## Code References and Acknowledgements

None currently, outside of Qt documentation and tutorials.

Websites consulted for ideas:

#### Serialization
- http://www.ics.com/blog/object-serialization-and-persistence-using-qdatastream#.VFtkPSUjthE
- http://www.mimec.org/node/351