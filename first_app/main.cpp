#include <algorithm>
#include <iostream>
#include <random>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    std::vector<int> v{3, 1, 4};

    auto it = v.end();
    --it;
    auto pv = std::prev(it);

    std::cout << *pv << '\n';
    std::cout << *it << '\n';
    std::cout << *(std::next(pv)) << '\n';
    return 0;
}