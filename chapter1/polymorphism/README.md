# `override` keyword
The `override` keyword is used to explicitly state that a function in a derived class is intended to override a virtual function in its base class.

## Key functions
* **Error Checking**: If the base class function is not virtual, or if the function signature (name, parameter types, const-qualification) does not match the base class's virtual function, the compiler will issue a compilation error.
* **Preventing Subtle Bugs**: It prevents common mistakes such as: Mismatched parameter lists (e.g., forgetting a const or using a different type). Accidentally not overriding the function, which can lead to unexpected behavior due to slicing or calling the wrong function through a base class pointer.

```cpp

class Animal {
public:
    virtual void eat()
    {
        std::cout << "eat something" << std::endl;
    }

    virtual void run()
    {
        std::cout << "run run run" << std::endl;
    }
};

class Cat : public Animal {
public:
    /* If the eat function of the base class changes
     * signature(e.g: void eat() const). 
     * The compiler notifies an error to show  
     * that doesn't match between the base class and 
     * derived class 
     */
    void eat() override 
    {
        std::cout << "cats like to eat fish" << std::endl;
    }
};

int main(int argc, char *argv[])
{
    Cat cat;

    cat.eat();
    cat.run();

    return 0;
}
```

# `final` keyword
The `final` keyword can be applied to a virtual function or an entire class. 
## Applied to Virtual Function
When applied to a virtual function in a base class, it prevents any derived classes from further overriding that specific function.

* **Purpose**: To enforce a design decision where a particular implementation in the class hierarchy must be the final one.
* **Error**: If a class attempts to override a function marked with final, the compiler will issue a compilation error.

## Applied to Class 
When applied to a class definition, it prevents the class from being inherited from by any other class.

* **Purpose**: To enforce that a class is a leaf node in the inheritance tree, ensuring that its behavior and structure cannot be modified by subclasses. This is similar to a "sealed" class in other languages.
* **Error**: If a class attempts to inherit from a class marked with final, the compiler will issue a compilation error.

```cpp
#include <iostream>

class Animal {
public:
    Animal() = default;
    ~Animal() = default;

    virtual void eat()
    {
        std::cout << "eat something" << std::endl;
    }

    virtual void run()
    {
        std::cout << "run run run" << std::endl;
    }
};

class Cat final : public Animal {
public:
    Cat() = default;
    ~Cat() = default;

    void eat() override 
    {
        std::cout << "cats like to eat fish" << std::endl;
    }
};

/* 
 * OrangeCat can't inherit Cat, because the Cat class 
 * is marked final.
 */
class OrangeCat final : public Animal {
public:
    OrangeCat() = default;
    ~OrangeCat() = default;

    void eat()
    {
        std::cout << "orange cats also like to eat fish" << std::endl;
    }
};

int main(int argc, char *argv[])
{
    Cat cat;
    OrangeCat orangeCat;

    cat.eat();
    cat.run();
    orangeCat.eat();

    return 0;
}
```
