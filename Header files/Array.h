#ifndef ARRAY_H
#define ARRAY_H

#define MAX_ARR 64

#include "Call.h"

class Array
{
  public:
    Array();
    Array(Array&);
    void cleanup();
    bool add(Call*);
    bool add(Array&);
    Call* get(int);
    int getSize();
    void print();

  private:
    int   size;
    Call* calls[MAX_ARR];
};

#endif
