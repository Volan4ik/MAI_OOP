#include "../include/Vector.h"
#include <iostream>

template <typename T>
SimpleVector<T>::SimpleVector() : data(nullptr), size(0), capacity(0) {}

template <typename T>
SimpleVector<T>::SimpleVector(const SimpleVector& other)
    : data(new T[other.capacity]), size(other.size), capacity(other.capacity) {
    for (size_t i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

template <typename T>
SimpleVector<T>& SimpleVector<T>::operator=(const SimpleVector& other) {
    if (this == &other) return *this;
    data.reset(new T[other.capacity]);
    size = other.size;
    capacity = other.capacity;
    for (size_t i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
    return *this;
}

template <typename T>
SimpleVector<T>::SimpleVector(SimpleVector&& other) noexcept
    : data(std::move(other.data)), size(other.size), capacity(other.capacity) {
    other.size = 0;
    other.capacity = 0;
}

template <typename T>
SimpleVector<T>& SimpleVector<T>::operator=(SimpleVector&& other) noexcept {
    if (this != &other) {
        data = std::move(other.data);
        size = other.size;
        capacity = other.capacity;
        other.size = 0;
        other.capacity = 0;
    }
    return *this;
}

template <typename T>
SimpleVector<T>::~SimpleVector() = default;

template <typename T>
void SimpleVector<T>::PushBack(const T& value) {
    if (size == capacity) {
        Resize(capacity == 0 ? 1 : capacity * 2);
    }
    data[size++] = value;
}

template <typename T>
void SimpleVector<T>::PopBack() {
    if (size > 0) {
        --size;
    }
}

template <typename T>
void SimpleVector<T>::Erase(size_t index) {
    if (index < size) {
        for (size_t i = index; i < size - 1; ++i) {
            data[i] = std::move(data[i + 1]);
        }
        --size;
    }
}

template <typename T>
T& SimpleVector<T>::operator[](size_t index) {
    return data[index];
}

template <typename T>
const T& SimpleVector<T>::operator[](size_t index) const {
    return data[index];
}

template <typename T>
size_t SimpleVector<T>::Size() const {
    return size;
}

template <typename T>
size_t SimpleVector<T>::Capacity() const {
    return capacity;
}

template <typename T>
void SimpleVector<T>::Resize(size_t newCapacity) {
    std::unique_ptr<T[]> newData(new T[newCapacity]);
    for (size_t i = 0; i < size; ++i) {
        newData[i] = std::move(data[i]);
    }
    data = std::move(newData);
    capacity = newCapacity;
}
