#include <iostream>

class Complex{
private:
    double a;
    double b;

public:
    Complex(){
        a = 0;
        b = 0;
    }

    Complex(double c_a, double c_b){
        a = c_a;
        b = c_b;
    }

    Complex& operator = (const Complex& c){
        a = c.a;
        b = c.b;
        return *this;
    }

    ~Complex() {};

    Complex& operator += (const Complex& c){
        a += c.a;
        b += c.b;
        return *this;
    }

    Complex operator + (const Complex& c){
        Complex res;
        res.a = a + c.a;
        res.b = b + c.b;
        return res;
    }

    Complex& operator *= (const Complex& c){
        double new_a, new_b;
        new_a = (a * c.a) - (b * c.b);
        new_b = (a * c.b) + (b * c.a);
        a = new_a;
        b = new_b;
        return *this;
    }

    Complex operator * (const Complex& c){
        Complex res;
        res.a = (a * c.a) - (b * c.b);
        res.b = (a * c.b) + (b * c.a);
        return res;
    }

    Complex& operator ++ (){
        a++;
        return *this;
    }

    Complex operator ++ (int){
        Complex temp(*this);
        a++;
        return temp;
    }

    friend std::istream & operator >> (std::istream &in, Complex &c){
        in >> c.a;
        in >> c.b;
        return in;
    }

    friend std::ostream & operator << (std::ostream &out, const Complex &c) {
        out << c.a << " + " << c.b << "i";
        return out;
    }




};

int main() {
    Complex c1, c2, c3;

    std::cin >> c1;
    std::cin >> c2;

    c3 = c1 + c2;
    std::cout << c3 << std::endl;

    c3 = c1 * c2;
    std::cout << c3 << std::endl;

    ++c1;
    std::cout << c1 << std::endl;

    c1 += c2;
    std::cout << c1 << std::endl;

    c1 *= c2;
    std::cout << c1 << std::endl;

    ++c1;
    std::cout << c1 << std::endl;

}
