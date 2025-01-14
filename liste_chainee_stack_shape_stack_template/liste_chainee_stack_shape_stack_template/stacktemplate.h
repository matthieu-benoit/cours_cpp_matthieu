//
//  stacktemplate.h
//  Suivi_de_cours
//
//  Created by Matthieu Benoit on 12/12/2024.
//

#include <iostream>

#ifndef STACKTEMPLATE_H
#define STACKTEMPLATE_H
template <typename T >
class Stacktemplate {
private :
    int top;
    T * p;
public :
    int size;
    Stacktemplate (int s) {
        size = s; top = 0; p = new T [size];
    }
    
    void push(T x) {
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
