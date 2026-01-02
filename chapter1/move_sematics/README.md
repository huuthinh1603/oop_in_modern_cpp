
# What is move?
Move semantics is a importance mechanism in C++ 11 that help optimizing performance by reusing resource instead copy them

```cpp
std::string c = "Hello, World!!!"
std::string s = std::move(c);
```

# How does an object support move semantics?
Objects are spawned from class belong to standard library, they have been support default. Custom objects of developer will need to implement 2 methods are 'move constructor and move assignment'
```cpp
T(T&& other);
T& operator=(T&& other)
```

An object after moving-from, that object will become valid but unspecified 
```cpp
std::string c = "hi";
std::string s = std::move(c); // c is still valid but unspecified

//  then after moving-from c variable, c is empty() and be able to assign a new string
c = "hello"; 
```

# When does move semantics occur?
It occur when: 
* return a temp object: ``` std::string func() { std::string("hello"); } ```
* assign to a temp object: ``` std::string a = "hello"; ```
* use std::move()

