//
//  circle.h
//  Suivi_de_cours
//
//  Created by Matthieu Benoit on 12/12/2024.
//

#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

class circle : public shape {
private:
    double radius;
public:
    circle(double r ) {
        radius = r;
    }
    void calculArea () {
        std::cout<< 3.14159 * std::pow(radius,2) << std::endl;
    }
};
#endif
