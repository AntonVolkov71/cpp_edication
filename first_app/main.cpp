#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

/*
Задание 4
Избавьтесь от дублирования кода. Вынесите общую функциональность вывода в шаблонную функцию Print, принимающую ссылку на поток вывода и объект шаблонного типа, элементы которого нужно вывести. Вызовите её из операторов вывода вектора и множества.

Пример

const set<string> cats = {"Мурка"s, "Белка"s, "Георгий"s, "Рюрик"s};
cout << cats << endl;

const vector<int> ages = {10, 5, 2, 12};
cout << ages << endl;
Вывод

Белка, Георгий, Мурка, Рюрик
10, 5, 2, 12
Подсказка
Не забудьте назвать вспомогательную функцию Print, первым её аргументом сделать ссылку на поток, а вторым — контейнер шаблонного типа.

*/

template<typename Key, typename Value>
ostream &operator<<(ostream &out, const pair<Key, Value> &container) {
    out <<"(" << container.first << "," << container.second << ")";

    return out;
}

template<typename Type>
ostream & Print(ostream &out, const Type &container) {
    bool first = true;

    for (const auto& element : container) {
        if (!first) {
            out << ", ";
        }

        first = false;
        out << element;
    }

    return out;
}

template<typename Type>
ostream &operator<<(ostream &out, const vector<Type> &container) {
    out <<"[";
    Print(out, container);
    out <<"]";

    return out;
}

template<typename Type>
ostream &operator<<(ostream &out, const set<Type> &container) {
    out <<"{";
    Print(out, container);
    out <<"}";

    return out;
}

template<typename Key, typename Value>
ostream &operator<<(ostream &out, const map<Key, Value> &container) {
    out <<"<";
    Print(out, container);
    out <<">";

    return out;
}


int main() {
    const vector<int> ages = {10, 5, 2, 12};
    cout << "vector: "<< ages << endl;

    const set<string> cats = {"Murka"s, "Belka"s, "Zyablik"s, "Tiblayk"s};
    cout << "set: " << cats << endl;

    const map<string, int> cat_ages = {
        {"Murka"s, 10},
        {"Belka"s, 5},
        {"Zyablik"s, 2},
        {"Tiblayk"s, 12}
    };

    cout << "map: "<< cat_ages << endl;
}