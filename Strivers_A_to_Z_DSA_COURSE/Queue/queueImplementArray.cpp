#include <bits/stdc++.h>
using namespace std;

class MyQueue {
    int* queue;
    int capacity;
    int size;
    int frontIndex;
    int rearIndex;

public:
    MyQueue(int capacity) {
        this->capacity = capacity;
        queue = new int[capacity];
        size = 0;
        frontIndex = 0;
        rearIndex = -1;
    }

    ~MyQueue() {
        delete[] queue;
    }

    bool isFull() {
        return size == capacity;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full" << endl;
            return;
        }
        rearIndex = rearIndex + 1;
        queue[rearIndex] = value;
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        frontIndex = frontIndex + 1;
        size--;
    }

    int front() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1; 
        }
        return queue[frontIndex];
    }

    int rear() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1; 
        }
        return queue[rearIndex];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = 0; i < size; i++) {
            cout << queue[frontIndex + i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MyQueue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();
    cout << "Front element: " << q.front() << endl;
    cout << "Rear element: " << q.rear() << endl;
    q.dequeue();
    q.dequeue();
    q.enqueue(60);
    q.display();
    cout << "Front element: " << q.front() << endl;
    cout << "Rear element: " << q.rear() << endl;

    return 0;
}
