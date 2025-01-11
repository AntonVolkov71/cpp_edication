/*
    Test project

    Created by Anton Y. Volkov (volkovanton71@yandex.ru)
    09.01.2024
*/

#include <iostream>
#include <complex>
#include <ctime>
#include <vector>
using namespace std;

void show_vect(const char *it, const size_t size) {
    for (size_t i = 0; i < size; i++, ++it) {
        cout << *it << '\n';
    }
}

void reverse(const char *it_left_begin, char *it_right_end, const size_t size) {
    for (size_t i = 0; i < size; ++i, ++it_left_begin, --it_right_end) {
        *it_right_end = *it_left_begin;
    }
}

void test2(char *&ch) {
    cout << &ch << endl;
    cout << *ch << endl;
}


int main(int argc, char *argv[]) {
    const size_t size = 5;
    char vect[size] = {'a', 'b', 'g', 'd', 'e'};
    char vect2[size] = {};

    show_vect(begin(vect), size);
    cout << endl;

    reverse(begin(vect), end(vect2) - 1, size);
    show_vect(begin(vect2), size);
    return 0;
}
