//
//  main.cpp
//  TPBoidsMatthieuBenoit
//
//  Created by Matthieu Benoit on 04/02/2025.
//

#include <SDL2/SDL.h>
#include <iostream>
#include <random>
#include "bird.h"



int main(int argc, char* argv[]) {
    // Initialiser SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Erreur SDL: " << SDL_GetError() << std::endl;
        return -1;
    }

    // Créer une fenêtre SDL
    SDL_Window* window = SDL_CreateWindow("Bird",
                                          SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                          windowWidth, windowHeight, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Erreur fenêtre: " << SDL_GetError() << std::endl;
        return -1;
    }

    // Créer un renderer SDL
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Erreur renderer: " << SDL_GetError() << std::endl;
        return -1;
    }

    // Création du world
    std::vector<Bird*> world;
    Bird bird1(450, 300, -5, 1, true);
    world.push_back(&bird1);
    Bird bird2(350, 300, -5, 1, false);
    //world.push_back(&bird2);
    //on dit qui est voisin de qui
    //world[0]->neighbors.push_back(world[1]);
    //world[1]->neighbors.push_back(world[0]);
    
    int compteur = 0;
    
    bool running = true;
    SDL_Event event;

    while (running) {
        // Gestion des événements
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            //permet d'ajouter des birds
            if (event.type == SDL_MOUSEBUTTONDOWN) {
                int x; int y;
                SDL_GetMouseState(&x, &y);
                Bird* bird = new Bird(x,y,0,0, false);
                world.push_back(bird);
            }
        }
        // Vérifie si un prédateur a mangé un bird
        for (auto it = world.begin(); it != world.end(); ++it) {
            Bird* potentiel_predator = *it;
            if (potentiel_predator->predator) {  // Si c'est un prédateur
                for (auto it2 = world.begin(); it2 != world.end(); ) {
                    Bird* bird = *it2;

                    if (!bird->predator) { // Un prédateur ne peut pas manger un autre prédateur
                        if (bird->distance(*potentiel_predator) < bird->d_min) {
                            delete bird;  // Libère la mémoire, l'oiseau est mangé
                            it2 = world.erase(it2);  // Supprime et met à jour l'itérateur
                            continue; // Ne pas faire `++it2` après `erase()`
                        }
                    }
                    ++it2;  // Passe au suivant seulement si on n'a pas supprimé
                }
            }
        }
        //réinitialisation du nb de rebonds d'un oiseau toutes les 100 frames (environ toutes les 3 sec si delay de 30ms entre chaque frame)
        if (compteur == 100) {
            for (auto it = world.begin(); it != world.end(); ++it) {
                Bird* bird = *it;
            }
            compteur = 0;
        }
        compteur += 1;
        
        // Mise à jour de la position des birds
        for (size_t i = 0; i < world.size(); ++i) {
            world[i]->update(world, compteur);
        }
        
        // Fond d'écran
        for (int y = 0; y < windowHeight; ++y) {
            float a = y / float(windowHeight);
            int r = int( (1-a) * 255 * 0.0 + a * 255 );
            int g = int( (1-a) * 255 * 0.2 + a * 255 );
            int b = int( (1-a) * 255 * 0.5 + a * 255 );
            SDL_SetRenderDrawColor(renderer, r, g, b, 255);
            SDL_RenderDrawLine(renderer, 0, y, windowWidth, y);  // Dessine une ligne horizontale
        }
        
        // Effacer l'écran avec un fond noir
        //SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Noir
        //SDL_RenderClear(renderer);

        // Affichage des Birds
        for (size_t i = 0; i < world.size(); ++i) {
            world[i]->render(renderer);
        }

        // Afficher le rendu à l'écran
        SDL_RenderPresent(renderer);

        // Limiter la vitesse de la boucle à environ 33 FPS
        SDL_Delay(30); // 30 ms de délai entre chaque frame
    
    }

    // Libération des ressources et fermeture
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
