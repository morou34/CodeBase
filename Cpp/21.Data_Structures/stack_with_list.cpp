#include <iostream>
#include <string>
#include <list>

template <typename T>
struct Node
{
    T data;
    Node<T> *next;

    Node()
    {
        this->next = nullptr;
    };
    Node(T x) : data{x}, next{nullptr} {}
    ~Node()
    {
        std::cout << "<Node> data = " << data << " destroyed." << std::endl;
    }
};
template <typename T>
class stack_with_list
{
private:
    Node<T> *head{nullptr};
    int size{0};

public:
    bool isEmpty() { return size > 0 ? false : true; }
    void push(T data)
    {
        Node<T> *node = new Node<T>(data);
        node->next = head;
        head = node;
        size++;
    }

    void push_back(T data)
    {
        Node<T> *node = new Node<T>();
        Node<T> *newNode = new Node<T>(data);

        if (size == 0)
        {
            head = newNode;
            size++;
            return;
        }

        node = head;
        while (node->next != nullptr) // NULL
        {
            node = node->next;
        }
        node->next = newNode;
        size++;
    }

    T pop()
    {
        if (size == 0)
        {
            std::cout << "stack is empty" << std::endl;
        }
        else
        {
            T data;
            Node<T> *temp;
            temp = head;
            head = head->next;
            data = temp->data;
            delete temp;
            size--;
            return data;
        }
    }

    T back()
    {
        Node<T> *node = head;
        while (node->next != nullptr)
        {
            node = node->next;
        }
        return node->data;
    }

    void print()
    {
        if (size == 0)
        {
            std::cout << "Stack is empty." << std::endl;
            return;
        }

        Node<T> *p = new Node<T>();
        p = head;
        while (p != nullptr)
        {
            std::cout << p->data << "|";
            p = p->next;
        }
        std::cout << "\n";
    }
    int length() { return size; }
};

std::string reverse_string(std::string str)
{
    stack_with_list<char> text;
    for (const auto &ch : str)
    {
        if (std::isalpha(ch))
            text.push(ch);
    }
    std::string reversed;
    while (text.length() > 0)
        reversed += text.pop();
    return reversed;
}

bool valide_parentheses(std::string expression)
{
    std::string LP{"[{("};
    std::string RP{"]})"};
    stack_with_list<char> stack;
    for (auto &ch : expression)
    {
        if (LP.find(ch) != std::string::npos)
        {
            stack.push(ch);
        }
        if (RP.find(ch) != std::string::npos)
        {
            if (stack.length() > 0)
            {

                if (ch == '}')
                {
                    if (stack.back() == '{')
                        stack.pop();
                    else
                        return false;
                }
                else if (ch == ']')
                {
                    if (stack.back() == '[')
                        stack.pop();
                    else
                        return false;
                }
                else
                {
                    if (stack.back() == '(')
                        stack.pop();
                    else
                        return false;
                    // ')'
                }
            }
            else
                return false;
        }
    }
    return stack.length() > 0 ? 0 : 1;
}
int main(int argc, char const *argv[])
{

    stack_with_list<int> stack;
    stack.print();
    for (size_t i = 1; i <= 10; i++)
    {
        stack.push(10 * i);
    }
    stack.print();
    stack.pop();
    stack.pop();
    stack.print();
    std::cout << "size: " << stack.length() << std::endl;

    std::cout << "-------------------" << std::endl;
    std::string text{"Cpp is awesome"};
    std::string reversed = reverse_string(text);
    std::cout << reversed << std::endl;

    stack_with_list<char> mystack;
    mystack.push_back('X');
    mystack.push_back('C');
    mystack.push_back('A');
    mystack.push_back('F');
    mystack.print();
    std::cout << mystack.back() << std::endl;

    std::string code{"{{{hello world.}}}"};
    std::cout << "valid code: " << valide_parentheses(code) << std::endl;

    return 0;
}
