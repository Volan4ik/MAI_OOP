#include "../include/Vector.h"
#include <utility>
#include <iostream>

template <typename T>
SimpleVector<T>::SimpleVector() : data(nullptr), size(0), capacity(0) {}

template <typename T>
SimpleVector<T>::~SimpleVector() {
    delete[] data;
}

template <typename T>
void SimpleVector<T>::PushBack(T value) {
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
        // Сдвигаем элементы влево
        for (size_t i = index; i < size - 1; ++i) {
            data[i] = std::move(data[i + 1]);
        }
        --size;  // Уменьшаем размер
    }
}

template <typename T>
T& SimpleVector<T>::operator[](size_t index) {
    return data[index];
}

template <typename T>
size_t SimpleVector<T>::Size() const {
    return size;
}

template <typename T>
void SimpleVector<T>::Resize(size_t newCapacity) {
    T* newData = new T[newCapacity];
    for (size_t i = 0; i < size; ++i) {
        newData[i] = std::move(data[i]);
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
}
