#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>

int main() {
    while (true) {
//         Получаем текущее время
        auto now = std::chrono::system_clock::now();
        std::time_t now_c = std::chrono::system_clock::to_time_t(now);

        //         Выводим время в формате ЧЧ:ММ:СС
        std::cout << std::put_time(std::localtime(&now_c), "%H:%M:%S") << std::endl;

        std::cout << "Hello" << std::flush;

        // Задержка 5 секунд
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }

    return 0;
}
