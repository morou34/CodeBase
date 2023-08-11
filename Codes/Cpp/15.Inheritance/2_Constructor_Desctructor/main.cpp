#include <iostream>
#include <string>
#include <ostream>
#include <vector>

class Vehicule
{
protected:
    std::string name;

public:
    Vehicule();                               // No args constructor
    Vehicule(std::string name);               // overloaded constructor
    Vehicule(const Vehicule &source);         // copy constructor
    Vehicule(Vehicule &&source);              // move constructor
    Vehicule &operator=(const Vehicule &rhs); // copy assignment
    Vehicule &operator=(Vehicule &&rhs);      // move assignment
    ~Vehicule();
};

Vehicule::Vehicule() : name{"Vehicule"} {}
Vehicule::Vehicule(std::string name) : name{name} {}
Vehicule::~Vehicule() {}

// Copy constructor
Vehicule::Vehicule(const Vehicule &source) : name{source.name}
{
    std::cout << "Vehicule Copy constructor for: " << name << std::endl;
}

// Move constructor
Vehicule::Vehicule(Vehicule &&source) : name{source.name}
{
    std::cout << "Vehicule Move constructor for: " << source.name << std::endl;
}
// copy assignment
Vehicule &Vehicule::operator=(const Vehicule &rhs)
{
    if (this != &rhs)
    {
        this->name = rhs.name;
        std::cout << "Vehicule Copy assignment for: " << this->name << std::endl;
    }
    return *this;
}

// Move assignment
Vehicule &Vehicule::operator=(Vehicule &&rhs)
{
    if (this != &rhs)
    {
        this->name = rhs.name;
        std::cout << "Vehicule Move assignment for: " << this->name << std::endl;
    }
    return *this;
}

class Car : public Vehicule
{
    friend std::ostream &operator<<(std::ostream &os, const Car &car);
    friend std::istream &operator>>(std::istream &is, Car &car);

private:
    int production;

public:
    Car();                                 // No args constructor
    Car(std::string name, int production); // overloaded constructor
    ~Car();
    Car(const Car &source);         // Copy constructor
    Car(Car &&source);              // Move constructor
    Car &operator=(const Car &rhs); // Copy assignment
    Car &operator=(Car &&rhs);      // Move assignment
    std::string get_name() { std::cout << name << " ." << production << std::endl; };
};

Car::Car() : production{2000} {}

Car::Car(std::string name, int production) : Vehicule{name}, production{production} {}

Car::~Car() {}

// copy constructor
Car::Car(const Car &source) : Vehicule{source.name}, production{source.production}
{
    std::cout << "Car Copy Constructor for: " << name << std::endl;
}

// Move constructor
Car::Car(Car &&source) : Vehicule(source.name), production{source.production}
{
    std::cout << "Car Move Constructor for: " << name << std::endl;
}

Car &Car::operator=(const Car &rhs)
{
    if (this != &rhs)
    {
        Vehicule::operator=(rhs);
        this->production = rhs.production;
        std::cout << "Car Copy Assignment for: " << this->name << std::endl;
    }
    return *this;
}

Car &Car::operator=(Car &&rhs)
{
    if (this != &rhs)
    {
        Vehicule::operator=(std::move(rhs));
        this->production = rhs.production;
        std::cout << "Car Move Assignment for: " << this->name << std::endl;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Car &car)
{
    os << car.name << " | " << car.production;
    return os;
}

std::istream &operator>>(std::istream &is, Car &car)
{
    std::cout << "Enter car and production: ";
    std::cin >> car.name >> car.production;
    return is;
}

int main(int argc, char const *argv[])
{
    Car audi;
    Car mercedes;
    Car audiA3{"Audi-A3", 2020};
    std::cout << audi << std::endl;
    std::cout << audiA3 << std::endl;
    // std::cin >> mercedes;
    std::cout << mercedes << std::endl;

    // Vehicule copy constructor
    Vehicule bmw1{"BMW"};
    Vehicule bmw2{bmw1};
    // Vehicule Move constructor
    std::vector<Vehicule> vehicules;
    vehicules.push_back(Vehicule{"Mazda"});
    // Vehicule copy assignment
    Vehicule projectS{"Subaru"};
    Vehicule subaru;
    subaru = projectS;
    // Vehicule Move assignment
    Vehicule toyota;
    toyota = Vehicule{"Toyota"};

    std::cout << "\n____ Car Stuff ____" << std::endl;
    // Car Copy constructor
    Car newCar{audiA3};
    // Car Move constructor
    std::vector<Car> cars;
    cars.push_back(Car{"Ferrari", 2020});
    // Car Copy assignment & Vehicule copy assignment:
    // The child class invokes the parent class copy assignment explicitly.
    Car honda;
    honda = newCar;
    // Car Move assignment & Vehicule move assignment.
    Car mazirati;
    mazirati = Car{"Mazeratti", 2323};

    return 0;
}
