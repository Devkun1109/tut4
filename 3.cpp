#include <iostream>
using namespace std;

class Queue {
    int front, rear, size;
    int* arr;
    
public:
    Queue(int s) {
        front = rear = -1;
        size = s;
        arr = new int[s];
    }

    bool isFull() {
        return rear == size - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void enqueue(int value) {
        if (isFull()) return;
        if (front == -1) front = 0;
        arr[++rear] = value;
    }

    int dequeue() {
        if (isEmpty()) return -1;
        return arr[front++];
    }

    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    void resetFront() {
        front = 0;
    }

    int getSize() {
        return rear - front + 1;
    }
};

class Stack {
    int top;
    int* arr;
    int size;

public:
    Stack(int s) {
        size = s;
        arr = new int[s];
        top = -1;
    }

    bool isFull() {
        return top == size - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int value) {
        if (isFull()) return;
        arr[++top] = value;
    }

    int pop() {
        if (isEmpty()) return -1;
        return arr[top--];
    }
};

void interleaveQueue(Queue& q) {
    int size = q.getSize();
    Stack s(size / 2);

    for (int i = 0; i < size / 2; i++) {
        s.push(q.dequeue());
    }

    while (!s.isEmpty()) {
        q.enqueue(s.pop());
    }

    for (int i = 0; i < size / 2; i++) {
        q.enqueue(q.dequeue());
    }

    for (int i = 0; i < size / 2; i++) {
        s.push(q.dequeue());
    }

    while (!s.isEmpty()) {
        q.enqueue(s.pop());
        q.enqueue(q.dequeue());
    }
}

int main() {
    Queue q(6);
    q.enqueue(4);
    q.enqueue(7);
    q.enqueue(11);
    q.enqueue(20);
    q.enqueue(5);
    q.enqueue(9);

    interleaveQueue(q);

    while (!q.isEmpty()) {
        cout << q.dequeue() << " ";
    }

    return 0;
}
