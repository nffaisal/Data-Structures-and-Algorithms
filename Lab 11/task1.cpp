
#include <iostream>
using namespace std;

void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void printTree(int arr[], int n) {
    cout << "Root: " << (n > 0 ? arr[0] : -1) << endl;

    for (int i = 0; i < n; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n) {
            cout << arr[i] << " -> Left: "
                 << arr[left] << endl;
        }

        if (right < n) {
            cout << arr[i] << " -> Right: "
                 << arr[right] << endl;
        }
    }
}

bool verifyMaxHeap(int arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[i] < arr[left])
            return false;

        if (right < n && arr[i] < arr[right])
            return false;
    }
    return true;
}

int main() {
    int arr[] = {35, 12, 43, 8, 51, 27, 19};
    int n = 7;

    cout << "Original Array: ";
    display(arr, n);

    cout << "\nOriginal Tree:\n";
    printTree(arr, n);

    buildMaxHeap(arr, n);

    cout << "\nMax Heap Array: ";
    display(arr, n);

    cout << "\nHeap Tree:\n";
    printTree(arr, n);

    cout << "\nHeap Property: "
         << (verifyMaxHeap(arr, n) ? "Valid" : "Invalid")
         << endl;

    // Boundary case: empty array
    int empty[1];
    buildMaxHeap(empty, 0);

    // Single element
    int single[] = {10};
    buildMaxHeap(single, 1);

    // Repeated values
    int repeated[] = {5, 5, 3, 5, 2};
    buildMaxHeap(repeated, 5);

    cout << "\nRepeated Values Heap: ";
    display(repeated, 5);

    return 0;
}
