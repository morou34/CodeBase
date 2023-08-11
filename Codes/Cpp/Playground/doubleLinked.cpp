#include <iostream>

struct Node
{
    int data;
    Node *next;
    Node *previous;

    Node() : Node(0){};
    Node(int data) : data{data}, next{nullptr}, previous{nullptr} {};
};

Node *head_ptr{nullptr};

void print()
{
    if (head_ptr == nullptr)
    {
        std::cout << "List is empty" << std::endl;
        return;
    }

    Node *current = new Node();
    current = head_ptr;
    while (current != nullptr)
    {
        std::cout << current->data << "|";
        current = current->next;
    }
}

void reversePrint(Node *p)
{
    if (head_ptr == nullptr)
    {
        std::cout << "List is empty" << std::endl;
        return;
    }
    if (p == nullptr)
        return;
    reversePrint(p->next);
    std::cout << p->data << "|";
}

void push_front(int x)
{
    Node *newNode = new Node(x);
    if (head_ptr == nullptr)
    {
        head_ptr = newNode;
        return;
    }

    newNode->next = head_ptr;
    head_ptr->previous = newNode;
    head_ptr = newNode;
}

int main(int argc, char const *argv[])
{
    print();
    for (size_t i = 1; i <= 10; i++)
        push_front(i);

    print();
    std::cout << "\n";
    reversePrint(head_ptr);

    return 0;
}
