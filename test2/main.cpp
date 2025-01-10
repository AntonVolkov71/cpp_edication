/*
    Test project

    Created by Anton Y. Volkov (volkovanton71@yandex.ru)
    09.01.2024
*/

#include <cmath>
#include <iostream>
using namespace std;
#include <bitset>

int main(int argc, char *argv[]) {
    int a = 10, b = 4;

    int c = a / b; // 2
    float d = static_cast<float>(a) / static_cast<float>(b); // 2.5
    float e = a / static_cast<float>(b); // 2.5
    float f = static_cast<float>(a) / b; // 2.5

    cout << c << endl;
    cout << d << endl;
    cout << e << endl;
    cout << f << endl;
    return 0;
}
