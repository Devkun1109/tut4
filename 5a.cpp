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

class StackUsingTwoQueues {
    Queue q1, q2;

public:
    StackUsingTwoQueues(int s) : q1(s), q2(s) {}

    void push(int value) {
        q2.enqueue(value);
        while (!q1.isEmpty()) {
            q2.enqueue(q1.dequeue());
        }

        Queue temp = q1;
        q1 = q2;
        q2 = temp;
    }

    int pop() {
        if (q1.isEmpty()) return -1;
        return q1.dequeue();
    }

    bool isEmpty() {
        return q1.isEmpty();
    }
};

int main() {
    StackUsingTwoQueues stack(10);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;

    return 0;
}
