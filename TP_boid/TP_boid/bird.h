//
//  bird.h
//  TP_boid
//
//  Created by Matthieu Benoit on 17/12/2024.
//

#ifndef BIRD_H
#define BIRD_H

class bird {
public:
    int x;
    int y;
    int image_width;
    int image_height;
    void render() {
        std::cout<<"P3"<<std::endl;
        std::cout<<image_width<<" "<<image_height<<std::endl;
        std::cout<<"255"<<std::endl;
        for (int j = 0; j < image_height; j++) {
            for (int i = 0; i < image_width; i++) {
                if (j == y and i == x) {
                    int r = 255;
                    int g = 255;
                    int b = 255;
                    std::cout<<r<<" "<<g<<" "<<b<<std::endl;
                }
                else {
                    int r = 0;
                    int g = 0;
                    int b = 0;
                    std::cout<<r<<" "<<g<<" "<<b<<std::endl;
                }
            }
        }
    }
    void generate_bird(int abs, int ord) {
        x = abs; y = ord;
        
    }
    
    void displace(int add_x, int add_y) {
        x += add_x; y += add_y;
    }
};

#endif
