#include <cassert>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>
#include <algorithm>

using namespace std;
using filesystem::path;

path operator ""_p(const char *data, std::size_t sz) {
    return path(data, data + sz);
}

struct File_ {
    File_(const path &p_, const filesystem::file_status &status_)
            : p(p_), status(status_) {}

    path p;
    filesystem::file_status status;
};


void SortFiles(vector<File_> &entries) {
    sort(entries.begin(), entries.end(), [](const File_ &a, const File_ &b) {
        return a.p.filename() > b.p.filename(); // обратный алфавит
    });
};

void PrintTree(ostream &dst, const path &p, const filesystem::file_status &status, int offset) {
    string spaces = "";
    spaces.append(offset, ' ');

    if (status.type() == filesystem::file_type::regular) {
        dst << spaces << p.filename().string() << '\n';
    } else if (status.type() == filesystem::file_type::directory) {
        dst << spaces << p.filename().string() << '\n';

        vector<File_> entries;
        offset += 2;

        for(const auto& entry: filesystem::directory_iterator(p)){
            entries.emplace_back(entry, entry.status());
        }

        SortFiles(entries);

        for (const auto& entry: entries) {
            PrintTree(dst, entry.p, entry.status, offset);
        }
    }
}


// напишите эту функцию
void PrintTree(ostream &dst, const path &p) {
    error_code err;

    dst << p.filename().string() << '\n';
    int offset = 2;

    vector<File_> entries;

    for (const auto &dir_entry: filesystem::directory_iterator(p)) {
        entries.emplace_back(dir_entry, dir_entry.status());
    }

    SortFiles(entries);

    for (const auto& entry: entries) {
        PrintTree(dst, entry.p, entry.status, offset);
    }
}

int main() {
    error_code err;
    filesystem::remove_all("test_dir", err);
    filesystem::create_directories("test_dir"_p / "a"_p, err);
    filesystem::create_directories("test_dir"_p / "b"_p, err);

    ofstream("test_dir"_p / "b"_p / "f1.txt"_p);
    ofstream("test_dir"_p / "b"_p / "f2.txt"_p);
    ofstream("test_dir"_p / "a"_p / "f3.txt"_p);

    ostringstream out;
    PrintTree(out, "test_dir"_p);

    assert(out.str() ==
           "test_dir\n"
           "  b\n"
           "    f2.txt\n"
           "    f1.txt\n"
           "  a\n"
           "    f3.txt\n"sv
    );
}
