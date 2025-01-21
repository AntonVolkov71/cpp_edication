/*
    Test project

    Created by Anton Y. Volkov (volkovanton71@yandex.ru)
    09.01.2024
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

pair<bool, double> CalcMedian(vector<double> samples) {
    if (samples.empty()) {
        return {false, 0};
    }

    // верните {true, медиана}, если она существует,
    // то есть вектор непустой,
    // иначе - {false, 0}
    // обратите внимание - вектор принимаем по значению,
    // так как его придётся немного подпортить, чтобы вернуть ответ
    sort(samples.begin(), samples.end());

    if (samples.size() % 2 == 0) {
        return {true, (samples[samples.size() / 2 - 1] + samples[samples.size() / 2]) / 2};
    } else {
        double median = samples[samples.size() / 2];

        return {true, median};
    }
}

int main() {
    /*
        CalcMedian({1, 2, 3, 4}) == 2.5;
        CalcMedian({1, 2, 3}) == 2;
        CalcMedian({1, 2, 1000}) == 2; // медиана устойчива к небольшому числу сильно отклоняющихся от нормы значений
    */
    vector<double> samples = {1, 2, 3, 4};
    // vector<double> samples = {1, 2, 3};
    // vector<double> samples = {1, 2, 1000};

    pair<bool, double> result = CalcMedian(samples);
    if (result.first) {
        cout << result.second << endl;
    } else {
        cout << "Empty vector"s << endl;
    }
}
