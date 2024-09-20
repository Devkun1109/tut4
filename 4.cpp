#include <iostream>
using namespace std;

class Queue {
    int front, rear, size;
    char* arr;

public:
    Queue(int s) {
        front = rear = -1;
        size = s;
        arr = new char[s];
    }

    bool isFull() {
        return rear == size - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void enqueue(char value) {
        if (isFull()) return;
        if (front == -1) front = 0;
        arr[++rear] = value;
    }

    char dequeue() {
        if (isEmpty()) return -1;
        return arr[front++];
    }

    char getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }
};

void findFirstNonRepeating(string str) {
    int freq[256] = {0};
    Queue q(str.length());

    for (int i = 0; i < str.length(); i++) {
        freq[str[i]]++;
        q.enqueue(str[i]);

        while (!q.isEmpty() && freq[q.getFront()] > 1) {
            q.dequeue();
        }

        if (q.isEmpty()) {
            cout << "-1 ";
        } else {
            cout << q.getFront() << " ";
        }
    }
}

int main() {
    string input = "aabc";
    findFirstNonRepeating(input);
    return 0;
}
