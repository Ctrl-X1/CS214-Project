#ifndef STACK_H
#define STACK_H

#include <string>
using std::string;

class stack_darray
{
    private:
        int *arr;
        int size;
        int top;

    public:
        stack_darray();
        stack_darray(int n);
        ~stack_darray();

        void resize(int nsize);

        void push(int num);
        int pop();
        void print();
        bool isEmpty();

        void saveToFile(const string& filename);
        void loadFromFile(const string& filename);
};

#endif