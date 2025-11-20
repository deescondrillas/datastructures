// Act 4.2 – 20 de noviembre, 2025

// A01739410 – Franco De Escondrillas Vazquez
// A01739522 – Sergio Sebastian Cortez Yepez
// A01739190 – Carlos Arturo Ferat Torres

#pragma once

template <class T>
class List {
    public:
    //Constructor
    List(int size = 1024) {
        this->elements = new T[size]();
    }

    //Destructor
    ~List() {
        delete[] this->elements;
    }

    //Push
    void push(T data) {
        this->elements[back++] = data;
    }

    //Front
    T idx(int i) {
        return this->elements[i];
    }

    //Size
    int size() {
        return this->back - this->head;
    }

    private:
        int head = 0;
        int back = 0;
        T *elements;
};
