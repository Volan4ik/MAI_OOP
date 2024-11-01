#ifndef SIMPLE_VECTOR_H
#define SIMPLE_VECTOR_H

#include <memory>
#include <utility>

template <typename T>
class SimpleVector {
public:
    SimpleVector();                              
    SimpleVector(const SimpleVector& other);     
    SimpleVector& operator=(const SimpleVector& other);  
    SimpleVector(SimpleVector&& other) noexcept; 
    SimpleVector& operator=(SimpleVector&& other) noexcept; 
    ~SimpleVector();                             

    void PushBack(const T& value);               
    void PopBack();                              
    void Erase(size_t index);                    
    T& operator[](size_t index);                 
    const T& operator[](size_t index) const;     
    size_t Size() const;                         
    size_t Capacity() const;                     

private:
    std::unique_ptr<T[]> data;    
    size_t size;                  
    size_t capacity;              

    void Resize(size_t newCapacity);             
};

#endif
