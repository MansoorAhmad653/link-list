#include <iostream>
#include <cstring>
using namespace std;

#define MAXSUB 5        // Max Subjects

// Structure Declaration for Student Node
struct student
{
    string name;
    int rno;
    int mks[MAXSUB], mobt;
    float perc;         // %age
    char grad;
    student* next;      // Pointer to the next student node
};

// Function Prototypes
void readFun(student*& first);
void appFun(student*& first);
student* searchFun(student* first, int s);
void sortFun(student*& first);
void delFun(student*& first, int s);
void updFun(student* first, int s);
void dispFun(student* first);

// Function Definitions
void readFun(student*& first)
{
    int n, sum;
    cout << "Enter Number of Students to add: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        student* newNode = new student; // Dynamically allocate memory for a new student node
        cout << "Enter Data for Student: " << i + 1 << endl;

        cout << "Name: ";
        cin.ignore(30, '\n');
        getline(cin, newNode->name);

        cout << "Reg#: ";
        cin >> newNode->rno; // reg#

        sum = 0;
        cout << "Enter Marks [Max 100] of students:" << endl;
        for (int j = 0; j < MAXSUB; j++) // 5 subject marks
        {
            cout << "Enter Marks of Subject: " << j + 1 << " : ";
            cin >> newNode->mks[j];
            sum += newNode->mks[j];
        }

        newNode->mobt = sum; // marks obtained

        // %age calculation
        newNode->perc = (newNode->mobt * 100.0) / 500.0;

        // Grade Assignment
        if (newNode->perc >= 80)
            newNode->grad = 'A';
        else if (newNode->perc >= 70)
            newNode->grad = 'B';
        else if (newNode->perc >= 60)
            newNode->grad = 'C';
        else if (newNode->perc >= 50)
            newNode->grad = 'D';
        else
            newNode->grad = 'F';

        newNode->next = first; // Insert at the first of the list
        first = newNode;
    }
}

void appFun(student*& first)
{
    int sum;
    student* newNode = new student; // Dynamically allocate memory for a new student node

    cout << "Enter Data for New Student:" << endl;
    cout << "Name: ";
    cin.ignore(30, '\n');
    getline(cin, newNode->name);

    cout << "Reg#: ";
    cin >> newNode->rno;

    sum = 0;
    cout << "Enter Marks [Max 100] of students:" << endl;
    for (int j = 0; j < MAXSUB; j++)
    {
        cout << "Enter Marks of Subject: " << j + 1 << " : ";
        cin >> newNode->mks[j];
        sum += newNode->mks[j];
    }

    newNode->mobt = sum;

    // %age calculation
    newNode->perc = (newNode->mobt * 100.0) / 500.0;

    // Grade Assignment
    if (newNode->perc >= 80)
        newNode->grad = 'A';
    else if (newNode->perc >= 70)
        newNode->grad = 'B';
    else if (newNode->perc >= 60)
        newNode->grad = 'C';
    else if (newNode->perc >= 50)
        newNode->grad = 'D';
    else
        newNode->grad = 'F';

    newNode->next = first; // Insert at the first of the list
    first = newNode;
}

student* searchFun(student* first, int s)
{
    student* temp = first;
    while (temp != 0)
    {
        if (temp->rno == s)
            return temp;
        temp = temp->next;
    }
    return 0;
}

void sortFun(student*& first)
{
    if (first == 0 || first->next == 0)
        return;

    student* sorted =0;

    while (first != 0)
    {
        student* curr = first;
        first = first->next;

        if (sorted == 0 || sorted->rno > curr->rno)
        {
            curr->next = sorted;
            sorted = curr;
        }
        else
        {
            student* temp = sorted;
            while (temp->next != 0 && temp->next->rno < curr->rno)
            {
                temp = temp->next;
            }
            curr->next = temp->next;
            temp->next = curr;
        }
    }

    first = sorted;
    cout << "Data Sorted successfully..." << endl;
}

void delFun(student*& first, int s)
{
    student* temp = first, *prev = 0;
    if (temp != 0 && temp->rno == s)
    {
        first = temp->next; // Remove the first
        delete temp;
        cout << "Student deleted successfully..." << endl;
        return;
    }

    while (temp != 0 && temp->rno != s)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == 0)
    {
        cout << "Student Not found in the List, can't be deleted..." << endl;
        return;
    }

    prev->next = temp->next;
    delete temp;
    cout << "Student deleted successfully..." << endl;
}

void updFun(student* first, int s)
{
    student* temp = searchFun(first, s);
    if (temp != 0)
    {
        cout << "Old Data:\n";
        cout << "Name: " << temp->name << ", Reg#: " << temp->rno << ", Marks: ";
        for (int i = 0; i < MAXSUB; i++)
            cout << temp->mks[i] << " ";
        cout << ", Total: " << temp->mobt << ", %age: " << temp->perc << ", Grade: " << temp->grad << endl;

        int sum = 0;
        cout << "Enter New Data for Student Having Reg#: " << temp->rno << endl;
        cout << "Name: ";
        cin.ignore(30, '\n');
        getline(cin, temp->name);

        cout << "Enter Marks [Max 100] of students:" << endl;
        for (int j = 0; j < MAXSUB; j++)
        {
            cout << "Enter Marks of Subject: " << j + 1 << " : ";
            cin >> temp->mks[j];
            sum += temp->mks[j];
        }

        temp->mobt = sum;

        // %age calculation
        temp->perc = (temp->mobt * 100.0) / 500.0;

        // Grade Assignment
        if (temp->perc >= 80)
            temp->grad = 'A';
        else if (temp->perc >= 70)
            temp->grad = 'B';
        else if (temp->perc >= 60)
            temp->grad = 'C';
        else if (temp->perc >= 50)
            temp->grad = 'D';
        else
            temp->grad = 'F';

        cout << "Student's Record Updated successfully..." << endl;
    }
    else
    {
        cout << "Student Not found in the List, can't be updated..." << endl;
    }
}

void dispFun(student* first)
{
    int i = 1;
    student* temp = first;
    while (temp != 0)
    {
        cout << i++ << " - ";
        cout << temp->rno << " - " << temp->name << " - ";
        for (int j = 0; j < MAXSUB; j++)
            cout << temp->mks[j] << " - ";
        cout << temp->mobt << " - " << temp->perc << " - " << temp->grad << endl;
        temp = temp->next;
    }
}

int main() {
    //declarations
    student* first = 0;   // first of the linked list
    int sinfo;
    int choice;

    // Menu
    do {
        cout << "**** MENU ****" << endl
            << " 1. Read & Store Data " << endl
            << " 2. Append new record " << endl
            << " 3. Search a record " << endl
            << " 4. Sort Data " << endl
            << " 5. Delete a record " << endl
            << " 6. Update a record " << endl
            << " 7. Display Result Card " << endl
            << " 8. Exit " << endl;

        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            readFun(first);
            break;
        case 2:
            appFun(first);
            break;
        case 3:
            if (first != 0)
            {
                cout << "Enter Reg# of the student to be searched: ";
                cin >> sinfo;
                student* found = searchFun(first, sinfo);
                if (found == 0)
                    cout << "Student ID: " << sinfo << " not exists" << endl;
                else
                    cout << "Student ID: " << sinfo << " found" << endl;
            }
            else
                cout << "First, store data using Option-1...\n";
            break;
        case 4:
            if (first != 0)
            {
                sortFun(first);
            }
            else
                cout << "First, store data using Option-1...\n";
            break;
        case 5:
            if (first != 0)
            {
                cout << "Enter Reg# of the student to be deleted: ";
                cin >> sinfo;
                delFun(first, sinfo);
            }
            else
                cout << "First, store data using Option-1...\n";
            break;
        case 6:
            if (first != 0)
            {
                cout << "Enter Reg# of the student to be updated: ";
                cin >> sinfo;
                updFun(first, sinfo);
            }
            else
                cout << "First, store data using Option-1...\n";
            break;
        case 7:
            if (first !=0)
            {
                dispFun(first);
            }
            else
                cout << "First, store data using Option-1...\n";
            break;
        case 8:
            exit(0);
        default:
            cout << "Invalid Choice...\n";
        }
    } while (true);

    return 0;
}

