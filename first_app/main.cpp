#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <numeric>
#include <map>
#include <windows.h>

using namespace std;

template<typename Iter>
void PrintRange(Iter beg, Iter it_end) {
    while (beg != it_end) {
        cout << *beg << " ";
        ++beg;
    }


    cout << endl;
}

template<typename Type>
class Queue {
    public:
        void Push(const Type& el){

        }
private:
        double
};

int main() {
    SetConsoleOutputCP(CP_UTF8);

    Queue<int> queue;
    vector<int> values(5);

    // заполняем вектор для тестирования очереди
    iota(values.begin(), values.end(), 1);
    // перемешиваем значения
    random_shuffle(values.begin(), values.end());

    PrintRange(values.begin(), values.end());

    cout << "Заполняем очередь"s << endl;

    // заполняем очередь и выводим элемент в начале очереди
    for (int i = 0; i < 5; ++i) {
        queue.Push(values[i]);
        cout << "Вставленный элемент "s << values[i] << endl;
        cout << "Первый элемент очереди "s << queue.Front() << endl;
    }

    cout << "Вынимаем элементы из очереди"s << endl;

    // выводим элемент в начале очереди и вытаскиваем элементы по одному
    while (!queue.IsEmpty()) {
        // сначала будем проверять начальный элемент, а потом вытаскивать,
        // так как операция Front на пустой очереди не определена
        cout << "Будем вынимать элемент "s << queue.Front() << endl;
        queue.Pop();
    }
    return 0;
}