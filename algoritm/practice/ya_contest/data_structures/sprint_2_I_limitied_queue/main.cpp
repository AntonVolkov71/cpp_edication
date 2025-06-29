#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

const string INPUT_NAME = "input.txt";
const string OUTPUT_NAME = "output.txt";

class Data {
public:
    struct Command {
        Command(const string &cmd, const string &val): key(cmd), value(val) {
        }

        string key;
        string value;
    };

    Data(int max_size): max_size_(max_size) {
    }

    void AddCommand(const string &key, const string &value) {
        commands.emplace_back(key, value);
    }

    int GetMaxSize() const {
        return max_size_;
    }

    vector<Command> GetCommands() const {
        return commands;
    }

private:
    vector<Command> commands;
    int max_size_ = 0;
};


Data ParseCommands(const string &file_name) {
    ifstream input(file_name);

    if (!input) throw runtime_error("Cannot open input: " + file_name);

    int n;
    input >> n;
    input.ignore();

    int max_size;
    input >> max_size;
    input.ignore();

    Data data(max_size);

    for (int i = 0; i < n; ++i) {
        string line;
        getline(input, line);

        if (!line.empty()) {
            stringstream ss(line);
            string key;
            string value;

            ss >> key >> value;

            data.AddCommand(key, value);
        }
    }

    return data;
}


struct Node {
    Node(const string &val, Node *nxt): value(val), next(nxt) {
    }

    string value;
    Node *next;
};

class Queue {
public:
    Queue(const int max_size): max_size_(max_size) {
    }

    ~Queue() {
       while (head_) {
           Node *tmp = head_->next;
           delete head_;;

            head_ = tmp;
       }
    }

    size_t Size() const {
        return size_;
    }

    void Push(string value) {
        if (static_cast<int>(size_) == max_size_) {
            throw length_error("error");
        }

        // если пустой список голова и хвост имееют одно значение
        Node *node = new Node(value, nullptr);

        if (head_ == nullptr) {
            head_ = tail_ = node;
        } else {
            tail_->next = node;
            tail_ = tail_->next;
        }

        ++size_;
    }

    string Peek() const {
        if (head_ == nullptr) {
            return "None";
        }

        return head_->value;
    }

    string Pop() {
        if (head_ == nullptr) {
            return "None";
        }

        string value = head_->value;
        Node *node = head_->next;;

        delete head_;

        head_ = node;

        --size_;
        return value;
    }

private:
    Node *head_ = nullptr;
    Node *tail_ = nullptr;
    int max_size_ = 0;
    size_t size_ = 0;
};

vector<string> Solution(const string &input_file_name) {
    Data data = ParseCommands(input_file_name);
    vector<string> res;

    Queue queue(data.GetMaxSize());
    for (auto &cmd: data.GetCommands()) {
        try {
            if (cmd.key == "size") {
                res.push_back(to_string(queue.Size()));
            } else if (cmd.key == "push") {
                queue.Push(cmd.value);
            } else if (cmd.key == "peek") {
                res.push_back(queue.Peek());
            } else if (cmd.key == "pop") {
                res.push_back(queue.Pop());
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
