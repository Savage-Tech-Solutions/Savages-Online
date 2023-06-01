# Steps to compile the Game:
## Starting from the root directory called "Savages-Online"

### This Create's a directory/folder named build and then goes inside of it 
1.
```bash
mkdir build && cd build
```

### Building the game with a CMakeLists.txt file to generate a Makefile for compilation:
**Things to note when using the ***cmake -S <SOURCE_DESTINATION> -B <BUILD_DESTINATION> -Wno-dev*** command from terminal:**
***Which in our case the root directory looks for the source from Savages-Online/src so we use '..' to denote going back a folder to be out of the build directory/folder***
***The build destination we'll use a '.' to indicate it to make the executable in the current directory/folder which will be found as build/Savages-Online (A UNIX Executable file)***
***The -Wno-dev is just a compiler flag needed to avoid a deprecation issue being compiled.***

2.
```bash
cmake -S .. -B . -Wno-dev
```

### Now compile the built game into a executable file:
3.
```bash
make
```