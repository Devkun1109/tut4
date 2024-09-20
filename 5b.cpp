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

    int getSize() {
        return rear - front + 1;
    }
};

class StackUsingOneQueue {
    Queue q;

public:
    StackUsingOneQueue(int s) : q(s) {}

    void push(int value) {
        q.enqueue(value);
        int n = q.getSize();
        for (int i = 0; i < n - 1; i++) {
            q.enqueue(q.dequeue());
        }
    }

    int pop() {
        if (q.isEmpty()) return -1;
        return q.dequeue();
    }

    bool isEmpty() {
        return q.isEmpty();
    }
};

int main() {
    StackUsingOneQueue stack(10);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;

    return 0;
}

