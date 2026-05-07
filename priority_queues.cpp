#include "priority_queues.h"

// #define CLEAR system("clear")
// #define PAUSE                                                               \
//     do {                                                                    \
//         cout << "\nPress Enter to continue...";                             \
//         cin.ignore();                                                       \
//         cin.get();                                                          \
//     } while (0)
#define PERSISTANCE_FILE "queue_dump.txt"

priorityQueue::priorityQueue(string filename) { head = NULL; this->filename = filename; }

void priorityQueue::load_pq_from_file() {
    ifstream file(filename);
    if (!file.is_open()) {
        ofstream create(filename);
        create.close();
        return;
    }
    int data, priority;
    char comma;
    while (file >> data >> comma >> priority) {
        enqueue(data, priority);
    }
    file.close();
}

void priorityQueue::enqueue(int data, int priority) {

    node *temp, *q;
    temp = new node;
    temp->data = data;
    temp->priority = priority;

    if (head == NULL || priority > head->priority) {
        temp->link = head;
        head = temp;
    } else {
        q = head;
        while (q->link != NULL && q->link->priority >= priority)
            q = q->link;
        temp->link = q->link;
        q->link = temp;
    }
}

int priorityQueue::dequeue() {
    if (head == NULL) {
        cout << "Queue is empty" << endl;
        return NULL;
    }
    node *temp;
    int item;
    item = head->data;
    temp = head;
    head = head->link;
    delete temp;
    return item;
}

void priorityQueue::display() {
    if (head == NULL) {
        cout << "Queue is empty" << endl;
        return;
    }
    node *p = head;
    while (p != NULL) {
        cout << "(" << p->data << ", p=" << p->priority << ")";
        if (p->link != NULL)
            cout << " -> ";
        p = p->link;
    }
    cout << endl;
}

void priorityQueue::dump_to_file() {
    ofstream file(filename);
    node *p = head;
    while (p != NULL) {
        file << p->data << "," << p->priority << endl;
        p = p->link;
    }
    file.close();
}

priorityQueue::~priorityQueue() {
    if (head == NULL)
        return;
    node *temp;
    while (head != NULL) {
        temp = head;
        head = head->link;
        delete temp;
    }
}