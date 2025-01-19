/*
Test project

    Created by Anton Y. Volkov (volkovanton71@yandex.ru)
    09.01.2024
*/
#pragma once
//double &operator[](int i);
namespace Proba_NS {
    class complex {
        double re, im; // representation: two doubles
    public:
        complex(double r, double i) : re{r}, im{i} {} // construct complex from two scalars
        complex(double r) : re{r}, im{0} {} // construct complex from one scalar
        complex() : re{0}, im{0} {} // default complex: {0,0}
        double real() const { return re; }

        void real(double d) { re = d; }

        double imag() const { return im; }

        void imag(double d) { im = d; }


        complex &operator*=(complex &z) {
            re *= z.re;
            re *= z.re;
            return *this;
        }

        complex &operator+=(complex &z) {
            re += z.re;
            re += z.re;
            return *this;
        }

        complex &operator-=(complex &z) {
            re -= z.re;
            re -= z.re;
            return *this;
        }

        complex &operator/=(complex &z) {
            re /= z.re;
            re /= z.re;
            return *this;
        }

        complex operator+(complex a, complex b) {
            return a += b;
        }

        complex operator+(complex a) {
            return {
                    a.re, a.im
            };
        }

//        complex operator-(complex a, complex b) {
//            return a -= b;
//        }
//
//        complex operator-(complex a) {
//            return {
//                -a.real(), -a.imag()
//            };
//        }
//
//        complex operator*(complex a, complex b) { return a*=b; }
//        complex operator/(complex a, complex b) { return a/=b; }


        //        complex& operator+=(complex z) { re+=z.re , im+=z.im; return ∗this; } // add to re and im
//        complex& operator−=(complex z) { re−=z.re , im−=z.im; return ∗this; }
        // defined out-of-class somewhere
//        complex& operator/=(complex); // defined out-of-class somewhere

    };
}


//Proba_NS::complex& Proba_NS::complex::operator∗=(Proba_NS::complex z){

//};