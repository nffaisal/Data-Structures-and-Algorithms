

#include <iostream>
using namespace std;

const int SIZE = 5;
int items[SIZE];
int top = -1;

void push(int value)
{
    if (top == SIZE - 1)
    {
        cout << "Stack is full. Cannot insert.\n";
        return;
    }

    top++;
    items[top] = value;
    cout << value << " pushed into stack.\n";
}

void pop()
{
    if (top == -1)
    {
        cout << "Stack is empty. Cannot remove.\n";
        return;
    }

    cout << "Removed: " << items[top] << endl;
    top--;
}

void peek()
{
    if (top == -1)
    {
        cout << "Stack is empty.\n";
        return;
    }

    cout << "Top element: " << items[top] << endl;
}

void display()
{
    if (top == -1)
    {
        cout << "Stack is empty.\n";
        return;
    }

    cout << "Stack (top to bottom): ";

    for (int i = top; i >= 0; i--)
    {
        cout << items[i] << " ";
    }

    cout << endl;
}

int main()
{
    push(10);
    push(20);
    push(30);

    display();
    pop();
    peek();

    // Test a full stack
    push(40);
    push(50);
    push(60);
    push(70); // Stack is now full
    push(80); // This insertion should fail

    display();

    // Remove all elements
    while (top != -1)
    {
        pop();
    }

    pop(); // Test removal from an empty stack
    peek();

    return 0;
}