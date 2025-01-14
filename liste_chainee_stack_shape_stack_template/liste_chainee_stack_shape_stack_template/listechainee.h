//
//  listechainee.h
//  Suivi_de_cours
//
//  Created by Matthieu Benoit on 12/12/2024.
//
#include <iostream>

#ifndef LISTECHAINEE_H
#define LISTECHAINEE_H

struct noeud {
    int x;
    noeud * p;
};

class list {
public:
    int top;
    noeud * p;
    
    list() {
        p = nullptr; top = 0;
    }
    
    void push(int x) {
        noeud node;
        node.x = x; node.p = p;
        p = &node;
        top += 1;
    }
    
    void print () {
        for (int i = 0; i < top; i ++) {
            std::cout << (*p).x << std::endl;
            p = (*p).p;
        }
    }
};
//autre version de moi
//struct block {
//    int v;
//    block * p; // c'est dingue
//};
//
//class chaine {
//    public :
//    block * top;
//    void init() {
//        top = nullptr;
//    }
//    void push (int value) {
//        block * b = new block;
//        (*b).p = top;
//        (*b).v = value;
//        top = b;
//    }
//    void print () {
//        block * q = top;
//        while (q != nullptr) {
//            std::cout << (*q).v << std::endl;
//            q = (*q).p;
//        }
//    }
//};

//corrigé chatgpt
/*
struct noeud {
    int x;          // Donnée stockée dans le nœud
    noeud* p;       // Pointeur vers le nœud suivant
};

class list {
private:
    noeud* head;    // Pointeur vers le premier nœud

public:
    // Constructeur
    list() : head(nullptr) {}

    // Destructeur pour libérer la mémoire
    ~list() {
        while (head != nullptr) {
            noeud* temp = head;
            head = head->p;
            delete temp;
        }
    }

    // Ajouter un élément au début de la liste
    void push(int x) {
        noeud* node = new noeud; // Allocation dynamique
        node->x = x;
        node->p = head;
        head = node;
    }

    // Afficher les éléments de la liste
    void print() const {
        noeud* current = head; // Utilisation d'un pointeur temporaire
        while (current != nullptr) {
            std::cout << current->x << std::endl;
            current = current->p;
        }
    }
};
*/
#endif
