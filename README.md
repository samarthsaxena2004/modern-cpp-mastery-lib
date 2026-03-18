# modern-cpp-mastery-lib

> A header-only C++17 library demonstrating modern C++ features — custom containers, allocators, RAII, and move semantics.

Built as a learning project to practice the exact skills used in systems/embedded C++ roles.

---

## Features

- **`FixedVector<T, N>`** — Stack-allocated fixed-capacity vector with full move semantics and range-for support
- **`CustomAllocator<T>`** — STL-compatible custom allocator demonstrating low-level memory control
- **`ScopedTimer`** — RAII-based high-resolution timer; prints elapsed time automatically on scope exit

## Concepts Demonstrated

| Concept | Where |
|---|---|
| Templates (`template<T, N>`) | `FixedVector` |
| Move semantics + `noexcept` | `FixedVector` move ctor/assignment |
| RAII | `ScopedTimer`, `std::array` |
| Rule of 5 | `FixedVector` |
| Custom allocators | `CustomAllocator` |
| Iterator protocol | `FixedVector::begin()/end()` |

## Build

```bash
mkdir -p build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . --config Release
./demo
```

Requires: CMake 3.16+, C++17-compatible compiler (clang++ / g++)

## Memory Safety

Built with AddressSanitizer + UBSan:

```bash
cmake .. -DCMAKE_BUILD_TYPE=Debug
cmake --build .
./demo   # runs clean — 0 leaks
```
