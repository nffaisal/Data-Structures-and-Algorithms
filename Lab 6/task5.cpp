#include <iostream>
using namespace std;

const int SIZE = 5;
int items[SIZE];
int front = -1;
int rear = -1;

void enqueue(int value)
{
    if (rear == SIZE - 1)
    {
        cout << "Queue is full. Cannot insert.\n";
        return;
    }

    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear++;
    }

    items[rear] = value;
    cout << value << " added to queue.\n";
}

void dequeue()
{
    if (front == -1)
    {
        cout << "Queue is empty. Cannot remove.\n";
        return;
    }

    cout << "Removed: " << items[front] << endl;

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front++;
    }
}

void peekFront()
{
    if (front == -1)
    {
        cout << "Queue is empty.\n";
        return;
    }

    cout << "Next value: " << items[front] << endl;
}

void display()
{
    if (front == -1)
    {
        cout << "Queue is empty.\n";
        return;
    }

    cout << "Queue (front to rear): ";

    for (int i = front; i <= rear; i++)
    {
        cout << items[i] << " ";
    }

    cout << endl;
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    dequeue();
    peekFront();
    display();

    // Remove all remaining elements
    dequeue();
    dequeue();

    // Test removal from an empty queue
    dequeue();

    // Test insertion after the queue resets
    enqueue(40);
    peekFront();
    display();

    return 0;
}