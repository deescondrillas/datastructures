// Act 5.1 – 29 de noviembre, 2025
// class Vector

# pragma once

template <class T>
class Vector {
public:
    // Constructor
    Vector() : data(nullptr), size(0), capacity(0) {}
    // Constructor con tamaño
    Vector(int size_){
        size = size_;
        capacity = size_;
        data = new T[size];
    };
    // Copiar
    Vector(const Vector& other){
        size = other.size;
        capacity = other.capacity;
        data = new T[capacity];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }
    // Destructor
    ~Vector(){
        delete[] data;
    }
    // Para copiar
    Vector& operator=(const Vector& other){
        if (this != &other) {
            delete[] data;

            size = other.size;
            capacity = other.capacity;
            data = new T[capacity];

            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    void resize(int newSize){
        if (newSize > capacity) {
            grow(newSize);
        }
        size = newSize;
    }

    // push back
    void pb(T& value){
        if (size == capacity) allocate();
        data[size++] = value;
    }

    // pop back
    void pop_back(){
        if (size > 0) size--;
    }

    // Retorna tamaño
    int Size() {
        return size;
    }

    // Operador []
    T& operator[](int index){
        return data[index];
    }

    const T& operator[](int index) const{
        return data[index];
    }


private:
    T* data;
    int capacity;
    int size;

    void allocate(){
        int newSize = size == 0 ? 1 : size * 2;
        grow(newSize);
    }

    void grow(int newSize_){
        int newSize = newSize_;
        T* new_data = new T[newSize];

        for (int i = 0; i < size; i++) {
            new_data[i] = data[i];
        }

        delete[] data;
        data = new_data;
        capacity = newSize;
    }
};
