#include <iostream>
using namespace std;

class Box {
private:
    double length;
    double width;
    double height;

public:

    // 1) setAllInfo: inside class
    void setAllInfo(double l, double w, double h) {
        if (l > 0) length = l;
        if (w > 0) width = w;
        if (h > 0) height = h;
    }

    // 2) setHeight: inside class
    void setHeight(double h) {
        if (h > 0) height = h;
    }

    // 3) getHeight: inside class
    void getHeight(double& h) const {
        h = height;
    }

    // 4) getWidth: inside class
    double getWidth() const {
        return width;
    }

    // 5) getVolume: inside class
    double getVolume() const {
        return length * width * height;
    }

    // 6) getAllInfo: outside class
    void getAllInfo(double& l, double& w, double& h) const;

    // 7) print: outside class
    void print() const;

    // 8) compare: outside class
    bool compare(const Box& other) const;
};

// Implementation outside class
void Box::getAllInfo(double& l, double& w, double& h) const {
    l = length;
    w = width;
    h = height;
}

void Box::print() const {
    cout << "Length = " << length
         << ", Width = " << width
         << ", Height = " << height << endl;
}

bool Box::compare(const Box& other) const {
    return (length == other.length &&
            width == other.width &&
            height == other.height);
}

int main() {
    Box box1, box2;

    // 2) Input values for box1
    double l, w, h;
    cout << "Enter length, width, height for box1: ";
    cin >> l >> w >> h;
    box1.setAllInfo(l, w, h);

    // 3) Set values for box2
    box2.setAllInfo(2, 7, 4);

    // 4) Print box1 and box2
    cout << "\nBox1: ";
    box1.print();
    cout << "Box2: ";
    box2.print();

    // 5) Print volume of box1
    cout << "\nVolume of Box1 = " << box1.getVolume() << endl;

    // 6) Increment height of box1 by 3
    double currentHeight;
    box1.getHeight(currentHeight);
    box1.setHeight(currentHeight + 3);

    // 7) Print box1 and box2 again
    cout << "\nAfter increasing Box1 height:\n";
    cout << "Box1: ";
    box1.print();
    cout << "Box2: ";
    box2.print();

    // 8) Compare
    if (box1.compare(box2))
        cout << "\nThe boxes are equal.\n";
    else
        cout << "\nThe boxes are not equal.\n";

    return 0;
}