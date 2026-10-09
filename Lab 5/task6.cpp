#include <iostream>
using namespace std;

class LinkedStack {
private:

    struct node {
        int data;
        node* next;
    };

    node* top;

public:

    LinkedStack() {
        top = nullptr;
    }

    bool IsEmpty() {
        return top == nullptr;
    }

    void Push(int value) {

        node* newNode = new node;

        newNode->data = value;

        // New node becomes top
        newNode->next = top;

        top = newNode;

        cout << value << " pushed into stack." << endl;
    }

    void Pop() {

        if (IsEmpty()) {

            cout << "Stack Underflow. Stack is empty." << endl;
            return;
        }

        node* temp = top;

        cout << "Popped: " << top->data << endl;

        top = top->next;

        delete temp;
    }

    void Peek() {

        if (IsEmpty()) {

            cout << "Stack Underflow. Stack is empty." << endl;
            return;
        }

        cout << "Top: " << top->data << endl;
    }

    void Display() {

        if (IsEmpty()) {

            cout << "Stack is empty." << endl;
            return;
        }

        node* current = top;

        cout << "Stack (top to bottom): ";

        while (current != nullptr) {

            cout << current->data << " ";

            current = current->next;
        }

        cout << endl;
    }

    void ClearStack() {

        while (top != nullptr) {

            node* temp = top;

            top = top->next;

            delete temp;
        }
    }

    ~LinkedStack() {
        ClearStack();
    }
};

int main() {

    // Name:
    // Registration Number:
    // Section:

    LinkedStack stack;

    int choice;
    int value;

    do {

        cout << "\n========== STACK MENU ==========\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";

        cin >> choice;

        switch (choice) {

        case 1:

            cout << "Enter value: ";
            cin >> value;

            stack.Push(value);

            break;

        case 2:

            stack.Pop();

            break;

        case 3:

            stack.Peek();

            break;

        case 4:

            stack.Display();

            break;

        case 5:

            cout << "Exiting..." << endl;

            break;

        default:

            cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 5);

    return 0;
}