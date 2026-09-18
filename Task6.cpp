#include <iostream>
using namespace std;

/* wrong code
int main() {
  int n = 3;
int* values = new int[n];
for (int i = 0; i <= n; i++)
    cin >> values[i];
delete values;
cout << values[0];
} */

//correct code

int main() {
    int n = 3;
    int* values = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    cout << "Values: ";
    for (int i = 0; i < n; i++) {
        cout << values[i] << " ";
    }

    delete[] values;
    values = nullptr;

    return 0;
}