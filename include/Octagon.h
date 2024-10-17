#ifndef OCTAGON_H
#define OCTAGON_H

#include "Figure.h"
#include <vector>

class Octagon : public Figure {
private:
    std::vector<std::pair<double, double>> vertices;
public:
    Octagon();
    double area() const override;
    std::pair<double, double> geometricCenter() const override;
    void print(std::ostream& out) const override;
    void read(std::istream& in) override;
    operator double() const override;

    friend std::ostream& operator<<(std::ostream& os, const Octagon& obj);
    friend std::istream& operator>>(std::istream& os, Octagon& obj);
};

#endif // OCTAGON_H
