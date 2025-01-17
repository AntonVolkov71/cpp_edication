/*
Test project

    Created by Anton Y. Volkov (volkovanton71@yandex.ru)
    09.01.2024
*/
#pragma once

namespace Proba_Name {
    class Vector {
    public:
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

}
