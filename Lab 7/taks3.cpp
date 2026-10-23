
#include <iostream>
using namespace std;

class CircularQueue {
private:
    int arr[5];
    int front;
    int rear;

public:
    // Constructor
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    // Check whether the queue is empty
    bool IsEmpty() {
        return front == -1;
    }

    // Check whether the circular queue is full
    bool IsFull() {
        return (rear + 1) % 5 == front;
    }

    // Insert a value at the rear
    void Enqueue(int value) {
        if (IsFull()) {
            cout << "Queue is full! Cannot insert "
                 << value << "." << endl;
            return;
        }

        // First insertion
        if (IsEmpty()) {
            front = 0;
            rear = 0;
        } else {
            // Move rear forward circularly
            rear = (rear + 1) % 5;
        }

        arr[rear] = value;

        cout << value << " inserted into the queue."
             << endl;
    }


    void Dequeue() { //remove and display the front value 
        if (IsEmpty()) {
            cout << "Queue is empty! Cannot dequeue."
                 << endl;
            return;
        }

        cout << "Removed: " << arr[front] << endl;

        // If only one element exists
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            // Move front forward circularly
            front = (front + 1) % 5;
        }
    }

    // Display the front value without removing it
    void Peek() {
        if (IsEmpty()) {
            cout << "Queue is empty! Nothing to peek."
                 << endl;
            return;
        }

        cout << "Front element: " << arr[front]
             << endl;
    }

    // Display each element from front to rear
    void Display() {
        if (IsEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue: ";

        int i = front;

        while (true) {
            cout << arr[i] << " ";

            if (i == rear) {
                break;
            }

            i = (i + 1) % 5;
        }

        cout << endl;
    }

    // Display indices for testing
    void ShowIndices() {
        cout << "front = " << front
             << ", rear = " << rear << endl;
    }
};

int main() {

    CircularQueue q;

    cout << "Task 3: Circular Queue"
         << endl;

    // Fill the queue
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);
    q.Enqueue(50);

    q.Display();
    q.ShowIndices();

    // Remove two elements
    q.Dequeue();
    q.Dequeue();

    q.Display();

    // Reuse the freed positions
    q.Enqueue(60);
    q.Enqueue(70);

    q.Display();
    q.ShowIndices();

    // This insertion must fail
    q.Enqueue(80);

    // Peek at the front
    q.Peek();

    // Empty the queue
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();

    q.Display();

    // Test deletion from an empty queue
    q.Dequeue();

    // Test insertion after becoming empty
    q.Enqueue(90);
    q.Display();
    q.ShowIndices();

    return 0;
}
