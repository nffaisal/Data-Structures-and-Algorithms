
#include <iostream>
using namespace std;

class ArrayDeque {
private:
    int arr[5];
    int front;
    int rear;

public:
    // Constructor
    ArrayDeque() {
        front = -1;
        rear = -1;
    }

    // Check whether deque is empty
    bool IsEmpty() {
        return front == -1;
    }

    // Check whether deque is full
    bool IsFull() {
        return !IsEmpty() && (rear + 1) % 5 == front;
    }

    // Insert at the front
    void InsertFront(int value) {
        if (IsFull()) {
            cout << "Deque is full! Cannot insert "
                 << value << " at front." << endl;
            return;
        }

        if (IsEmpty()) {
            // First element occupies index 0
            front = 0;
            rear = 0;
        } else {
            // Move front backward circularly
            front = (front + 5 - 1) % 5;
        }

        arr[front] = value;

        cout << value << " inserted at front."
             << endl;
    }

    // Insert at the rear
    void InsertRear(int value) {
        if (IsFull()) {
            cout << "Deque is full! Cannot insert "
                 << value << " at rear." << endl;
            return;
        }

        if (IsEmpty()) {
            front = 0;
            rear = 0;
        } else {
            // Move rear forward circularly
            rear = (rear + 1) % 5;
        }

        arr[rear] = value;

        cout << value << " inserted at rear."
             << endl;
    }

    // Delete from the front
    void DeleteFront() {
        if (IsEmpty()) {
            cout << "Deque is empty! Cannot delete "
                 << "from front." << endl;
            return;
        }

        cout << "Deleted from front: "
             << arr[front] << endl;

        if (front == rear) {
            // Last element removed
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % 5;
        }
    }

    // Delete from the rear
    void DeleteRear() {
        if (IsEmpty()) {
            cout << "Deque is empty! Cannot delete "
                 << "from rear." << endl;
            return;
        }

        cout << "Deleted from rear: "
             << arr[rear] << endl;

        if (front == rear) {
            // Last element removed
            front = -1;
            rear = -1;
        } else {
            rear = (rear + 5 - 1) % 5;
        }
    }

    // Display from front to rear
    void Display() {
        if (IsEmpty()) {
            cout << "Deque is empty." << endl;
            return;
        }

        cout << "Deque: ";

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
};

int main() {
    ArrayDeque d;

    cout << "Task 5: Circular Array Deque"
         << endl;

    // Initial insertions
    d.InsertRear(20);
    d.InsertFront(10);
    d.InsertRear(30);

    d.Display();   // 10 20 30

    // Delete from both ends
    d.DeleteRear();    // Removes 30
    d.DeleteFront();   // Removes 10

    d.Display();   // 20

    // Build the required deque
    d.InsertFront(5);
    d.InsertRear(30);
    d.InsertRear(40);
    d.InsertFront(1);

    d.Display();   // 1 5 20 30 40

    // Both insertions must be rejected
    d.InsertFront(0);
    d.InsertRear(50);

    d.Display();   // 1 5 20 30 40

    // Test deletion of the only element
    cout << "\nSingle Element Test 1"
         << endl;

    ArrayDeque d1;
    d1.InsertRear(100);
    d1.DeleteFront();
    d1.Display();
    d1.DeleteRear();  // Empty-deque check

    // Test deletion of the only element from rear
    cout << "\nSingle Element Test 2"
         << endl;

    ArrayDeque d2;
    d2.InsertFront(200);
    d2.DeleteRear();
    d2.Display();
    d2.DeleteFront(); // Empty-deque check

    return 0;
}
