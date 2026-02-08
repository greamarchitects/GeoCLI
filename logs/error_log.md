# Error Log – GeoCLI (Code & Tooling Only)

**Project:** GeoCLI – Geometry Command Line Interface  
**Course:** C++ Programming Fundamentals  
**Author:** Gresa Calliku  

---

## Error 1: Header files not found (`cli.hpp`, `geometry.hpp`, etc.)

**Error message**
```
fatal error: cli.hpp: No such file or directory
```

**Cause**
- Header files were placed inside the `include/` directory.
- The compiler was not told where to look for them.

**Fix**
- Added include path to compiler flags.

**Solution**
```bash
-Iinclude
```

---

## Error 2: Source files not found during compilation

**Error message**
```
cc1plus: fatal error: src/main.cpp: No such file or directory
```

**Cause**
- Compilation was run from the wrong directory.
- Relative paths did not match the project structure.

**Fix**
- Compiled from the project root.
- Updated Makefile to use `SRC_DIR` and `BUILD_DIR`.

---

## Error 3: `make` reports “Nothing to be done for all”

**Cause**
- `TARGET` was not properly linked to object files.
- Object rules were missing or incorrect.

**Fix**
- Introduced object-based build using pattern rules.
- Ensured `$(TARGET)` depends on `$(OBJECTS)`.

---

## Error 4: `.o` and executable not generated

**Cause**
- Compilation and linking steps were mixed into a single rule.
- No rule existed for compiling individual `.cpp` files into `.o`.

**Fix**
```make
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
```

---

## Error 5: Menu input rejects valid numeric input

**Cause**
- Mixed usage of `cin >> choice` and custom input functions.

**Fix**
- Centralized numeric input using `cli::read_int`.

---

## Error 6: `read_choice` logic incorrect

**Cause**
- `read_choice` returns `char` but was treated as `int`.

**Fix**
- Compared against `'a'`, `'b'`.

---

## Error 7: Default argument redefinition

**Cause**
- Default argument defined in both header and source.

**Fix**
- Kept default only in header.

---

## Error 8: Const correctness violation

**Cause**
- Non-const references used with const objects.

**Fix**
```cpp
const geometry::Point&
```

---

## Error 9: `geometry_primitives` not declared

**Cause**
- Missing header and namespace mismatch.

**Fix**
- Added `geometry_primitives.hpp`.

---

## Error 10: Static functions declared but not defined

**Cause**
- `static` functions declared in headers.

**Fix**
- Removed `static`, implemented in `.cpp`.

---

## Error 11: CSV header not supported

**Cause**
- CSV contained header (`polygon_id,x,y`).

**Fix**
- Skipped header, grouped by polygon ID.

---

## Error 12: Directory path treated as file

**Cause**
- No filesystem validation.

**Fix**
- Added `std::filesystem` checks.

---

_End of Error Log_
