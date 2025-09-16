# CPP Module 01 - Memory allocation, pointers to members, references, switch statement

This module covers memory management, the differences between pointers and references, and introduces advanced C++ concepts.

## Table of Contents
- [ex00: BraiiiiiiinnnzzzZ](#ex00-braiiiiiiinnnzzzzz)
- [ex01: Moar brainz!](#ex01-moar-brainz)
- [ex02: HI THIS IS BRAIN](#ex02-hi-this-is-brain)
- [ex03: Unnecessary violence](#ex03-unnecessary-violence)
- [ex04: Sed is for losers](#ex04-sed-is-for-losers)
- [ex05: Harl 2.0](#ex05-harl-20)
- [ex06: Harl filter](#ex06-harl-filter)

## Learning Objectives
- Understanding stack vs heap allocation
- Mastering pointers and references
- Memory management with `new` and `delete`
- Pointer to member functions
- File I/O operations
- Switch statements

---

## ex00: BraiiiiiiinnnzzzZ

**Concepts:** Stack vs Heap allocation, object lifetime

### Files
- `Zombie.hpp` - Zombie class declaration
- `Zombie.cpp` - Zombie class implementation
- `newZombie.cpp` - Heap allocation function
- `randomChump.cpp` - Stack allocation function
- `main.cpp` - Testing both allocation methods

### Key Learning Points
- **Stack allocation**: Objects are automatically destroyed when out of scope
- **Heap allocation**: Objects persist until explicitly deleted with `delete`
- **Memory management**: Every `new` must have a corresponding `delete`

### Usage
```bash
make
./zombie
```

---

## ex01: Moar brainz!

**Concepts:** Dynamic array allocation, array management

### Files
- `Zombie.hpp` - Enhanced Zombie class
- `Zombie.cpp` - Implementation with name setter
- `zombieHorde.cpp` - Array allocation function
- `main.cpp` - Testing array allocation

### Key Learning Points
- **Array allocation**: `new Type[size]` creates arrays on heap
- **Array deallocation**: Must use `delete[]` for arrays
- **Object initialization**: Setting values for dynamically allocated objects

### Usage
```bash
make
./zombie_horde
```

---

## ex02: HI THIS IS BRAIN

**Concepts:** Pointers vs References

### Files
- `main.cpp` - Demonstration of pointer and reference behavior

### Key Learning Points
- **Pointers**: Store memory addresses, can be reassigned, can be null
- **References**: Aliases to existing variables, cannot be reassigned, cannot be null
- **Memory addresses**: Understanding how both point to the same location
- **Syntax differences**: `*ptr` vs direct access with references

### Usage
```bash
make
./brain
```

**Expected Output:**
```
string address: [memory_address]
stringPTR address: [same_memory_address]
stringREF address: [same_memory_address]
value of string: HI THIS IS BRAIN
value of stringPTR: HI THIS IS BRAIN
value of stringREF: HI THIS IS BRAIN
```

---

## ex03: Unnecessary violence

**Concepts:** Object composition, references in classes

### Files
- `Weapon.hpp` - Weapon class declaration
- `Weapon.cpp` - Weapon implementation
- `HumanA.hpp` - HumanA class (reference to weapon)
- `HumanA.cpp` - HumanA implementation
- `HumanB.hpp` - HumanB class (pointer to weapon)
- `HumanB.cpp` - HumanB implementation
- `main.cpp` - Testing both human types

### Key Learning Points
- **References in classes**: Must be initialized in constructor initializer list
- **Pointers in classes**: Can be null, can be reassigned
- **Object relationships**: Composition vs aggregation
- **Constructor initialization lists**: Proper initialization of reference members

### Usage
```bash
make
./violence
```

---

## ex04: Sed is for losers

**Concepts:** File I/O, string manipulation

### Files
- `main.cpp` - File processing implementation

### Key Learning Points
- **File streams**: `std::ifstream` and `std::ofstream`
- **String operations**: `std::string::find()` and `std::string::replace()`
- **Error handling**: Checking file operations
- **Command line arguments**: Processing program parameters

### Usage
```bash
make
./sed_is_for_losers <filename> <s1> <s2>
```

Creates `<filename>.replace` with all occurrences of `s1` replaced by `s2`.

---

## ex05: Harl 2.0

**Concepts:** Pointers to member functions, function arrays

### Files
- `Harl.hpp` - Harl class declaration
- `Harl.cpp` - Implementation with pointer to member functions
- `main.cpp` - Testing Harl complaints

### Key Learning Points
- **Pointer to member functions**: `ReturnType (ClassName::*ptr)(Parameters)`
- **Function arrays**: Creating lookup tables with function pointers
- **Dynamic function calling**: Calling functions based on string input
- **Member function syntax**: `(object.*functionPtr)()` and `(objectPtr->*functionPtr)()`

### Usage
```bash
make
./harl
```

### Implementation Highlight
```cpp
void (Harl::*complaint[4])(void) = {
    &Harl::debug,
    &Harl::info,
    &Harl::warning,
    &Harl::error
};
```

---

## ex06: Harl filter

**Concepts:** Switch statements, cascading function calls

### Files
- `Harl.hpp` - Enhanced Harl class
- `Harl.cpp` - Implementation with cascading calls
- `main.cpp` - Command line filtering

### Key Learning Points
- **Switch statements**: Alternative to if-else chains
- **Cascading function calls**: Each function calls subsequent levels
- **Command line processing**: Single parameter programs
- **Log level filtering**: Displaying current level and above

### Usage
```bash
make
./harlFilter "WARNING"
```

### Smart Implementation
Instead of using switch fallthrough, each function calls the next level:
- `debug()` calls `info()`, `warning()`, `error()`
- `info()` calls `warning()`, `error()`
- `warning()` calls `error()`
- `error()` stands alone

---

## Compilation
Each exercise includes a Makefile with:
- **Compiler**: `c++`
- **Flags**: `-Wall -Wextra -Werror -std=c++98`
- **Standard**: C++98 compliance

## Key Takeaways
1. **Memory Management**: Understanding when to use stack vs heap
2. **Pointers vs References**: Knowing when to use each
3. **Function Pointers**: Advanced technique for dynamic function calling
4. **Object Lifetime**: Proper resource management
5. **File Operations**: Basic I/O in C++
6. **Modern C++ Patterns**: Clean, efficient code organization

## Common Pitfalls Avoided
- Memory leaks (proper `delete` usage)
- Dangling pointers (careful object lifetime management)
- Reference initialization (must be done in constructor)
- File handling errors (proper error checking)
- Function pointer syntax (correct dereferencing)