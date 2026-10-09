#include <iostream>
using namespace std;

class DoublyList {
private:

    struct node {
        int data;
        node* next;
        node* prev;
    };

    node* head;
    node* tail;

public:

    DoublyList() {
        head = nullptr;
        tail = nullptr;
    }

    void AddNode(int value) {

        node* newNode = new node;

        newNode->data = value;
        newNode->next = nullptr;
        newNode->prev = nullptr;

        // If list is empty
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            // Add at the end
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void PrintForward() {

        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        node* current = head;

        cout << "Forward: ";

        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }

    void PrintReverse() {

        if (tail == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        node* current = tail;

        cout << "Reverse: ";

        while (current != nullptr) {
            cout << current->data << " ";
            current = current->prev;
        }

        cout << endl;
    }

    void ClearList() {

        node* current = head;

        while (current != nullptr) {

            node* temp = current;

            current = current->next;

            delete temp;
        }

        head = nullptr;
        tail = nullptr;
    }

    ~DoublyList() {
        ClearList();
    }
};

int main() {

    // Name:
    // Registration Number:
    // Section:

    DoublyList list;

    int count;
    int value;

    cout << "Enter number of nodes: ";
    cin >> count;

    for (int i = 0; i < count; i++) {

        cout << "Enter value: ";
        cin >> value;

        list.AddNode(value);
    }

    list.PrintForward();
    list.PrintReverse();

    return 0;
}