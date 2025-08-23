# CPP Module 00 - Complete C++ Concepts Reference

A comprehensive guide to all C++ concepts learned in Module 00, with practical examples.

---

## Table of Contents
1. [Classes vs Objects](#classes-vs-objects)
2. [Access Specifiers](#access-specifiers)
3. [Constructors and Destructors](#constructors-and-destructors)
4. [Static Members](#static-members)
5. [Const Correctness](#const-correctness)
6. [Member Initialization Lists](#member-initialization-lists)
7. [This Pointer](#this-pointer)
8. [Method Overloading](#method-overloading)
9. [Pass by Value vs Reference](#pass-by-value-vs-reference)
10. [Namespaces](#namespaces)
11. [Header Guards](#header-guards)
12. [42 Official Concepts](#42-official-concepts)

---

## Classes vs Objects

### Definition
- **Class**: Blueprint/template that defines structure and behavior
- **Object/Instance**: Actual entity created from a class (same thing, different terms)

```cpp
class Car {                    // CLASS (blueprint)
private:
    std::string brand;
    int speed;
    
public:
    Car(std::string b);        // Constructor
    void accelerate();         // Method
    int getSpeed() const;      // Const method
};

Car myCar("Toyota");          // OBJECT/INSTANCE
Car yourCar("Honda");         // Another OBJECT/INSTANCE
```

### Key Points
- Class = Abstract concept (no memory allocated)
- Object = Concrete instance (takes memory space)
- One class can create many objects

---

## Access Specifiers

### Purpose
Control who can access class members - fundamental to **encapsulation**.

```cpp
class BankAccount {
private:
    double balance;           // Only class methods can access
    std::string pin;          // Protected secret data
    
public:
    void deposit(double amt); // Anyone can call
    double getBalance();      // Anyone can call
    bool withdraw(double amt);// Anyone can call
    
protected:                    // For inheritance (future modules)
    void logTransaction();    // Only class and derived classes
};
```

### Protection Types
1. **Validation Protection**: Prevent invalid data
2. **Data Consistency**: Keep related data synchronized
3. **Implementation Details**: Hide internal workings
4. **Security**: Control access to sensitive data
5. **Resource Management**: Proper cleanup

---

## Constructors and Destructors

### Basic Syntax
```cpp
class Student {
private:
    std::string name;
    int age;
    
public:
    // Default constructor
    Student() : name("Unknown"), age(0) {
        std::cout << "Default constructor called" << std::endl;
    }
    
    // Parameterized constructor
    Student(std::string n, int a) : name(n), age(a) {
        std::cout << "Parameterized constructor called" << std::endl;
    }
    
    // Destructor
    ~Student() {
        std::cout << "Destructor called for " << name << std::endl;
    }
};

Student s1;              // Calls default constructor
Student s2("Alice", 20); // Calls parameterized constructor
// Destructors called automatically when objects go out of scope
```

### Private Constructor Pattern
```cpp
class Singleton {
private:
    Singleton() {}  // Private! Can't create objects normally
    
public:
    Singleton(int value) { /* logic */ }  // Public parameterized
    
    static Singleton* getInstance() {
        static Singleton instance;
        return &instance;  // Only way to get default instance
    }
};
```

---

## Static Members

### Concept
- **Static attributes**: Belong to CLASS, shared by ALL instances
- **Instance attributes**: Each object has its own copy

```cpp
class Counter {
private:
    static int totalObjects;  // Shared by ALL instances
    int instanceId;           // Unique to each instance
    
public:
    Counter() {
        instanceId = ++totalObjects;  // Each gets unique ID
    }
    
    // Static method - belongs to CLASS
    static int getTotalCount() {
        return totalObjects;          // Can only access static members
        // return instanceId;         // ERROR! No access to instance members
    }
    
    // Instance method - belongs to OBJECT
    void showInfo() {
        std::cout << "ID: " << instanceId << std::endl;        // OK
        std::cout << "Total: " << totalObjects << std::endl;   // OK
    }
};

// Must define static members outside class
int Counter::totalObjects = 0;

Counter c1;  // totalObjects = 1, c1.instanceId = 1
Counter c2;  // totalObjects = 2, c2.instanceId = 2
std::cout << Counter::getTotalCount();  // Output: 2
```

### Access Rules
| Method Type | Can Access Static | Can Access Instance | Why |
|-------------|------------------|-------------------|-----|
| Static | ✅ YES | ❌ NO | No `this` pointer |
| Instance | ✅ YES | ✅ YES | Has `this` pointer |

---

## Const Correctness

### Const Methods
```cpp
class DataHolder {
private:
    int value;
    mutable int accessCount;  // Can change in const methods
    
public:
    // Const method - promises not to modify object state
    int getValue() const {
        accessCount++;        // OK! mutable allows this
        return value;         // OK! Just reading
        // value = 10;        // ERROR! Would change state
    }
    
    // Non-const method - can modify object
    void setValue(int v) {
        value = v;           // OK
    }
};

const DataHolder constObj(42);
DataHolder normalObj(24);

constObj.getValue();    // OK - const method on const object
// constObj.setValue(10); // ERROR! Non-const method on const object
normalObj.getValue();   // OK - const method on normal object
normalObj.setValue(10); // OK - non-const method on normal object
```

### Rule of Thumb
- **All getters should be const** (they don't modify state)
- **Setters cannot be const** (they modify state)

---

## Member Initialization Lists

### Syntax and Benefits
```cpp
class Rectangle {
private:
    const int id;        // const members MUST use initialization list
    int width, height;
    
public:
    // GOOD: Initialization list (efficient)
    Rectangle(int i, int w, int h) : id(i), width(w), height(h) {
        // Constructor body for complex logic only
    }
    
    // BAD: Assignment in body (less efficient + can't do const)
    // Rectangle(int i, int w, int h) {
    //     id = i;     // ERROR! Can't assign to const
    //     width = w;  // Default construction + assignment
    //     height = h; // Default construction + assignment
    // }
};
```

### Benefits
1. **Required for const members**
2. **More efficient** (direct initialization vs construction + assignment)
3. **Cleaner code**

---

## This Pointer

### Concept
Implicit pointer to the current object, available in all instance methods.

```cpp
class Student {
private:
    std::string name;
    
public:
    void setName(std::string name) {
        this->name = name;  // 'this' disambiguates parameter from member
        // Without 'this', parameter shadows member
    }
    
    Student& returnSelf() {
        return *this;  // Return reference to current object
    }
    
    void compare(const Student& other) {
        if (this == &other) {
            std::cout << "Same object!" << std::endl;
        }
    }
};

Student alice;
alice.setName("Alice").returnSelf();  // Method chaining possible!
```

---

## Method Overloading

### Same Name, Different Parameters
```cpp
class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }
    
    double add(double a, double b) {    // Different parameter types
        return a + b;
    }
    
    int add(int a, int b, int c) {      // Different number of parameters
        return a + b + c;
    }
    
    // ERROR: Return type alone doesn't count
    // double add(int a, int b);        // Conflict with first add()
};

Calculator calc;
calc.add(5, 3);        // Calls int version
calc.add(5.5, 3.2);    // Calls double version
calc.add(1, 2, 3);     // Calls three-parameter version
```

---

## Pass by Value vs Reference

### Different Ways to Pass Parameters
```cpp
// Pass by VALUE - copies the data (slower for large objects)
void modifyValue(int x) {
    x = 100;  // Only changes the copy, not original
}

// Pass by REFERENCE - works with original data
void modifyReference(int& x) {
    x = 100;  // Changes the original variable
}

// Pass by CONST REFERENCE - efficient but safe (recommended for objects)
void printValue(const std::string& text) {
    std::cout << text;  // No copy made, but can't modify
    // text = "new";    // ERROR! const prevents modification
}

int num = 5;
std::string message = "Hello";

modifyValue(num);           // num is still 5
modifyReference(num);       // num is now 100
printValue(message);        // Efficient, message unchanged
```

### When to Use What
- **By value**: Small types (int, char, bool)
- **By reference**: When you need to modify the original
- **By const reference**: Large objects you only read from

---

## Namespaces

### Purpose
Organize code and prevent naming conflicts.

```cpp
// Standard library namespace
std::cout << "Hello World" << std::endl;
std::string name = "Alice";
std::vector<int> numbers;

// Why we don't use "using namespace std"
// using namespace std;  // BAD - pollutes global namespace

// Custom namespaces (for larger projects)
namespace Math {
    double pi = 3.14159;
    double add(double a, double b) {
        return a + b;
    }
}

// Usage
double result = Math::add(5.0, 3.0);
std::cout << Math::pi << std::endl;
```

---

## Header Guards

### Traditional vs Modern
```cpp
// Traditional header guards (works everywhere)
#ifndef MYCLASS_HPP
#define MYCLASS_HPP

class MyClass {
    // Class definition
};

#endif

// Modern C++ (cleaner, preferred)
#pragma once

class MyClass {
    // Class definition
};
```

### Benefits of `#pragma once`
1. **Simpler**: One line vs three
2. **No naming conflicts**: No need for unique macro names
3. **Less error-prone**: Can't misspell guard names
4. **Faster compilation**: Compiler can optimize better

---

## 42 Official Concepts

### Namespaces ✅
```cpp
std::cout << "Using std namespace" << std::endl;
// Never: using namespace std;
```

### Stdio streams ✅
```cpp
std::cin >> input;
std::cout << output << std::endl;
// Input validation
if (std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(1000, '\n');
}
```

### Class and instance ✅
```cpp
class MyClass { };        // Class definition
MyClass obj;              // Instance creation
```

### Member attributes and member function ✅
```cpp
class Example {
private:
    int memberAttribute;      // Member attribute
public:
    void memberFunction();    // Member function
};
```

### This ✅
```cpp
void setName(std::string name) {
    this->name = name;  // this refers to current object
}
```

### Initialization list ✅
```cpp
Constructor(int x, int y) : member1(x), member2(y) { }
```

### Const ✅
```cpp
int getValue() const;  // Const method
const int value = 42;  // Const variable
```

### Visibility ✅
```cpp
class Example {
private:    // Only class can access
    int data;
public:     // Anyone can access
    void method();
protected:  // Class and derived classes (inheritance)
    void helper();
};
```

### Class vs struct ✅
```cpp
class MyClass {     // Default: private
    int data;       // private by default
};

struct MyStruct {   // Default: public  
    int data;       // public by default
};
```

### Accessors ✅
```cpp
class Student {
private:
    std::string name;
public:
    // Getter (accessor)
    std::string getName() const { return name; }
    // Setter (mutator)  
    void setName(const std::string& n) { name = n; }
};
```

### Comparisons
```cpp
class Student {
private:
    int grade;
public:
    bool operator==(const Student& other) const {
        return grade == other.grade;
    }
    bool operator<(const Student& other) const {
        return grade < other.grade;
    }
};
```

### Non member attributes and non member functions
```cpp
// Non-member (global) variables
int globalCounter = 0;

// Non-member (free) functions
void printMessage(const std::string& msg) {
    std::cout << msg << std::endl;
}

class MyClass {
    // Member attributes and functions go here
};
```

### Pointers to members
```cpp
class Calculator {
public:
    int add(int a, int b) { return a + b; }
    int value;
};

// Pointer to member function
int (Calculator::*operation)(int, int) = &Calculator::add;

// Pointer to member variable
int Calculator::*member = &Calculator::value;

Calculator calc;
int result = (calc.*operation)(5, 3);  // Calls add(5, 3)
```

---

## Quick Reference

### Class Template
```cpp
#pragma once
#include <iostream>
#include <string>

class MyClass {
private:
    static int count;
    std::string name;
    int value;
    
public:
    // Constructors
    MyClass();
    MyClass(const std::string& n, int v);
    
    // Destructor
    ~MyClass();
    
    // Getters (const methods)
    std::string getName() const;
    int getValue() const;
    
    // Setters
    void setName(const std::string& n);
    void setValue(int v);
    
    // Static methods
    static int getCount();
    
    // Other methods
    void display() const;
};

// Static member definition (in .cpp file)
int MyClass::count = 0;
```

---

## Best Practices Learned

1. **Always use const for getters**
2. **Use initialization lists for constructors**
3. **Prefer `#pragma once` over traditional header guards**
4. **Use pass by const reference for large objects**
5. **Make data members private, provide public interface**
6. **Use static members for class-level data**
7. **Never use `using namespace std` in headers**
8. **RAII: Constructor acquires resources, destructor releases them**

---

*This reference covers all concepts from CPP Module 00. Keep this handy for future modules!*