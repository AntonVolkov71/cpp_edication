#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#ifndef REMOTE_JUDGE

#include <cassert>
#include <iostream>
#include <string>

using namespace std;

struct Node {
    std::string value;
    Node *next;

    Node(const std::string &value, Node *next) : value(value), next(next) {

    }
};

#endif


int solution(Node *head, const std::string &elem) {
    int idx = 0;

    while (head) {
        if (head->value == elem) {
            return idx;
        }
        head = head->next;
        ++idx;
    }

    return -1;
}

#ifndef REMOTE_JUDGE

void test() {
    Node node3("node3", nullptr);
    Node node2("node2", &node3);
    Node node1("node1", &node2);
    Node node0("node0", &node1);
    int idx = solution(&node0, "node2");
    assert(idx == 2);
}

int main() {
    test();
//    cout << "OK!";
}

#endif