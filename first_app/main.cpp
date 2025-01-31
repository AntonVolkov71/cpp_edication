#include <iostream>
#include <string>
#include <map>

using namespace std;

// Определяет, будет ли слово палиндромом
// text может быть строкой, содержащей строчные символы английского алфавита и пробелы
// Пустые строки и строки, состоящие только из пробелов, — это не палиндромы
bool IsPalindrome(const string &text) {
    bool res = false;

    if (text.empty()) {
        return false;
    }

    int left = 0;
    int right = static_cast<int>(text.size() - 1);

//    if ((left == right) && (text[left] == text[right])) {
//        return true;
//    }

    while (left != right) {
        if (!text[left]) {
            left++;
            continue;
        }

        if (!text[right]) {
            right--;
            continue;
        }

        if (text[left] == text[right]) {
            left++;
            right--;
            res= true;
        } else {
            return false;
        }
    }

    // Напишите недостающий код
    return res;
}

int main() {
//    string text;
//    getline(cin, text);

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

//    if (IsPalindrome(text)) {
//        cout << "palindrome"s << endl;
//    } else {
//        cout << "not a palindrome"s << endl;
//    }
}