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
