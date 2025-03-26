#include <iostream>
#include "ArbolBinarioOrd.h"

int main(){
    ArbolBinarioOrd<int> arbol;
    arbol.insertar(50);
    arbol.insertar(30);
    arbol.insertar(70);
    arbol.insertar(20);
    arbol.insertar(40);
    arbol.insertar(60);
    arbol.insertar(80);

    std::cout << "Tamaño antes de eliminar: " << arbol.tamano() << std::endl;

    arbol.eliminar(30);  // Caso 3: Nodo con dos hijos
    arbol.eliminar(20);  // Caso 1: Nodo hoja
    arbol.eliminar(70);  // Caso 2: Nodo con un solo hijo

    std::cout << "Tamaño después de eliminar: " << arbol.tamano() << std::endl;
    arbol.preOrden();
    return 0;
}