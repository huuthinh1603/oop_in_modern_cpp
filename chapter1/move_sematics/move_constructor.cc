/* 
 * Use a std::move for an object that hasn't declared 'move constructor or move assignment', then copy constructor will be used
 */


#include <iostream>

#define DEFAULT_BUFFER_SIZE     1024

class Buffer {
public:
    Buffer() = delete;

    Buffer(void *data, size_t size) : m_data(nullptr), m_size(0)
    {
        if (size < DEFAULT_BUFFER_SIZE)
            size = DEFAULT_BUFFER_SIZE;

        m_data = malloc(size);
        if (!m_data)
        {
            std::cout << "Failed to allocate heap" << std::endl;
            return;
        }
        else
        {
            // m_data = memcpy()
        }

        m_size = size;


    }

    ~Buffer()
    {
        free(m_data);
    }

    Buffer(Buffer& other)
    {
        std::cout << "Buffer copy constructor" << std::endl;
    }

    Buffer(Buffer&& other)
    {
        std::cout << "Buffer move constructor" << std::endl;
        this->m_data = other.m_data;
        this->m_size = other.m_size;
    }

    Buffer& operator=(Buffer&& other)
    {
        std::cout << "move operator assignment" << std::endl;
        return *this;
    }

    void *getData()
    {
        return m_data;
    }

    size_t getSize()
    {
        return m_size;
    }

private:
    void *m_data;
    size_t m_size;
};

int main(int argc, char *argv[])
{ 
    char s[] = "Hello, World!!!";
    Buffer buf1(s, sizeof(s));
    // Buffer eg2 = std::move(eg1);

    return 0;
}