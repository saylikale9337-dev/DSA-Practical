#include <iostream>
using namespace std;

struct Task
{
    int taskID;
    string taskName;
    string priority;
    string status;
    Task *next;
};

Task *head = NULL;

// Add Task
void addTask()
{
    Task *newTask = new Task();

    cout << "\nEnter Task ID: ";
    cin >> newTask->taskID;

    cin.ignore();

    cout << "Enter Task Name: ";
    getline(cin, newTask->taskName);

    cout << "Enter Priority (High/Medium/Low): ";
    getline(cin, newTask->priority);

    cout << "Enter Status (Pending/In Progress/Completed): ";
    getline(cin, newTask->status);

    newTask->next = NULL;

    if(head == NULL)
    {
        head = newTask;
    }
    else
    {
        Task *temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newTask;
    }

    cout << "\nTask Added Successfully.\n";
}

// Display Tasks
void displayTasks()
{
    if(head == NULL)
    {
        cout << "\nNo Tasks Available.\n";
        return;
    }

    Task *temp = head;

    cout << "\nMission Tasks:\n";

    while(temp != NULL)
    {
        cout << "\nTask ID : " << temp->taskID;
        cout << "\nTask Name : " << temp->taskName;
        cout << "\nPriority : " << temp->priority;
        cout << "\nStatus : " << temp->status;
        cout << "\n----------------------";

        temp = temp->next;
    }
}

// Search Task
void searchTask()
{
    int id;

    cout << "\nEnter Task ID to Search: ";
    cin >> id;

    Task *temp = head;

    while(temp != NULL)
    {
        if(temp->taskID == id)
        {
            cout << "\nTask Found";
            cout << "\nTask Name : " << temp->taskName;
            cout << "\nPriority : " << temp->priority;
            cout << "\nStatus : " << temp->status;
            return;
        }
        temp = temp->next;
    }

    cout << "\nTask Not Found.";
}

// Delete Task
void deleteTask()
{
    int id;

    cout << "\nEnter Task ID to Delete: ";
    cin >> id;

    if(head == NULL)
    {
        cout << "\nList Empty.";
        return;
    }

    if(head->taskID == id)
    {
        Task *temp = head;
        head = head->next;
        delete temp;

        cout << "\nTask Deleted.";
        return;
    }

    Task *current = head;

    while(current->next != NULL &&
          current->next->taskID != id)
    {
        current = current->next;
    }

    if(current->next == NULL)
    {
        cout << "\nTask Not Found.";
        return;
    }

    Task *temp = current->next;
    current->next = temp->next;

    delete temp;

    cout << "\nTask Deleted Successfully.";
}

// Update Status
void updateStatus()
{
    int id;

    cout << "\nEnter Task ID: ";
    cin >> id;

    cin.ignore();

    Task *temp = head;

    while(temp != NULL)
    {
        if(temp->taskID == id)
        {
            cout << "Enter New Status: ";
            getline(cin,temp->status);

            cout << "\nStatus Updated.";
            return;
        }

        temp = temp->next;
    }

    cout << "\nTask Not Found.";
}

// Count Tasks
void countTasks()
{
    int count = 0;

    Task *temp = head;

    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    cout << "\nTotal Tasks = " << count;
}

// Main Function
int main()
{
    int choice;

    do
    {
        cout << "\n\n===== SPACE MISSION TASK MANAGEMENT =====";
        cout << "\n1. Add Task";
        cout << "\n2. Display Tasks";
        cout << "\n3. Search Task";
        cout << "\n4. Delete Task";
        cout << "\n5. Update Task Status";
        cout << "\n6. Count Tasks";
        cout << "\n7. Exit";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                addTask();
                break;

            case 2:
                displayTasks();
                break;

            case 3:
                searchTask();
                break;

            case 4:
                deleteTask();
                break;

            case 5:
                updateStatus();
                break;

            case 6:
                countTasks();
                break;

            case 7:
                cout << "\nProgram Ended.";
                break;

            default:
                cout << "\nInvalid Choice.";
        }

    } while(choice != 7);

    return 0;
}
