#include <iostream>
#include <iomanip> 

bool bruteForceKey(uint8_t target_key) {
    uint8_t current_key = 0x00;
    unsigned int attempts = 0;

    while (current_key != target_key) {
        std::cout << "������� �������� �����: 0x" << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(current_key) << std::endl;

        // ����������, �� ������� ����
        if (current_key == target_key) {
            std::cout << "�������� ����: 0x" << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(current_key) << std::endl;
            std::cout << "ʳ������ �����: " << attempts << std::endl;
            return true;
        }

        // ���� �� �������, �������� �������� �����
        ++current_key;
        attempts++;

        // �������� �� �������, ���� �������� ����� �������� 0xFF
        if (current_key == 0x00) {
            std::cout << "���� �� ��������." << std::endl;
            return false;
        }
    }

    return false;
}

int main() {
    uint8_t target_key = 0x9D; // ������������ ����, ���� ������� ������

    if (bruteForceKey(target_key)) {
        std::cout << "���� ��������." << std::endl;
    }
    else {
        std::cout << "���� �� ��������." << std::endl;
    }

    return 0;
}
