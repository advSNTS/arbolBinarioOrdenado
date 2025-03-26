#include "NodoBinario.h"

template <class T>
NodoBinario<T>::NodoBinario(){
    this->dato = NULL;
}

template <class T>
NodoBinario<T>::NodoBinario(T val){
    this->dato = val;
}

template <class T>
NodoBinario<T>::~NodoBinario() {
    delete this->hijoIzq;
    delete this->hijoDer;
}

template <class T>
T NodoBinario<T>::obtenerDato(){
    return this->dato;
}

template <class T>
void NodoBinario<T>::fijarDato(T val){
    this->dato = val;
}

template <class T>
NodoBinario<T>* NodoBinario<T>::obtenerHijoIzq(){
    return this->hijoIzq;
}

template <class T>
NodoBinario<T>* NodoBinario<T>::obtenerHijoDer(){
    return this->hijoDer;
}

template <class T>
void NodoBinario<T>::fijarHIjoIzq(NodoBinario<T>* izq){
    this->hijoIzq = izq;
}

template <class T>
void NodoBinario<T>::fijarHijoDer(NodoBinario<T>* der){
    this->hijoDer = der;
}

template <class T>
bool NodoBinario<T>::esHoja(){
    return (this->hijoDer==NULL && this->hijoIzq == NULL);
}