#include <iostream>
#include <vector>
#include <memory>
#include "../include/Pentagon.h"
#include "../include/Hexagon.h"
#include "../include/Octagon.h"

int main() {
    std::vector<std::unique_ptr<Figure>> figures;
    char choice;

    while (std::cin >> choice) {
        if (choice == '5') {
            auto fig = std::make_unique<Pentagon>();
            std::cin >> *fig;
            figures.push_back(std::move(fig));
        } else if (choice == '6') {
            auto fig = std::make_unique<Hexagon>();
            std::cin >> *fig;
            figures.push_back(std::move(fig));
        } else if (choice == '8') {
            auto fig = std::make_unique<Octagon>();
            std::cin >> *fig;
            figures.push_back(std::move(fig));
        }
    }

    // Вывод данных о фигурах
    for (const auto& fig : figures) {
        std::cout << "Geometric Center: " << fig->geometricCenter().first << ", "
                  << fig->geometricCenter().second << "\n";
        std::cout << "Area: " << static_cast<double>(*fig) << "\n";
    }

    return 0;
}
