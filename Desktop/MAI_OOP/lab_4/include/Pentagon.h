#ifndef PENTAGON_H
#define PENTAGON_H

#include "Figure.h"
#include "Vector.h"

class Pentagon : public Figure {
private:
    std::vector<std::pair<double, double>> vertices;
public:
    Pentagon();
    double area() const override;
    std::pair<double, double> geometricCenter() const override;
    void print(std::ostream& out) const override;
    void read(std::istream& in) override;
    operator double() const override;

    friend std::ostream& operator<<(std::ostream& os, const Pentagon& obj);
    friend std::istream& operator>>(std::istream& os, Pentagon& obj);
};

#endif // PENTAGON_H
