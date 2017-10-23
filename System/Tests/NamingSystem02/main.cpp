#include <iostream>
#include <string>

using namespace std;

struct effect{
    string name;
    string description;
    void effects() {
        cout << "Effect: "<< name << endl << "  " << description << endl;
    }
};

effect recogniseEffect(string a);
void recogniseEffects(string a);
void writeEffects(effect effectList[], int length);

int main() {
    string code = "";

    cin >> code;

    recogniseEffects(code);

    return 0;
}

void recogniseEffects(string a) {
    int length = (a.length() - (a.length() % 3)) / 3;
    effect effectList[length];
    string part = "";

    for (int y = 0; y < length; y++) {
        for (int i = 0; i < 3; i++) {
            part = part + a[(y * 3) + i];
        }
        effectList[y] = recogniseEffect(part);
        part = "";
    }

    writeEffects(effectList, length);
}

void writeEffects(effect effectList[], int length) {
    for (int y = 0; y < length; y++) {
        cout << "1 - ";
        effectList[y].effects();
    }
}

effect recogniseEffect(string a) {
    effect INeffect;

    if (a == "AAA") {
        INeffect.name = "Heal";
        INeffect.description = "Heals some HP";
    } else if (a == "BBB") {
        INeffect.name = "Stamina";
        INeffect.description = "Recovers some Stamina";
    } else if (a == "CCC") {
        INeffect.name = "Mana";
        INeffect.description = "Recovers some Mana";
    } else if (a == "AAB") {
        INeffect.name = "Poison";
        INeffect.description = "Damages HP";
    } else if (a == "BAB") {
        INeffect.name = "Poison";
        INeffect.description = "Damages Stamina";
    } else if (a == "CAB") {
        INeffect.name = "Poison";
        INeffect.description = "Damages Mana";
    } else if (a == "ABA") {
        INeffect.name = "Offering";
        INeffect.description = "Give up some HP for some Stamina";
    } else if (a == "CBA") {
        INeffect.name = "Offering";
        INeffect.description = "Give up some Mana for some Stamina";
    } else if (a == "BAA") {
        INeffect.name = "Offering";
        INeffect.description = "Give up some Stamina for some HP";
    } else if (a == "CAA") {
        INeffect.name = "Offering";
        INeffect.description = "Give up some Mana for some HP";
    } else if (a == "ACA") {
        INeffect.name = "Offering";
        INeffect.description = "Give up some HP for some Mana";
    } else if (a == "BCA") {
        INeffect.name = "Offering";
        INeffect.description = "Give up some Stamina for some Mana";
    } else {
        INeffect.name = "Unknown";
        INeffect.description = "None";
    }

    return INeffect;
}
