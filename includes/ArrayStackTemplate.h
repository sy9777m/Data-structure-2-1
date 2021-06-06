#pragma once
#include <iostream>

#define MAX_STACK_SIZE 100

inline int error(const char* str) {
    std::cerr << str << "\n";
    exit(1);
}

template <typename T>
class ArrayStack{
    private:
        T data[MAX_STACK_SIZE];
        int top;
    public:
        ArrayStack() {
            top = -1;
        }
        ~ArrayStack() {}

        bool isEmpty() {return top == -1;}
        bool isFull() {return top == MAX_STACK_SIZE - 1;}
        void push(T e) {
            if (isFull()) {
                error("stack is full");
            }

            data[++top] = e;
        }

        T pop() {
            if (isEmpty()) {
                error("stack is empty");
            }

            return data[top--];
        }

        T peek() {
            if (isEmpty()) {
                error("stack is empty");
            }

            return data[top];
        }

        void display() {
            std::cout << "number of stack: " << top + 1 << "\n";
            for (int i = 0; i < top + 1; i++) {
                std::cout << "<" << data[i] << ">";
            }
            std::cout << "\n";
        }
};