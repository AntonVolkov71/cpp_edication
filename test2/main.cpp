/*
    Test project

    Created by Anton Y. Volkov (volkovanton71@yandex.ru)
    09.01.2024
*/

#include <iostream>
#include <vector>
#include <complex>
#include "proba.h"

using namespace std;


int main(int argc, char *argv[]) {


    complex dd = {2.4, 55.6};
    complex aa = {2.2323, 24.6};

    dd -= aa;

    cout << "real: " << dd.real() << endl;
    cout << "imag: " << dd.imag() << endl;


    return 0;
}