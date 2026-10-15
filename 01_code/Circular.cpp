#include <iostream>
#include <string>
using namespace std;

struct Task
{
    int id;
    string name, priority, status;
    Task *next;
};

Task *head = NULL;

void addTask()
{
    Task *n = new Task;

    cout << "Enter Task ID: ";
    cin >> n->id;
    cin.ignore();

    cout << "Enter Task Name: ";
    getline(cin, n->name);

    cout << "Enter Priority: ";
    getline(cin, n->priority);

    cout << "Enter Status: ";
    getline(cin, n->status);

    if (head == NULL)
    {
        head = n;
        n->next = head;
    }
    else
    {
        Task *temp = head;

        while (temp->next != head)
            temp = temp->next;

        temp->next = n;
        n->next = head;
    }

    cout << "Task Added Successfully.\n";
}

void displayTasks()
{
    if (head == NULL)
    {
        cout << "List is Empty.\n";
        return;
    }

    Task *temp = head;

    do
    {
        cout << "\nID: " << temp->id;
        cout << "\nName: " << temp->name;
        cout << "\nPriority: " << temp->priority;
        cout << "\nStatus: " << temp->status << "\n";

        temp = temp->next;
    } while (temp != head);
}

void searchTask()
{
    if (head == NULL)
    {
        cout << "List is Empty.\n";
        return;
    }

    int id;
    cout << "Enter Task ID: ";
    cin >> id;

    Task *temp = head;

    do
    {
        if (temp->id == id)
        {
            cout << "Task Found: " << temp->name << "\n";
            cout << "Priority: " << temp->priority << "\n";
            cout << "Status: " << temp->status << "\n";
            return;
        }

        temp = temp->next;
    } while (temp != head);

    cout << "Task Not Found.\n";
}

void deleteTask()
{
    if (head == NULL)
    {
        cout << "List is Empty.\n";
        return;
    }

    int id;
    cout << "Enter Task ID to Delete: ";
    cin >> id;

    Task *curr = head;
    Task *prev = NULL;

    do
    {
        if (curr->id == id)
        {
            if (curr->next == curr)
            {
                head = NULL;
            }
            else
            {
                if (curr == head)
                {
                    Task *last = head;

                    while (last->next != head)
                        last = last->next;

                    head = head->next;
                    last->next = head;
                }
                else
                {
                    prev->next = curr->next;
                }
            }

            delete curr;
            cout << "Task Deleted Successfully.\n";
            return;
        }

        prev = curr;
        curr = curr->next;

    } while (curr != head);

    cout << "Task Not Found.\n";
}

void countTasks()
{
    if (head == NULL)
    {
        cout << "Total Tasks = 0\n";
        return;
    }

    int count = 0;
    Task *temp = head;

    do
    {
        count++;
        temp = temp->next;
    } while (temp != head);

    cout << "Total Tasks = " << count << "\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n--- SPACE MISSION TASK MANAGEMENT ---";
        cout << "\n1. Add Task";
        cout << "\n2. Display Tasks";
        cout << "\n3. Search Task";
        cout << "\n4. Delete Task";
        cout << "\n5. Count Tasks";
        cout << "\n6. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1: addTask(); break;
            case 2: displayTasks(); break;
            case 3: searchTask(); break;
            case 4: deleteTask(); break;
            case 5: countTasks(); break;
            case 6: cout << "Program Ended.\n"; break;
            default: cout << "Invalid Choice.\n";
        }

    } while (choice != 6);

    return 0;
}
