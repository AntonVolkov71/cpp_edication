#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <filesystem>
#include <ranges>

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

vector<Command> ParseCommands(const string &file_name) {
    vector<Command> commands;
    ifstream input(file_name);
    if (!input) throw runtime_error("Cannot open input: " + file_name);

    int n;
    input >> n;
    input.ignore();

    for (int i = 0; i < n; ++i) {
        string line;
        getline(input, line);
        if (!line.empty()) {
            stringstream ss(line);
            string key;
            int value;
            ss >> key >> value;
            commands.emplace_back(key, value);
        }
    }

    return commands;
}

struct Node {
    Node(const int value, Node *next, Node *prev, const int max)
            : value(value), next(next), prev(prev), max(max) {
    }

    int value;
    int max;
    Node *next;
    Node *prev;
};

class Stack_ {
public:
    void Push(const int &value) {
        if (head_ == nullptr) {
            head_ = tail_ = new Node(value, nullptr, nullptr, value);
        } else {
            int max = tail_->max > value ? tail_->max : value;

            tail_->next = new Node(value, nullptr, tail_, max);
            tail_ = tail_->next;
        }
    }

    void Pop() {
        if (head_ == nullptr) {
            throw length_error("error");
        }

        if (head_ == tail_) {

            head_ = nullptr;
            tail_ = nullptr;

            return;
        }

        tail_->prev->next = nullptr;
        tail_ = tail_->prev;
    }


    int Top() const {
        if (head_ == nullptr) {
            throw length_error("error");
        }

        return tail_->value;
    }

    int GetMax() const {
        if (head_ == nullptr) {
            throw length_error("None");
        }

        return tail_->max;
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

vector<string> Solution(const string &input_file_name) {
    vector<Command> commands = ParseCommands(input_file_name);
    vector<string> res;

    Stack_ stack_;


    for (const auto &cmd: commands) {
        try {
            if (cmd.key == "push") {
                stack_.Push(cmd.value);
            } else if (cmd.key == "pop") {
                stack_.Pop();
            } else if (cmd.key == "top") {
                res.push_back(to_string(stack_.Top()));
            } else if (cmd.key == "get_max") {
                res.push_back(to_string(stack_.GetMax()));
            }
        } catch (exception &e) {
            res.push_back(e.what());
        }
    }

    return res;
}

void RunTests(string tests_file_path);


int main(int argc, char *argv[]) {
    try {
        if (argc > 1) {
            RunTests(argv[1]);
        } else {
            vector<string> result = Solution(INPUT_NAME);

            for (const auto &line: result) {
                cout << line << endl;
            }
        }
    } catch (const exception &e) {
        cerr << "Fatal error: " << e.what() << endl;
        return 1;
    }

    return 0;
}

vector<string> ReadOutputFile(const string &path) {
    vector<string> result;
    ifstream file(path);
    if (!file) throw runtime_error("Cannot open output: " + path);

    string line;
    while (getline(file, line)) {
        if (!line.empty()) result.push_back(line);
    }
    return result;
}

void RunTests(string tests_file_path) {
    int test_id = 1;

    for (const auto &entry: fs::directory_iterator(tests_file_path)) {
        if (!entry.is_directory()) continue;

        string input_path = entry.path().string() + "\\" + INPUT_NAME;
        string output_path = entry.path().string() + "\\" + OUTPUT_NAME;

        try {
            vector<string> expected = ReadOutputFile(output_path);
            vector<string> actual = Solution(input_path);

            bool success = (expected == actual);

            cout << "Test #" << test_id++ << ": " << (success ? "OK" : "FAIL") << endl;

            if (!success) {
                for (size_t i = 0; i < actual.size(); ++i) {
                    cout << "  [" << i << "]: "
                         << actual[i]
                         << (actual[i] == expected[i] ? " == " : " != ")
                         << (i < expected.size() ? expected[i] : "-------") << endl;
                }
                cout << endl;
            }
        } catch (const exception &e) {
            cout << "Test #" << test_id++ << ": ERROR (" << e.what() << ")" << endl;
        }
    }
}
