/*
    Test project

    Created by Anton Y. Volkov (volkovanton71@yandex.ru)
    09.01.2024
*/

#include <iostream>
#include <vector>

using namespace std;

enum class Color {
    red, blue, green
};

enum Traffic_light {
    green, yellow, red
};

Traffic_light &operator++(Traffic_light &t) {
    switch (t) {
        case Traffic_light::red:
            return t = Traffic_light::green;
        case Traffic_light::green:
            return t = Traffic_light::yellow;
        case Traffic_light::yellow:
            return t = Traffic_light::red;
    }
}

int main(int argc, char *argv[]) {


    Color col = Color::red;
    // int i = Color::red; // error нельзя получить индекс
    int i = Traffic_light::red;

    cout << i << endl;


    return 0;
}
