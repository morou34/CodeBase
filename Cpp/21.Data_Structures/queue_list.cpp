#include <iostream>

template <typename T>
struct Node
{
    T data;
    Node<T> *next;

    Node() = default;
    Node(T val) : data{val}, next{nullptr} {};
};

template <typename T>
class Queue
{
private:
    Node<T> *head;
    Node<T> *rear;
    int length{0};

public:
    Queue() = default;
    bool empty();
    T front();
    void enqueue(T val);
    void dequeue();
    int size();
};

template <typename T>
void Queue<T>::enqueue(T val)
{
    // create a new node
    Node<T> *node = new Node<T>(val);

    // if queue is empty, the node will be
    // the head/front and rear at the same time
    if (length == 0)
    {
        head = node;
        rear = node;
    }
    // if there is at least one element
    // point the current element to new node
    // point rear to new node
    else
    {
        rear->next = node;
        rear = node;
    }
    length++;
}

template <typename T>
void Queue<T>::dequeue()
{
    // nothing to delete if list is empty
    if (empty())
    {
        std::cout << "Queue is empty." << std::endl;
        return;
    }
    // point to the head/front of the queue
    Node<T> *temp = head;

    // point head to next element
    head = head->next;

    // remove the first element
    delete temp;

    // decrease size by 1
    length--;
}

template <typename T>
T Queue<T>::front()
{
    // return fist node value
    return head->data;
}

template <typename T>
bool Queue<T>::empty() { return length == 0; }

template <typename T>
int Queue<T>::size() { return length; }

int main(int argc, char const *argv[])
{
    Queue<int> numbres;
    numbres.enqueue(10);
    numbres.enqueue(20);
    numbres.enqueue(30);
    numbres.enqueue(40);

    while (!numbres.empty())
    {
        // Get the front of the queue.
        std::cout << numbres.front() << " ";

        // delete front element
        numbres.dequeue();
    }

    std::cout << "\n";

    std::cout << "empty(): " << numbres.empty() << std::endl;
    std::cout << "size(): " << numbres.size() << std::endl;
    return 0;
}
