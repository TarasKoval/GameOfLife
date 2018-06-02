# Game of Life
 
OOP implementation of famous Game of Life

## Getting Started

### Prerequisites

I use CMake to build the system.

You need to have CMake 3.5.2

## Installing

### First step:

Good installer with separate executable files will be in the next versions, but for now:

In CMakeLists.txt you need to left one of three lines:

```
sources/main.cpp
sources/tests.cpp
sources/fastSimulation.cpp
```

### Second step:

In bash:

```
    cmake ./CMakeLists.txt
```

Output (approximately):

```
-- The C compiler identification is GNU 5.4.0
-- The CXX compiler identification is GNU 5.4.0
-- Check for working C compiler: /usr/bin/cc
-- Check for working C compiler: /usr/bin/cc -- works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Detecting C compile features
-- Detecting C compile features - done
-- Check for working CXX compiler: /usr/bin/c++
-- Check for working CXX compiler: /usr/bin/c++ -- works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done
-- Generating done
-- Build files have been written to: YourFolder
```

### Third step:

```
    make
```

Output (approximately):

```
Scanning dependencies of target mainGame
[ 25%] Building CXX object CMakeFiles/mainGame.dir/sources/main.cpp.o
[ 50%] Building CXX object CMakeFiles/mainGame.dir/sources/Game.cpp.o
[ 75%] Building CXX object CMakeFiles/mainGame.dir/sources/checkFilesForEquality.cpp.o
[100%] Linking CXX executable mainGame
[100%] Built target mainGame
```

### Forth step:

In this version, I have dependencies on resource folder.

So you have to put the executable file in any folder inside the project.

Folder structer need to look like this: /projectFolder/randomFolderName/mainGame

Then run the executable.

## Running the tests

In CMakeLists.txt leave next line:

```
    sources/tests.cpp
```

And go through the installation process.

## Error handling

If you chose to start the game with pattern and after choosing the pattern, you got next message:

```
Wrong address to the file
```

That's mean you need to through the Installation: Forth step.

## Author

* **Taras Koval** - *All work* - [TarasKoval](https://github.com/TarasKoval)

## License

No license - do what you want
