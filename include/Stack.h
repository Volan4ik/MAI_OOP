#ifndef STACK_H
#define STACK_H

#include <memory_resource>
#include <iterator>

template <typename T, typename Allocator = std::pmr::polymorphic_allocator<T>>
class Stack {
public:
    using value_type = T;
    using allocator_type = Allocator;
    using size_type = std::size_t;

    Stack(std::pmr::memory_resource* memRes = std::pmr::get_default_resource())
        : allocator(memRes), data(nullptr), topIndex(-1), capacity(0) {}

    ~Stack() {
        allocator.deallocate(data, capacity);
    }

    void push(const T& value) {
        if (topIndex + 1 >= capacity) {
            resize(capacity == 0 ? 1 : capacity * 2);
        }
        data[++topIndex] = value;
    }

    void pop() {
        if (!empty()) {
            --topIndex;
        }
    }

    T& top() {
        return data[topIndex];
    }

    const T& top() const {
        return data[topIndex];
    }

    bool empty() const {
        return topIndex == -1;
    }

    size_type size() const {
        return topIndex + 1;
    }

    class Iterator {
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;

        Iterator(pointer ptr) : ptr(ptr) {}

        reference operator*() const { return *ptr; }
        pointer operator->() { return ptr; }
        Iterator& operator++() { ++ptr; return *this; }
        Iterator operator++(int) { Iterator tmp = *this; ++ptr; return tmp; }
        friend bool operator==(const Iterator& a, const Iterator& b) { return a.ptr == b.ptr; };
        friend bool operator!=(const Iterator& a, const Iterator& b) { return a.ptr != b.ptr; };

    private:
        pointer ptr;
    };

    Iterator begin() { return Iterator(data); }
    Iterator end() { return Iterator(data + topIndex + 1); }

private:
    void resize(size_type newCapacity) {
        T* newData = allocator.allocate(newCapacity);
        for (size_type i = 0; i <= topIndex; ++i) {
            newData[i] = std::move(data[i]);
        }
        allocator.deallocate(data, capacity);
        data = newData;
        capacity = newCapacity;
    }

    Allocator allocator;
    T* data;
    size_type topIndex;
    size_type capacity;
};

#endif // STACK_H