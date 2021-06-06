#pragma once
#include <iostream>
#include "BinaryNode.h"
#include "CircularQueue.h" // 레벨 순회용

class BinaryTree{
    protected:
        BinaryNode* root;
        // 트리의 순회연산 (2주차)

    public:
        BinaryTree(): root(nullptr){}
        ~BinaryTree(){}

        void setRoot(BinaryNode* node){
            root = node;
        }
        BinaryNode* getRoot(){
            return root;
        }
        bool isEmpty() {
            return root==nullptr;
        }

        void inorder(BinaryNode *node){
            if(node != nullptr){
                if(node->getLeft() != nullptr){
                    inorder(node->getLeft());
                }
                std::cout << " [" << node->getData() << "] ";
                if(node->getRight()!= nullptr){
                    inorder(node->getRight());
                }
            }
        }       
        void inorder(){
            std::cout << "inorder: ";
            inorder(root);
            std::cout << "\n";            
        }        
        void preorder(BinaryNode *node){
            if(node != nullptr){
                std::cout << " [" << node->getData() << "] ";
                if(node->getLeft() != nullptr){
                    preorder(node->getLeft());
                }
                if(node->getRight()!= nullptr){
                    preorder(node->getRight());
                }                
            }
        }

        void postorder(BinaryNode *node) {
            if(node != nullptr){
                if(node->getLeft() != nullptr){
                    postorder(node->getLeft());
                }
                if(node->getRight()!= nullptr){
                    postorder(node->getRight());
                }
                std::cout << " [" << node->getData() << "] ";
            }
        }

        void preorder(){
            std::cout << "preorder: ";
            preorder(root);
            std::cout << "\n";
        }
        void postorder(){
            std::cout << "postorder: ";
            postorder(root);
            std::cout << "\n";
        }
        
        void levelorder(){
            std::cout << "levelorder: ";
            if(!isEmpty()){
                CircularQueue q;
                q.enqueue(root);
                while (!q.isEmpty()){
                    BinaryNode* n = q.dequeue();
                    if(n != nullptr){
                        std::cout << " [" << n->getData() << "] ";
                        q.enqueue(n->getLeft ());
                        q.enqueue(n->getRight());
                    }
                }
            }
            std::cout << "\n";
        }

        int getCount(){
            return isEmpty() ? 0 : getCount(root);
        }
        
        int getCount(BinaryNode *node){
            if(node == nullptr){
                return 0;
            }
            return 1 + getCount(node->getLeft()) + getCount(node->getRight());
        }
        int	getLeafCount(){
            return isEmpty() ? 0 : getLeafCount(root);
        }
        int getLeafCount(BinaryNode *node) {
            if(node == nullptr){
                return 0;
            }
            if(node->isLeaf()){
                return 1;
            }
            else return getLeafCount(node->getLeft()) + getLeafCount(node->getRight());
        }
        int	getHeight(){
            return isEmpty() ? 0 : getHeight(root);
        }
        int getHeight(BinaryNode *node) {
            if(node == nullptr){
                return 0;
            }
            int hLeft  = getHeight(node->getLeft());
            int hRight = getHeight(node->getRight());
            return (hLeft>hRight) ? hLeft+1 : hRight+1;
        }
        
        int calcSize(){
            return calcSize(root);
        }
        int calcSize(BinaryNode *node){
            if(node == nullptr){
                return 0;
            }
            return node->getData() + calcSize(node->getLeft()) + calcSize(node->getRight());
        }

        int evaluate(){ // 수식 계산 함수
            return evaluate(root);
        }
        int evaluate(BinaryNode *node){
            if(node == nullptr){
                return 0;
            }
            if(node->isLeaf()) return node->getData();
            else {
                int op1 = evaluate(node->getLeft());
                int op2 = evaluate(node->getRight());
                switch(node->getData()){
                    case '+': return op1+op2;
                    case '-': return op1-op2;
                    case '*': return op1*op2;
                    case '/': return op1/op2;
                }
                return 0;
            }
        }



};