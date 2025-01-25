#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <execution>
using namespace std;


/*
Задание
Пусть ваша поисковая система возвращает не любые документы, а документы с самой высокой релевантностью. Напишите функцию FindTopDocuments, которая должна находить только MAX_RESULT_DOCUMENT_COUNT = 5 результатов. Объявите эту глобальную константу вверху своего решения. Функцию FindTopDocuments поместите там же, где для вывода итогового результат мы вызывали FindDocuments. Саму FindDocuments замените на функцию FindAllDocuments, которая будет возвращать все результаты поиска в виде пар из идентификатора документа и релевантности {document_id, relevance}. Отсортируйте результат FindAllDocuments по убыванию, чтобы использовать его в FindTopDocuments.

Примеры
Ввод

a the on cat
6
a fat cat sat on a mat and ate a fat rat
fat rat
a fat cat rat
a fat cat sat
a fat cat
a fat dog
funny fat cat on a mat with rat
Вывод

{ document_id = 0, relevance = 3 }
{ document_id = 2, relevance = 2 }
{ document_id = 1, relevance = 2 }
{ document_id = 5, relevance = 1 }
{ document_id = 4, relevance = 1 }
Подсказка
Вспомните, что должна возвращать функция FindAllDocuments, чтобы сортировка по убыванию поставила наверх документы с наибольшей релевантностью.
 */
constexpr int kMaxResultDocuments = 5;

struct Document {
    int id;
    int relevance;
};

string ReadLine() {
    string s;
    getline(cin, s);
    return s;
}

int ReadLineWithNumber() {
    int result;
    cin >> result;
    ReadLine();
    return result;
}

vector<string> SplitIntoWords(const string &text) {
    vector<string> words;
    string word;
    for (const char c: text) {
        if (c == ' ') {
            words.push_back(word);
            word = "";
        } else {
            word += c;
        }
    }
    words.push_back(word);

    return words;
}


class SearchServer {
public:
    void AddDocument(int document_id, const string &document) {
        for (const string &word: SplitIntoWordsNoStop(document)) {
            word_to_documents_[word].insert(document_id);
        }
    }

    void SetStopWords(const string &text) {
        for (const string &word: SplitIntoWords(text)) {
            stop_words_.insert(word);
        }
    }

    vector<Document> FindTopDocuments(const string &query) const {
        vector<Document> documents = FindAllDocuments(query);

        sort(execution::par, documents.begin(), documents.end(), [](const Document &lhs, const Document &rhs)->bool
            {
                 if (lhs.relevance == rhs.relevance) {
                     return lhs.id > rhs.id;
                 }

                 return lhs.relevance > rhs.relevance;
             }
        );

        if (documents.size() > kMaxResultDocuments) {
            documents.resize(kMaxResultDocuments);
        }

        return documents;
    }

private:
    vector<string> SplitIntoWordsNoStop(const string &text) const {
        vector<string> words;

        for (const string &word: SplitIntoWords(text)) {
            if (stop_words_.count(word) == 0) {
                words.push_back(word);
            }
        }

        return words;
    }

    vector<Document> FindAllDocuments(const string &query) const {
        const vector<string> query_words = SplitIntoWordsNoStop(query);
        map<int, int> document_to_relevance;

        for (const string &word: query_words) {
            if (word_to_documents_.count(word) == 0) {
                continue;
            }
            for (const int document_id: word_to_documents_.at(word)) {
                ++document_to_relevance[document_id];
            }
        }

        vector<Document> found_documents(document_to_relevance.size());

        for (auto [document_id, relevance]: document_to_relevance) {
            found_documents.push_back({document_id, relevance});
        }

        return found_documents;
    }

    map<string, set<int> > word_to_documents_;
    set<string> stop_words_;
};

SearchServer CreateSearchServer() {
    SearchServer search_server;
    const string stop_words_joined = ReadLine();

    search_server.SetStopWords(stop_words_joined);

    const int document_count = ReadLineWithNumber();

    for (int document_id = 0; document_id < document_count; ++document_id) {
        search_server.AddDocument(document_id, ReadLine());
    }

    return search_server;
}

int main() {
    const SearchServer server = CreateSearchServer();

    const string query = ReadLine();
    for (auto [id, relevance]: server.FindTopDocuments(query)) {
        cout << "{ document_id = "s << id << ", relevance = "s << relevance << " }"s << endl;
    }
}
