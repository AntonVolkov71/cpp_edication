/*
    Test project

    Created by Anton Y. Volkov (volkovanton71@yandex.ru)
    09.01.2024
*/

#include <iostream>
#include <vector>
#include <complex>
#include "proba.h"
#include <numeric>
#include <set>

using namespace std;

/*


 */

struct Descending {
    bool operator()(int a, int b) const {
        return a > b;  // Сортировка по убыванию
    }
};


int main(int argc, char *argv[]) {

    std::set<int, Descending> set1 = {1, 2, 3, 4, 5};


    for (auto it = set1.begin(); it != set1.end(); ++it) {
        cout << "it: " << *it << endl;
    }


    return 0;
}