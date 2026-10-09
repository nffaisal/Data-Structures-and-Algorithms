#include <iostream>
using namespace std;

class ArrayStack {
private:

    int items[5];
    int top;

public:

    ArrayStack() {
        top = -1;
    }

    bool IsEmpty() {
        return top == -1;
    }

    bool IsFull() {
        return top == 4;
    }

    void Push(int value) {

        if (IsFull()) {
            cout << "Stack Overflow. Stack is full." << endl;
            return;
        }

        top++;

        items[top] = value;

        cout << value << " pushed into stack." << endl;
    }

    void Pop() {

        if (IsEmpty()) {
            cout << "Stack Underflow. Stack is empty." << endl;
            return;
        }

        cout << "Popped: " << items[top] << endl;

        top--;
    }

    void Peek() {

        if (IsEmpty()) {
            cout << "Stack Underflow. Stack is empty." << endl;
            return;
        }

        cout << "Top: " << items[top] << endl;
    }

    void Display() {

        if (IsEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << "Stack (top to bottom): ";

        for (int i = top; i >= 0; i--) {

            cout << items[i] << " ";
        }

        cout << endl;
    }
};

int main() {

    // Name:
    // Registration Number:
    // Section:

    ArrayStack stack;

    stack.Push(10);
    stack.Push(20);
    stack.Push(30);
    stack.Push(40);
    stack.Push(50);

    cout << endl;

    stack.Display();

    // Sixth push
    stack.Push(60);

    cout << endl;

    // Pop 50
    stack.Pop();

    // Peek 40
    stack.Peek();

    cout << endl;

    stack.Display();

    cout << "\nEmptying stack:\n";

    stack.Pop();
    stack.Pop();
    stack.Pop();
    stack.Pop();

    // Extra pop
    stack.Pop();

    return 0;
}