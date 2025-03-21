#include <cassert>
#include <string>

int main() {
    using namespace std;

    string practicum = "Practicum"s;

    string* paracticum_ptr = &practicum;

    // Прежде чем обратиться к методу length, разыменуем указатель
    assert((*paracticum_ptr).length() == 9);

    // Также обращение к полям и методам структур и классов
    // доступно при помощи операции ->
    assert(paracticum_ptr->substr(2, 3) == "act"s);
}