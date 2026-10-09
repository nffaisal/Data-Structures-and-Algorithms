#include <iostream>
using namespace std;

class CircularList {
private:

    struct node {
        int data;
        node* next;
    };

    node* head;
    node* tail;

public:

    CircularList() {
        head = nullptr;
        tail = nullptr;
    }

    void AddNode(int value) {

        node* newNode = new node;

        newNode->data = value;

        // Empty list
        if (head == nullptr) {

            head = newNode;
            tail = newNode;

            // Node points to itself
            newNode->next = head;
        }
        else {

            // New node goes after tail
            newNode->next = head;

            tail->next = newNode;

            tail = newNode;
        }
    }

    void PrintList() {

        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        node* current = head;

        cout << "Circular List: ";

        do {
            cout << current->data << " ";

            current = current->next;

        } while (current != head);

        cout << endl;
    }

    int CountNodes() {

        if (head == nullptr) {
            return 0;
        }

        int count = 0;

        node* current = head;

        do {

            count++;

            current = current->next;

        } while (current != head);

        return count;
    }

    void ClearList() {

        if (head == nullptr) {
            return;
        }

        // Break circular connection
        tail->next = nullptr;

        node* current = head;

        while (current != nullptr) {

            node* temp = current;

            current = current->next;

            delete temp;
        }

        head = nullptr;
        tail = nullptr;
    }

    ~CircularList() {
        ClearList();
    }
};

int main() {

    // Name:
    // Registration Number:
    // Section:

    CircularList list;

    int count;
    int value;

    cout << "Enter number of nodes: ";
    cin >> count;

    for (int i = 0; i < count; i++) {

        cout << "Enter value: ";
        cin >> value;

        list.AddNode(value);
    }

    list.PrintList();

    cout << "Number of nodes: "
         << list.CountNodes() << endl;

    return 0;
}