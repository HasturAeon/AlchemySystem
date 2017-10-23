#include <iostream>
#include <fstream>

using namespace std;

struct effect {
    string code;
    string name;
};

const int NUMBER = 4;
const int arrayLength = NUMBER * NUMBER * NUMBER;
effect effectsList[arrayLength];

void fileInit(int letters, const char* name);
void initArrayFromFile(const char* fileName);
void writeArray();
string nameEffect(string code);

int main() {
    const char* fileName = "effects.txt";
    //fileInit(NUMBER, fileName);

    initArrayFromFile(fileName);

    writeArray();

    cout << nameEffect("CDC") << endl;

    /*
    This time the goal is to load the effects from a .txt file or a .json file(or a custom one)
    Then, the goal is to merge(XD) the merging system and naming system to work together
    */
    return 0;
}

void writeArray() {
    for (int y = 0; y < arrayLength; y++) {
        cout << effectsList[y].code << ": " << effectsList[y].name << endl;
    }
}

string nameEffect(string code) {
    for (int y = 0; y < arrayLength; y++) {
        if (effectsList[y].code == code) {
            return effectsList[y].name;
        }
    }
}

void fileInit(int letters, const char* name) {
    ofstream effectsFile;
    effectsFile.open(name);
    effectsFile.clear();
    for (int a = 0; a < letters; a++) {
        for (int b = 0; b < letters; b++) {
            for (int c = 0; c < letters; c++) {
                effectsFile << char(65 + a) << char(65 + b) << char(65 + c) << "\n";
                //cout << char(65 + a) << char(65 + b) << char(65 + c) << "\n"; (debug)
            }
        }
    }
    effectsFile.close();
}

void initArrayFromFile(const char* fileName) {
    ifstream effectsFile;
    effectsFile.open(fileName);
    int y = 0;
    string code = "";
    string name = "";
    while(effectsFile >> code >> name) {
        effectsList[y].code = code;
        effectsList[y].name = name;
        y++;
    }
    effectsFile.close();
}
