#ifndef NODOBINARIO_H
#define NODOBINARIO_H

template <class T>
class NodoBinario
{
protected:
    T dato;
    NodoBinario<T>* hijoIzq;
    NodoBinario<T>* hijoDer;
public:
    NodoBinario();
    NodoBinario(T val);
    ~NodoBinario();
    T obtenerDato();
    void fijarDato(T val);
    NodoBinario<T>* obtenerHijoIzq();
    NodoBinario<T>* obtenerHijoDer();
    void fijarHIjoIzq(NodoBinario<T>* izq);
    void fijarHijoDer(NodoBinario<T>* der);
    bool esHoja();
};


#include "NodoBinario.hxx"
#endif