//QueueA.h
#pragma once
#if !defined QUEUE_ARRAY_H
#define QUEUE_ARRAY_H

template <class T>
class QueueA {
private:
    int back;
    int front;
    int currentSize;
    T items;
    int capacity;
    void resize();
public:
    QueueA();
    ~QueueA();

    void enqueue(T* item);
    void dequeue();
    T* peek();

    int size();
    bool isEmpty();
};

template<class T>
inline void QueueA<T>::resize() {
    T newArray = new T * [capacity * 2];
    int j = front;
    for (int i = 0; i < capacity; i++) {
        newArray[i] = items[j];
        j++;
        if (j == capacity) j = 0;
    }
    delete[] items;
    items = newArray;
    //Some assignments for front and back
    front = 0;
    back = capacity - 1;
    capacity = 2;
}

template<class T>
inline QueueA<T>::QueueA() {
    capacity = 2;
    front = 0;
    currentSize = 0;
    items = new T[capacity];
    back = capacity - 1;
}

template<class T>
inline QueueA<T>::~QueueA() {
    delete[] items;
}

template<class T>
inline void QueueA<T>::enqueue(T* item) {
    if (capacity == currentSize) resize();
    back++;
    if (back == capacity) back = 0;
    items[back] = item;
    currentSize++;
}

template<class T>
inline void QueueA<T>::dequeue() {
    T* item = nullptr;
    if (!isEmpty()) {
        item = items[front];
        items[front] = nullptr;
        front++;
        if (front == capacity) front = 0;
        currentSize--;
    }

}

template<class T>
inline T* QueueA<T>::peek() {
    T* item = nullptr;
    if (!isEmpty())
        item = items[front];
    return item;
}

template<class T>
inline int QueueA<T>::size() {
    return currentSize;
}

template<class T>
inline bool QueueA<T>::isEmpty() {
    return currentSize == 0;
}

#endif