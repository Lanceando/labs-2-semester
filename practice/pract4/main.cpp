#include <iostream>
#include <fstream>
#include <string>
#include <vector>




class Device {
private:
    std::string m_name;
public:
    Device() = default;

    virtual void poll() = 0;
    virtual ~Device() = default;

};

class ElectricityMeter : public Device {
private:
    std::string type = "Electricity Meter";
    std::string m_name;

public:
    explicit ElectricityMeter(const std::string &name) : m_name(name) {}

    void poll() override {

        std::cout << type + ": " << m_name  << std::endl;
    }

    ~ElectricityMeter() override = default;

};

class DiscreteInputBlock : public Device {
private:
    std::string m_name;
    std::string type = "DiscreteInputBlock";

public:
    explicit DiscreteInputBlock(const std::string &name) : m_name(name) {}

    void poll() override {

        std::cout << type + ": " << m_name  << std::endl;
    }

    ~DiscreteInputBlock() override = default;
};

class HeatingControlBlock : public Device {
private:
    std::string m_name;
    std::string type = "HeatingControlBlock";

public:
    explicit HeatingControlBlock(const std::string &name) : m_name(name) {}
    void poll() override {

        std::cout << type + ": " << m_name  << std::endl;
    }



    ~HeatingControlBlock() override = default;
};

int main()
{
    setlocale(LC_ALL, "ru");
    std::ifstream input("../devices.txt");

    if (!input.is_open()) {
        std::cout << "Failed to open devices file" << std::endl;
    }

    std::vector<Device*> devices;

    std::string deviceType, deviceName;
    while (input >> deviceType >> deviceName) {
        if (deviceType == "ElectricityMeter") {
            devices.push_back(new ElectricityMeter(deviceName));
        }
        else if (deviceType == "DiscreteInputBlock") {
            devices.push_back(new DiscreteInputBlock(deviceName));
        }
        else if (deviceType == "HeatingControlBlock") {
            devices.push_back(new HeatingControlBlock(deviceName));
        }
        else {
            std::cout << "Error. Unknow device type" << deviceType << std::endl;
        }
    }
    input.close();

    for (auto device : devices) {
        device->poll();
    }
    for (auto device : devices) {
        delete device;
    }

};
