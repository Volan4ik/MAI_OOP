#ifndef SEVEN_H
#define SEVEN_H

#include <string>
#include <iostream>

class Seven {
public:
    Seven();
    Seven(const size_t size);
    Seven(const std::string& str);
    Seven(const Seven& other);
    Seven(Seven&& other) noexcept;
    ~Seven();

    const size_t getSize() const{
        return size;
    }

    Seven& operator=(const Seven& other);
    Seven& operator=(Seven&& other) noexcept;

    Seven operator+(const Seven& other) const;
    Seven operator-(const Seven& other) const;
    bool operator==(const Seven& other) const;
    bool operator!=(const Seven& other) const;
    bool operator<(const Seven& other) const;
    bool operator>(const Seven& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Seven& num);

private:
    unsigned char* digits;
    size_t size;

    bool is_valid_digit(char ch) const;
    void handle_error(const char* message) const;
};

#endif
