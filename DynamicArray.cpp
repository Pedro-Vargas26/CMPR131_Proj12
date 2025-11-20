#pragma once
#include "DynamicArray.h"

constexpr int ALLOC_INCREMENTS = 5;

// Default constructor
template<typename T>
DynamicArray<T>::DynamicArray() :
    p_ptr(nullptr),
    arrSize(0),
    arrCapacity(0),
    isSorted(false)
{
}

// Copy constructor (deep copy)
template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray& other)
{
    arrSize = other.arrSize;
    arrCapacity = other.arrCapacity;
    isSorted = other.isSorted;

    if (arrCapacity > 0) {
        p_ptr = new T[arrCapacity];
        for (int i = 0; i < arrSize; ++i)
            p_ptr[i] = other.p_ptr[i];
    }
    else {
        p_ptr = nullptr;
    }
}

// Assignment operator (deep copy)
template<typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray& other)
{
    if (this == &other)
        return *this;

    // Allocate new memory first
    T* newPtr = nullptr;
    if (other.arrCapacity > 0) {
        newPtr = new T[other.arrCapacity];
        for (int i = 0; i < other.arrSize; ++i)
            newPtr[i] = other.p_ptr[i];
    }

    // Delete old memory
    delete[] p_ptr;

    // Assign
    p_ptr = newPtr;
    arrSize = other.arrSize;
    arrCapacity = other.arrCapacity;
    isSorted = other.isSorted;

    return *this;
}

// Destructor
template<typename T>
DynamicArray<T>::~DynamicArray()
{
    delete[] p_ptr;
    p_ptr = nullptr;
    arrSize = 0;
    arrCapacity = 0;
}

// Return pointer
template<typename T>
const T* DynamicArray<T>::data() const noexcept {
    return p_ptr;
}

// Append element
template<typename T>
void DynamicArray<T>::append(const T& obj) noexcept
{
    if (!p_ptr) {
        arrCapacity = ALLOC_INCREMENTS;
        p_ptr = new T[arrCapacity];
        p_ptr[0] = obj;
        arrSize = 1;
        return;
    }

    if (arrSize < arrCapacity) {
        p_ptr[arrSize++] = obj;
    }
    else {
        T* newArr = new T[arrCapacity + ALLOC_INCREMENTS];
        for (int i = 0; i < arrSize; ++i)
            newArr[i] = p_ptr[i];

        delete[] p_ptr;
        p_ptr = newArr;
        p_ptr[arrSize++] = obj;
        arrCapacity += ALLOC_INCREMENTS;
    }
}

template<typename T>
bool DynamicArray<T>::exists(const T& needle) const noexcept {
    for (int i = 0; i < arrSize; i++)
        if (p_ptr[i] == needle) return true;
    return false;
}

template<typename T>
bool DynamicArray<T>::empty() const noexcept {
    return arrSize == 0;
}

template<typename T>
void DynamicArray<T>::clear() noexcept {
    delete[] p_ptr;
    p_ptr = nullptr;
    arrSize = 0;
    arrCapacity = 0;
    isSorted = false;
}

template<typename T>
size_t DynamicArray<T>::size() const noexcept { return arrSize; }

template<typename T>
size_t DynamicArray<T>::capacity() const noexcept { return arrCapacity; }

template<typename T>
int DynamicArray<T>::find(const T& needle) const noexcept {
    for (int i = 0; i < arrSize; i++)
        if (p_ptr[i] == needle) return i;
    return -1;
}

template<typename T>
T& DynamicArray<T>::operator[](int index) {
    if (index < 0 || index >= arrSize)
        throw std::out_of_range("DynamicArray index out of bounds");
    return p_ptr[index];
}

template<typename T>
const T& DynamicArray<T>::operator[](int index) const {
    if (index < 0 || index >= arrSize)
        throw std::out_of_range("DynamicArray index out of bounds");
    return p_ptr[index];
}

template<typename T>
bool DynamicArray<T>::sorted() const noexcept {
    return isSorted;
}

template<typename T>
void DynamicArray<T>::sort() {
    if (arrSize <= 1) return;
    for (int i = 1; i < arrSize; i++) {
        T key = p_ptr[i];
        int j = i - 1;
        while (j >= 0 && p_ptr[j] > key) {
            p_ptr[j + 1] = p_ptr[j];
            j--;
        }
        p_ptr[j + 1] = key;
    }
    isSorted = true;
}

template<typename T>
void DynamicArray<T>::sorted_insert(const T& obj) noexcept {
    if (!isSorted) return;
    if (!p_ptr) {
        arrCapacity = ALLOC_INCREMENTS;
        p_ptr = new T[arrCapacity];
        p_ptr[0] = obj;
        arrSize = 1;
        return;
    }
}

template<typename T>
int DynamicArray<T>::remove(const T& needle) noexcept {
    int idx = find(needle);
    if (idx == -1) return 0;

    for (int j = idx; j < arrSize - 1; j++)
        p_ptr[j] = p_ptr[j + 1];

    arrSize--;
    return 1;
}

template<typename T>
int DynamicArray<T>::remove(const T& needle, bool allOrOne) noexcept
{
    if (!allOrOne)
        return remove(needle);

    int count = 0;
    while (remove(needle) > 0)
        count++;
    return count;
}
