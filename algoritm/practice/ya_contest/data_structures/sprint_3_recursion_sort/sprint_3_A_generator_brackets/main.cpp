#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

const string INPUT_NAME = "input.txt";
const string OUTPUT_NAME = "output.txt";


int ParseCommands(const string &file_name) {
    ifstream input(file_name);

    if (!input) throw runtime_error("Cannot open input: " + file_name);

    int n;
    input >> n;
    input.ignore();


    return n;
}

void gen(int n, int open, int close, string res){
    if((open + close) == (2 * n) ){
        cout << res << '\n';

        return;
    }

    if(open > close){
        gen(n, open, close + 1, res + ')');
    }

    if(open < n){
        gen(n, open + 1, close, res + '(');
    }


}

vector<string> Solution(const string &input_file_name) {
    int n = ParseCommands(input_file_name);

    vector<string> res;

    gen(n, 0,0, "");

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
