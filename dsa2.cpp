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


