#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <filesystem>
#include <ranges>
#include <map>

using namespace std;
namespace fs = std::filesystem;
namespace rng = std::ranges;
namespace view = rng::views;

const string INPUT_NAME = "input.txt";
const string OUTPUT_NAME = "output.txt";


struct Command {
    Command(const string &cmd, const int val) : key(cmd), value(val) {
    }

    string key;
    int value;
};

string ParseInput(const string &file_name) {
    vector<Command> commands;
    ifstream input(file_name);
    if (!input) throw runtime_error("Cannot open input: " + file_name);

    string line;
    input >> line;
    input.ignore();

    return line;
}

struct Node {
    Node(const char value, Node *next, Node *prev)
            : value(value), next(next), prev(prev) {
    }

    char value;
    Node *next;
    Node *prev;
};

class Stack_ {
public:
    void Push(const char &value) {
        if (head_ == nullptr) {
            head_ = tail_ = new Node(value, nullptr, nullptr);
        } else {
            tail_->next = new Node(value, nullptr, tail_);
            tail_ = tail_->next;
        }
    }

    char Pop() {
        if (head_ == nullptr) {
            throw length_error("error");
        }

        char value = tail_->value;
        Node *tmp = tail_;

        if (head_ == tail_) {

            head_ = nullptr;
            tail_ = nullptr;

            return value;
        }

        tail_->prev->next = nullptr;
        tail_ = tail_->prev;

        delete tmp;

        return value;
    }

    bool IsEmpty(){
        return head_ == nullptr;
    }

    ~Stack_() {
        while (head_) {
            Node *tmp = head_;
            head_ = head_->next;
            delete tmp;
        }
    }

private:
    Node *head_ = nullptr;
    Node *tail_ = nullptr;
};


const map<char, char> bracket_pairs{
        {'}', '{'},
        {')', '('},
        {']', '['}
};

string Solution(const string &input_file_name) {
    string brackets = ParseInput(input_file_name);
    string res;

    Stack_ stack_;

    try {
        for (const auto &bracket: brackets) {

            // если есть пара получаем значит это закрывающая
            // и перед ней в стеке должна быть открывающая
            if (bracket_pairs.contains(bracket)) {
                char pop = stack_.Pop();
                char openBracket = bracket_pairs.at(bracket);

                if (pop != openBracket) {
                    return "False";
                }
            } else {
                stack_.Push(bracket);
            }
        }
    } catch (exception &e) {
        return "False";
    }

    return stack_.IsEmpty() ? "True" : "False";
}

void RunTests(string tests_file_path);


int main(int argc, char *argv[]) {
    try {
        if (argc > 1) {
            RunTests(argv[1]);
        } else {
            cout << Solution(INPUT_NAME) << endl;
        }
    } catch (const exception &e) {
        cerr << "Fatal error: " << e.what() << endl;
        return 1;
    }

    return 0;
}

string ReadOutputFile(const string &path) {
    ifstream file(path);

    if (!file) throw runtime_error("Cannot open output: " + path);

    string line;
    getline(file, line);

    return line;
}

void RunTests(string tests_file_path) {
    int test_id = 1;

    for (const auto &entry: fs::directory_iterator(tests_file_path)) {
        if (!entry.is_directory()) continue;

        string input_path = entry.path().string() + "\\" + INPUT_NAME;
        string output_path = entry.path().string() + "\\" + OUTPUT_NAME;

        try {
            string expected = ReadOutputFile(output_path);
            string actual = Solution(input_path);

            bool success = (expected == actual);

            cout << "Test #" << test_id++ << ": " << (success ? "OK" : "FAIL") << endl;

            if (!success) {
                cout << actual
                     << (actual == expected ? " == " : " != ")
                     << expected;
                cout << endl;
            }
        } catch (const exception &e) {
            cout << "Test #" << test_id++ << ": ERROR (" << e.what() << ")" << endl;
        }
    }
}
