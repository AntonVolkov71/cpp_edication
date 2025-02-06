#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <random>

using namespace std;


template<typename It>
void PrintRange(It range_begin, It range_end) {
    for (auto it = range_begin; it != range_end; ++it) {
        cout << *it << " "s;
    }
    cout << endl;
}

template<typename Container, typename Iterator>
void EraseAndPrint(Container &container, Iterator position) {
    auto it_erase = container.erase(position);
    PrintRange(container.begin(), position);
    PrintRange(it_erase, container.end());
}

template<typename Container>
void EraseAndPrint(Container &container, int position) {
    auto it_erase = container.erase(container.begin() + position);
    PrintRange(container.begin(), it_erase);
    PrintRange(it_erase, container.end());
}


template<typename Container>
void EraseAndPrint(Container &container, int erase_position, int add_erase_start, int add_erase_end) {
    container.erase(container.begin() + erase_position);
    PrintRange(container.begin(), container.end());

    container.erase(container.begin() + add_erase_start, container.begin() + add_erase_end);
    PrintRange(container.begin(), container.end());
}


bool IsPowOfTwo(int i) {
    if (i == 0) {
        return false;
    }

    if (i == 1) {
        return true;
    }

    if (i % 2 != 0) {
        return false;
    }

    return IsPowOfTwo(i / 2);
}

int main() {
    int result = IsPowOfTwo(6);
    cout << result << endl;
    Ханойская башня Задание 3
}
