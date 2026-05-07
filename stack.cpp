#include "stack.h"
#include <iostream>
#include <fstream>
using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using std::ifstream;

stack_darray::stack_darray()
{
    arr = NULL;
    size = 0;
    top = -1;
}

stack_darray::stack_darray(int n)
{
    arr = new int[n];
    size = n;
    top = -1;
}

stack_darray::~stack_darray()
{
    delete [] arr;
}

void stack_darray::resize(int nsize)
{
    int * new_arr = new int[nsize];
    int limit = top;
    for(int i = 0; i <= limit; i++)
    {
        new_arr[i] = arr[i];
    }
    
    delete [] arr;

    arr = new_arr;
    size = nsize;
}

void stack_darray::push(int num)
{
    if(top == (size - 1))
    {
        resize(++size);
    }
    top++;
    arr[top] = num;
}

int stack_darray::pop()
{
    if(top == -1)
    {
        cout << "Stack is empty." << endl;
        return 0;
    }
    return arr[top--];
}

void stack_darray::print()
{
    int temp = top;
    while(temp != -1)
    {
        cout << "[ " << arr[temp] << " ]";
        cout << endl;
        temp--;
    }
}

bool stack_darray::isEmpty()
{
    if(top == -1)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

void stack_darray::saveToFile(const string& filename)
{
    ofstream out(filename); // overwrite
    for(int i = 0; i <= top; i++)
    {
        out << arr[i] << endl;
    }
}

void stack_darray::loadFromFile(const string& filename)
{
    ifstream in(filename);
    int value;
    while(in >> value)
    {
        push(value);
    }
}
