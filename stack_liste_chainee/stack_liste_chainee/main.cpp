//
//  main.cpp
//  Suivi de cours
//
//  Created by Matthieu Benoit on 21/11/2024.
//

#include <iostream>
#include <cmath>
float const pi = 4 * std::atan(1);

struct shape {
    
    float x; float y; // position de la shape
    float aire;
    shape () {
        x = 0; y = 0;
    }
    virtual float Calcularea () {
        return 0;
    }
    virtual bool IsInShape() {
        return true;
    }
};

struct point : public shape {
    point (float abs, float ord) {
        x = abs; y = ord;
        
    }
};

struct rectangle : public shape {
    float L; float l;
    rectangle (float Longueur, float largeur) {
        L = Longueur; l = largeur;
    }
    float Calcularea () {
        return L * l;
    }
    /*bool IsInShape(point p) {
        if (p.x < L) and (p.y < l) {
            return true;
        }
        return false;
    }*/
};
struct circle : public shape {
    float r;
    circle (float radius) {
        r = radius;
    }
    float Calcularea () {
        return pi * std::pow(r,2);
    }
};

struct ShapeStack {
    shape * * stack;
    int top;
    int size;
    
    ShapeStack (int taille) {
        size = taille; top = 0;
        stack = new shape* [size];
    }
    
    ~ShapeStack () {
        delete [] stack;
    }
    
    void push(shape * x) {
        if (top < size) {
            stack[top] = x;
            top += 1;
        }
    }
    
    void pop() {
        top -= 1;
    }
    
    void print () {
        for (int i = 0; i < top; i ++) {
            std::cout << stack[i] << " aire : " << (*stack[i]).Calcularea() << std::endl;
        }
    }
    
    void somme2area (shape * p1, shape * p2) {
        std::cout << (*p1).Calcularea() + (*p2).Calcularea() << std::endl;
    }
    
    void sommeallarea () {
        float s = 0;
        for (int i =0; i < top; i ++) {
            s += (*stack[i]).Calcularea();
        }
        std::cout << s << std::endl;
    }
};

struct block {
    int v;
    block * p; // c'est dingue
};

class chaine {
    public :
    block * top;
    void init() {
        top = nullptr;
    }
    void push (int value) {
        block * b = new block;
        (*b).p = top;
        (*b).v = value;
        top = b;
    }
    void print () {
        block * q = top;
        while (q != nullptr) {
            std::cout << (*q).v << std::endl;
            q = (*q).p;
        }
    }
};

int main () {
    ShapeStack s (5);
    
    circle c (3);
    rectangle r1 (4,3);
    rectangle r2 (3,2);
    
    s.push(&c);
    s.push(&r1);
    s.push(&r2);
    s.print();
    s.somme2area(&c, &r1);
    s.sommeallarea();
    
    
    chaine liste_chainee;
    liste_chainee.init();
    liste_chainee.push(1);
    liste_chainee.push(2);
    liste_chainee.print();
}
