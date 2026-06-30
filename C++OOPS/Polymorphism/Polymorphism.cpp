// polymorphism_example.cpp
// Demonstrates Compile-time Polymorphism (overloading) and
// Run-time Polymorphism (virtual functions / dynamic dispatch)

#include <iostream>
#include <vector>
using namespace std;

// ---------------- Compile-Time Polymorphism ----------------

// Function Overloading: same name "add", different parameter types/counts
class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }
    double add(double a, double b) {
        return a + b;
    }
    int add(int a, int b, int c) {
        return a + b + c;
    }
};

// Operator Overloading: redefining '+' for a custom Point class
class Point {
public:
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    // Overload the + operator to add two points
    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }

    void display() const {
        cout << "(" << x << ", " << y << ")\n";
    }
};

// ---------------- Run-Time Polymorphism ----------------

class Shape {
public:
    // Pure virtual-like usage here is just "virtual" (not pure) so Shape
    // itself can still be instantiated conceptually if needed.
    virtual double area() const {
        return 0.0;
    }

    virtual void draw() const {
        cout << "Drawing a generic shape.\n";
    }

    // VERY IMPORTANT: virtual destructor for safe polymorphic deletion
    virtual ~Shape() {
        cout << "Shape destructor\n";
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return 3.14159 * radius * radius;
    }

    void draw() const override {
        cout << "Drawing a Circle with radius " << radius
             << " | Area = " << area() << "\n";
    }

    ~Circle() override {
        cout << "Circle destructor\n";
    }
};

class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() const override {
        return width * height;
    }

    void draw() const override {
        cout << "Drawing a Rectangle " << width << "x" << height
             << " | Area = " << area() << "\n";
    }

    ~Rectangle() override {
        cout << "Rectangle destructor\n";
    }
};

int main() {
    cout << "===== Compile-Time Polymorphism =====\n";
    Calculator calc;
    cout << "add(2, 3) = " << calc.add(2, 3) << "\n";
    cout << "add(2.5, 3.5) = " << calc.add(2.5, 3.5) << "\n";
    cout << "add(1, 2, 3) = " << calc.add(1, 2, 3) << "\n";

    Point p1(1, 2), p2(3, 4);
    Point p3 = p1 + p2;   // uses overloaded operator+
    cout << "p1 + p2 = ";
    p3.display();

    cout << "\n===== Run-Time Polymorphism =====\n";
    // Vector of base class pointers holding different derived objects
    vector<Shape*> shapes;
    shapes.push_back(new Circle(5.0));
    shapes.push_back(new Rectangle(4.0, 6.0));

    // The correct draw() is chosen at RUNTIME based on actual object type
    for (Shape* s : shapes) {
        s->draw();
    }

    // Proper cleanup - virtual destructor ensures derived destructors run too
    for (Shape* s : shapes) {
        delete s;
    }

    return 0;
}
