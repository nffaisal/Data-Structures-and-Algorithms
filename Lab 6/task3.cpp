

#include <iostream>
#include <cstring>
using namespace std;

const int SIZE = 20;

char items[SIZE];
int top = -1;

void push(char ch)
{
    if (top == SIZE - 1)
    {
        cout << "Stack is full.\n";
        return;
    }

    top++;
    items[top] = ch;
}

char pop()
{
    if (top == -1)
    {
        return '\0';
    }

    char ch = items[top];
    top--;

    return ch;
}

int main()
{
    char word[SIZE + 1];

    cout << "Enter a word (maximum 20 characters): ";
    cin >> word;

    int length = strlen(word);

    if (length > SIZE)
    {
        cout << "Word is too long.\n";
        return 0;
    }

    // Push every character
    for (int i = 0; i < length; i++)
    {
        push(word[i]);
    }

    cout << "Reversed word: ";

    // Pop and print every character
    while (top != -1)
    {
        cout << pop();
    }

    cout << endl;

    return 0;
}