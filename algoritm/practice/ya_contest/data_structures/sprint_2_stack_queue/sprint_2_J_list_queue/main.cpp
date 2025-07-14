#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

const string INPUT_NAME = "input.txt";
const string OUTPUT_NAME = "output.txt";


struct Command {
    Command(const string &cmd, const string &val): key(cmd), value(val) {
    }

    string key;
    string value;
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
            string key, value;
            ss >> key >> value;
            commands.emplace_back(key, value);
        }
    }

    return commands;
}

struct Node {
    Node(const string &value_n, Node *next_n)
        : value(value_n), next(next_n) {
    }

    string value;
    Node *next;
};

class Queue {
public:
    size_t Size() const {
        return size_;
    }

    void Put(const string &value) {
        Node *node = new Node(value, nullptr);
        if (head_ == nullptr) {
            head_ = tail_ = node;
        } else {
            tail_->next = node;
            tail_ = tail_->next;
        }

        size_++;
    }

    string Get() {
        if (head_ == nullptr) {
            return "error";
        }

        Node *node = head_;
        string result = node->value;

        head_ = head_->next;
        delete node;
        if (head_ == nullptr) {
            tail_ = nullptr;
        }

        --size_;

        return result;
    }

    ~Queue() {
        while (head_) {
            Node *tmp = head_;
            head_ = head_->next;
            delete tmp;
        }
    }

private:
    Node *head_ = nullptr;
    Node *tail_ = nullptr;
    size_t size_ = 0;
};

vector<string> Solution(const string &input_file_name) {
    vector<Command> commands = ParseCommands(input_file_name);
    vector<string> res;

    Queue queue;

    for (auto &cmd: commands) {
        if (cmd.key == "size") {
            res.push_back(to_string(queue.Size()));
        } else if (cmd.key == "put") {
            queue.Put(cmd.value);
        } else if (cmd.key == "get") {
            res.push_back(queue.Get());
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
