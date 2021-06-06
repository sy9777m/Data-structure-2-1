#pragma once
#include <iostream>
#include "Student.h"

#define MAX_STACK_SIZE 100

inline int error(const char* str) {
    std::cerr << str << "\n";
    exit(1);
}

class StudentStack{
    private:
        Student data[MAX_STACK_SIZE];
        int top;
    public:
        StudentStack() {
            top = -1;
        }
        ~StudentStack() {}

        bool isEmpty() {return top == -1;}
        bool isFull() {return top == MAX_STACK_SIZE - 1;}
        void push(Student e) {
            if (isFull()) {
                error("stack is full");
            }

            data[++top] = e;
        }

        Student pop() {
            if (isEmpty()) {
                error("stack is empty");
            }

            return data[top--];
        }

        Student peek() {
            if (isEmpty()) {
                error("stack is empty");
            }

            return data[top];
        }

        void display() {
            std::cout << "number of stack: " << top + 1 << "\n";
            for (int i = 0; i < top + 1; i++) {
                std::cout << " < " << data[i].contents() << ">";
            }
            std::cout << "\n";
        }
};