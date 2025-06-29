#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

const string INPUT_NAME = "input.txt";
const string OUTPUT_NAME = "output.txt";

// class Data {
// public:
//     Data(int n, int m){
//         delete[] matrix_;
//         matrix_ = new int[n];
//
//     }
//
//     void AddElement(const int n, const int m, const int value) {
//         matrix_[n][m] = value;
//     }
//
//     const int (*Getmatrix() const)[] {
//         return matrix_;
//     }
//
// private:
//     int matrix_[0][0];
// };


void ParseCommands(const string &file_name) {
    ifstream input(file_name);

    if (!input) throw runtime_error("Cannot open input: " + file_name);

    int n, m;
    input >> n;
    input.ignore();

    input >> m;;
    input.ignore();

    // Data data(n, m);

    int res[m][n];
    for (int i = 0; i < n; ++i) {
        string line;
        getline(input, line);


        if (!line.empty()) {
            // cout << "line " << line << endl;
            stringstream ss(line);
            // string key;
            int value;
            int j = 0;

            while (ss >> value) {
                // cout << '[' << j << ']' << '[' << i << ']' << value << endl;
                res[j][i] = value;
                j++;
            }
            // cout << endl;

            // ss >> key >> value;
            //
            // data.AddCommand(key, value);
        }

        // cout << endl;
    }


    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << res[i][j] << ' ';
        }

        cout << endl;
    }
    // return data;
}


vector<string> Solution(const string &input_file_name) {
    ParseCommands(input_file_name);
    vector<string> res;

    // Queue queue(data.GetMaxSize());
    // for (auto &cmd: data.GetCommands()) {
    //     try {
    //         if (cmd.key == "size") {
    //             res.push_back(to_string(queue.Size()));
    //         } else if (cmd.key == "push") {
    //             queue.Push(cmd.value);
    //         } else if (cmd.key == "peek") {
    //             res.push_back(queue.Peek());
    //         } else if (cmd.key == "pop") {
    //             res.push_back(queue.Pop());
    //         }
    //     } catch (exception &e) {
    //         res.push_back(e.what());
    //     }
    // }

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
