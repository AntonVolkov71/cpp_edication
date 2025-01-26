#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

/*
Задание
Примените шаблонную функцию ComputeTermFreqs и определите, какое животное встречается наибольшее число раз. Животное в этом задании задаётся парой pair<string, int>.

Если максимальное число раз встречаются несколько животных, выведите наименьшего из них. Гарантируется, что вектор содержит хотя бы одно животное.

Подсказка
Вызовите ComputeTermFreqs для вектора animals, проитерируйтесь по результату и найдите ключ с наибольшим значением. Если очередной ключ имеет частоту, равную уже найденной максимальной, не переписывайте им ключ-ответ.
*/
struct Animal {
   string name;
   int age;
};

template <typename Term>
map<Term, int> ComputeTermFreqs(const vector<Term>& terms) {
   map<Term, int> term_freqs;

   for (const Term& term : terms) {
      ++term_freqs[term];
   }
   return term_freqs;
}

Animal FindMaxFreqAnimal(const vector<Animal>& animals) {
   int max_freq = 0;
   Animal max_freq_animal= {"", 0};

   // вот здесь вызываем шаблонную функцию
   for (const auto& [animal, freq] : ComputeTermFreqs(animals)) {
      if (freq > max_freq) {
         max_freq = freq;
         max_freq_animal = animal;
      }
   }
   return max_freq_animal;
}

int main() {
   const vector<Animal> animals = {
      {"Murka"s, 5},
      {"Belka"s, 6},
      {"Murka"s, 7},
      {"Murka"s, 5},
      {"Belka"s, 6},
  };
   const Animal max_freq_animal = FindMaxFreqAnimal(animals);
   cout << max_freq_animal.name << " "s
        << max_freq_animal.age << endl;
}

