// Act 4.2 – 20 de noviembre, 2025
// class queue

#pragma once

template <class T>
class Queue {
  public:
    // Constructor
    Queue(int size = 1024) {
        this->queue = new T[size]();
    }

    // Destructor
    ~Queue() {
        delete[] this->queue;
    }

    // Push
    void push(T data) {
        this->queue[back] = data;
        this->back++;
    }

    // Pop
    void pop() {
        head++;
    }

    // Front
    T front() {
        return this->queue[head];
    }

    // Empty
    bool empty() {
        return this->head == this->back;
    }

    // Size
    int size() {
        return this->back - this->head;
    }

  private:
    int head = 0;
    int back = 0;
    T *queue;
};
