
#include <iostream>
using namespace std;

class LinkedDeque {
private:
    // Doubly linked node structure
    struct node {
        int data;
        node* next;
        node* prev;
    };

    node* front;
    node* rear;

public:
    // Constructor
    LinkedDeque() {
        front = nullptr;
        rear = nullptr;
    }

    // Check whether deque is empty
    bool IsEmpty() {
        return front == nullptr;
    }

    // Insert a node at the front
    void InsertFront(int value) {
        node* newNode = new node;

        newNode->data = value;
        newNode->prev = nullptr;
        newNode->next = front;

        if (IsEmpty()) {
            // First node is both front and rear
            front = newNode;
            rear = newNode;
        } else {
            front->prev = newNode;
            front = newNode;
        }

        cout << value << " inserted at front."
             << endl;
    }

    // Insert a node at the rear
    void InsertRear(int value) {
        node* newNode = new node;

        newNode->data = value;
        newNode->next = nullptr;
        newNode->prev = rear;

        if (IsEmpty()) {
            // First node is both front and rear
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << value << " inserted at rear."
             << endl;
    }

    // Delete a node from the front
    void DeleteFront() {
        if (IsEmpty()) {
            cout << "Deque is empty! "
                 << "Cannot delete from front."
                 << endl;
            return;
        }

        node* temp = front;

        cout << "Deleted from front: "
             << temp->data << endl;

        if (front == rear) {
            // Only one node exists
            front = nullptr;
            rear = nullptr;
        } else {
            front = front->next;
            front->prev = nullptr;
        }

        delete temp;
    }

    // Delete a node from the rear
    void DeleteRear() {
        if (IsEmpty()) {
            cout << "Deque is empty! "
                 << "Cannot delete from rear."
                 << endl;
            return;
        }

        node* temp = rear;

        cout << "Deleted from rear: "
             << temp->data << endl;

        if (front == rear) {
            // Only one node exists
            front = nullptr;
            rear = nullptr;
        } else {
            rear = rear->prev;
            rear->next = nullptr;
        }

        delete temp;
    }

    // Display nodes from front to rear
    void Display() {
        if (IsEmpty()) {
            cout << "Deque is empty." << endl;
            return;
        }

        node* current = front;

        cout << "Deque: ";

        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }

    // Delete all remaining nodes
    void ClearDeque() {
        while (front != nullptr) {
            node* temp = front;
            front = front->next;
            delete temp;
        }

        rear = nullptr;
    }

    // Automatically clean up remaining nodes
    ~LinkedDeque() {
        ClearDeque();
    }

    // Prevent copying objects that own dynamically allocated nodes
    LinkedDeque(const LinkedDeque&) = delete;
    LinkedDeque& operator=(const LinkedDeque&) = delete;
};

int main() {
    // Replace with your own details
    // Name: Your Name
    // Registration Number: Your Registration Number
    // Section: BSCS-15D / BSCS-15E

    LinkedDeque d;
    int choice;
    int value;

    cout << "Task 6: Linked Deque"
         << endl;

    do {
        cout << "\nDEQUE MENU" << endl;
        cout << "1. Insert at Front" << endl;
        cout << "2. Insert at Rear" << endl;
        cout << "3. Delete from Front" << endl;
        cout << "4. Delete from Rear" << endl;
        cout << "5. Display Deque" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            d.InsertFront(value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            d.InsertRear(value);
            break;

        case 3:
            d.DeleteFront();
            break;

        case 4:
            d.DeleteRear();
            break;

        case 5:
            d.Display();
            break;

        case 6:
            cout << "Exiting deque menu."
                 << endl;
            break;

        default:
            cout << "Invalid choice! "
                 << "Please select 1-6."
                 << endl;
        }

    } while (choice != 6);

    // Release any nodes left in the deque
    d.ClearDeque();

    cout << "Deque memory cleared." << endl;

    return 0;
}
