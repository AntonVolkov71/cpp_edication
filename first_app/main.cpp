#include <numeric>
#include <iostream>
#include <vector>
#include <valarray>

using namespace std;

class Greeter {
public:
    Greeter(const string& name)
            : name_(name)
    {
        cout << "Hello, "s << name_ << "!"s << endl;
    }

    ~Greeter() {
        // Поля класса внутри деструктора еще не уничтожены, и к ним можно обращаться
        cout << "Goodbye, "s << name_ << "!"s << endl;
    }
private:
    string name_;
};

Greeter ReturnGreeter() {
    return {"result"s};
}

int main() {
    ReturnGreeter();
    Greeter body("body"s);
}