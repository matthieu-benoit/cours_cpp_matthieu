//
//  bird.h
//  TPBoidsMatthieuBenoit
//
//  Created by Matthieu Benoit on 04/02/2025.
//

#include <SDL2/SDL.h>
#include <iostream>
#include <random>

#ifndef BIRD_H
#define BIRD_H


const int windowWidth = 800;
const int windowHeight = 600;



class Bird {
public:
    float x, y;  // Position
    float vx, vy; // Vitesse
    bool predator;
    
    float v_max = 6;
    float d_min = 10; // distance minimale avant d'être mangé
    float d_max2 = 50; // distance maximale de proximité
    float d_max1 = 300; // distance maximale d'interaction
    std::vector<Bird*> neighbors;
    std::vector<Bird*> closeneighbors;
    
    float distance(const Bird& A) const {
        return std::sqrt(std::pow((x - A.x), 2) + std::pow((y - A.y), 2));
    }
    
    Bird(float x, float y, float vx, float vy, bool predator) : x(x), y(y), vx(vx), vy(vy), predator(predator) {
        if (predator) {
            v_max = 3; // on limite la vitesse du prédateur pour laisser une chance aux oiseaux
        }
    }
    
    void update(std::vector<Bird*>& world, int compteur) {
        x += vx;
        y += vy;
        
        // Recherche des voisins
        neighbors.clear();
        for (size_t i = 0; i < world.size(); ++i) {
            if (world[i] != this && distance(*world[i]) < d_max1) { // Vérifier la distance et exclure soi-même
                neighbors.push_back(world[i]);
            }
        }
        
        // Recherche des voisins proches
        closeneighbors.clear();
        for (size_t i = 0; i < world.size(); ++i) {
            if (world[i] != this && distance(*world[i]) < d_max2) { // Vérifier la distance et exclure soi-même
                closeneighbors.push_back(world[i]);
            }
        }
        
        // Calcul des forces d'interaction
        float force_x = 0;
        float force_y = 0;
        float BarycentreVoisinsX = 0;
        float BarycentreVoisinsY = 0;
        float BarycentreVoisinsVX = 0;
        float BarycentreVoisinsVY = 0;
        for (size_t i = 0; i < neighbors.size(); i++) {
            if (neighbors[i]->predator) {   // interaction répulsive
                force_x += 0.01 * (x - neighbors[i]->x);
                force_y += 0.01 * (y - neighbors[i]->y);
            }
            else {
                BarycentreVoisinsX += neighbors[i]->x;
                BarycentreVoisinsY += neighbors[i]->y;
                BarycentreVoisinsVX += neighbors[i]->vx;
                BarycentreVoisinsVY += neighbors[i]->vy;
            }
        }
        if (neighbors.size() > 0) { // les oiseaux sont attirés par le barycentre du groupe d'oiseaux voisins : COHÉSION
            force_x += 0.005 * - (x - BarycentreVoisinsX/neighbors.size());
            force_y += 0.005 * - (y - BarycentreVoisinsY/neighbors.size());
            // et leur direction tend à se rapprocher de la direction moyenne du groupe : ALIGNEMENT
            vx += 0.1 * BarycentreVoisinsVX/neighbors.size();
            vy += 0.1 * BarycentreVoisinsVY/neighbors.size();
        }
        for (size_t i = 0; i < closeneighbors.size(); i++) {
            if (!predator) {   // interaction répulsive si deux oiseaux non prédateurs sont trop proches : SÉPARATION
                force_x += 0.05 * (x - closeneighbors[i]->x);
                force_y += 0.05 * (y - closeneighbors[i]->y);
            }
        }
        
        //vérifie si on est en dessous de la vitesse limite
        float speed = std::sqrt(vx * vx + vy * vy);
        if (speed > v_max) {
            vx = (vx / speed) * v_max;
            vy = (vy / speed) * v_max;
        }
        
        // Actualisation de la vitesse due aux forces
        vx += force_x;
        vy += force_y;
        
        // Rebond sur les bords
        if (x < 0 || x > windowWidth) {
            vx = -vx;
        }
        if (y < 0 || y > windowHeight) {
            vy = -vy;
        }
    }


    // Affiche le bird à l'écran
    void render(SDL_Renderer* renderer) {
        SDL_Rect BirdRect = {static_cast<int>(x), static_cast<int>(y), 10, 10}; // Le bird est un carré de 10x10
        if (predator) {
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Couleur rouge
        }
        else {
            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // Couleur blanche
        }
        SDL_RenderFillRect(renderer, &BirdRect);
    }
};
#endif

