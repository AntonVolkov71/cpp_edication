/*
    Test project

    Created by Anton Y. Volkov (volkovanton71@yandex.ru)
    09.01.2024
*/

#include <iostream>
#include <vector>
#include <numeric>
#include <chrono>
#include <execution>

using namespace std;

/*


 */

#include <random>
#include <ctime>


int main(int argc, char *argv[]) {


    const size_t testSize = 1'000'000;
    const int iterationCount = 5;

    random_device rd;
    mt19937 mersenne(rd());

    vector<int> integers(testSize);

    for (auto &i: integers) {
        i = static_cast<int>(rd());
    }

    for (int i = 0; i < iterationCount; ++i) {
        vector<int> sorted(integers);
        const auto startTime = chrono::high_resolution_clock::now();

        sort(sorted.begin(), sorted.end());

        const auto endTime = chrono::high_resolution_clock::now();

        cout << "Sequential sort: " << chrono::duration_cast<chrono::duration<int, milli>>(endTime - startTime).count()
             << endl;
    }


    for (int i = 0; i < iterationCount; ++i) {
        vector<int> sorted(integers);

        const auto startTime = chrono::high_resolution_clock::now();

        sort(execution::par, sorted.begin(), sorted.end());

        const auto endTime = chrono::high_resolution_clock::now();

        cout << "Parallel sort: " << chrono::duration_cast<chrono::duration<int, milli>>(endTime - startTime).count()
             << endl;
    }

    return 0;
}