#pragma once
#include "SingleLinkedList.h"

inline int error(const char* str) {
    std::cerr << str << "\n";
    exit(1);
}

class LinkedListStack : public s_linked_list {
    public:
        LinkedListStack(): s_linked_list(){};
        bool isEmpty() {return Size() == 0;}
        void push(int e) {
            push_front(e);
        }
        
        int pop() {
            if(isEmpty()) error ("stack is empty");
            return pop_front();
        }

        int peek(){
            if(isEmpty()) error ("stack is empty");
            return head -> data;
        }

        void display() {
            node* ptr = head;
            std::cout << "number of stack: " << Size() << "\n";

            for (int i = 0; i < Size(); i++) {
                std::cout << "<" << ptr -> data << ">";
                ptr = ptr -> next;
            }
            std::cout << "\n";
        }
};