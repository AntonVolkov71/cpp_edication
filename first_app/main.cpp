#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <iterator>

using namespace std;

/*
Задание 2
Напишите функцию-шаблон FindAndPrint, которая бы принимала контейнер и переменную типа элемента контейнера. Функция должна распечатать на первой строчке часть контейнера, предшествующую найденному элементу, а на второй строчке часть, последующую элементу, включая сам элемент. Если элемент в контейнере не найден, выведите весь контейнер одной строкой. Используйте ваше решение из предыдущей задачи для вывода результатов на экран.

Пример вызова функции
int main() {
    set<int> test = {1, 1, 1, 2, 3, 4, 5, 5};
    FindAndPrint(test, 3);
    FindAndPrint(test, 0);
}
Пример вывода
1 2
3 4 5
1 2 3 4 5
Подсказка
Вы можете применить функцию find или find_if стандартной библиотеки <algorithm>.*/



template<typename It>
void PrintRange(It begin, It end) {
    cout << *begin;
    for (++begin; begin != end; ++begin) {
        cout << " "s << *begin;
    }
}

template<typename Container, typename D>
void FindAndPrint(const Container &container, const D& comp ){
    auto findEl = find(container.begin(), container.end(), comp);

    if(findEl == container.end()){
        PrintRange(container.begin(), container.end());
    } else {
        PrintRange(container.begin(), findEl);
        cout << endl;
        PrintRange(findEl, container.end());
    }

    cout << endl;
}

int main() {

    set<int> test2 = {1, 1, 1, 2, 3, 4, 5, 5};
    FindAndPrint(test2, 3);
    FindAndPrint(test2, 0);
}