#include <iostream>
#include <vector>
#include <string>

enum class Color {
    Red,
    Green,
    Blue
};

class Figure {
private:
    int m_x, m_y;
    Color m_color;

public:
    Figure(int x, int y, Color color): m_x(x), m_y(y), m_color(color) {}

    virtual void Square() = 0;
};

class Triangle: public Figure {
private:
    int m_a, m_b, m_c;
    std::string type = "Triangle";
public:
    Triangle(int x, int y, Color color, int a, int b, int c): Figure(x,y,color),m_a(a), m_b(b), m_c(c) {}
    
    void Square() {
        double p = (m_a + m_b + m_c) / 2;
        //return sqrt(p * (p - m_a) * (p - m_b) * (p - m_c));    
        std::cout << "Square of " + type + ": " << sqrt(p * (p - m_a) * (p - m_b) * (p - m_c)) << std::endl;
    }
};

class Rectangle: public Figure {
private:
    int m_a, m_b;
    std::string type = "Rectangle";

public:
    Rectangle(int x, int y, Color color, int a, int b): Figure(x, y, color), m_a(a), m_b(b) {}

    void Square() {
        //return m_a * m_b;
        std::cout << "Square of " + type + ": " << m_a * m_b << std::endl;
    }
};

class Circle : public Figure {
private:
    int m_r;
    double PI = 3.14;
    std::string type = "Circle";

public:
    Circle(int x, int y, Color color, int r): Figure(x, y, color), m_r(r) {}

    void Square() {
        //return PI * (m_r*m_r);
        std::cout << "Square of " + type + ": " << PI * (m_r * m_r) << std::endl;
    }
};

int main()
{
    
    std::vector<Figure*> figures;
    figures.push_back(new Triangle(0, 0, Color::Red, 3, 4, 5));
    figures.push_back(new Rectangle(0, 0, Color::Green, 2, 4));
    figures.push_back(new Circle(0, 0, Color::Blue, 3));

    for (auto figure : figures)
    {
        figure->Square();
        std::cout << std::endl;
    }

    
    for (auto figure : figures)
    {
        delete figure;
    }
}
