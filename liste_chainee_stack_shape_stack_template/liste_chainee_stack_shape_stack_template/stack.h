//
//  stack.h
//  Suivi_de_cours
//
//  Created by Matthieu Benoit on 12/12/2024.
//

#include <iostream>

#ifndef STACK_H
#define STACK_H

class Stack {
private :
    int top;
    int * p;
public :
    int size;
    Stack (int s) {
        size = s; top = 0; p = new int [size];
    }
    
    void push(int x) {
        if (top < size) {
            p[top] = x; // ou bien *(p+top) = x;
            top += 1;
        }
    }
    void pull() {
        top -= 1;
    }
    void print() {
        for (int i = 0; i < top; i++)
            std::cout<< p[i] << " "<<std::endl;
    }
};
#endif
