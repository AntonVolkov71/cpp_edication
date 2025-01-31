#include <iostream>
#include <string>
#include <map>

using namespace std;

/*
Задание
Напишите программу. Она должна определять, будет ли палиндромом текст, введённый пользователем в первой строке стандартного ввода. Гарантируется, что текст содержит только строчные символы английского алфавита и пробелы. Пробелы в любом количестве могут стоять в начале и в конце строки, а также между словами. Пусть программа их игнорирует. Если строка пустая или состоит только из пробелов, она не считается палиндромом.

Примеры палиндромов: radar, never odd or even.

Примеры строк, которые не будут палиндромами: apple, kick.

Подсказка
Составьте план тестирования до написания кода. Не пытайтесь сразу создать программу, решающую задачу полностью. Следуйте плану тестирования и двигайтесь маленькими итерациями:

напишите код для прохождения теста в самой простой ситуации,
доработайте программу так, чтобы она проходила два теста, затем три.
При тестировании не забывайте обработать граничные условия — пустые строки и строки из одних пробелов.
 */

bool IsPalindrome(const string &text) {
    if (text.empty()) {
        return false;
    }

    int left = 0;
    int right = static_cast<int>(text.size() - 1);

    bool res = false;
    while (left <= right) {

        if (text[left] == ' ') {
            left++;
            continue;
        }

        if (text[right] == ' ') {

            right--;
            continue;
        }

        if (text[left] == text[right]) {
            left++;
            right--;
            res = true;
        } else {
            return false;
        }
    }

    return res;
}

int main() {

    map<string, bool> tests;

    tests.insert({"", false});
    tests.insert({"     ", false});
    tests.insert({"anton", false});
    tests.insert({"tonot", true});
    tests.insert({"tt tt", true});
    tests.insert({"tt t t   ", true});
    tests.insert({"a", true});
    tests.insert({"aa", true});
    tests.insert({"  a   ", true});


    for (const auto &test: tests) {
        cout << "Test: ";

        string isRes = IsPalindrome(test.first) == test.second
                       ? "OK"
                       : test.first + " Error";

        cout << isRes << endl;

    }
}