#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string PurifyWord(const string& word) {
    string pure_word;
    for (const char c : word) {
        if (c != '-' && c != '+' && c != '!') {
            pure_word.push_back(c);
        }
    }
    return pure_word;
}


int main() {
    const vector<string> words = {"!Cat"s, "-pushisty"s};
    vector<string> pure_words;

    for (const string& word : words) {
        pure_words.push_back(PurifyWord(word));
    }

    for (const string& word : pure_words) {
        cout << word << endl;
    }
}