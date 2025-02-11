#include <algorithm>
#include <iostream>
#include <random>

using namespace std;

void PrintSpacesPositions(string &str) {
    size_t pos = 0;
    size_t i;

    while ((i = str.find(" "s, pos)) != string::npos) {
        cout << i << endl;
        pos = i + 1;
    }
}

int main() {
    string str = "He said: one and one and one is three"s;
    PrintSpacesPositions(str);
    return 0;
}