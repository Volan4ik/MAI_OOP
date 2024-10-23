#ifndef SIMPLE_VECTOR_H
#define SIMPLE_VECTOR_H

template <typename T>
class SimpleVector {
public:
    SimpleVector();
    ~SimpleVector();

    void PushBack(T value);        
    void PopBack();                 
    void Erase(size_t index);       
    T& operator[](size_t index);    
    size_t Size() const;            

private:
    T* data;      
    size_t size;                   
    size_t capacity;               

    void Resize(size_t newCapacity);  
};

#endif
