//
//  main.cpp
//  TP_boid
//
//  Created by Matthieu Benoit on 12/12/2024.
//

#include <iostream>
#include "bird.h"

int main() {
    bird b;
    b.image_width = 10;
    b.image_height = 10;
    b.generate_bird(5,5);
    b.displace(2, 2);
    b.render();
}
