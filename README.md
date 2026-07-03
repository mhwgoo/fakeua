`fakeua` is designed both as a C program and as a C library for getting a random and valid browser user-agent string for unix-like systems. It is tiny, and every run will randomly yield a different user-agent string.

### As a program
run `./build.sh` and then `fakeua <subcommand>`

| **subcommand** | **use of the subcommand** |
| -------------- | ------------------------------------------------------------------------------------------------------------------------- |
| browser [name] [-f] | Optional name from chrome, edge, firefox, safari, opera (case insensitive) with optional '-f' disabling use of cache |
| dump | Dump user-agent data to binary files as caches by browser name |
| delete | Delete caches if any |
| help | Show this help message and exit |

### As a library
Include `fakeua.h` into your C file and build with `-DBUILD_AS_LIBRARY` option for the above functionalities.

### Dependency
Just `curl`, which usually comes with the unix systems.
