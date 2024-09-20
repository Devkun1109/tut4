#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class CircularQueue {
private:
    int data[MAX_SIZE];
    int front;
    int rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % MAX_SIZE == front;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }

        if (isEmpty()) {
            front = 0;
        }

        rear = (rear + 1) % MAX_SIZE;
        data[rear] = x;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1; // Return a sentinel value to indicate failure
        }

        int x = data[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
        return x;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot peek." << endl;
            return -1; // Return a sentinel value to indicate failure
        }
        return data[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue elements: ";
        for (int i = front; i != rear; i = (i + 1) % MAX_SIZE) {
            cout << data[i] << " ";
        }
        cout << data[rear] << endl;
    }
};

int main() {
    CircularQueue q;
    int choice, x;

    while (true) {
        cout << "\nCircular Queue Operations:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to enqueue: ";
                cin >> x;
                q.enqueue(x);
                break;
            case 2:
                x = q.dequeue();
                if (x != -1) {
                    cout << "Dequeued element: " << x << endl;
                }
                break;
            case 3:
                x = q.peek();
                if (x != -1) {
                    cout << "Top element: " << x << endl;
                }
                break;
            case 4:
                q.display();
                break;
            case 5:
                exit(0);
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}