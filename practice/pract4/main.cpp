#include <iostream>
#include <vector>
#include <string>
#include <fstream>



class Device {
private:
    std::string m_name;
    std::string m_type;

public:

    Device(const std::string& type, const std::string& name) : m_name(name), m_type(type) {}

    virtual void poll() {
        std::cout << m_type << " " << m_name << ": Какие-то данные" << std::endl;
        // Некоторая реализация 
    }
};

class  ElectricityMeter: public Device {
public:
    ElectricityMeter(const std::string& type, const std::string& name): Device(type, name) {}

};

class DiscreteInputBlock : public Device {

public:
    DiscreteInputBlock(const std::string& type, const std::string& name): Device(type, name) {}
};

class HeatingControlBlock : public Device {

public:
    HeatingControlBlock(const std::string& type, const std::string& name): Device(type, name) {}
};


int main()
{
    setlocale(LC_ALL, "ru");
    std::ifstream input("devices.txt");

    if (!input.is_open()) {
        std::cout << "Failed to open devices file" << std::endl;
    }
    
    std::vector<Device*> devices;

    std::string deviceType, deviceName;
    while (input >> deviceType >> deviceName) {
        if (deviceType == "ElectricityMeter") {
            devices.push_back(new ElectricityMeter(deviceType, deviceName));
        }
        else if (deviceType == "DiscreteInputBlock") {
            devices.push_back(new DiscreteInputBlock(deviceType, deviceName));
        }
        else if (deviceType == "HeatingControlBlock") {
            devices.push_back(new HeatingControlBlock(deviceType, deviceName));
        }
        else {
            std::cout << "Error. Unknow device type" << deviceType << std::endl;
        }
    }

    for (auto device : devices) {
        device->poll();
    }

    for (auto device : devices) {
        delete device;
    }

}
