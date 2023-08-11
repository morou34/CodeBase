#include <iostream>
#include <string>

template <typename T>
struct Node
{
    Node<T> *next;
    T data;

    Node() : next{nullptr} {}
    Node(T value) : next{nullptr}, data{value} {}
};

template <typename T>
class queue
{
private:
    Node<T> *head;
    Node<T> *tail;

public:
    queue() : head{nullptr}, tail{nullptr} {};

    void enqueue(T data)
    {
        Node<T> *node = new Node<T>(data);
        if (head == nullptr)
        {
            head = node;
            tail = node;
        }
        else
        {
            tail->next = node;
            tail = node;
        }
    }

    T dequeue()
    {
        Node<T> *node = head;
        head = head->next;
        return node->data;
    }

    void print()
    {
        Node<T> *node = head;
        while (node != nullptr)
        {
            std::cout << node->data << "<-";
            node = node->next;
        }
        std::cout << "\n";
    }
};

int main(int argc, const char **argv)
{
    queue<int> numbers;
    for (size_t i = 1; i < 11; i++)
        numbers.enqueue(i);

    numbers.print();

    std::cout << numbers.dequeue() << std::endl;
    std::cout << numbers.dequeue() << std::endl;
    return 0;
}