# About
An implementation of [spiral matrix task](https://leetcode.com/problems/spiral-matrix/description/).

# Build

To build you can use either Qt5 or Qt6

If Qt is in PATH then
```console
mkdir build && cd build
cmake ..
cmake --build . -j $(sysctl -n hw.logicalcpu)
```

You can specify Qt path like so
```console
cmake .. -DCMAKE_PREFIX_PATH="qt_prefix_path"
```

If you installed Qt with brew you can
```console
cmake .. -DCMAKE_PREFIX_PATH=$(brew --prefix qt@5)
```

# Run
If you do `./spiral rows cols` then you invoke console output.</br>
If you do `./spiral` without arguments you will invoke app with qt window.

# Code style
There are rules to code style:
* Class names are `UpperCamelCase`
* Structs names are `lowerCamelCase`
* Methods are `UpperCamelCase`
* Braces are Allman style like so
```c++
void foo
{
    if (a)
    {
        ...
    }
}
```
* All primitive or primitive mimicking types are `lowerCamelCase` (QString, std::string, int, double, bool, etc.)
* All non-primitive types should be `UpperCamelCase`
* Qt slots should be as signals
* Qt signals should be `lowerCamelCase`
* Enum names should be `UpperCamelCase` and values should be also `UpperCamelCase`

Most of this can be achieved with `clang-tidy` checks and `clang-format` formatter that uses .clang-format configuration like so
```console
clang-format -i src/window.cpp
```
from project root and window.cpp file will be formatted as it should be (Allman braces, column 120 max width etc.)

# Test

There is also tests
```console
cd build && ctest
```
or you can run each test individually
