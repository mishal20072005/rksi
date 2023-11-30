#include <iostream>
#include "electronics.h"

int main() {
    const int MAX_PRODUCTS = 5; // ������������ ���������� ������� �� ������
    Electronics* products[MAX_PRODUCTS];

    // �������� �������
    products[0] = new Smartphone("iPhone 12", 999.99, 24);
    products[1] = new Laptop("Dell XPS 13", 1299.99, 12);
    products[2] = new TV("Samsung QLED", 1999.99, "220V");
    products[3] = new Refrigerator("LG Smart Fridge", 1499.99, "110V");
    products[4] = new TV("Sony OLED", 2999.99, "220V");

    std::cout << "������ ������� �� ������:" << std::endl;

    // ����� ���������� � ������ ������
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        std::cout << i + 1 << ". " << products[i]->getName() << std::endl;
    }

    std::cout << std::endl;

    // �������� ������������� ���������� ������
    int choice;
    std::cout << "������� ����� ������ ��� ��������� ��� �������������: ";
    std::cin >> choice;

    if (choice >= 1 && choice <= MAX_PRODUCTS) {
        int index = choice - 1;
        std::cout << "��������: " << products[index]->getName() << std::endl;
        std::cout << "����: $" << products[index]->getPrice() << std::endl;
        std::cout << products[index]->getAdditionalInfo() << std::endl;
    }
    else {
        std::cout << "������������ ����� ������." << std::endl;
    }

    // ������������ ������
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        delete products[i];
    }

    return 0;
}