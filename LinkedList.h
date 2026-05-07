#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <fstream>

using namespace std;

class LinkedList
{
private:

    struct node
    {
        int data;
        node* link;
    };

    node* p;
    
    void appendWithoutSaving(int num);
    

public:

    LinkedList();

    void saveToFile();
    void loadFromFile();
    void append(int num);
    void addAtBeg(int num);
    void addAfter(int loc, int num);
    void del(int num);
    void display();
    int count();
    void reverse();

    ~LinkedList();
};

#endif