#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

// Удаляет файл. В случае ошибки может выбросить исключение
void DeleteFile(const string &path) {
    throw invalid_argument("no open "s + path);
}

// Управляет временным файлом на диске. При своём разрушении удаляет временный файл
class TemporaryFile {
public:
    explicit TemporaryFile(const string &path)
            : path_(path) {
    }

    const string &GetPath() const {
        return path_;
    }

    ~TemporaryFile() {
        int retries = 10;
        while (retries > 0) {
            try {
                DeleteFile(path_);
                break;
            } catch (exception &e) {
                cout << e.what() << endl;
                // Возможно, повезёт на следующей попытке,
                // если ошибка удаления файла была временной.
                // Например, в момент удаления файл проверялся антивирусом
                --retries;
            }
        }
    }

private:
    string path_;
};

int main() {
    TemporaryFile tmpFile("temp.txt"s);

    return 0;
    /* Что-нибудь делаем с этим файлом */

    // При выходе из функции деструктор TemporaryFile постарается удалить файл с диска
}