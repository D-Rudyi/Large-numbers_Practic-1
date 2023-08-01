//#include <iostream>
//#include <cmath>
//#include <random>
//#include <Windows.h>
//
//using namespace std;
//
//int main() {
//
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    int key_lengths[] = {8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096};
//
//    for (int i = 0; i < sizeof(key_lengths) / sizeof(key_lengths[0]); ++i) {
//        
//        
//        int key_length = key_lengths[i];
//        // ��������� ������������ ������ ��� ������ �����
//        double key_space = pow(2, key_length);
//        cout << "����� �����: " << key_length << " ��� - ������������ ������: " << key_space << endl;
//        
//        // ��������� ���������� �������� �����
//        random_device rd;
//        mt19937 gen(rd());
//        uniform_int_distribution<unsigned long long> dis(0, pow(2, key_length) - 1);
//        unsigned long long random_key = dis(gen);
//
//        cout << "��������� �������� �����: " << hex << random_key << endl;
//    }
//
//
//    return 0;
//
//}
#include <iostream>
#include <iomanip>
#include <random>

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
    // ����� ������ � �����
    int keyLengths[] = { 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096 };

    // ��������� ������ � ����� �� �����
    for (int i = 0; i < sizeof(keyLengths) / sizeof(keyLengths[0]); ++i) {
        int keyLength = keyLengths[i];
        std::string key = generateRandomKey(keyLength);
        std::cout << "����� " << keyLength << "-������� �����: 0x" << key << std::endl;
    }

    return 0;
}

