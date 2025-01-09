#include <iostream>
#include "proba.cpp";

using namespace std;


int main() {
    int number;
    // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the
    // <b>lang</b> variable name to see how CLion can help you rename it.
    cout << "Input number:" ;

    cin >> number;
    // cin.ignore();
    cout << number << endl;
    cin.get();

    func_out("Hello from main");
    return 0;
}

