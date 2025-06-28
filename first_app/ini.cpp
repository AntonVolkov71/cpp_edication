#include "ini.h"

using namespace std;

namespace ini {
    Section &Document::AddSection(std::string name) {
        sections_[name] = Section();

        return sections_[name];
    }


    const Section &Document::GetSection(const std::string &name) const {
        auto it = sections_.find(name);

        if (it != sections_.end()) {
            return it->second;
        }

        return empty_section_;
    }

    std::size_t Document::GetSectionCount() const {
        return sections_.size();
    }

    Document Load(std::istream &input) {
        Document doc;

        // получить строку текст на вход построчно
        // в каждой строке определяем секция по [] или ключ-значение по = исключая пробелы
        // пустую пропускаем
        // парсим отдельно название секции и ключ значение
        // запоминаем и записываем название секции, после в эту секцию записываем ключ значение
        // пока не закончатся строки
        string section_name = "";
        Section *current_section = nullptr;
        std::string line;

        while (std::getline(input, line)) {
            if (line.empty()) {
                continue;
            } else if (line[0] == '[') {
                auto endBracket = line.find(']');
                if (endBracket == std::string::npos) continue;

                // вырезать между [ и ]
                section_name = line.substr(1, endBracket - 1);
                Trim(section_name);
                current_section = &doc.AddSection(section_name);
            } else if (current_section != nullptr) {
                // читаем ключ значение только если есть название секции
                // без пробелов
                // пробел в начале и конце
                // пробел начало
                // пробел конец
                int equalSign = line.find('=');
                if (equalSign == std::string::npos) continue;

                std::string key = line.substr(0, equalSign);
                std::string value = line.substr(equalSign + 1);
                Trim(key); // функция, удаляющая пробелы по краям
                Trim(value);

                current_section->insert({
                    key,
                    value
                });
            }
        }

        return doc;
    }

    void Trim(std::string &s) {
        size_t start = s.find_first_not_of(" ");
        size_t end = s.find_last_not_of(" ");
        s = (start == std::string::npos) ? "" : s.substr(start, end - start + 1);
    }
} // namespace ini {

// место для реализаций методов и функций библиотеки ini
// не забудьте, что они должны быть помещены в namespace ini
