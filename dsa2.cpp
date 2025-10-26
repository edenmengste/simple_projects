#include <iostream>
using namespace std;

template <typename T>

class AList {
private:
    int maxSize;
    int listSize;
    int curr;
    T* listArray;

public:
    AList(int size = 100) {
        maxSize = size;
        listSize = curr = 0;
        listArray = new T[maxSize];
    }

    ~AList() {
        delete[] listArray;
    }

    void clear() {
        delete[] listArray;
        listSize = curr = 0;
        listArray = new T[maxSize];
    }

    bool insert(const T& item) {
        if (listSize >= maxSize || curr < 0 || curr > listSize) return false;
        for (int i = listSize; i > curr; i--)
            listArray[i] = listArray[i - 1];
        listArray[curr] = item;
        listSize++;
        return true;
    }

    bool append(const T& item) {
        if (listSize >= maxSize) return false;
        listArray[listSize++] = item;
        return true;
    }

    bool remove() {
        if (listSize == 0 || curr < 0 || curr >= listSize) return false;
        for (int i = curr; i < listSize - 1; i++)
            listArray[i] = listArray[i + 1];
        listSize--;
        return true;
    }

    T getValue() const {
        if (curr < 0 || curr >= listSize) throw out_of_range("Invalid position");
        return listArray[curr];
    }

    void clear(){
        delete [] listArray;

    }
};


