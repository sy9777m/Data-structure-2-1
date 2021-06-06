#pragma once
#include <iostream>

#define INF 9999

// 다른 식으로 singly linked list를 구현해봅시다.

class node {
    private:
        int weight;
        int v1;
        int v2;
        node* next;

    public:
        node(int val = INF, int vx1 = -1, int vx2 = -1){
            weight = val;
            v1 = vx1;
            v2 = vx2;
            next = nullptr;
        }
        ~node(){}

        node* getLink(){ return next; }
        int getWeight(){ return weight; }
        int getSource(){ return v1; }
        int getTarget(){ return v2; }

        void setLink(node* target){ next = target; }
       
        void insertNext(node *newnode){
            if(newnode != nullptr) {
                newnode->next = next;
                next = newnode;
            }
        } // 노드의 다음 자리에 새 노드를 넣는 연산

        node* removeNext() {
            node* removed = next;
            if(removed != nullptr)
                next = removed->next;
            return removed;
        } // 노드의 다음 자리 노드를 지우는 연산
}; 

class o_linked_list{
    protected:
        node origin;
        
    public:
        o_linked_list(){} //생성자
        ~o_linked_list(){ clear(); } //소멸자

        void clear(){
            while(!isEmpty()){
                origin.removeNext();
            }
        } // 리스트를 지우는 연산
        
        bool isEmpty(){
            return getHead() == nullptr;
        } // 공백 확인

        node* getHead(){
            return origin.getLink();
        } // 첫 노드를 부르는 연산        

        void removeHead(){
            origin.removeNext();
        } // 첫 노드를 부르는 연산  

        void orderedInsert(node *n){
            int w = n->getWeight();
            node* prev = &origin;
            node* now = getHead();
            while(now != nullptr){
                int now_w = now->getWeight();
                if(now_w >= w){
                    prev->insertNext(n);
                    return;
                }
                prev = now;
                now = now->getLink();                    
            }
            prev->insertNext(n);
        } // 삽입연산
        
        size_t size(){
            int count = 0;
            for(node *p = getHead(); p != nullptr ; p = p->getLink()){
                count++;
            }
            return count;
        } // 사이즈 구하기        

        void display(){
            std::cout << "전체 항목의 수: " << size() << "\n";
            for(node *p = getHead(); p != nullptr ; p = p->getLink()){
                std::cout << p->getWeight() << " " << p->getSource() << " " << p->getTarget() << "\n";
            }
        } // Linked List의 전체 내용 출력
        
};






