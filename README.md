# StackVec
Generic [Vec](https://doc.rust-lang.org/std/vec/struct.Vec.html) structure utilizing the stack rather than the heap in C11.

## Building
A library can be build as follows:
```
cmake build/
cd build/
cmake --build .
```
The library can then be found in `build/libstackvec.a`, relative to the project root.

## Tests
Tests can be found in the `tests/` directory.
They can be run as follows:
```
cmake build/
cd build/
cmake --build .
ctest
```

## License
MIT or Apache-2.0, at your option