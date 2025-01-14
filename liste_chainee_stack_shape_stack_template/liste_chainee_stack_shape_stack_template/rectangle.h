//
//  rectangle.h
//  Suivi_de_cours
//
//  Created by Matthieu Benoit on 12/12/2024.
//

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class rectangle : public shape{
private:
    double length;
    double width;
public:
    rectangle(double l, double w) {
        length = l; width = w;
    }
    void calculArea () {
        std::cout<< length * width << std::endl;
    }
};
#endif
