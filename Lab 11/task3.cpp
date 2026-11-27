
#include <iostream>
#include <utility>
using namespace std;

struct Job {
    int id;
    int priority;
};

void swapJobs(Job &a, Job &b) {
    Job temp = a;
    a = b;
    b = temp;
}

void heapifyDown(Job heap[], int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size &&
        heap[left].priority > heap[largest].priority)
        largest = left;

    if (right < size &&
        heap[right].priority > heap[largest].priority)
        largest = right;

    if (largest != i) {
        swapJobs(heap[i], heap[largest]);
        heapifyDown(heap, size, largest);
    }
}

bool insertJob(Job heap[], int &size,
               int capacity, Job item) {

    if (size == capacity)
        return false;

    int i = size;
    heap[size] = item;
    size++;

    // Move new job upward
    while (i > 0) {
        int parent = (i - 1) / 2;

        if (heap[i].priority > heap[parent].priority) {
            swapJobs(heap[i], heap[parent]);
            i = parent;
        }
        else {
            break;
        }
    }

    return true;
}

bool peekJob(const Job heap[], int size, Job &item) {
    if (size == 0)
        return false;

    item = heap[0];
    return true;
}

bool removeJob(Job heap[], int &size, Job &item) {
    if (size == 0)
        return false;

    item = heap[0];

    heap[0] = heap[size - 1];
    size--;

    if (size > 0)
        heapifyDown(heap, size, 0);

    return true;
}

void displayJobs(Job heap[], int size) {
    if (size == 0) {
        cout << "Priority Queue is empty.\n";
        return;
    }

    cout << "\nJobs in Heap Array Order:\n";

    for (int i = 0; i < size; i++) {
        cout << "ID: " << heap[i].id
             << " | Priority: " << heap[i].priority
             << endl;
    }
}

int main() {
    const int CAPACITY = 20;
    Job heap[CAPACITY];
    int size = 0;

    int choice;

    do {
        cout << "\n===== PRIORITY QUEUE =====\n";
        cout << "1. Insert Job\n";
        cout << "2. Peek Job\n";
        cout << "3. Remove Job\n";
        cout << "4. Display Jobs\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            Job item;

            cout << "Enter Job ID: ";
            cin >> item.id;

            cout << "Enter Priority: ";
            cin >> item.priority;

            if (insertJob(heap, size, CAPACITY, item))
                cout << "Job inserted successfully.\n";
            else
                cout << "Priority Queue is full!\n";
        }

        else if (choice == 2) {
            Job item;
            int oldSize = size;

            if (peekJob(heap, size, item)) {
                cout << "Highest Priority Job:\n";
                cout << "ID: " << item.id
                     << " Priority: " << item.priority << endl;

                cout << "Queue size unchanged: "
                     << (oldSize == size ? "Yes" : "No") << endl;
            }
            else {
                cout << "Priority Queue is empty!\n";
            }
        }

        else if (choice == 3) {
            Job item;

            if (removeJob(heap, size, item)) {
                cout << "Removed Job:\n";
                cout << "ID: " << item.id
                     << " Priority: " << item.priority << endl;
            }
            else {
                cout << "Priority Queue is empty!\n";
            }
        }

        else if (choice == 4) {
            displayJobs(heap, size);
        }

        else if (choice == 5) {
            cout << "Exiting program.\n";
        }

        else {
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
