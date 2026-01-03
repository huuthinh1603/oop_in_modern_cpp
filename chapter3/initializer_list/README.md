# Initialization and Assignment in C++

From the compiler's perspective, there are 2 ways to initialize a value for a variable:

* Construction: The object is created and given its initial state in a single step. `<type> v = <value>;`
  
* Assignment: This is a two-step process. First, the object is default-constructed (given a "blank" or dummy state), and then the assignment operator is called to overwrite that state. `<type> v; v = <value>;`

## Performance Comparison

Construction performance is always higher than assignment depended on type of variable.

|Type                | Performance   | Why?                 |
| ------------------ | ------------- | -------------------- |
| Primitive data | Negligible |
|Complex Objects | Significant | Two steps: 1.Allocate a small default buffer (construction). 2. Deallocate it and allocate a new, larger buffer for the data (assignment) |
|Move Type           | Critical      | Initializing directly is often the only way to ensure ownership is transferred without unnecessary overhead |

e.g:

```cpp
std::string s;      // 1. Default constructor: allocates 0-15 bytes (Small String Optimization)
s = "A very long string..."; // 2. Assignment: checks size, reallocates heap memory, copies characters
```

You have paid for two operations where one would suffice. If you use `std::string s = "A very long string...";`, the string is constructed exactly once with the correct size.

# Member Initializer List(Construction type)

**Initializer Lists** are a way to initialize class members and base classes before the body of the constructor executes. They are specified after the constructor’s parameter list, starting with a colon : and followed by a list of initializers

```cpp
ClassName::ClassName(parameters) : 
    member1(value1), 
    member2(value2),
    baseClassBaseConstructor(value) 
{ 
    // Constructor body
}
```

## Benefits of Using Initializer Lists

1. **Efficiency**: Initializer lists initialize member variables directly, avoiding the overhead of default initialization followed by assignment.
2. **Const Members**: Members declared as const or references must be initialized through initializer lists because they cannot be assigned values after construction.
3. **Base Class Initialization**: Initializer lists are essential for initializing base classes before the derived class’s constructor body executes.
4. **Complex Initializations**: Initializer lists allow for more complex initializations of member variables that require specific arguments or are initialized with other objects.

