#include <iostream>
#include <cstring>
using namespace std;

struct student{
    char name[20];
    int age;
    struct student *next;
    struct student *previous;
};

struct student *start = NULL;

void insert_begin(student *p){
    if (!p) return;
    p->next = start;
    p->previous = NULL;
    if (start) start->previous = p;
    start = p;
    cout<<"Inserted at the beginning\n";
}

void insert_end(student *p){
    if (!p) return;
    p->next = NULL;
    p->previous = NULL;
    if(start==NULL) {
        start = p;
    } else {
        student *q = start;
        while(q->next != NULL){
            q = q->next;
        }
        q->next = p;
        p->previous = q;
    }
    cout << "Inserted at the end.\n";
}

void insert_mid(int pos, student *p){
    if (!p) return;
    if (pos <= 1 || start == NULL) {
        insert_begin(p);
        return;
    }
    student* q = start;
    // move to node at position pos-1 (or last node if pos is too large)
    for(int i = 1; i < pos-1 && q->next != NULL; i++){
        q = q->next;
    }
    // insert after q
    p->next = q->next;
    p->previous = q;
    if (q->next) q->next->previous = p;
    q->next = p;
    cout<<"Inserted successfully\n";
}

void display(student *p){
    if (p == NULL) {
        cout << "List is empty\n";
        return;
    }
    int pos = 1;
    while (p != NULL) {
        cout << pos << ". Name: " << p->name << ", Age: " << p->age << endl;
        p = p->next;
        pos++;
    }
}

void printReverse(student *node) { // call it with printReverse(start)
    if (node == NULL) {
        cout << "List is empty\n";
        return;
    }
    // find last node
    student *q = node;
    while (q->next) q = q->next;
    // traverse backwards using previous pointers (safe and simple)
    int pos = 1;
    while (q) {
        cout << pos << ". Name: " << q->name << ", Age: " << q->age << endl;
        q = q->previous;
        pos++;
    }
}

void delBeg(){
    if(start == NULL){
        cout<<"List is empty\n";
        return;
    }
    student *temp= start;
    start = temp->next;
    if (start) start->previous = NULL;
    delete temp;
    cout<<"Deleted beginning node\n";
}

void delend(){
    if(start==NULL){
        cout<<"Empty list\n";
        return;
    }
    if (start->next == NULL){
        delete start;
        start = NULL;
        cout << "Deleted last node\n";
        return;
    }
    student *q = start;
    while(q->next->next != NULL){
        q = q->next;
    }
    student *temp = q->next;
    q->next = NULL;
    delete temp;
    cout << "Deleted end node\n";
}

void delparticular(int pos){
    if(start==NULL){
        cout<<"Empty list\n";
        return;
    }
    if (pos <= 1) {
        delBeg();
        return;
    }
    student *q = start;
    // move to node at position pos-1 (previous)
    for(int i = 1; i < pos-1 && q->next != NULL; ++i){
        q = q->next;
    }
    if (q->next == NULL){
        cout<<"No sufficient node\n";
        return;
    }
    student *temp = q->next;
    q->next = temp->next;
    if (temp->next) temp->next->previous = q;
    delete temp;
    cout<<"Deleted node at position "<<pos<<"\n";
}

// Added: search by name (case-sensitive exact match)
void searchByName(){
    if (start == NULL) {
        cout << "List is empty\n";
        return;
    }
    char query[100];
    cout << "Enter name to search: ";
    cin >> ws;
    cin.getline(query, sizeof(query));

    student *q = start;
    int pos = 1;
    bool found = false;
    while (q != NULL) {
        if (std::strcmp(q->name, query) == 0) {
            cout << pos << ". Name: " << q->name << ", Age: " << q->age << endl;
            found = true;
            // continue to find duplicate names; remove break to find all
        }
        q = q->next;
        pos++;
    }
    if (!found) cout << "No student named \"" << query << "\" found\n";
}

int main(){
    int main_choice = -1, insert_choice, position;
    student s;
    do{
        cout << "\n   Main Menu \n";
        cout << "1. Add students\n";
        cout << "2. Insert student\n";
        cout << "3. Delete student\n";
        cout << "4. Display student\n";
        cout << "5. Search student\n"; // added menu entry
        cout << "0. Exit\n";
        cout << "Enter a choice: ";
        if(!(cin >> main_choice)) break;

        switch(main_choice){
            case 1: {
                cout<<"Enter student's name: ";
                cin >> ws;
                cin.getline(s.name, sizeof(s.name));
                cout<<"Enter their age: ";
                cin>>s.age;

                student *p = new student;
                std::strncpy(p->name, s.name, sizeof(p->name)-1);
                p->name[sizeof(p->name)-1] = '\0';
                p->age = s.age;
                p->next = NULL;
                p->previous = NULL;
                insert_end(p);

                cout<<"Registered successfully\n";
                break;
            }
            case 2:{
                cout<<"Enter the student info you want to insert-> Name: ";
                cin >> ws;
                cin.getline(s.name, sizeof(s.name));
                cout<<"Age: ";
                cin>>s.age;

                student *p = new student;
                std::strncpy(p->name, s.name, sizeof(p->name)-1);
                p->name[sizeof(p->name)-1] = '\0';
                p->age = s.age;
                p->next = NULL;
                p->previous = NULL;

                cout<<"1.Insert at the beginning"<<endl;
                cout<<"2.Insert at the middle (position)"<<endl;
                cout<<"3.Insert at the end"<<endl;
                cout<<"0.exit"<<endl;
                cout<<"Enter choice: ";
                cin>>insert_choice;

                switch (insert_choice)
                {
                case 1:
                    insert_begin(p);
                    break;
                case 2:
                    cout<<"Where do you want to insert? ";
                    cin>>position;
                    insert_mid(position,p);
                    break;
                case 3:
                    insert_end(p);
                    break;
                default:
                    delete p;
                    break;
                }
                break;
            }
            case 3:{
                cout<<"1.Delete the beginning"<<endl;
                cout<<"2.Delete at the middle (position)"<<endl;
                cout<<"3.Delete the end"<<endl;
                cout<<"0.exit"<<endl;
                cout<<"Enter choice: ";
                cin>>insert_choice;

                switch (insert_choice)
                {
                case 1:
                    delBeg();
                    break;
                case 2:
                    cout<<"Where do you want to delete? ";
                    cin>>position;
                    delparticular(position);
                    break;
                case 3:
                    delend();
                    break;
                default:
                    break;
                }
                break;
            }
            case 4:{
                cout<<"1.Display forward"<<endl;
                cout<<"2.Display backward"<<endl;
                cout<<"0.Exit"<<endl;
                cin>>insert_choice;
                switch(insert_choice){
                    case 1:
                       display(start);
                       break;
                    case 2:
                       printReverse(start);
                       break;
                    default:
                       break;
                }
                break;
            }
            case 5:{ // handle search
                searchByName();
                break;
            }
            default:
                break;
        }
    } while(main_choice!=0);

    return 0;
}