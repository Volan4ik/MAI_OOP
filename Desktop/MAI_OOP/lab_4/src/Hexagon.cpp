#include "../include/Hexagon.h"
#include <cmath>

Hexagon::Hexagon() : vertices(6) {}

double Hexagon::area() const {
    double sum = 0;
    for (size_t i = 0; i < vertices.size(); ++i) {
        auto [x1, y1] = vertices[i];
        auto [x2, y2] = vertices[(i + 1) % vertices.size()];
        sum += (x1 * y2 - x2 * y1);
    }
    return std::abs(sum) / 2.0;
}

std::pair<double, double> Hexagon::geometricCenter() const {
    double x_sum = 0, y_sum = 0;
    for (const auto& [x, y] : vertices) {
        x_sum += x;
        y_sum += y;
    }
    return {x_sum / vertices.size(), y_sum / vertices.size()};
}

void Hexagon::print(std::ostream& out) const {
    for (const auto& [x, y] : vertices) {
        out << "(" << x << ", " << y << ") ";
    }
}

void Hexagon::read(std::istream& in) {
    for (auto& [x, y] : vertices) {
        in >> x >> y;
    }
}

Hexagon::operator double() const
{
    return this->area();
}

std::ostream& operator<<(std::ostream& os, const Hexagon& obj) {
    obj.print(os);

    return os;
}


std::istream& operator>>(std::istream& is, Hexagon& obj) {
    obj.read(is);

    return is;
}