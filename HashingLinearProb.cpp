#include<iostream>
using namespace std;

#define max 10

class student {
public:
    int roll_no;
    string name;
    char grade;
    student() {
        roll_no = -1;
        name = " ";
        grade = ' ';
    }
    friend class Hash;
};

class Hash {
    student hashtable[max];
public:
    Hash() {
        for (int i = 0; i < max; i++) {
            hashtable[i].roll_no = -1;
        }
    }
    void linear_without();
    void display();
    void linear_with();
};

void Hash::linear_without() {
    student s;
    char ch = 'y';
    int index, i, flag = 0;

    while (ch == 'y') {
        cout << "\n Enter the student records: ";
        cout << "\nRoll no: ";
        cin >> s.roll_no;
        cout << "Name:";
        cin >> s.name;
        cout << "Grade: ";
        cin >> s.grade;
        index = s.roll_no % max;

        if (hashtable[index].roll_no == -1) {
            hashtable[index] = s;
            flag = 1;
        } else {
            i = 1;
            i = (index + i) % max;
            while (i != index) {
                if (hashtable[i].roll_no == -1) {
                    hashtable[i] = s;
                    flag = 1;
                    break;
                }
                i = (i + 1) % max;
            }
            if (flag == 0) {
                cout << "Hash table full! cannot accept any more entries!";
                break;
            }
        }
        display();
        cout << "\n do you want to add any more records?(y or n)";
        cin >> ch;
    }
}

void Hash::linear_with() {
    student s, temp;
    char ch = 'y';
    int index, i, flag = 0;
    while (ch == 'y') {
        cout << "\n Enter the student records: ";
        cout << "\n Roll no";
        cin >> s.roll_no;
        cout << "Name";
        cin >> s.name;
        cout << "Grade";
        cin >> s.grade;
        index = s.roll_no % max;
        if (hashtable[index].roll_no == -1) {
            hashtable[index] = s;
            flag = 1;
        } else {
            temp = s;
            if (hashtable[index].roll_no % max != index) {
                temp = hashtable[index];
                hashtable[index] = s;
            }

            i = 1;
            i = (index + i) % max;
            while (i != index) {
                if (hashtable[i].roll_no == -1) {
                    hashtable[i] = temp;
                    flag = 1;
                    break;
                }
                i = (i + 1) % max;
            }
        }
        if (flag == 0) {
            cout << "Hash table full! cannot accept";
            break;
        }
        display();
        cout << "\n do you want to add any more record(y or n): ";
        cin >> ch;
    }
}

void Hash::display() {
    cout << "\n The student records are as follows:";
    cout << "\nROLLNO\tNAME\tGRADE\n";
    for (int i = 0; i < max; i++) {
        cout << i << "\t" << hashtable[i].roll_no << "\t" << hashtable[i].name << "\t" << hashtable[i].grade << "\n";
    }
}

int main() {
    Hash h;
    int f;
    do {
        cout << "\nMENU";
        cout << "\n1. linear without \n2. linear with \n3. display \n4. exit";
        cout << "\nEnter your choice: ";
        cin >> f;
        switch (f) {
            case 1:
                h.linear_without();
                break;
            case 2:
                h.linear_with();
                break;
            case 3:
                h.display();
                break;
            default:
                return 0;
        }
    } while (f < 4);
    return 0;
    
}