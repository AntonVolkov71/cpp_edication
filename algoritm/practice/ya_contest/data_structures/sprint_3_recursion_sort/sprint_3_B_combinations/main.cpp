#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <filesystem>
#include <map>
#include <string>

using namespace std;
namespace fs = std::filesystem;

const string INPUT_NAME = "input.txt";
const string OUTPUT_NAME = "output.txt";


vector<int> ParseCommands(const string &file_name) {
    ifstream input(file_name);

    if (!input) throw runtime_error("Cannot open input: " + file_name);

    vector<int> nums;
    string line;
    input >> line;
    input.ignore();

    for(char s: line){
        nums.emplace_back(s - '0');
    }


    return nums;
}

map<int, string> phone{
        {2, "abc"},
        {3, "def"},
        {4, "ghi"},
        {5, "jkl"},
        {6, "mno"},
        {7, "pqrs"},
        {8, "tuv"},
        {9, "wxyz"}
};

void print(vector<string> dicts, int pos, string prefix) {

    if (pos == dicts.size()) {
        cout << prefix << ' ';
        return;
    }

    for (int i = 0; i < dicts[pos].size(); ++i) {
        print(dicts, pos + 1, prefix + dicts[pos][i]);

    }

}

vector<string> Solution(const string &input_file_name) {
    vector<int> nums = ParseCommands(input_file_name);
    vector<string> dicts;

    for (const auto num: nums) {
        dicts.emplace_back(phone.at(num));
    }

    vector<string> res;
    print(dicts, 0, "");

    return res;
}

void RunTests(string tests_file_path);


int main(int argc, char *argv[]) {
    try {
        if (argc > 1) {
            RunTests(argv[1]);
        } else {
            vector<string> result = Solution(INPUT_NAME);

//            for (const auto &line: result) {
//                cout << line << ' ';
//            }
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
