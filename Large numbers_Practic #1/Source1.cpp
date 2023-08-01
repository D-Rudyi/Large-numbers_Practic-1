#include <iostream>
#include <iomanip>
#include <random>
#include <Windows.h>
#include <cmath>
#include <chrono>
#include <string>

using namespace std;


// Функция для генерации случайного ключа заданной длины в шестнадцатеричном формате
std::string generateRandomKey(int keyLength) {
    // Проверка, чтобы длина ключа была корректной
    if (keyLength <= 0 || keyLength % 4 != 0) {
        std::cerr << "Некорректная длина ключа!" << std::endl;
        return "";
    }

    // Генератор случайных чисел
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 15);

    // Вычисляем количество символов в шестнадцатеричной строке
    int numHexChars = keyLength / 4;

    // Генерируем шестнадцатеричную строку
    std::string result;
    result.reserve(numHexChars);
    for (int i = 0; i < numHexChars; ++i) {
        int randomDigit = dis(gen);
        result += static_cast<char>(randomDigit < 10 ? '0' + randomDigit : 'A' + randomDigit - 10);
    }

    return result;
}


int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Длины ключей в битах
    int keyLengths[] = { 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096 };

    // Генерация ключей и вывод на экран
    for (int i = 0; i < sizeof(keyLengths) / sizeof(keyLengths[0]); ++i) {
        int keyLength = keyLengths[i];
        // Вычисляем пространство ключей для данной длины
        double key_space = pow(2, keyLength);
        cout << "Длина ключа: " << keyLength << " бит - Пространство ключей: " << key_space << endl;

        std::string key = generateRandomKey(keyLength);
        std::cout << "Ключ " << keyLength << "-битный: 0x" << key << std::endl;

        
       
    }
  
    return 0;
}
