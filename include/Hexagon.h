#ifndef HEXAGON_H
#define HEXAGON_H

#include "Figure.h"
#include <vector>

class Hexagon : public Figure {
private:
    std::vector<std::pair<double, double>> vertices;
public:
    Hexagon();
    double area() const override;
    std::pair<double, double> geometricCenter() const override;
    void print(std::ostream& out) const override;
    void read(std::istream& in) override;
    operator double() const override;

    friend std::ostream& operator<<(std::ostream& os, const Hexagon& obj);
    friend std::istream& operator>>(std::istream& os, Hexagon& obj);
};

#endif // HEXAGON_H
