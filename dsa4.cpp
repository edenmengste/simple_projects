#include <iostream>
#include <cstring>
using namespace std;

struct student {
    char name[20];
    int age;
    student *next;
    student *previous;
};

student *start = NULL;

// Insert at beginning
void insert_begin(student *p) {
    if (start == NULL) {
        start = p;
        p->next = NULL;
        p->previous = NULL;
    } else {
        p->next = start;
        p->previous = NULL;
        start->previous = p;
        start = p;
    }
    cout << "Inserted at the beginning.\n";
}

// Insert at end
void insert_end(student *p) {
    p->next = NULL;
    if (start == NULL) {
        p->previous = NULL;
        start = p;
    } else {
        student *q = start;
        while (q->next != NULL)
            q = q->next;
        q->next = p;
        p->previous = q;
    }
    cout << "Inserted at the end.\n";
}

// Insert at middle (after position c)
void insert_mid(int c, student *p) {
    student *q = start;
    for (int i = 1; i < c && q != NULL; i++)
        q = q->next;

    if (q == NULL) {
        cout << "Less number of nodes than " << c << ".\n";
        return;
    }

    p->next = q->next;
    p->previous = q;
    if (q->next != NULL)
        q->next->previous = p;
    q->next = p;

    cout << "Inserted successfully after position " << c << ".\n";
}

// Display forward
void display() {
    student *q = start;
    int pos = 1;
    while (q != NULL) {
        cout << pos << ". Name: " << q->name << ", Age: " << q->age << endl;
        q = q->next;
        pos++;
    }
}

// Display backward
void displayBackward() {
    student *q = start;
    if (q == NULL) {
        cout << "List is empty.\n";
        return;
    }

    while (q->next != NULL)
        q = q->next;

    int pos = 1;
    while (q != NULL) {
        cout << pos << ". Name: " << q->name << ", Age: " << q->age << endl;
        q = q->previous;
        pos++;
    }
}

// Delete at beginning
void delBeg() {
    if (start == NULL) {
        cout << "List is empty.\n";
        return;
    }
    student *temp = start;
    start = start->next;
    if (start != NULL)
        start->previous = NULL;
    delete temp;
    cout << "First node deleted.\n";
}

// Delete at end
void delend() {
    if (start == NULL) {
        cout << "Empty list.\n";
        return;
    }
    if (start->next == NULL) {
        delete start;
        start = NULL;
        cout << "Last node deleted. List is now empty.\n";
        return;
    }
    student *q = start;
    while (q->next->next != NULL)
        q = q->next;
    student *temp = q->next;
    q->next = NULL;
    delete temp;
    cout << "Last node deleted.\n";
}

// Delete a particular node at position c
void delparticular(int c) {
    if (start == NULL) {
        cout << "Empty list.\n";
        return;
    }
    if (c == 1) {
        delBeg();
        return;
    }

    student *q = start;
    for (int i = 1; i < c - 1 && q != NULL; i++)
        q = q->next;

    if (q == NULL || q->next == NULL) {
        cout << "No sufficient nodes.\n";
        return;
    }

    student *temp = q->next;
    q->next = temp->next;
    if (temp->next != NULL)
        temp->next->previous = q;
    delete temp;
    cout << "Node at position " << c << " deleted.\n";
}

int main() {
    int main_choice, insert_choice, position;
    student s;

    do {
        cout << "\nMain Menu\n";
        cout << "1. Add student\n";
        cout << "2. Insert student\n";
        cout << "3. Delete student\n";
        cout << "4. Display students\n";
        cout << "0. Exit\n";
        cout << "Enter a choice: ";
        cin >> main_choice;

        switch (main_choice) {
            case 1: {
                cout << "Enter student's name: ";
                cin >> s.name;
                cout << "Enter age: ";
                cin >> s.age;
                cout << "Registered successfully.\n";
                break;
            }

            case 2: {
                cout << "Enter student info to insert → Name: ";
                cin >> s.name;
                cout << "Age: ";
                cin >> s.age;

                student *p = new student;
                strcpy(p->name, s.name);
                p->age = s.age;

                cout << "1. Insert at beginning\n";
                cout << "2. Insert at middle\n";
                cout << "3. Insert at end\n";
                cout << "0. Exit\n";
                cout << "Enter choice: ";
                cin >> insert_choice;

                switch (insert_choice) {
                    case 1: insert_begin(p); break;
                    case 2:
                        cout << "Insert after which position? ";
                        cin >> position;
                        insert_mid(position, p);
                        break;
                    case 3: insert_end(p); break;
                    default: break;
                }
                break;
            }

            case 3: {
                cout << "1. Delete at beginning\n";
                cout << "2. Delete at middle\n";
                cout << "3. Delete at end\n";
                cout << "0. Exit\n";
                cout << "Enter choice: ";
                cin >> insert_choice;

                switch (insert_choice) {
                    case 1: delBeg(); break;
                    case 2:
                        cout << "Delete which position? ";
                        cin >> position;
                        delparticular(position);
                        break;
                    case 3: delend(); break;
                    default: break;
                }
                break;
            }

            case 4: {
                cout << "1. Display forward\n";
                cout << "2. Display backward\n";
                cout << "0. Exit\n";
                cin >> insert_choice;
                if (insert_choice == 1) display();
                else if (insert_choice == 2) displayBackward();
                break;
            }
        }
    } while (main_choice != 0);

    return 0;
}
