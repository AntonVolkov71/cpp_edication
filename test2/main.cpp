/*
    Test project

    Created by Anton Y. Volkov (volkovanton71@yandex.ru)
    09.01.2024
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Document {
    int id;
    int elevance;
};

int main() {
    vector<Document> docs = {{1, 2}};

    std::cout << docs[2].id << std::endl;
    return 0;
}
