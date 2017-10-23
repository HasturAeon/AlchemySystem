#include <iostream>
#include <stdio.h>

using namespace std;

string merging(string a, string b);

int main() {
    string first = "BBB";
    string second = "AAA";
    string result = merging(first, second);

    cout << "First: " << first << endl << "Second: " << second << endl << "Result: " << result << endl;

    return 0;
}

string merging(string a, string b) {
    string result = "";

    for (int y = 0; y < a.length(); y++) {
        if (y % 2 == 0) {
            result = result + a[y];
        } else {
            result = result + b[y];
        }
    }
    return result;
}
