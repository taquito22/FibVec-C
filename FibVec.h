#ifndef FIBVEC_H
#define FIBVEC_H

// This provides the size_t type:
#include <cstddef>

class FibVec {
  // Member Variables
  size_t m_capacity;
  size_t m_count;
  int* arr;

  // Helper Functions
 void resize(size_t newCapacity);
 size_t nextFib(size_t num);
 size_t prevFib(size_t num);
 size_t prevPrevFib(size_t num);

public:
  // Constructor and Destructor
  FibVec();
  ~FibVec();

  // Member Functions
size_t count() const;
size_t capacity() const;

void insert(int value, size_t index);
int lookup(size_t index) const;
int pop();
void push(int value);
int remove(size_t index);

};

#endif