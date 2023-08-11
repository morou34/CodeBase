#include <iostream>
class stack
{
private:
    static constexpr int MAX_SIZE = 20;
    int top{-1}, array[MAX_SIZE];

public:
    stack() = default;

    void push(int x)
    {
        if (top == MAX_SIZE - 1)
        {
            std::cout << "Stack Overflow, can't add: " << x << std::endl;
            return;
        }
        array[++top] = x;
        // std::cout << "value added: " << x << "  | top :" << top << std::endl;
    }

    void pop()
    {
        if (top == -1)
        {
            std::cout << "Stack is empty." << std::endl;
            return;
        }
        top--;
    }

    bool empty() { return top > -1 ? true : false; }

    int size() { return top + 1; };

    void print()
    {
        for (size_t i = 0; i <= top; i++)
            std::cout << array[i] << "|";

        std::cout << "\n";
    }
};

int main(int argc, char const *argv[])
{
    stack mystack;
    mystack.pop();
    for (size_t i = 1; i <= 30; i++)
        mystack.push(i);

    std::cout << std::boolalpha;
    std::cout << "size: " << mystack.size() << std::endl;
    std::cout << "empty: " << mystack.empty() << std::endl;
    mystack.print();

    mystack.pop();
    std::cout << "size: " << mystack.size() << std::endl;
    mystack.print();

    return 0;
}
