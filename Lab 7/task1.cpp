
#include <iostream>
using namespace std;

class ArrayQueue {  //array queue with the pointers
private:
    int arr[5];
    int front;
    int rear;

public:
    // Constructor: initialize an empty queue
    ArrayQueue() {
        front = -1;
        rear = -1;
    }
    // Check whether the queue is empty
    bool IsEmpty() {
        return front == -1;
    }

    bool IsFull() { //check whether the queue is full
        return rear == 4;
    }

    // Insert a value at the rear
    void Enqueue(int value) { //insert a value at rear
        if (IsFull()) {
            cout << "Queue is full. Cannot insert"<< value << endl;
            return;
        }

        if (IsEmpty()) { //if inserting the first element
            front = 0;
        }

        rear++;
        arr[rear] = value;

        cout << value << "inserted into the queue"
             << endl;
    }

    void Dequeue() { //remove and display first value
        if (IsEmpty()) {
            cout << "Queue is empty! Cannot dequeue."
                 << endl;
            return;
        }

        cout << "Removed: " << arr[front] << endl;

        if (front == rear) { //if this was the last element
            front = -1;
            rear = -1;
        } else {
            front++;
        }
    }

    void Peek() { //display front value without removing it
        if (IsEmpty()) {
            cout << "Queue is empty! Nothing to peek."
                 << endl;
            return;
        }

        cout << "Front element: " << arr[front] << endl;
    }

    void Display() { //display elements front to rear
        if (IsEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue: ";

        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main() {


    ArrayQueue q;

    cout << "Task 1: Linear Array Queue"
         << endl;

    // Insert five values
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);
    q.Enqueue(50);

    q.Display();

    // Check the front element
    q.Peek();

    // Remove two elements
    q.Dequeue();
    q.Dequeue();

    q.Display();

    // This insertion must fail because rear == 4
    q.Enqueue(60);

    q.Display();

    // Remove all remaining elements
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();

    // Test dequeue on an empty queue
    q.Dequeue();

    // Test reuse after resetting the indices
    q.Enqueue(70);
    q.Display();
    q.Peek();

    return 0;
}
