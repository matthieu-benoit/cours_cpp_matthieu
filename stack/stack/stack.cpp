//
//  stack.cpp
//  test2
//
//  Created by Matthieu Benoit on 07/11/2024.
//
# include <iostream>
# include <cmath>
float pi = 4 * std::atan(1);
struct IntStack3 { // création d'une pile pouvant contenir 3 éléments au maximum
    
    int stack[3];
    int nb_de_valeurs;
    
    void init () {
        nb_de_valeurs = 0;
    }
    
    void push(int n) {
        if (nb_de_valeurs >= 3) {
            std::cout << "plus de place" << std::endl;
        }
        if (nb_de_valeurs < 3) {
            int * p = &stack[nb_de_valeurs];
            *p = n;
            nb_de_valeurs += 1;
        }
    }
    
    
    void print() {
        for (int i = 0; i < nb_de_valeurs; i = i + 1) {
            std::cout << stack[i] << std::endl;
        }
    }
    
    
    void pop() {
        nb_de_valeurs -= 1;
    }
};


















struct IntStackTailleVariable { /* création d'une pile de taille variable */
    
    int * p;
    int nb_de_valeurs;
    int size;
    
    void init(int taille) {
        size = taille;
        p = new int[size];
        nb_de_valeurs = 0;
    }
    
    void push(int n) {
        if (nb_de_valeurs >= size) {
            std::cout << "plus de place" << std::endl;
        }
        if (nb_de_valeurs < size) {
            *(p + nb_de_valeurs) = n;
            nb_de_valeurs += 1;
        }
    }
    void print() {
        for (int i = 0; i < nb_de_valeurs; i = i + 1) {
            std::cout << p[i] << std::endl;
        }
    }
    
    
    void pop() {
        nb_de_valeurs -= 1;
    }
};












// VERSION AVEC UN CONSTRUCTEUR ET UN DESTRUCTEUR
struct intStack {
    int * stack;
    int size;
    int top;
    
    intStack (int size) {
        stack = new int[size];
        top = 0;
        std::cout << "le constructeur est appelé" << std::endl;
    }
    
    ~intStack () { // le detructeur permet d'éviter les fuites mémoires = espace alloué inutilisable, en deletant les new qu'on a créé
        delete [] stack;
        std::cout << "le detructeur est appelé" << std::endl;
    }
    
    void push(int n) {
        if (top >= 3) {
            std::cout << "plus de place" << std::endl;
        }
        if (top < 3) {
            *(stack + top) = n;
            top += 1;
        }
    }
    void print() {
        for (int i = 0; i < top; i = i + 1) {
            std::cout << stack[i] << std::endl;
        }
    }
    
    
    void pop() {
        top -= 1;
    }
    
};










// VERSION AVEC UN CONSTRUCTEUR ET UN DESTRUCTEUR ET UN COPY CONSTRUCTEUR
struct IntStack {
    int * stack;
    int size;
    int top;
    
    IntStack (int size) {
        stack = new int[size];
        top = 0;
        std::cout << "le constructeur est appelé" << std::endl;
    }
    
    ~IntStack () {
        delete [] stack;
        std::cout << "le destructeur est appelé" << std::endl;
    }
    
    IntStack (const IntStack & myStack1) { /* on crée une référence de l'objet dont on souhaite stocker les attributs dans le nouvel objet myStack2 pour éviter de recopier myStack1 dans lors l'appel de la fonction et donc d'utiliser inutilement de l'espace mémoire */
        size = myStack1.size; /* quand on fait { IntStack myStack2 = myStack1 ; } on crée un objet nommé myStack2 qui a pour type la struct, il va donc posséder les attributs size, top et stack qui sont initialisés dans la fonction copy constructeur */
        top = myStack1.top;
        stack = new int [size];
        for (int i = 0; i <= top; i ++) {
            stack[i] = myStack1.stack[i];  // rappel stack[i] = *(stack +i)
        }
        std::cout << "le copy constructeur est appelé" << std::endl;
    }
    
    void push(int n) {
        if (top >= 3) {
            std::cout << "plus de place" << std::endl;
        }
        if (top < 3) {
            *(stack + top) = n;
            top += 1;
        }
    }
    void print() {
        for (int i = 0; i < top; i = i + 1) {
            std::cout << stack[i] << std::endl;
        }
    }
    
    
    void pop() {
        top -= 1;
    }
    
};










// VERSION AVEC UN CONSTRUCTEUR ET UN DESTRUCTEUR ET UN COPY CONSTRUCTEUR ET UN OPÉRATEUR
struct int_stack {
    int * stack;
    int size;
    int top;
    
    int_stack (int size) {
        stack = new int[size];
        top = 0;
        std::cout << "le constructeur est appelé" << std::endl;
    }
    
    ~int_stack () {
        delete [] stack;
        std::cout << "le destructeur est appelé" << std::endl;
    }
    
    int_stack (const int_stack & myStack1) { // on nomme intstack la référence de Intstack
        size = myStack1.size;
        top = myStack1.top;
        stack = new int [size];
        for (int i = 0; i <= top; i ++) {
            stack[i] = myStack1.stack[i];  // rappel stack[i] = *(stack +i)
        }
        std::cout << "le copy constructeur est appelé" << std::endl;
    }
    
    /* différence entre le constructeur copy et l'operateur :
     
     le constructeur copie permet de créer une copie d'un ojbjet possédant une structure.
     Le constructeur copie est une fonction membre de cette structure.
     IntStack myStack2 = myStack1; implique le constructeur copie, on défini MyStack2 à ce moment-là.
      
     l'opérateur permet de recopier les données d'un objet dans un autre objet déjà créé.
     l'opérateur fait partie de la structure.
     MyStack2 = MyStack1; implique l'opérateur. MyStack2 a été défini au préalable.
     
     */
    int_stack & operator = (const int_stack & myStack1) {
        /* quand on fait MyStack2 = MyStack1; on veut recopier les données de MyStack1 dans MyStack2, this se rapporte à la l value donc à MyStack2, on veut donc supprimer les valeurs de l'attribut stackde MyStack2 étant donné qu'on n'en aura plus besoin, d'où le delete */
        delete [] stack;
        top = myStack1.top;
        size = myStack1.size;
        stack = new int [size];
        for ( int i =0; i <= top; i ++) {
            stack[i] = myStack1.stack[i];
        }
        std::cout << "l'opérateur est appelé" << std::endl;
        return * this;
    }
    
    void push(int n) {
        if (top >= 3) {
            std::cout << "plus de place" << std::endl;
        }
        if (top < 3) {
            *(stack + top) = n;
            top += 1;
        }
    }
    void print() {
        for (int i = 0; i < top; i = i + 1) {
            std::cout << stack[i] << std::endl;
        }
    }
    
    
    void pop() {
        top -= 1;
    }
    
};


















struct shape {
    
    int x; int y; // position de la shape
    
    void move(int dx, int dy) {
        x += dx; y += dy;
    }
    
    shape () { // constructeur
        x = 0 ; y = 0;
    }
    
    virtual float Calcularea () {
        return 0;
    }
    
};

struct circle : public shape {
    
    float r;
    float area;
    
    circle (float radius) { // constructeur
        r = radius;
    }
    
    float Calcularea () {
        area = pi * std::pow(r, 2);
        return area;
    }
    
};

struct rectangle : public shape {
    
    float L;
    float l;
    float area;
    
    rectangle (float Longueur, float largeur) { // constructeur
        L = Longueur; l = largeur;
    }
    
    float Calcularea () {
        area = L * l;
        return area;
    }
    
};

struct ShapeStack {
    shape * * stack;
    int size;
    int top;
    
    ShapeStack (int size) {
        stack = new shape* [size];
        top = 0;
        std::cout << "le constructeur est appelé" << std::endl;
    }
    
    ~ShapeStack () {
        delete [] stack;
        std::cout << "le detructeur est appelé" << std::endl;
    }
    
    void push(shape * forme) {
        if (top >= 3) {
            std::cout << "plus de place" << std::endl;
        }
        if (top < 3) {
            stack[top] = forme;
            top += 1;
        }
    }
    void print() {
        for (int i = 0; i < top; i = i + 1) {
            std::cout << stack[i] << " area : "<< ( *stack[i] ).Calcularea() << std::endl;
        }           // ( *stack[i] ).Calcularea() est équivalent à  stack[i]->Calcularea()
    }
    
    
    void pop() {
        top -= 1;
    }
    
};








int main (int argc, char ** argv) {
    std::cout << " PILE 1 : " << std::endl;
    IntStack3 stack;
    stack.init();
    stack.push(1);
    stack.push(2);
    //stack.pop();
    stack.print();
    
    std::cout << "  " << std::endl;
    std::cout << " PILE 2 : " << std::endl;
    IntStackTailleVariable stack2;
    stack2.init(6);
    stack2.push(1);
    stack2.push(2);
    stack2.push(3);
    stack2.push(4);
    stack2.pop();
    stack2.print();
    
    std::cout << "  " << std::endl;
    std::cout << " PILE 3 : " << std::endl;
    intStack stack3 (10);
    stack3.push(1);
    stack3.push(2);
    stack3.push(1);
    stack3.print();
    
    std::cout << "  " << std::endl;
    std::cout << " PILE 4 : " << std::endl;
    IntStack myStack1 (100);
    myStack1.push(1);
    myStack1.push(2);
    myStack1.print();
    { IntStack myStack2 = myStack1 ; } /* on crée une variable automatique myStack2 qui a pour durée de vie entre les { } qui est détruite par le destructeur dès la sortie de { } et qui est la copie de myStack1 sauf que les données (attributs) seront stockés à une autre adresse */
    
    std::cout << "  " << std::endl;
    std::cout << " PILE 5 : " << std::endl;
    int_stack MyStack1 (100);
    int_stack MyStack2 (100);
    myStack1.push(1);
    myStack1.push(2);
    myStack1.print();
    MyStack2 = MyStack1;
    std::cout << pi << std::endl;
    
    
    
    std::cout << "  " << std::endl;
    std::cout << " PILE 6 : " << std::endl;
    ShapeStack s (20);
    
    circle c(2.0);
    
    s.push(&c);
    s.push(new circle(20.0));
    s.push(new rectangle(10.0, 5.0));
    
    s.print();
    return 0;
}
