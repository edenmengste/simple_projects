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
    if(start==NULL){
        start=p; 
        p->next=NULL;
    }
    else{
        p->next=start;
        start=p;
        cout<<"Inserted at the beginning";
    }
}

void insert_end(student *p){
    student *q=start;
    if(start==NULL) start=p;
    else{
        while(q->next!=NULL){
            q =q->next;
        }
        q->next=p;
    }
    cout << "Inserted at the end.\n";
}

void insert_mid(int c, student *p){
    student* q= start;
    for(int i=1; i<c; i++){
        q=q->next;
    }
    if(q==NULL){ 
        cout<<"Less number of nodes than "<<c<<".\n";
        return;
    }
    else{
        p->next = q->next;
        q->next=p;
        cout<<"Inserted successfully";
    }

}

void display(student *p){
    int pos = 1;
    while (p != NULL) {
        cout << pos << ". Name: " << p->name << ", Age: " << p->age << endl;
        p = p->next;
        pos++;
    }
}

void printReverse(student *node) { //call it with printReverse(start)
    if (node == NULL) return;         
    printReverse(node->next);         
    cout << node->name << endl;       
}

void delBeg(){
    if(start ==NULL) cout<<"List is empty";
    student *temp= start;
    start = temp->next;
    delete temp;
}

void delend(){
    if(start==NULL) cout<<"Empty list";
    student *q=start;
    while(q->next->next!=NULL){
        q=q->next;
    }
    student *temp = q->next;
    q->next=NULL;
    delete temp;
}

void delparticular(int c){
    if(start==NULL) cout<<"Empty list";
    student *q=start;
    for(int i=1;i<c;i++){
       if(q == NULL || q->next == NULL) {
        cout<<"No sufficient node";
        return;
       }
       q=q->next;
    }
    student *temp=q->next;
    q->next=temp->next;
    delete temp;   

}

int main(){
    int main_choice, insert_choice, position;
    student s;
    do{
        cout << "\n   Main Menu \n";
        cout << "1. Add students\n";
        cout << "2. Insert student\n";
        cout << "3. Delete student\n";
        cout << "4. Display student\n";
        cout << "0. Exit\n";
        cout << "Enter a choice: ";
        cin >> main_choice;

        switch(main_choice){
            case 1: {
                cout<<"Enter students name: ";
                cin>>s.name;
                cout<<"Enter their age: ";
                cin>>s.age;

                // create node and insert into list
                student *p = new student;
                std::strcpy(p->name, s.name);
                p->age = s.age;
                p->next = NULL;
                insert_end(p);

                cout<<"Registered successfully\n";
                break;
            }
            case 2:{
            cout<<"Enter the student info you want to insert-> Name: ";
            cin>>s.name;
            cout<<"Age: ";
            cin>>s.age;

            student *p = new student;
            std::strcpy(p->name, s.name);
            p->age=s.age;

            cout<<"1.Insert at the beginning"<<endl;
            cout<<"2.Insert at the middle"<<endl;
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
                break;
            }
            break;
          }
            case 3:{
            cout<<"1.Delete the beginning"<<endl;
            cout<<"2.Delete at the middle"<<endl;
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
        }
    }
    while(main_choice!=0);
}
   return 0;
}