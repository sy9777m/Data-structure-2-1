#pragma once
#include "ArrayStackTemplate.h"
#include <string>
#include <sstream>
#include <iostream>

double calcPostfixExpr() {
    char c;
    double val;
    ArrayStack<double> st;
    while (std::cin.get(c) && c != '\n') {
        if (c == '+' || c == '-' || c == '*' || c == '/') {
            double val2 = st.pop();
            double val1 = st.pop();
            switch(c) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '/': st.push(val1 / val2); break;
                case '*': st.push(val1 * val2); break;
            }

        }
        else if (c >= '0' && c <= '9') {
            std::cin.unget();
            std::cin >> val;
            st.push(val);
        }
    }
    return(st.pop());
}

double calcPostfixExpr(std::string str) {
    std::istringstream iss(str);
    char c;
    double val;
    ArrayStack<double> st;
    while (iss.get(c) && c != '\n') {
        if (c == '+' || c == '-' || c == '*' || c == '/') {
            double val2 = st.pop();
            double val1 = st.pop();
            switch(c) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '/': st.push(val1 / val2); break;
                case '*': st.push(val1 * val2); break;
            }

        }
        else if (c >= '0' && c <= '9') {
            iss.unget();
            iss >> val;
            st.push(val);
        }
    }
    return(st.pop());
}

inline int priority(char op) {
    switch(op){
        case '(': case ')': return 0;
        case '+': case '-': return 1;
        case '/': case '*': return 2;
    }
    return -1;
}

std::string infix2Postfix() {
    char c, op;
    double val;
    std::ostringstream oss;
    ArrayStack<char> st;
    while (std::cin.get(c) && c != '\n') {
        if (c >= '0' && c <= '9') {
            std::cin.unget();
            std::cin >> val;
            oss << val << " ";
        }

        else if (c == '(') {
            st.push(c);
        }

        else if (c == ')') {
            while(!st.isEmpty()) {
                op = st.pop();
                if (op == '(') break;
                else oss << op << " ";
            }
        }

        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while(!st.isEmpty()) {
                op = st.peek();
                if(priority(c) <= priority(op)) {
                    oss << op << " ";
                    st.pop();
                }
                else break;
            }
            st.push(c);
        }
    }

    while(!st.isEmpty()) {
        op = st.peek();
        oss << st.pop() << " ";
    }

    return oss.str();
}


std::string infix2Postfix(std::string istr) {
    char c, op;
    double val;
    std::ostringstream oss;
    std::istringstream iss(istr);
    ArrayStack<char> st;
    while (iss.get(c) && c != '\n') {
        if (c >= '0' && c <= '9') {
            iss.unget();
            iss >> val;
            oss << val << " ";
        }

        else if (c == '(') {
            st.push(c);
        }

        else if (c == ')') {
            while(!st.isEmpty()) {
                op = st.pop();
                if (op == '(') break;
                else oss << op << " ";
            }
        }

        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while(!st.isEmpty()) {
                op = st.peek();
                if(priority(c) <= priority(op)) {
                    oss << op << " ";
                    st.pop();
                }
                else break;
            }
            st.push(c);
        }
    }

    while(!st.isEmpty()) {
        op = st.peek();
        oss << st.pop() << " ";
    }

    return oss.str();
}