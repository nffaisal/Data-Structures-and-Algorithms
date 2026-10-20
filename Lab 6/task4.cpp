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

    display();

    // Fill the remaining spaces
    enqueue(40);
    enqueue(50);

    // Test insertion when full
    enqueue(60);

    display();

    return 0;
}