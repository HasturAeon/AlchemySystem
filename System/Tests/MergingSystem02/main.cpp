#include <iostream>
#include <string>

using namespace std;

string merging(string a, string b, int temp1, int temp2);

int main() {
    string first = "";
    string second = "";
    int a = 0;
    int b = 0;

    cout << "First ingredient code: ";
    cin >> first;
    cout << endl << "How much code to inject: ";
    cin >> a;
    cout << "Second ingredient code: ";
    cin >> second;
    cout << endl << "How much code to inject: ";
    cin >> b;

    string result = merging(first, second, a, b);
    result.resize(first.length());

    cout << first << " " << a << endl << second << " " << b << endl << result << endl;

    return 0;
}

string merging(string a, string b, int temp1, int temp2) {
    string result = "";
    bool choose = false;

    if (temp1 >= a.length() || temp1 >= b.length() || temp2 >= a.length() || temp2 >= b.length() || temp1 == 0 || temp2 == 0) {
        cout << "ERROR: too hot/cold" << endl;
        result = "";
        return result;
    }

    for (int y = 0; y < a.length(); y++) {
        if (choose == false) {
            for (int i = 0; i < temp1; i++) {
                if (y > a.length()) {
                    return result;
                }
                if (i > 0) {
                    y++;
                }
                result = result + a[y];
            }
            choose = true;
        } else {
            for (int i = 0; i < temp2; i++) {
                if (y > b.length()) {
                    return result;
                }
                if (i > 0) {
                    y++;
                }
                result = result + b[y];
            }
            choose = false;
        }
    }

    return result;
}
