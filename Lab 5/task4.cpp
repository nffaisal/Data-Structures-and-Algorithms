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

        if (head == nullptr) {

            head = newNode;
            tail = newNode;

            newNode->next = head;
        }
        else {

            newNode->next = head;

            tail->next = newNode;

            tail = newNode;
        }
    }

    void DeleteNode(int value) {

        // Empty list
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        // Only one node
        if (head == tail) {

            if (head->data == value) {

                delete head;

                head = nullptr;
                tail = nullptr;

                cout << "Node deleted." << endl;
            }
            else {
                cout << "Value not found." << endl;
            }

            return;
        }

        // Deleting head
        if (head->data == value) {

            node* temp = head;

            head = head->next;

            tail->next = head;

            delete temp;

            cout << "Node deleted." << endl;

            return;
        }

        // Search for node
        node* previous = head;
        node* current = head->next;

        while (current != head) {

            if (current->data == value) {

                // If deleting tail
                if (current == tail) {

                    tail = previous;
                }

                previous->next = current->next;

                // Make sure tail points to head
                tail->next = head;

                delete current;

                cout << "Node deleted." << endl;

                return;
            }

            previous = current;
            current = current->next;
        }

        cout << "Value not found." << endl;
    }

    void PrintList() {

        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        node* current = head;

        cout << "List: ";

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

        // Break the circle
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

    cout << "\nOriginal List:\n";
    list.PrintList();

    cout << "Count: "
         << list.CountNodes() << endl;

    int deleteValue;

    cout << "\nEnter value to delete: ";
    cin >> deleteValue;

    list.DeleteNode(deleteValue);

    cout << "\nAfter deletion:\n";
    list.PrintList();

    cout << "Count: "
         << list.CountNodes() << endl;

    return 0;
}