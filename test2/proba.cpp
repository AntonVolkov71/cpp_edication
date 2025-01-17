/*
Test project

    Created by Anton Y. Volkov (volkovanton71@yandex.ru)
    09.01.2024
*/
#include "proba.h"
#include <iostream>

using namespace std;

class Vector {
public:
    Vector(int s) : elem(new double[s]), sz(s) {}

    double &operator[](int i) {
        return elem[i];
    }

    double &Vector::operator[](int i) {
        if (i < 0 || size() <= i)
            throw out_of_range{"Vector::operator[]"};
        return elem[i];
    }

    int size() { return sz; }

private:
    double *elem;
    int sz;
};

double read_adn_sum(int s) {
    Vector v(s);

    for (int i = 0; i < v.size(); ++i) {
        cin >> v[i];
    }

    double sum = 0;

    for (int i = 0; i < v.size(); ++i) {
        sum += v[i];
    }

    return sum;
}