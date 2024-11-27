#include <iostream>
#include <string>
using namespace std;

void printPattern(int n) {
    string pattern = "";
    for (int i = 1; i <= n; ++i) {
        pattern += string(i, '*') + "\n";
    }
    cout << pattern;
}

int main() {
    int n = 4; 
    printPattern(n);
    return 0;
}