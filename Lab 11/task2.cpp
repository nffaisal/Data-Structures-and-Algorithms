
#include <iostream>
#include <utility>
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
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void heapSort(int arr[], int n) {
    buildMaxHeap(arr, n);

    cout << "Initial Max Heap: ";
    display(arr, n);

    for (int i = n - 1; i > 0; i--) {
        // Move maximum element to sorted suffix
        swap(arr[0], arr[i]);

        cout << "\nAfter root exchange: ";
        display(arr, n);

        // Repair only the active heap
        maxHeapify(arr, i, 0);

        cout << "After heap repair:  ";
        for (int j = 0; j < n; j++) {
            if (j == i)
                cout << "| ";

            cout << arr[j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arr[] = {35, 12, 43, 8, 51, 27, 19};
    int n = 7;

    cout << "Original Array: ";
    display(arr, n);

    heapSort(arr, n);

    cout << "\nSorted Array (Ascending): ";
    display(arr, n);

    // Already sorted
    int sorted[] = {1, 2, 3, 4, 5};
    heapSort(sorted, 5);

    // Reverse sorted
    int reversed[] = {5, 4, 3, 2, 1};
    heapSort(reversed, 5);

    // Repeated values
    int repeated[] = {4, 2, 4, 1, 2};
    heapSort(repeated, 5);

    // Empty and single-element arrays
    int empty[1];
    heapSort(empty, 0);

    int single[] = {10};
    heapSort(single, 1);

    return 0;
}
