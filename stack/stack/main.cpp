//
//  main.cpp
//  test2
//
//  Created by Matthieu Benoit on 05/11/2024.
// std::cout << "Hello, World!\n" << tab[0] << std::endl;

#include <iostream>

int mainx (int argc, const char * argv[]) {
    
    int tab[] = { 16, 50, 8, 3, 56, 23, 15 };
    
    for (int i = 0; i < 7; i = i + 1) {
        
        if (tab[i + 1] < tab[i]) {
            int a = tab[i];
            int b = tab[i + 1];
            tab[i] = b;
            tab[i + 1] = a;
        }
    }
    // Affiche le tableau trié
    std::cout << "Tableau trié : ";
    for (int i = 0; i < 7; i++) {
        std::cout << tab[i] << " ";
    }
    std::cout << std::endl;
    
    
    // ce code est une première version, il ne trie pas complètement le tableau tab
    // essai n°2
    
    for (int i = 0; i < 7; i = i + 1) {
        for (int j = 0; j < i - 1; j = j + 1) {
            if (tab[j + 1] < tab[j]) {
                int a = tab[j];
                int b = tab[j + 1];
                tab[j] = b;
                tab[j + 1] = a;
            }
            
        }
    }
    // Affiche le tableau trié
    std::cout << "Tableau trié : ";
    for (int i = 0; i < 7; i++) {
        std::cout << tab[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
