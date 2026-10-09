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

        if (head == nullptr) {

            head = newNode;
            tail = newNode;
        }
        else {

            newNode->prev = tail;
            tail->next = newNode;

            tail = newNode;
        }
    }

    void InsertBefore(int position, int value) {

        // Position must be at least 1
        if (position < 1) {
            cout << "Invalid position." << endl;
            return;
        }

        // Empty list
        if (head == nullptr) {
            cout << "List is empty. Cannot insert before a node." << endl;
            return;
        }

        node* current = head;

        int currentPosition = 1;

        // Find the node at the given position
        while (current != nullptr && currentPosition < position) {

            current = current->next;
            currentPosition++;
        }

        // Position does not exist
        if (current == nullptr) {
            cout << "Invalid position." << endl;
            return;
        }

        node* newNode = new node;

        newNode->data = value;

        // Insert before current
        newNode->next = current;
        newNode->prev = current->prev;

        // If inserting before head
        if (current->prev == nullptr) {

            head = newNode;
        }
        else {

            current->prev->next = newNode;
        }

        current->prev = newNode;
    }

    void DeleteNode(int value) {

        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        node* current = head;

        // Find first matching node
        while (current != nullptr && current->data != value) {
            current = current->next;
        }

        // Value not found
        if (current == nullptr) {
            cout << "Value not found." << endl;
            return;
        }

        // If deleting head
        if (current->prev == nullptr) {

            head = current->next;
        }
        else {

            current->prev->next = current->next;
        }

        // If deleting tail
        if (current->next == nullptr) {

            tail = current->prev;
        }
        else {

            current->next->prev = current->prev;
        }

        delete current;

        // If list became empty
        if (head == nullptr) {
            tail = nullptr;
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

    cout << "\nOriginal List:\n";
    list.PrintForward();
    list.PrintReverse();

    int position;
    int insertValue;

    cout << "\nEnter position before which to insert: ";
    cin >> position;

    cout << "Enter value to insert: ";
    cin >> insertValue;

    list.InsertBefore(position, insertValue);

    cout << "\nAfter insertion:\n";
    list.PrintForward();
    list.PrintReverse();

    int deleteValue;

    cout << "\nEnter value to delete: ";
    cin >> deleteValue;

    list.DeleteNode(deleteValue);

    cout << "\nAfter deletion:\n";
    list.PrintForward();
    list.PrintReverse();

    return 0;
}