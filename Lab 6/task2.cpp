// Name: YOUR NAME
// Registration Number: YOUR ROLL NUMBER
// Section: BSCS-15D / BSCS-15E
// Task 2: Stack using a linked list

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* top = nullptr;

void push(int value)
{
    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = top;
    top = newNode;

    cout << value << " pushed into stack.\n";
}

void pop()
{
    if (top == nullptr)
    {
        cout << "Stack is empty. Cannot remove.\n";
        return;
    }

    Node* temp = top;

    cout << "Removed: " << temp->data << endl;

    top = top->next;
    delete temp;
}

void peek()
{
    if (top == nullptr)
    {
        cout << "Stack is empty.\n";
        return;
    }

    cout << "Top element: " << top->data << endl;
}

void display()
{
    if (top == nullptr)
    {
        cout << "Stack is empty.\n";
        return;
    }

    Node* current = top;

    cout << "Stack (top to bottom): ";

    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }

    cout << endl;
}

void clearStack()
{
    while (top != nullptr)
    {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

int main()
{
    push(5);
    push(15);
    push(25);

    display();
    pop();
    peek();

    // Test empty stack
    clearStack();
    pop();

    // Release any remaining allocated memory
    clearStack();

    return 0;
}