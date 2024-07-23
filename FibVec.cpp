#include "FibVec.h"

// This provides exception types:
#include <stdexcept>


// FibVec Function Implementations

FibVec::FibVec() : m_capacity(1), m_count(0), arr(new int[1]) {}

FibVec::~FibVec() {
    delete[] arr;
}

void FibVec::resize(size_t newCapacity) {
    int* newArr = new int[newCapacity];
    for (size_t i = 0; i < m_count; ++i) {
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    m_capacity = newCapacity;
}

size_t nextFib(size_t num) {
    size_t a = 0, b = 1, c;
    while (b < num) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

size_t prevFib(size_t num) {
    size_t a = 0, b = 1, c;
    while (b < num) {
        c = a + b;
        a = b;
        b = c;
    }
    return a;
}

size_t prevPrevFib(size_t num) {
    size_t a = 0, b = 1, c;
    while (b < num) {
        c = a + b;
        a = b;
        b = c;
    }
    size_t prevPrev = 0;
    size_t prev = 1;
    while (prev < a) {
        size_t temp = prev;
        prev += prevPrev;
        prevPrev = temp;
    }
    return prevPrev;
}

size_t FibVec::count() const {
    return m_count;
}

size_t FibVec::capacity() const {
    return m_capacity;
}

void FibVec::insert(int value, size_t index) {
    if (index > m_count) {
        throw std::out_of_range("Index out of range");
    }

    if (m_count + 1 > m_capacity) {
        size_t newCapacity = nextFib(m_capacity + 1); 
        resize(newCapacity);
    }

    if (index == 0) {
        for (size_t i = m_count; i > 0; --i) {
            arr[i] = arr[i - 1];
        }
        arr[0] = value;
    } else {
        for (size_t i = m_count; i > index; --i) {
            arr[i] = arr[i - 1];
        }
        arr[index] = value;
    }

    m_count++;
}

int FibVec::lookup(size_t index) const {
    if (index >= m_count) {
        throw std::out_of_range("Index out of range");
    }
    return arr[index];
}

int FibVec::pop() {
    if (m_count == 0) {
        throw std::underflow_error("Underflow Error");
    }

    int value = arr[m_count - 1];
    m_count--;

    if (m_count == 0 && m_capacity == 2) {
        size_t newCapacity = 1; 
        resize(newCapacity);
    } else if (m_count < prevPrevFib(m_capacity) && prevPrevFib(m_capacity) >= 1) {
        size_t newCapacity = prevFib(m_capacity);
        resize(newCapacity);
    }

    return value;
}

void FibVec::push(int value){
    insert(value, m_count);
}


int FibVec::remove(size_t index) {
    if (index >= m_count) {
        throw std::out_of_range("Index out of range");
    }

    int value = arr[index];
    for (size_t i = index; i < m_count - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    m_count--;

    if (m_count < prevPrevFib(m_capacity) && prevPrevFib(m_capacity) >= 1) {
        size_t newCapacity = prevFib(m_capacity);
        resize(newCapacity);
    }

    return value;
}