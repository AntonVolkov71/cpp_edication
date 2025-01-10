/*
    Test project

    Created by Anton Y. Volkov (volkovanton71@yandex.ru)
    09.01.2024
*/

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    char a = '2';

    cout << static_cast<int>(a) << endl; // 50 номер из ASCII

    string str1 = "42";
    string str2 = "55text";
    string str3 = "222 text 55";
    string str4 = "222.5 text 55";
    string str5 = "text 55";
    string str6 = "-55";
    string str7 = "55.5 text";


    int num1 = stoi(str1);
    int num2 = stoi(str2);
    int num3 = stoi(str3);
    float num4 = stoi(str4);  // stoi только для целого
    int num6 = stoi(str6);    // отрицательные тоже можно
    float num7 = stof(str7);   // stof -> float из текста в float
    double num8 = stof(str7);  // stof -> float из текста в double Еще корректно так как float меньше double
    float num9 = stod(
            str7);   // stod -> double из текста в float !!Можно, но не корректно так как из большего в меньший
    double num10 = stod(str7); // корректно из текста в double

    try {
        try {
            float num5 = stoi(str5); // будет ошибка так как начинается со строки
            cout << num5 << endl; // 42
        } catch (const std::invalid_argument &e) {
            cout << "Caught invalid_argument exception: " << e.what() << endl; // stoi
            throw; // если throw e тогда родитель потеряет контекст, будет std::exception
        }
    } catch (exception &e) {
        cout << "ERROR: " << e.what() << endl; // stoi
    }

    cout << num1 << endl; // 42
    cout << num2 << endl; // 55
    cout << num3 << endl; // 222
    cout << num4 << endl; // 222
    cout << num6 << endl; // -55
    cout << num7 << endl; // 55.5
    cout << num8 << endl; // 55.5
    cout << num9 << endl; // 55.5
    cout << num10 << endl; // 55.5

    return 0;
}
