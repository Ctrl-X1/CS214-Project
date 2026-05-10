#include <iostream>
#include <fstream>
#include "stack.h"
#include "LinkedList.h"
#include "priority_queues.h"
using namespace std;

#define CLEAR system("cls")
#define PAUSE system("pause")
#define PERSISTANCE_FILE "queue_dump.txt"

void SAD_menu(stack_darray &stack);
void LinkedList_menu(LinkedList &l);
void pq_menu(priorityQueue &pq);

int main()
{
    stack_darray stack;
    stack.loadFromFile("stack.txt");

    priorityQueue pq(PERSISTANCE_FILE);
    pq.load_pq_from_file();

    LinkedList list;
    list.loadFromFile();

    int choice = -1;

    while (choice != 0)
    {
        CLEAR;

        cout << "\n===== DATA STRUCTURES EMULATOR SYSTEM =====\n";
        cout << "1. Linked List Emulator." << endl;
        cout << "2. Stack Emulator." << endl;
        cout << "3. Prioriry Queue Emulator." << endl;
        cout << "0. Exit." << endl;
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            LinkedList_menu(list);
            break;
        case 2:
            SAD_menu(stack);
            break;
        case 3:
            pq_menu(pq);
            break;
        case 0:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice, enter another number.\n";
            PAUSE;
        }
    }
    
    return 0;
}

void SAD_menu(stack_darray &stack)
{
    int choice = -1;
    int data;

    while (choice != 0)
    {
        CLEAR;

        cout << "\n===== STACK EMULATOR =====\n";

        cout << "1. Push." << endl;
        cout << "2. Pop." << endl;
        cout << "3. Print." << endl;
        cout << "4. Check if empty." << endl;
        cout << "0. Back to main menu." << endl;
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            CLEAR;
            cout << "Enter a number to push: ";
            cin >> data;
            stack.push(data);
            cout << endl;
            stack.print();
            cout << endl;
            PAUSE;
            break;
        case 2:
            CLEAR;
            data = stack.pop();
            cout << "Poped value: " << data << endl;
            cout << endl;
            stack.print();
            cout << endl;
            PAUSE;
            break;
        case 3:
            CLEAR;
            cout << "Stack values: \n"
                 << endl;
            stack.print();
            cout << endl;
            PAUSE;
            break;
        case 4:
            CLEAR;
            if (stack.isEmpty())
            {
                cout << "Stack is empty." << endl;
            }
            else
            {
                cout << "Stack is not empty." << endl;
            }
            cout << endl;
            stack.print();
            cout << endl;
            PAUSE;
            break;
        case 0:
            stack.saveToFile("stack.txt");
            return;
        default:
            cout << "Invalid choice, enter another number.";
            PAUSE;
        }
    }
}

void LinkedList_menu(LinkedList &l)
{

    int choice, num, loc;

    do
    {
        CLEAR;
        cout << "\n===== LINKED LIST EMULATOR =====\n";

        cout << "1. Append\n";
        cout << "2. Add at Beginning\n";
        cout << "3. Add After Position\n";
        cout << "4. Delete\n";
        cout << "5. Display\n";
        cout << "6. Count\n";
        cout << "7. Reverse\n";
        cout << "0. Back to main menu\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:

            CLEAR;
            cout << ">> Action: APPEND OPERATION\n";
            cout << "Enter number: ";
            cin >> num;

            l.append(num);

            cout << "\n[ Current Visual State ]\n";
            l.display();
            cout << endl;
            PAUSE;
            break;

        case 2:
            CLEAR;
            cout << ">> Action: ADD AT BEGINNING\n";
            cout << "Enter number: ";
            cin >> num;

            l.addAtBeg(num);

            cout << "\n[ Current Visual State ]\n";
            l.display();
            cout << endl;
            PAUSE;
            break;

        case 3:
            CLEAR;
            cout << ">> Action: ADD AFTER POSITION\n";
            cout << "Enter location: ";
            cin >> loc;

            cout << "Enter number: ";
            cin >> num;

            l.addAfter(loc, num);
            
            cout << "\n[ Current Visual State ]\n";
            l.display();
            cout << endl;
            PAUSE;
            break;

        case 4:
            CLEAR;
            cout << ">> Action: DELETE OPERATION\n";
            cout << "Enter number to delete: ";
            cin >> num;

            l.del(num);

            cout << "\n[ Current Visual State ]\n";
            l.display();
            cout << endl;
            PAUSE;
            break;
        case 5:

            CLEAR;
            cout << ">> Action: MANUAL DISPLAY\n\n";
            l.display();
            cout << endl;
            PAUSE;
            break;

        case 6:

            CLEAR;
            cout << ">> Action: COUNT NODES\n";
            cout << "Total Nodes = "
                 << l.count() << endl << endl;

            cout << "[ Current Visual State ]\n";
            l.display(); 
            cout << endl;
            PAUSE;
            break;

        case 7:

            CLEAR;
            cout << ">> Action: REVERSE LIST\n";
            l.reverse();
            cout << "List reversed successfully.\n";
            
            cout << "\n[ Current Visual State ]\n";
            l.display();
            cout << endl;
            PAUSE;
            break;

        case 0:
            l.saveToFile();
            break;

        default:
            cout << "Invalid choice.\n";
            PAUSE;
        }

    } while (choice != 0);
}

void pq_menu(priorityQueue &pq)
{
    int choice = -1;
    int data, priority;

    while (choice != 0)
    {
        CLEAR;

        cout << "\n===== PQUEUE EMULATOR =====\n";

        cout << "1. Enqueue." << endl;
        cout << "2. Dequeue." << endl;
        cout << "3. Display." << endl;
        cout << "0. Back to main menu." << endl;
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            CLEAR;
            cout << ">> Action: ENQUEUE OPERATION\n";
            cout << "Enter data: ";
            cin >> data;
            cout << "Enter priority: ";
            cin >> priority;
            pq.enqueue(data, priority);

            cout << "\n[ Current Visual State ]\n";
            pq.display();
            cout << endl;
            PAUSE;
            break;
        case 2:
            CLEAR;
            cout << ">> Action: DEQUEUE OPERATION\n";
            data = pq.dequeue();

            if (data != 0)
            {
                cout << ">> Result: Dequeued value: " << data << "\n\n";
                cout << "[ Current Visual State ]\n";
                pq.display();
                cout << endl;
            }
            PAUSE;
            break;
        case 3:
            CLEAR;
            cout << ">> Action: MANUAL DISPLAY\n\n";
            pq.display();
            cout << endl;
            PAUSE;
            break;
        case 0:
            pq.dump_to_file();
            return;
        default:
            cout << "Invalid choice, enter another number." << endl;
            PAUSE;
        }
    }
}