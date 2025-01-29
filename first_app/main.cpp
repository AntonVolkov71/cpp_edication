ad#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

enum class AnimalSortKey {
    AGE,     // по полю age
    WEIGHT,  // по полю weight
    RELATIVE_WEIGHT  // по weight / age
};

struct Animal {
    string name;
    int age;
    double weight;
};

void PrintNames(const vector<Animal>& animals) {
    for (const Animal& animal : animals) {
        cout << animal.name << ' ';
    }
    cout << endl;
}
auto key_mapper_func = [](const Animal& animal) { return animal.name; };

// как написать SortBy?
template <typename Container, typename KeyMapper>
void SortBy(Container& container, KeyMapper key_mapper, bool is_reverse = false) {
    sort(container.begin(), container.end(),[key_mapper, is_reverse](const auto &lhs, const auto &rhs){
        return is_reverse
        ? key_mapper(lhs) < key_mapper(rhs)
        : key_mapper(lhs) > key_mapper(rhs);
    });
}

void SortBy(vector<Animal>& animals, AnimalSortKey sort_key, bool reverse = false) {
    switch (sort_key) {
        case AnimalSortKey::AGE:
            // возвращается void, но return помогает сразу выйти из функции
            return SortBy(animals, [](const auto& x) { return x.age; }, reverse);
        case AnimalSortKey::WEIGHT:
            return SortBy(animals, [](const auto& x) { return x.weight; }, reverse);
        case AnimalSortKey::RELATIVE_WEIGHT:
            return SortBy(animals, [](const auto& x) { return x.weight / x.age; }, reverse);
    }
}

int main() {
    vector<Animal> animals = {
            {"Mura"s,   10, 5},
            {"Bela"s,   5,  1.5},
            {"Geor"s, 2,  4.5},
            {"Ryri"s,   12, 3.1},
    };

    PrintNames(animals);

    SortBy(animals, key_mapper_func);
    PrintNames(animals);
    SortBy(animals, [](const Animal& animal) { return animal.name; }, true);
    PrintNames(animals);
    SortBy(animals, [](const Animal& animal) { return -animal.weight; });
    PrintNames(animals);
    SortBy(animals, AnimalSortKey::RELATIVE_WEIGHT);
    PrintNames(animals);
}