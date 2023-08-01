#include <iostream>
#include <iomanip>
#include <random>
#include <Windows.h>
#include <cmath>
#include <chrono>
#include <string>

using namespace std;


// ������� ��� ��������� ���������� ����� �������� ����� � ����������������� �������
std::string generateRandomKey(int keyLength) {
    // ��������, ����� ����� ����� ���� ����������
    if (keyLength <= 0 || keyLength % 4 != 0) {
        std::cerr << "������������ ����� �����!" << std::endl;
        return "";
    }

    // ��������� ��������� �����
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 15);

    // ��������� ���������� �������� � ����������������� ������
    int numHexChars = keyLength / 4;

    // ���������� ����������������� ������
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

    // ����� ������ � �����
    int keyLengths[] = { 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096 };

    // ��������� ������ � ����� �� �����
    for (int i = 0; i < sizeof(keyLengths) / sizeof(keyLengths[0]); ++i) {
        int keyLength = keyLengths[i];
        // ��������� ������������ ������ ��� ������ �����
        double key_space = pow(2, keyLength);
        cout << "����� �����: " << keyLength << " ��� - ������������ ������: " << key_space << endl;

        std::string key = generateRandomKey(keyLength);
        std::cout << "���� " << keyLength << "-������: 0x" << key << std::endl;

        
       
    }
  
    return 0;
}
