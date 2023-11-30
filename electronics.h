#ifndef ELECTRONICS_H
#define ELECTRONICS_H

#include <string>

// Абстрактный базовый класс электроники
class Electronics {
protected:
    std::string name;
    double price;
public:
    Electronics(const std::string& name, double price) : name(name), price(price) {}

    std::string getName() const {
        return name;
    }

    double getPrice() const {
        return price;
    }

    virtual std::string getAdditionalInfo() const = 0;
};

// Дочерний класс портативной электроники
class PortableElectronics : public Electronics {
protected:
    int batteryLife;
public:
    PortableElectronics(const std::string& name, double price, int batteryLife) : Electronics(name, price), batteryLife(batteryLife) {}

    int getBatteryLife() const {
        return batteryLife;
    }

    std::string getAdditionalInfo() const override {
        return "Battery Life: " + std::to_string(batteryLife) + " hours";
    }
};

// Дочерний класс бытовой электроники
class HomeElectronics : public Electronics {
protected:
    std::string powerSupply;
public:
    HomeElectronics(const std::string& name, double price, const std::string& powerSupply) : Electronics(name, price), powerSupply(powerSupply) {}

    std::string getPowerSupply() const {
        return powerSupply;
    }

    std::string getAdditionalInfo() const override {
        return "Power Supply: " + powerSupply;
    }
};

// Примеры конкретных видов портативной электроники
class Smartphone : public PortableElectronics {
public:
    Smartphone(const std::string& name, double price, int batteryLife) : PortableElectronics(name, price, batteryLife) {}
};

class Laptop : public PortableElectronics {
public:
    Laptop(const std::string& name, double price, int batteryLife) : PortableElectronics(name, price, batteryLife) {}
};

// Примеры конкретных видов бытовой электроники
class TV : public HomeElectronics {
public:
    TV(const std::string& name, double price, const std::string& powerSupply) : HomeElectronics(name, price, powerSupply) {}
};

class Refrigerator : public HomeElectronics {
public:
    Refrigerator(const std::string& name, double price, const std::string& powerSupply) : HomeElectronics(name, price, powerSupply) {}
};

#endif