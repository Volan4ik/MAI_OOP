#include <FearOfNumbers.h>

bool is_afraid(const std::string& day_of_week, int number) {
    if (day_of_week == "Понедельник") {
        return number == 12;
    } else if (day_of_week == "Вторник") {
        return number > 95;
    } else if (day_of_week == "Среда") {
        return number == 34;
    } else if (day_of_week == "Четверг") {
        return number == 0;
    } else if (day_of_week == "Пятница") {
        return number % 2 == 0;
    } else if (day_of_week == "Суббота") {
        return number == 56;
    } else if (day_of_week == "Воскресенье") {
        return number == 666 || number == -666;
    }
    return false;
}
