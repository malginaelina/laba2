#ifndef LABA2_DINAMICARRAY_H
#define LABA2_DINAMICARRAY_H

#include <iostream>

using namespace std;

#include <stdexcept>


template <typename T>  class DynamicArray {

private:
    T* data;
    int size;

public:
    //constructors
    DynamicArray();
    DynamicArray(int size);
    DynamicArray(T* items, int size);
    DynamicArray(const DynamicArray<T>& array);

    //Decomposition
    T Get(int index) const;
    int GetSize() const;

    //Operations
    void Set(int index, T value);
    void Resize(int size);


    //Destructor
    ~DynamicArray() = default;
};

//CONSTRUCTORS
template<typename T> DynamicArray<T>::DynamicArray(): size(0) {
    this->size = 0;
}

template<typename T> DynamicArray<T>::DynamicArray(int size) : size(size){
       if (size<0) {
            throw length_error("Negative size!");
       }
       this->size = size;
       this->data = new T[this->size];


}

template<typename T> DynamicArray<T>::DynamicArray(T* items, int size) : DynamicArray(size) {
        if (size<0) {
            throw length_error("Negative size!");
        }
        this->size =size;
        for (int i = 0; i < size; i++) {
            this->data[i] = items[i];
        }


}

template<typename T> DynamicArray<T>::DynamicArray(const DynamicArray<T> &array) : DynamicArray(array.size) {
    /*
        if (size > array.size || size<0) {
            throw "Index out of range!";
        }
        */
        this->size = size;
        for (int i = 0; i < array.size; i++)
            this->data[i] = array.data[i];


}

//DECOMPOSITION

template<typename T> T DynamicArray<T>::Get(int index) const {

    if (index < 0 || index >= this->size) {
        throw out_of_range("Index out of range!");
    }
    return this->data[index];
}

template<typename T> int DynamicArray<T>::GetSize() const {
    return this->size;
}

// OPERATIONS

template<typename T> void DynamicArray<T>::Set(int index, T value) {
        if (index<0 || index >=this->size) {
            throw out_of_range("Index out of range!");
        }
        this->data[index] = value;


}

template<typename T> void DynamicArray<T>::Resize(int size) {
        if (size < 0) {
            throw length_error("Negative size!");
        }
        T* newData = new T[size];
        for (int i = 0; i < (this->size > size ? size : this->size); i++) {
            newData[i] = data[i];
        }
        delete[] data;
        this->data = newData;
        this->size = size;

}

#endif //LABA2_DINAMICARRAY_H
