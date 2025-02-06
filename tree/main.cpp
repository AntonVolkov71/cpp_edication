#ifndef REMOTE_JUDGE

struct Node {
    int value;
    const Node *left = nullptr;
    const Node *right = nullptr;

    Node(int value, Node *left, Node *right) : value(value), left(left), right(right) {}
};

#endif

#ifdef REMOTE_JUDGE
#include "solution_tree.h"
#endif

#include <cmath>
#include <iostream>
#include <cassert>

using namespace std;

int maxV = numeric_limits<int>::max();
int minV = numeric_limits<int>::min();

bool Search(const Node *root, int lhs = minV, int rhs = maxV) {
    if (root == nullptr) {
        return true;
    }

    if ((lhs >= root->value) || (rhs <= root->value)) {
        return false;
    }

    bool left = Search(root->left, lhs, root->value);
    bool right = Search(root->right, root->value, rhs);

    return left && right;
};

bool Solution(const Node *root) {
    return Search(root, minV, maxV);
};


#ifndef REMOTE_JUDGE

void test() {
    {
        Node node1({1, nullptr, nullptr});
        Node node2({4, nullptr, nullptr});
        Node node3({3, &node1, &node2});
        Node node4({8, nullptr, nullptr});
        Node node5({5, &node3, &node4});
        assert(Solution(&node5));
    }
    {
        Node node1({1, nullptr, nullptr});
        Node node2({5, nullptr, nullptr});
        Node node3({3, &node1, &node2});
        Node node4({8, nullptr, nullptr});
        Node node5({5, &node3, &node4});
        assert(!Solution(&node5));
    }
}


int main() {
    test();
}

#endif