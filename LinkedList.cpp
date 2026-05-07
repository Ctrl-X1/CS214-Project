#include "LinkedList.h"

LinkedList::LinkedList()
{
    p = NULL;

}


void LinkedList::saveToFile()
{
    ofstream fout("linkedlist.txt", ios::out);

    node* temp = p;

    while (temp != NULL)
    {
        fout << temp->data << " ";

        temp = temp->link;
    }

    fout.close();
}


void LinkedList::loadFromFile()
{
    ifstream fin("linkedlist.txt");

    int num;

    while (fin >> num)
    {
        appendWithoutSaving(num);
    }

    fin.close();
}


void LinkedList::appendWithoutSaving(int num)
{
    node *temp, *r;

    if (p == NULL)
    {
        temp = new node;

        temp->data = num;
        temp->link = NULL;

        p = temp;
    }
    else
    {
        temp = p;

        while (temp->link != NULL)
        {
            temp = temp->link;
        }

        r = new node;

        r->data = num;
        r->link = NULL;

        temp->link = r;
    }
}


void LinkedList::append(int num)
{
    appendWithoutSaving(num);

}

void LinkedList::addAtBeg(int num)
{
    node* temp;

    temp = new node;

    temp->data = num;
    temp->link = p;

    p = temp;

}

void LinkedList::addAfter(int loc, int num)
{
    node *temp, *m;

    temp = p;

    for (int i = 0; i < loc - 1; i++)
    {
        temp = temp->link;

        if (temp == NULL)
        {
            cout << "There are less than "
                 << loc << " elements.\n";

            return;
        }
    }

    m = new node;

    m->data = num;

    m->link = temp->link;

    temp->link = m;

}


void LinkedList::del(int num)
{
    node *old, *temp;

    temp = p;

    while (temp != NULL)
    {
        if (temp->data == num)
        {
            if (temp == p)
            {
                p = temp->link;
            }
            else
            {
                old->link = temp->link;
            }

            delete temp;


            cout << "Deleted successfully.\n";

            return;
        }
        else
        {
            old = temp;
            temp = temp->link;
        }
    }

    cout << "Element not found.\n";
}



void LinkedList::display()
{
    node* temp = p;

    if (temp == NULL)
    {
        cout << "[]\n";

        return;
    }

    cout << "[";

    while (temp != NULL)
    {
        cout << temp->data;

        if (temp->link != NULL)
        {
            cout << ", ";
        }

        temp = temp->link;
    }

    cout << "]\n";
}


int LinkedList::count()
{
    int c = 0;

    node* temp = p;

    while (temp != NULL)
    {
        c++;

        temp = temp->link;
    }

    return c;
}


void LinkedList::reverse()
{
    node *q, *r, *s;

    q = p;

    r = NULL;

    while (q != NULL)
    {
        s = r;

        r = q;

        q = q->link;

        r->link = s;
    }

    p = r;

}


LinkedList::~LinkedList()
{
    node* q;

    while (p != NULL)
    {
        q = p->link;

        delete p;

        p = q;
    }
}