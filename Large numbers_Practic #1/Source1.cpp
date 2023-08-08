#include <iostream>
#include <iomanip> 

bool bruteForceKey(uint8_t target_key) {
    uint8_t current_key = 0x00;
    unsigned int attempts = 0;

    while (current_key != target_key) {
        std::cout << "Поточне значення ключа: 0x" << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(current_key) << std::endl;

        // Перевіряємо, чи знайшли ключ
        if (current_key == target_key) {
            std::cout << "Знайдено ключ: 0x" << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(current_key) << std::endl;
            std::cout << "Кількість спроб: " << attempts << std::endl;
            return true;
        }

        // Якщо не знайшли, збільшуємо значення ключа
        ++current_key;
        attempts++;

        // Перевірка на випадок, коли значення ключа перевищує 0xFF
        if (current_key == 0x00) {
            std::cout << "Ключ не знайдено." << std::endl;
            return false;
        }
    }

    return false;
}

int main() {
    uint8_t target_key = 0x9D; // Встановлюємо ключ, який потрібно знайти

    if (bruteForceKey(target_key)) {
        std::cout << "Ключ знайдено." << std::endl;
    }
    else {
        std::cout << "Ключ не знайдено." << std::endl;
    }

    return 0;
}
