#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>

class Figure {
public:
    virtual double area() const = 0;
    virtual std::pair<double, double> geometricCenter() const = 0;
    virtual void print(std::ostream& out) const = 0;
    virtual void read(std::istream& in) = 0;
    virtual ~Figure() = default;
    virtual operator double() const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Figure& figure) {
        figure.print(os);
        return os;
    }

    friend std::istream& operator<<(std::istream& is, Figure& figure) {
        figure.read(is);
        return is;
    }
};

#endif // FIGURE_H
