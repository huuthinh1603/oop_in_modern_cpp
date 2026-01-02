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



