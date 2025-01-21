#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <chrono>

using namespace std;


/*
Напишите функцию CountNames. Пусть она выясняет, какие слова из списка содержатся во множестве, и возвращает ответ в виде вектора единиц и нулей. Список кандидатов дан в виде вектора строк. Если слово есть во множестве, в ответе будет единица, иначе — ноль. В коде вы видите библиотеку <chrono>. Она содержит элементы, связанные с концептами времени.

Подсказка
Примените встроенный метод множества count.
 */

const int kSampleCount = 5;

vector<int> CountNamesLong(const set<string> &storage, const vector<string> &candidates) {
    vector<int> output;
    for (auto &name: candidates) {
        output.push_back(count(storage.begin(), storage.end(), name));
    }
    return output;
}

vector<int> CountNamesLongFast(const set<string> &storage, const vector<string> &candidates) {
    vector<int> output;

    for (auto &name: candidates) {
        output.push_back(storage.count(name));
    }
    return output;
}

template<typename Func>
void MeasureExecutionTime(const string &label, Func func) {
    double total_time = 0;
    for (int i = 0; i < kSampleCount; ++i) {
        auto start = chrono::steady_clock::now();

        func();
        auto end = chrono::steady_clock::now();
        total_time += chrono::duration_cast<chrono::microseconds>(end - start).count();
    }

    cout << "Average time Fast = "s << (total_time / kSampleCount) << "[µs]"s << endl;
}

int main() {
    set<string> s;
    vector<string> v;
    string stra = ""s;
    string strb = ""s;

    for (int j = 0; j < 10000; ++j) {
        s.insert(stra);
        stra += "a"s;
        if (j % 2 == 0) {
            v.push_back(strb);
            strb += "b"s;
        } else {
            v.push_back(stra);
        }
    }

    MeasureExecutionTime("slow version"s, [&]() { CountNamesLong(s, v); });
    MeasureExecutionTime("fast version"s, [&]() { CountNamesLongFast(s, v); });
}
