#include <vector>
#include <iostream>
#include <string>

class Cat {
public:
    Cat(const std::string &color, int age) : 
        m_color(std::move(color)), // Must use initializer list to initialize value for a member variable
        m_age(age)
    { }

    ~Cat() = default;

private:
    const std::string m_color;
    int m_age;
};

int main(int argc, char *argv[])
{
    Cat cat("yellow", 5);

    return 0;
}