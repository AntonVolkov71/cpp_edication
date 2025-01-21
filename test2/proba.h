/*
Test project

    Created by Anton Y. Volkov (volkovanton71@yandex.ru)
    09.01.2024
*/
#pragma once
#include <initializer_list>

namespace Proba_NS {
    class complex {
    private:
        double re, im; // representation: two doubles
    public:
        complex(const double &r, const double &i) : re{r}, im{i} {
        } // construct complex from two scalars

        complex(const double r) : re{r}, im{0} {
        } // construct complex from one scalar

        complex() : re{0}, im{0} {
        } // default complex: {0,0}

        complex(const std::initializer_list<double> list) {
            auto it = list.begin();

            re = (it != list.end()) ? *it++ : 0;
            im = (it != list.end()) ? *it : 0;
        } // можно создавать так complex z{3.0, 4.0};


        [[nodiscard]] double real() const { return re; }
        [[nodiscard]] double imag() const { return im; }

        void real(const double &d) { re = d; }
        void imag(const double &d) { im = d; }


        complex &operator*=(const complex &z) {
            double new_re = re * z.re - im * z.im;
            double new_im = re * z.im + im * z.re;

            re = new_re;
            im = new_im;

            return *this;
        }

        complex &operator/=(const complex &z) {
            double denominator = z.re * z.re + z.im * z.im;
            double new_re = (re * z.re + im * z.im) / denominator;
            double new_im = (im * z.re - re * z.im) / denominator;

            re = new_re;
            im = new_im;

            return *this;
        }

        complex &operator+=(const complex &z) {
            re += z.re;
            im += z.im;
            return *this;
        }

        complex &operator-=(const complex &z) {
            re -= z.re;
            im -= z.im;
            return *this;
        }

        friend complex operator+(complex a, const complex &b) { return a += b; }
        friend complex operator-(complex a, const complex &b) { return a -= b; }
        friend complex operator*(complex a, const complex &b) { return a *= b; }
        friend complex operator/(complex a, const complex &b) { return a /= b; }

        bool operator==(const complex &z) const { return re == z.re && im == z.im; }
        bool operator!=(const complex &z) const { return !(*this == z); }
    };
}

