#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <numeric>
#include <map>
#include <windows.h>

using namespace std;

template <typename It>
void PrintRange(It range_begin, It range_end) {
    for (auto it = range_begin; it != range_end; ++it) {
        cout << *it << " "s;
    }
    cout << endl;
}

template <typename Type>
class Stack {
public:
    void Push(const Type& element) {
        elements_.push_back(element);
    }

    void Pop() {
        elements_.pop_back();
    }

    const Type& Peek() const {
        const Type el = elements_.at(elements_.size() - 1);

        return el;
    }

    Type& Peek() {
        return elements_.at(elements_.size() - 1);
    }
    void Print() const {
        PrintRange(elements_.begin(), elements_.end());
    }
    uint64_t Size() const {
        return static_cast<uint64_t>(elements_.size());
    }
    bool IsEmpty() const {
        return elements_.empty();
    }

private:
    vector<Type> elements_;
};

template <typename Type>
struct ElMin{
    Type el;
    Type min_el;
};


template <typename Type>
ostream& operator<<(ostream& out, const ElMin<Type>& pair_to_print) {
    // будем выводить только сам элемент, выводить минимум не будем
    out << pair_to_print.el;
    return out;
}

template <typename Type>
class StackMin {
public:
    void Push(const Type& element) {
        ElMin<Type> new_pair = {element, element};

        if((!elements_.IsEmpty()) && new_pair.min_el > elements_.Peek().min_el){
            new_pair.min_el = elements_.Peek().min_el;
        }

        elements_.Push(new_pair);
    }
    void Pop() {
        // напишите реализацию метода
        elements_.Pop();
    }
    const Type& Peek() const {
        return elements_.Peek().el;
    }
    Type& Peek() {
        return elements_.Peek().el;
    }
    void Print() const {
        elements_.Print();
    }
    uint64_t Size() const {
        return elements_.size();
    }
    bool IsEmpty() const {
        return elements_.IsEmpty();
    }
    const Type& PeekMin() const {
        return elements_.Peek().min_el;
    }
    Type& PeekMin() {
        return elements_.Peek().min_el;
    }
private:
    Stack<ElMin<Type>> elements_;
};

template <typename Type>
class SortedStack {
public:
    void Push(const Type& element) {
        if(elements_.IsEmpty()){
            elements_.Push(element);
            return;
        }

        Type peek_el = elements_.Peek();

        if(peek_el < element){
            elements_.Pop();
            Push(element);
            elements_.Push(peek_el);
        } else {
            elements_.Push(element);
        }
    }
    void Pop() {
        elements_.Pop();
    }
    const Type& Peek() const {
        return elements_.Peek();
    }
    Type& Peek() {
        return elements_.Peek();
    }
    void Print() const {
        elements_.Print();
    }
    uint64_t Size() const {
        return elements_.Size();
    }
    bool IsEmpty() const {
        return elements_.IsEmpty();
    }
private:
    Stack<Type> elements_;
};

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SortedStack<int> stack;
    vector<int> values(5);

    // заполняем вектор для тестирования нашего стека
    iota(values.begin(), values.end(), 1);
    // перемешиваем значения
    random_shuffle(values.begin(), values.end());

    // заполняем стек и проверяем, что сортировка сохраняется после каждой вставки
    for (int i = 0; i < 5; ++i) {
        cout << "Вставляемый элемент = "s << values[i] << endl;
        stack.Push(values[i]);
        stack.Print();
    }
}