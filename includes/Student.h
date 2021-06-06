#pragma once
#include <iostream>
#include <string>

class Student{
    protected:
        int id;
        std::string name;
        std::string dept;
    public:
        Student(int i = 0, std::string nam = " ", std::string dep = " "){
            set(i, nam, dep);
        }

        void set(int i, std::string nam, std::string dep){
            id = i;
            name = nam;
            dept = dep;
        }

        void display() {
            std::cout << "id: " << id << " name: " << name << " major: " << dept << "\n";
        }

        std::string contents() {
            std::string str;
            str = "id: " + std::to_string(id) + " name: " + name + " major: " + dept;

            return str;
        }

        friend std::ostream& operator<<(std::ostream& os, Student& st);
};

std::ostream& operator<<(std::ostream& os, Student& st) {
    os << st.contents();
    return os;
}