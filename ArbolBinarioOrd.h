#ifndef ARBOLBINARIOORD_H
#define ARBOLBINARIOORD_H

#include "NodoBinario.h"
template <class T>
class ArbolBinarioOrd
{
protected:
    NodoBinario<T>* raiz;
public:
    ArbolBinarioOrd(/* args */);
    ~ArbolBinarioOrd();
    bool esVacio();
    T datoRaiz();
    int altura();
    int tamano();
    int tamano(NodoBinario<T>* nodo);
    bool insertar(T val);
    bool eliminar(T val);
    bool buscar(T val);
    void preOrden();
    void preOrden(NodoBinario<T>* nodo);
    void inOrden();
    void inOrden(NodoBinario<T>* nodo);
    void posOrden();
    void posOrden(NodoBinario<T>* nodo);
    void nivelOrden();
    int altura(NodoBinario<T>* nodo);
};


#include "ArbolBinarioOrd.hxx"
#endif