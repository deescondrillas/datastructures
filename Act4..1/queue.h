// Act 4.1 – 08 de noviembre, 2025
// Clase Queue

#pragma once

template <class T>
class Queue {
  public:
    //Constructor
    Queue(int size = 1024){
        queue = new T[size]();
    }

    //Destructor
    ~Queue(){
        delete[] queue;
    }

    //Push
    void push(T data){
        queue[back] = data;
        back++;
    }

    //Pop
    void pop(){
        head++;
    }

    //Front
    T front(){
        return queue[head];
    }

    //Empty
    bool empty(){
        return head == back;
    }

    //Size
    int size(){
        return back - head;
    }

  private:
    int head = 0;
    int back = 0;
    T *queue;
};
