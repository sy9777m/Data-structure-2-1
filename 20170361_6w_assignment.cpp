#include <iostream>
#include <deque>
#include <stack>
#include <fstream>
#include <iostream>
#include <string>

inline void error(const char* str) {
    std::cerr << str << "\n";
    exit(1);
}

bool StackCheckMatching(const char* filename){
    std::ifstream is(filename);
    if(!is.is_open()){
        error("error: opening file is failed.\n");
    }
    int nLine = 1;
    int nChar = 0;
    std::stack<char> stack;
    char ch;

    while(is.get(ch)){
        if(ch == '\n') { nLine++; }

        nChar++;

        if(ch == '[' || ch == '(' || ch == '{')
            stack.push(ch);

        else if(ch == ']' || ch == ')' || ch == '}') {
            char prev = stack.top();
            stack.pop();
            if((ch == ']' && prev != '[') ||  (ch == ')' && prev != '(') ||  (ch == '}' && prev != '{')){
                stack.push(prev);
                break;
            }
        }
    }
    is.close();
    std::cout << filename << "result: \n";
    
    if(!stack.empty()){
        std::cout << "Error is occured. Total lines: " << nLine << ", total characters: " << nChar << ")\n";
    }
    else{
        std::cout << "Success! Total lines: " << nLine << ", total characters:" << nChar << ")\n";
    }
    return stack.empty();
}


bool DequeCheckMatching(const char* filename){
    std::ifstream is(filename);
    if(!is.is_open()){
        error("error: opening file is failed.\n");
    }
    int nLine = 1;
    int nChar = 0;
    std::deque<char> que;
    char ch;

    while(is.get(ch)){
        if(ch == '\n') { nLine++; }

        nChar++;

        if(ch == '[' || ch == '(' || ch == '{')
            que.push_front(ch);

        else if(ch == ']' || ch == ')' || ch == '}') {
            char prev = que.front();
            que.pop_front();
            if((ch == ']' && prev != '[') ||  (ch == ')' && prev != '(') ||  (ch == '}' && prev != '{')){
                que.push_front(prev);
                break;
            }
        }
    }
    is.close();
    std::cout << filename << " result: \n";
    
    if(!que.empty()){
        std::cout << "Error is occured. Total lines: " << nLine << ", total characters: " << nChar << ")\n";
    }
    else{
        std::cout << "Success! Total lines: " << nLine << ", total characters:" << nChar << ")\n";
    }
    return que.empty();
}


int main(){
    StackCheckMatching("includes/ArrayStack.h");
    StackCheckMatching("blackboard.cpp");

    DequeCheckMatching("includes/ArrayStack.h");
    DequeCheckMatching("blackboard.cpp");

    return 0;
}