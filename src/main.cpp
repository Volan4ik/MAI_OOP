#include <iostream>
#include <memory>
#include "Pentagon.h"
#include "Hexagon.h"
#include "Octagon.h"
#include "Vector.h"

int main() {
    SimpleVector<std::shared_ptr<Figure>> figures;
    int choice;
    
    while (true) {
        std::cout << "1. Добавить фигуру\n2. Удалить фигуру\n3. Показать все фигуры\n4. Вычислить общую площадь\n5. Выход\n";
        std::cin >> choice;
        
        if (choice == 1) {
            int type;
            std::cout << "Выберите тип фигуры (1 - Пятиугольник, 2 - Шестиугольник, 3 - Восьмиугольник): ";
            std::cin >> type;
            
            std::shared_ptr<Figure> figure;
            if (type == 1) {
                figure = std::make_shared<Pentagon>();
            } else if (type == 2) {
                figure = std::make_shared<Hexagon>();
            } else if (type == 3) {
                figure = std::make_shared<Octagon>();
            }
            
            std::cin >> *figure;  
            figures.PushBack(figure); 
        } 
        else if (choice == 2) {
            size_t index;
            std::cout << "Введите индекс фигуры для удаления: ";
            std::cin >> index;
            if (index < figures.Size()) {
                figures.Erase(index);  
                std::cout << "Фигура удалена.\n";
            } else {
                std::cout << "Неверный индекс.\n";
            }
        }
        else if (choice == 3) {
            for (size_t i = 0; i < figures.Size(); ++i) {
                std::cout << "Фигура " << i + 1 << ":\n";
                std::cout << *figures[i];  
            }
        } 
        else if (choice == 4) {
            double totalArea = 0.0;
            for (size_t i = 0; i < figures.Size(); ++i) {
                totalArea += static_cast<double>(*figures[i]); 
            }
            std::cout << "Общая площадь всех фигур массива: " << totalArea << "\n";
        } 
        else if (choice == 5) {
            break;
        } else {
            std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    }

    return 0;
}
