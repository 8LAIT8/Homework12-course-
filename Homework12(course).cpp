#include <iostream>
using namespace std;

class Shape {
public:
    virtual ~Shape() {}
    virtual Shape* Clone() const = 0; 
    virtual void Draw() const = 0;    
};

class Rectangle : public Shape {
public:
    Rectangle(double length, double width)
        : itsLength(length), itsWidth(width) {}

    ~Rectangle() override {}

    Shape* Clone() const override {
        return new Rectangle(*this); 
    }

    void Draw() const override {
        cout << "Drawing Rectangle with length " << itsLength
            << " and width " << itsWidth << endl;
    }

protected:
    double itsLength;
    double itsWidth;
};

class Square : public Rectangle {
public:
    Square(double length)
        : Rectangle(length, length) {}

    ~Square() override {}

    Shape* Clone() const override {
        return new Square(*this); 
    }

    void Draw() const override {
        cout << "Drawing Square with side " << itsLength << endl;
    }
};

int main() {
    Shape* square1 = new Square(5.0);
    square1->Draw();

    Shape* square2 = square1->Clone(); 
    square2->Draw();

    delete square1;
    delete square2;

    return 0;
}

