#include <iostream>

struct Node
{
    int data;
    Node *next;

    Node() = default;
    Node(int data) : data{data}, next{nullptr} {};
};

void Insert(Node **head, int data)
{
    Node *newNode = new Node(data);

    if (*head == nullptr)
    {
        std::cout << "node->data: " << newNode->data << " inserted." << std::endl;
        *head = newNode;
    }

    else
    {
        Node *temp = new Node();
        temp->next = *head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
        std::cout << "node->data: " << newNode->data << " inserted." << std::endl;
    }
}
// Print the linked list in order
void print(Node *p)
{
    if (p == nullptr)
        return;
    std::cout << p->data << "|";
    print(p->next);
}

// Print the list reverse using reccursion
void reversePrint(Node *p)
{
    if (p == nullptr)
        return;

    reversePrint(p->next);
    std::cout << p->data << "|";
}

// Reverse link using reccursion
void ReverseList(Node *p, Node **head)
{
    // Exist condition
    if (p->next == nullptr)
    {
        *head = p;
        return;
    }
    ReverseList(p->next, head);
    Node *prev = p->next;
    prev->next = p;
    p->next = nullptr;
}

int main(int argc, char const *argv[])
{
    Node *head = {nullptr};

    for (size_t i = 5; i <= 10; i++)
        Insert(&head, i);

    print(head);
    std::cout << "\n";
    reversePrint(head);
    std::cout << "\n";
    // Here i need to modify the pointer passing by reference.
    ReverseList(head, &head);
    print(head);

    return 0;
}
