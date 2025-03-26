#include "ArbolBinarioOrd.h"
#include <queue>


template <class T>
ArbolBinarioOrd<T>::ArbolBinarioOrd(){
    this->raiz=NULL;
}

template <class T>
ArbolBinarioOrd<T>::~ArbolBinarioOrd(){
    if(this->raiz!=NULL){
        delete this->raiz;
        this->raiz = NULL;
    }
}

template <class T>
bool ArbolBinarioOrd<T>::esVacio(){
    return this->raiz == NULL;
}


template <class T>
T ArbolBinarioOrd<T>::datoRaiz(){
    return (this->raiz)->obtenerDato();
}

template <class T>
int ArbolBinarioOrd<T>::altura(){
    if(this->esVacio()){
        return -1;
    }
    else{
        return this->altura(this->raiz);
    }
}

template <class T>
int ArbolBinarioOrd<T>::altura(NodoBinario<T>* nodo){
    int valt;

    if(nodo->esHoja()){
        valt = 0;
    }
    else{
        int valt_izq = -1;
        int valt_der = -1;
        if(nodo->obtenerHijoIzq() != NULL){
            valt_izq = this->altura(nodo->obtenerHijoIzq());
        }
        if(nodo->obtenerHijoDer() != NULL){
            valt_der = this->altura(nodo->obtenerHijoDer());
        }
        if(valt_izq>valt_der){
            valt = valt_izq +1;
        }
        else{
            valt = valt_der +1;
        }
    }

    return valt;
}

template <class T>
void ArbolBinarioOrd<T>::inOrden(){
    if(!this->esVacio()){
        this->inOrden(this->raiz);
    }
}

template <class T>
void ArbolBinarioOrd<T>::inOrden(NodoBinario<T>* nodo){
    if(nodo!=NULL){
        this->inOrden(nodo->obtenerHijoIzq());
        std::cout<<nodo->obtenerDato()<<" ";
        this->inOrden(nodo->obtenerHijoDer());
    }
}

template <class T>
bool ArbolBinarioOrd<T>::buscar(T val){
    NodoBinario<T>* nodo = this->raiz;
    bool encontrado = false;

    while(nodo!=NULL && !encontrado){
        if(val< nodo->obtenerDato()){
            nodo = nodo->obtenerHijoIzq();
        }else if( val > nodo->obtenerDato()){
            nodo = nodo->obtenerHijoDer();
        }else{
            encontrado = true;
        }
    }
    return encontrado;
}

template <class T>
bool ArbolBinarioOrd<T>::insertar(T val){
    if(this->raiz==NULL){
        NodoBinario<T>* nuevo = new NodoBinario<T>();
        nuevo->fijarDato(val);
        this->raiz = nuevo;
        return true;
    }
    NodoBinario<T>* nodo = this->raiz;
    NodoBinario<T>* padre = this->raiz;
    bool insertado = false;
    bool duplicado = false;

    while(nodo!=NULL){
        padre = nodo;
        if(val < nodo->obtenerDato()){
            nodo = nodo->obtenerHijoIzq();
        }else if( val > nodo->obtenerDato()){
            nodo = nodo->obtenerHijoDer();
        }else{
            duplicado = true;
            break;
        }
    }
    if(!duplicado){
        NodoBinario<T>* nuevo = new NodoBinario<T>();
        nuevo->fijarDato(val);
        if(nuevo!=NULL){
            if(val<padre->obtenerDato()){
                padre->fijarHIjoIzq(nuevo);
            }
            else{
                padre->fijarHijoDer(nuevo);
            }
        }
        insertado = true;
    }
    return insertado;
}

template <class T>
void ArbolBinarioOrd<T>::nivelOrden(){
    if(!this->esVacio()){
        std::queue <NodoBinario<T>*> cola;
        cola.push(this->raiz);
        NodoBinario<T>* nodo;
        while(!cola.empty()){
            nodo = cola.front();
            cola.pop();
            std::cout<<nodo->obtenerDato()<<" ";
            if(nodo->obtenerHijoIzq()!=NULL){
                cola.push(nodo->obtenerHijoIzq());
            }
            if(nodo->obtenerHijoDer()!=NULL){
                cola.push(nodo->obtenerHijoDer());
            }
        }
    }
}

template <class T>
int ArbolBinarioOrd<T>::tamano() {
    return tamano(this->raiz);
}


template <class T>
int ArbolBinarioOrd<T>::tamano(NodoBinario<T>* nodo) {
    if (nodo == NULL) {
        return 0;
    }
    return 1 + tamano(nodo->obtenerHijoIzq()) + tamano(nodo->obtenerHijoDer());
}

template <class T>
bool ArbolBinarioOrd<T>::eliminar(T val) {
    NodoBinario<T>* nodo = this->raiz;
    NodoBinario<T>* padre = nullptr;

    // 1. Buscar el nodo a eliminar y su padre
    while (nodo != nullptr && nodo->obtenerDato() != val) {
        padre = nodo;
        if (val < nodo->obtenerDato()) {
            nodo = nodo->obtenerHijoIzq();
        } else {
            nodo = nodo->obtenerHijoDer();
        }
    }

    if (nodo == nullptr) {
        return false;  // No se encontró el valor
    }

    // Caso 1: El nodo es una hoja
    if (nodo->esHoja()) {
        if (padre == nullptr) {
            this->raiz = nullptr;
        } else if (padre->obtenerHijoIzq() == nodo) {
            padre->fijarHIjoIzq(nullptr);
        } else {
            padre->fijarHijoDer(nullptr);
        }
        delete nodo;
    }
    // Caso 2: Nodo con un solo hijo
    else if (nodo->obtenerHijoIzq() == nullptr || nodo->obtenerHijoDer() == nullptr) {
        NodoBinario<T>* hijo = (nodo->obtenerHijoIzq() != nullptr) ? nodo->obtenerHijoIzq() : nodo->obtenerHijoDer();

        if (padre == nullptr) {
            this->raiz = hijo;  // Si eliminamos la raíz, el hijo se convierte en la nueva raíz
        } else if (padre->obtenerHijoIzq() == nodo) {
            padre->fijarHIjoIzq(hijo);
        } else {
            padre->fijarHijoDer(hijo);
        }
        delete nodo;
    }
    // Caso 3: Nodo con dos hijos
    else {
        NodoBinario<T>* sucesor = nodo->obtenerHijoDer();
        NodoBinario<T>* padreSucesor = nodo;

        // Buscar el nodo más pequeño en el subárbol derecho (sucesor inorden)
        while (sucesor->obtenerHijoIzq() != nullptr) {
            padreSucesor = sucesor;
            sucesor = sucesor->obtenerHijoIzq();
        }

        // Reemplazar el valor del nodo a eliminar con el del sucesor
        nodo->fijarDato(sucesor->obtenerDato());

        // Ajustar punteros para eliminar el sucesor
        if (padreSucesor->obtenerHijoIzq() == sucesor) {
            padreSucesor->fijarHIjoIzq(sucesor->obtenerHijoDer());
        } else {
            padreSucesor->fijarHijoDer(sucesor->obtenerHijoDer());
        }

        delete sucesor;
    }

    return true;
}

template <class T>
void ArbolBinarioOrd<T>::preOrden() {
    preOrden(this->raiz);
    std::cout << std::endl;
}

template <class T>
void ArbolBinarioOrd<T>::preOrden(NodoBinario<T>* nodo) {
    if (nodo == NULL) {
        return;
    }
    std::cout << nodo->obtenerDato() << " ";
    preOrden(nodo->obtenerHijoIzq());
    preOrden(nodo->obtenerHijoDer());
}


template <class T>
void ArbolBinarioOrd<T>::posOrden() {
    posOrden(this->raiz);
    std::cout << std::endl;
}

template <class T>
void ArbolBinarioOrd<T>::posOrden(NodoBinario<T>* nodo) {
    if (nodo == NULL) {
        return;
    }
    posOrden(nodo->obtenerHijoIzq());
    posOrden(nodo->obtenerHijoDer());
    std::cout << nodo->obtenerDato() << " "; 
}