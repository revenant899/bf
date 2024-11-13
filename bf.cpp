#include <iostream>
#include <string>
using namespace std;


//struct Car {
//    double length;
//    double clearance;
//    double engineVolume;
//    int enginePower;
//    int wheelDiameter;
//    string color;
//    string transmissionType;
//
//    void setValues(double len, double clr, double engVol, int engPow, int wheelDiam, string clrName, string transType) {
//        length = len;
//        clearance = clr;
//        engineVolume = engVol;
//        enginePower = engPow;
//        wheelDiameter = wheelDiam;
//        color = clrName;
//        transmissionType = transType;
//    }
//
//    void display() const {
//        cout << "Довжина: " << length << " м" << endl;
//        cout << "Кліренс: " << clearance << " см" << endl;
//        cout << "Об'єм двигуна: " << engineVolume << " л" << endl;
//        cout << "Потужність двигуна: " << enginePower << " к.с." << endl;
//        cout << "Діаметр коліс: " << wheelDiameter << " дюймів" << endl;
//        cout << "Колір: " << color << endl;
//        cout << "Тип коробки передач: " << transmissionType << endl;
//    }
//
//    bool findValue(string searchColor) const {
//        return color == searchColor;
//    }
//};

struct Complex {
    double real;
    double imag;

    Complex(double r = 0, double i = 0) : real(r), imag(i) {}
};

Complex add(const Complex& c1, const Complex& c2) {
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

Complex subtract(const Complex& c1, const Complex& c2) {
    return Complex(c1.real - c2.real, c1.imag - c2.imag);
}

Complex multiply(const Complex& c1, const Complex& c2) {
    double real = c1.real * c2.real - c1.imag * c2.imag;
    double imag = c1.real * c2.imag + c1.imag * c2.real;
    return Complex(real, imag);
}

Complex divide(const Complex& c1, const Complex& c2) {
    double denominator = c2.real * c2.real + c2.imag * c2.imag;
    if (denominator == 0) {
        cerr << "Error: Division by zero." << endl;
        return Complex();
    }
    double real = (c1.real * c2.real + c1.imag * c2.imag) / denominator;
    double imag = (c1.imag * c2.real - c1.real * c2.imag) / denominator;
    return Complex(real, imag);
}

void printComplex(const Complex& c) {
    cout << c.real;
    if (c.imag >= 0) cout << " + " << c.imag << "i";
    else cout << " - " << -c.imag << "i";
    cout << endl;
}

int main() {
    Complex c1(4, 5);   
    Complex c2(2, -3); 

    cout << "c1 = ";
    printComplex(c1);
    cout << "c2 = ";
    printComplex(c2);

    Complex sum = add(c1, c2);
    cout << "\nc1 + c2 = ";
    printComplex(sum);

    Complex diff = subtract(c1, c2);
    cout << "c1 - c2 = ";
    printComplex(diff);

    Complex prod = multiply(c1, c2);
    cout << "c1 * c2 = ";
    printComplex(prod);

    Complex quot = divide(c1, c2);
    cout << "c1 / c2 = ";
    printComplex(quot);

    /*Car car1;
    car1.setValues(4.5, 15, 2.0, 150, 16, "Червоний", "Автомат");

    cout << "Інформація про автомобіль:" << endl;
    car1.display();

    string searchColor = "Червоний";
    if (car1.findValue(searchColor)) {
        cout << "Автомобіль знайдено за кольором: " << searchColor << endl;
    }
    else {
        cout << "Автомобіль з кольором " << searchColor << " не знайдено." << endl;
    }*/

}



