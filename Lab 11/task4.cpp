
#include <iostream>
#include <utility>
using namespace std;

void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void bubbleSort(int arr[], int n) {
    int comparisons = 0;
    int swaps = 0;

    cout << "\nNormal Bubble Sort:\n";

    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;

            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swaps++;
            }
        }

        cout << "Pass " << i + 1 << ": ";
        display(arr, n);
    }

    cout << "Comparisons: " << comparisons << endl;
    cout << "Swaps: " << swaps << endl;
}

void bubbleSortOptimized(int arr[], int n) {
    int comparisons = 0;
    int swaps = 0;

    cout << "\nOptimized Bubble Sort:\n";

    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;

            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swaps++;
                swapped = true;
            }
        }

        cout << "Pass " << i + 1 << ": ";
        display(arr, n);

        if (!swapped)
            break;
    }

    cout << "Comparisons: " << comparisons << endl;
    cout << "Swaps: " << swaps << endl;
}

void testArray(int original[], int n) {
    int normal[20];
    int optimized[20];

    for (int i = 0; i < n; i++) {
        normal[i] = original[i];
        optimized[i] = original[i];
    }

    cout << "\n================================\n";
    cout << "Original Array: ";
    display(original, n);

    bubbleSort(normal, n);
    bubbleSortOptimized(optimized, n);
}

int main() {

    int arr1[] = {5, 1, 4, 2, 8};
    int arr2[] = {1, 2, 4, 5, 8};
    int arr3[] = {8, 5, 4, 2, 1};
    int arr4[] = {4, 2, 4, 1, 2};

    cout << "TEST 1";
    testArray(arr1, 5);

    cout << "\nTEST 2";
    testArray(arr2, 5);

    cout << "\nTEST 3";
    testArray(arr3, 5);

    cout << "\nTEST 4: Repeated Values";
    testArray(arr4, 5);

    // Empty array
    int empty[1];
    cout << "\nTEST 5: Empty Array";
    testArray(empty, 0);

    // Single element
    int single[] = {10};
    cout << "\nTEST 6: Single Element";
    testArray(single, 1);

    return 0;
}
