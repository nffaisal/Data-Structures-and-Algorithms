#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter number of marks (1-10): ";
    cin >> n;

    // Allocate original block
    int* marks = new int[n];

    cout << "Enter " << n << " marks: ";
    for (int i = 0; i < n; i++) {
        cin >> *(marks + i);
    }

    // Allocate new block with one extra space
    int* newMarks = new int[n + 1];

    // Copy original values using pointer notation
    for (int i = 0; i < n; i++) {
        *(newMarks + i) = *(marks + i);
    }

    // Read new student's mark
    cout << "Enter new mark: ";
    cin >> *(newMarks + n);

    // Release old block
    delete[] marks;

    // Make original pointer point to new block
    marks = newMarks;

    // Update size
    n++;

    // Display all marks
    cout << "Marks: ";
    for (int i = 0; i < n; i++) {
        cout << *(marks + i) << " ";
    }

    cout << endl;

    // Release final block exactly once
    delete[] marks;
    marks = nullptr;

    return 0;
}