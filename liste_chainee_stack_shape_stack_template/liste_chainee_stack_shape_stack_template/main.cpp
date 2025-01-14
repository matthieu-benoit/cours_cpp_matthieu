//
//  main.cpp
//  Suivi_de_cours
//
//  Created by Matthieu Benoit on 12/12/2024.
//

#include <iostream>

#include "stack.h"
#include "stacktemplate.h"
#include "listechainee.h"
#include "circle.h"
#include "rectangle.h"

int main() {
    Stack stack(10);
    stack.push(3);
    stack.push(6);
    stack.print();
    
    Stacktemplate<float> stack2(10);
    stack2.push(3.1);
    stack2.push(6.1);
    stack2.print();
    
    list list;
    list.push(2);
    list.push(4);
    list.print();
    
    Stacktemplate<shape> shapeStack(10);
    circle c(2.0);
    rectangle r(3.0, 4.0);
    shapeStack.push(c);
    shapeStack.push(r);
    c.calculArea();
    r.calculArea();
}
