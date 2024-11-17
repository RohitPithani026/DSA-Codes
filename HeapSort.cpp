#include <iostream>
using namespace std;

class Heap {
    int marks[20];
public:
    void accept(int n);
    void display(int n, int flag);
    void heapsort(int n);
    void adjust(int n, int i);
};

void Heap::accept(int n) {
    for (int i = 0; i < n; i++) {
        cout << "\nEnter marks for student " << i + 1 << ": ";
        cin >> marks[i];
    }
}

void Heap::display(int n, int flag) {
    cout << "\nThe marks are as follows:\n";
    for (int i = 0; i < n; i++) {
        cout << marks[i] << "\t";
    }
    if (flag == 0) {
        cout << "\nThe maximum marks scored are: " << marks[n - 1];
        cout << "\nThe minimum marks scored are: " << marks[0];
    }
}

void Heap::heapsort(int n) {
    int i, t;
    for (i = ((n - 1) / 2); i >= 0; i--) {
        adjust(n, i);
    }
    cout << "\nThe max heap is:";
    display(n, 1);
    while (n > 0) {
        t = marks[0];
        marks[0] = marks[n - 1];
        marks[n - 1] = t;
        n--;
        adjust(n, 0);
    }
}

void Heap::adjust(int n, int i) {
    int j, temp;
    while ((2 * i + 1) < n) {
        j = (2 * i + 1);
        if ((j + 1) < n && (marks[j + 1] > marks[j])) {
            j = j + 1;
        }
        if (marks[i] > marks[j]) {
            break;
        } else {
            temp = marks[i];
            marks[i] = marks[j];
            marks[j] = temp;
        }
        i = j;
    }
}

int main() {
    int n, choice;
    Heap h;

    do {
        cout << "\n----- MENU -----" << endl;
        cout << "1. Accept data" << endl;
        cout << "2. Display marks" << endl;
        cout << "3. Sort marks" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter number of students appearing for exam: ";
                cin >> n;
                h.accept(n);
                break;
            case 2:
                h.display(n, 0);
                break;
            case 3:
                h.heapsort(n);
                cout << "\nMarks after sorting:" << endl;
                h.display(n, 0);
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 4);

    return 0;
}