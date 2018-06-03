# Game of Life
 
OOP implementation of famous Game of Life

### Target platform: Ubuntu 16.04

Language: C++11 compiled under GCC 5.4.0 using CMake 3.5.2

## Installing

### First step:

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
Scanning dependencies of target GameOfLife
[ 25%] Building CXX object CMakeFiles/GameOfLife.dir/sources/main.cpp.o
[ 50%] Building CXX object CMakeFiles/GameOfLife.dir/sources/Game.cpp.o
[ 75%] Building CXX object CMakeFiles/GameOfLife.dir/sources/functions.cpp.o
[100%] Linking CXX executable build/GameOfLife
[100%] Built target GameOfLife
```

## Author

* **Taras Koval** - *All work* - [TarasKoval](https://github.com/TarasKoval)

## License

No license - do what you want
