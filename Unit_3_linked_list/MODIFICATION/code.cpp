#include <iostream>
#include <string>
using namespace std;
struct Task
{
int id;
string name, priority, status;
Task *prev, *next;
};
Task *head = NULL, *tail = NULL;
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
n->prev = tail;
n->next = NULL;
if (head == NULL)
head = tail = n;
else {
tail->next = n;
tail = n;
}
cout << "Task Added Successfully.\n";
}
void displayForward()
{
Task *temp = head;
if (temp == NULL)
{
cout << "List is Empty.\n";
return;
}
while (temp != NULL)
{
cout << "\nID: " << temp->id;
cout << "\nName: " << temp->name;
cout << "\nPriority: " << temp->priority;
cout << "\nStatus: " << temp->status << "\n";
temp = temp->next;
}
}
void displayBackward()
{
Task *temp = tail;
if (temp == NULL) {
cout << "List is Empty.\n";
return;
}
while (temp != NULL)
{
cout << "\nID: " << temp->id;
cout << "\nName: " << temp->name;
cout << "\nStatus: " << temp->status << "\n";
temp = temp->prev;
}
}
void searchTask()
{
int id;
cout << "Enter Task ID: ";
cin >> id;
Task *temp = head;
while (temp != NULL)
{
if (temp->id == id)
{
cout << "Task Found: " << temp->name << "\n";
cout << "Priority: " << temp->priority << "\n";
cout << "Status: " << temp->status << "\n";
return;
} temp = temp->next;
}
cout << "Task Not Found.\n";
}
void deleteTask()
{
int id;
cout << "Enter Task ID to Delete: ";
cin >> id;
Task *temp = head;
while (temp != NULL && temp->id != id)
temp = temp->next;
if (temp == NULL)
{
cout << "Task Not Found.\n";
return;
}
if (temp->prev != NULL)
temp->prev->next = temp->next;
else
head = temp->next;
if (temp->next != NULL)
temp->next->prev = temp->prev;
else
tail = temp->prev;
delete temp;
cout << "Task Deleted Successfully.\n"; }
void countTasks()
{
int count = 0;
Task *temp = head;
while (temp != NULL)
{
count++;
temp = temp->next;
}
cout << "Total Tasks = " << count << "\n";
}
int main()
{
int choice;
do
{
cout << "\n--- SPACE MISSION TASK MANAGEMENT ---";
cout << "\n1. Add Task";
cout << "\n2. Display Forward";
cout << "\n3. Display Backward";
cout << "\n4. Search Task";
cout << "\n5. Delete Task";
cout << "\n6. Count Tasks";
cout << "\n7. Exit";
cout << "\nEnter Choice: ";
cin >> choice; switch (choice)
{
case 1: addTask(); break;
case 2: displayForward(); break;
case 3: displayBackward(); break;
case 4: searchTask(); break;
case 5: deleteTask(); break;
case 6: countTasks(); break;
case 7: cout << "Program Ended.\n"; break;
default: cout << "Invalid Choice.\n";
}
} while (choice != 7);
return 0;
}
