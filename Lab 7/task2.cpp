#include <iostream>
using namespace std;

class LinkedQueue {
private:
    // Node structure for the linked queue
    struct node {
        int data;
        node* next;
    };

    node* front;
    node* rear;

public:
    // Constructor: initialize an empty queue
    LinkedQueue() {
        front = nullptr;
        rear = nullptr;
    }

    // Check whether the queue is empty
    bool IsEmpty() {
        return front == nullptr;
    }

    // Insert a new node at the rear
    void Enqueue(int value) {
        node* newNode = new node;
        newNode->data = value;
        newNode->next = nullptr;

        if (IsEmpty()) {
            // First node becomes both front and rear
            front = newNode;
            rear = newNode;
        } else {
            // Link the old rear to the new node
            rear->next = newNode;
            rear = newNode;
        }

        cout << value << " inserted into the queue."
             << endl;
    }

    // Remove and display the front node
    void Dequeue() {
        if (IsEmpty()) {
            cout << "Queue is empty! Cannot dequeue."
                 << endl;
            return;
        }

        node* temp = front;

        cout << "Removed: " << temp->data << endl;

        front = front->next;

        // If the last node was removed
        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
    }

    // Display the front value without removing it
    void Peek() {
        if (IsEmpty()) {
            cout << "Queue is emptyNothing to peek."
                 << endl;
            return;
        }

        cout << "Front element: " << front->data
             << endl;
    }

    void Display() { //display values from front to rear
        if (IsEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        node* current = front;

        cout << "Queue: ";

        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }

    // Delete all remaining nodes
    void ClearQueue() {
        while (!IsEmpty()) {
            node* temp = front;
            front = front->next;
            delete temp;
        }

        // Both pointers must be null
        rear = nullptr;
    }

    // Destructor: automatically clean up remaining nodes
    ~LinkedQueue() {
        ClearQueue();
    }

    // Prevent copying objects that own dynamically allocated nodes
    LinkedQueue(const LinkedQueue&) = delete;
    LinkedQueue& operator=(const LinkedQueue&) = delete;
};

int main() {
    LinkedQueue q;

    cout << "Task 2: Linked Queue"
         << endl;

    // Insert three values
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);

    q.Display();

    // Remove the first value
    q.Dequeue();

    q.Display();

    // Peek should display 20 without removing it
    q.Peek();

    // Remove remaining values
    q.Dequeue();
    q.Dequeue();

    // Test removal from an empty queue
    q.Dequeue();

    // Insert after the queue becomes empty
    q.Enqueue(40);
    q.Display();

    // Test removing the only node
    q.Dequeue();
    q.Display();

    // Test insertion after removing the only node
    q.Enqueue(50);
    q.Enqueue(60);
    q.Display();

    // Release all remaining nodes before exit
    q.ClearQueue();

    q.Display();

    return 0;
}
