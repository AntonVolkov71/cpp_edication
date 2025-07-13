#include <iostream>
using namespace std;



void gen_binary(int n, string prefix, int left) {
    if (n == 0) {
        cout << string(left++, ' ') << prefix << endl;

        return;
    } else {
        cout <<string(left++, ' ') <<  prefix << endl;

//        gen_binary(n - 1, prefix + "0",left);
        gen_binary(n - 1, prefix + "1", left);
    }
}

int main() {
    gen_binary(3, "", 0);
    return 0;
}