#include <iostream>
#include <string>

const size_t MAX_SIZE = 10;

template <typename T>
class Queue
{
private:
    int length{0}, f{-1}, r{-1};
    T array[MAX_SIZE];

public:
    Queue() = default;
    int size() const { return length; }
    bool empty() const { return length > 0 ? false : true; }
    bool full() const { return length == MAX_SIZE; }
    T front() const { return array[f]; };

    void enqueue(const T data)
    {
        if ((r + 1) % MAX_SIZE == f)
        {
            std::cout << "Queue is full" << std::endl;
            return;
        }
        else if (empty())
        {
            f = r = 0;
        }
        else
        {
            r = (r + 1) % MAX_SIZE;
        }
        length++;
        array[r] = data;
    }

    void dequeue()
    {
        if (empty())
        {
            std::cout << "queue is empty." << std::endl;
            return;
        }
        else if (f == r)
        {
            r = f = -1;
        }
        else
        {
            f = (f + 1) % MAX_SIZE;
        }
        length--;
    }
};

int main(int argc, char const *argv[])
{
    /*
    Queue<int> numbers;
    std::cout << "empty(): " << numbers.empty() << std::endl; // empty(): 1
    std::cout << "size() : " << numbers.size() << std::endl;  // size() : 0

    numbers.enqueue(1);
    numbers.enqueue(2);
    numbers.enqueue(3);
    std::cout << "\nempty(): " << numbers.empty() << std::endl; // empty(): 0
    std::cout << "size() : " << numbers.size() << std::endl;    // size() : 3

    std::cout << "\nfront(): " << numbers.front() << std::endl; // front(): 1

    numbers.dequeue();                                          // removes 1
    numbers.dequeue();                                          // removes 2
    std::cout << "\nfront(): " << numbers.front() << std::endl; // front(): 3

    numbers.dequeue(); // removes 3
    numbers.dequeue(); // queue is empty.


    // inserting MAX SIZE ELEMENT TO THE QUEUE.
    Queue<char> letters;
    for (size_t i = 0; i < MAX_SIZE + 13; i++)
    {
        letters.enqueue(i + 65); // enqueue A, B, ... J : A = 65 in ascii
    }

    for (size_t i = 0; i < MAX_SIZE; i++)
    {
        std::cout << letters.front() << std::endl;
        letters.dequeue();
    }
    */
    auto print = [](Queue<char> q)
    {
        while (!q.empty())
        {
            std::cout << q.front() << " ";
            q.dequeue();
        }
        std::cout << "\n";
    };

    Queue<char> letters;
    std::cout << "=== Inserting MAX_SIZE + 2 Elements ===" << std::endl;

    for (size_t i = 0; i < MAX_SIZE + 2; i++)
    {
        letters.enqueue(i + 65); //
    }

    std::cout << "==============" << std::endl;

    print(letters);

    letters.dequeue();
    letters.dequeue();

    print(letters);

    letters.enqueue('X');
    letters.enqueue('Y');
    letters.enqueue('A');

    print(letters);
    return 0;
}

// Output : 
=== Inserting MAX_SIZE + 2 Elements ===
Queue is full
Queue is full
==============
A B C D E F G H I J
C D E F G H I J
Queue is full
C D E F G H I J X Y