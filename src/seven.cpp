#include "seven.h"

Seven::Seven() : size(0) {}

Seven::Seven(const size_t size) : size(size), digits(new unsigned char[size] {0}) {}

Seven::Seven(const std::string& str) : size(str.size()), digits(new unsigned char[size]) {
    for (size_t i = 0; i < size; ++i) {
        if (!is_valid_digit(str[i])) {
            handle_error("Invalid digit in seven number");
            return;
        }
        digits[size - i - 1] = str[i] - '0'; 
    }
}

Seven::Seven(const Seven& other) : size(other.size), digits(new unsigned char[other.size]) {
    for (size_t i = 0; i < size; ++i) {
        digits[i] = other.digits[i];
    }
}

Seven::Seven(Seven&& other) noexcept : size(other.size), digits(other.digits) {
    other.digits = nullptr;
    other.size = 0;
}

Seven::~Seven() {
    delete[] digits;
}

Seven& Seven::operator=(const Seven& other) {
    if (this != &other) {
        delete[] digits;
        size = other.size;
        digits = new unsigned char[size];
        for (size_t i = 0; i < size; ++i) {
            digits[i] = other.digits[i];
        }
    }
    return *this;
}

Seven& Seven::operator=(Seven&& other) noexcept {
    if (this != &other) {
        delete[] digits;
        size = other.size;
        digits = other.digits;
        other.digits = nullptr;
        other.size = 0;
    }
    return *this;
}

Seven Seven::operator+(const Seven& other) const {
    size_t maxSize = std::max(size, other.size);
    Seven result(maxSize + 1);
    unsigned char carry = 0;

    for (size_t i = 0; i < maxSize; ++i) {
        unsigned char sum = carry;
        if (i < size) sum += digits[i];
        if (i < other.size) sum += other.digits[i];
        carry = sum / 7;
        result.digits[i] = sum % 7;
    }

    if (carry > 0) {
        result.digits[maxSize] = carry;
        result.size = maxSize + 1;
    } else {
        result.size = maxSize;
    }

    return result;
}

Seven Seven::operator-(const Seven& other) const {
    handle_error("Subtraction not implemented yet");
    return *this;
}

bool Seven::operator==(const Seven& other) const {
    if (size != other.size) return false;
    for (size_t i = 0; i < size; ++i) {
        if (digits[i] != other.digits[i]) return false;
    }
    return true;
}

bool Seven::operator!=(const Seven& other) const {
    return !(*this == other);
}

bool Seven::operator<(const Seven& other) const {
    if (size != other.size) {
        return size < other.size;
    }
    for (size_t i = size; i > 0; --i) {
        if (digits[i - 1] != other.digits[i - 1]) {
            return digits[i - 1] < other.digits[i - 1];
        }
    }
    return false;
}

bool Seven::operator>(const Seven& other) const {
    return other < *this;
}

std::ostream& operator<<(std::ostream& os, const Seven& num) {
    for (size_t i = num.size; i > 0; --i) {
        os << static_cast<int>(num.digits[i - 1]);
    }
    return os;
}

bool Seven::is_valid_digit(char ch) const {
    return ch >= '0' && ch <= '6';
}

void Seven::handle_error(const char* message) const {
    std::cerr << "Error: " << message << std::endl;
}
