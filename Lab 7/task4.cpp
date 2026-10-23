
#include <iostream>
using namespace std;

class CircularQueue {
private:
    int arr[5];
    int front;
    int rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool IsEmpty() {
        return front == -1;
    }

    bool IsFull() {
        return !IsEmpty() && (rear + 1) % 5 == front;
    }

    void Enqueue(int value) {
        if (IsFull()) {
            cout << "Queue is full! Cannot insert "
                 << value << "." << endl;
            return;
        }

        if (IsEmpty()) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % 5;
        }

        arr[rear] = value;
    }

    void Dequeue() {
        if (IsEmpty()) {
            cout << "Queue is empty! Cannot dequeue."
                 << endl;
            return;
        }

        cout << "Removed: " << arr[front] << endl;

        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % 5;
        }
    }

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

    // Serve the front student and move them to the rear
    void RotateTurn() {
        if (IsEmpty()) {
            cout << "No students waiting. Cannot rotate."
                 << endl;
            return;
        }

        // Save the front student's ID before removing it
        int studentID = arr[front];

        cout << "Student served: " << studentID << endl;

        // Remove the front student
        Dequeue();

        // Insert that student at the rear
        Enqueue(studentID);

        cout << "Updated ";
        Display();
    }
};

int main() {
    CircularQueue q;

    cout << "Task 4: Rotating Service Turns"
         << endl;

    // Add three students
    q.Enqueue(101);
    q.Enqueue(102);
    q.Enqueue(103);

    cout << "\nInitial ";
    q.Display();

    // Run five turns
    for (int i = 1; i <= 5; i++) {
        cout << "\nTurn " << i << endl;
        q.RotateTurn();
    }

    // Test an empty queue
    cout << "\nEmpty Queue Test" << endl;

    CircularQueue emptyQueue;
    emptyQueue.RotateTurn();

    // Test a queue with one student
    cout << "\nSingle Student Test" << endl;

    CircularQueue singleQueue;
    singleQueue.Enqueue(201);
    singleQueue.Display();

    singleQueue.RotateTurn();

    return 0;
}
