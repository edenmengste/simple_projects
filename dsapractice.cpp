#include <iostream>
using namespace std;

template <typename T>

class Some{
private:
   int maxSize;
   int listSize;
   int curr;
   T* listArray;
public:
   Some(int max=50){
    maxSize = max;
    listSize = curr = 0;
    listArray = new T[maxSize];
   }

   ~Some(){
      delete [] listArray;
   }

   void clear(){
    delete[] listArray;
    listSize = curr = 0;
    listArray = new T[maxSize];
   }

   bool setPos(int pos){
    if(pos>=0 && listSize >= pos){
        curr = pos;
        return true;
    }
    return false;
   }

   bool getValue(T& it){
    if(listSize == 0 || curr<0 || curr>= listSize){
        return false;
    }
    it = listArray[curr];
    return true;
   }

   bool insert(T x){
    if(listSize==maxSize) return false;
    //shifting elements up
    for(int i=listSize; i>curr; i--){
        listArray[i] = listArray[i-1];
    }
    listArray[curr] = x;
    listSize++;
    return true;
   }

   bool append(int n){
    if (listSize == maxSize) return false;
    listArray[listSize++] = n;
    return true;
   }

   bool remove(){
    if(listSize == 0) return false;
    for(int i=curr; i<listSize-1;i++){
        listArray[i] = listArray[i+1];
   }
    listSize--;
        return true;
}

};

struct student{
    char name[20];
    int age;
    char dept[20];
    struct student *next;
};

struct student *start = NULL;
struct student *p = new student;

void insert_begin(student *p){
    student *temp;
    if(start==NULL){
        start=p; 
        p->next=NULL;
        cout<<"Inserted at the beginning";
    }
    else{
        temp=start;
        start=p;
        p->next = temp;
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
}

void insert_mid(int c, student *p){
    student* q= start;
    for(int i=1; i<c; i++){
        q=q->next;
    }
    if(q=NULL) cout<<"Less number of nodes than "<<c;
    else{
        p->next = q->next;
        q->next=p;
        cout<<"Inserted successfully";
    }

}

void display(student *p){
    student *q = start;
    do{
        if(q==NULL) cout<<"End of list";
        cout<<p->name<<endl;
    cout<<p->age<<endl;
    q=q->next;
    }
    while(q->next!=NULL);
}

void backward(student *p){
    student *q=start;
    while(q->next!=NULL){
            q =q->next; }
    while(p->next!=q){
        p=p->next;
    }
}