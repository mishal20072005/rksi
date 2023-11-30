#include <iostream>
#include "electronics.h"

int main() {
    const int MAX_PRODUCTS = 5; // Максимальное количество товаров на складе
    Electronics* products[MAX_PRODUCTS];

    // Создание товаров
    products[0] = new Smartphone("iPhone 12", 999.99, 24);
    products[1] = new Laptop("Dell XPS 13", 1299.99, 12);
    products[2] = new TV("Samsung QLED", 1999.99, "220V");
    products[3] = new Refrigerator("LG Smart Fridge", 1499.99, "110V");
    products[4] = new TV("Sony OLED", 2999.99, "220V");

    std::cout << "Список товаров на складе:" << std::endl;

    // Вывод информации о каждом товаре
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        std::cout << i + 1 << ". " << products[i]->getName() << std::endl;
    }

    std::cout << std::endl;

    // Просмотр характеристик выбранного товара
    int choice;
    std::cout << "Введите номер товара для просмотра его характеристик: ";
    std::cin >> choice;

    if (choice >= 1 && choice <= MAX_PRODUCTS) {
        int index = choice - 1;
        std::cout << "Название: " << products[index]->getName() << std::endl;
        std::cout << "Цена: $" << products[index]->getPrice() << std::endl;
        std::cout << products[index]->getAdditionalInfo() << std::endl;
    }
    else {
        std::cout << "Некорректный выбор товара." << std::endl;
    }

    // Освобождение памяти
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        delete products[i];
    }

    return 0;
}