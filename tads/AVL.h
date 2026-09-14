#ifndef AVL_H
#define AVL_H

template <class T>
class AVL
{
    public:
        // pre:
        // post: inserta un nodo de tipo T
        virtual void insertar(T dato) = 0;

        // pre: arbol existe
        // post: retorna si el dato pertenece al árbol
        virtual bool pertenece(T dato) = 0;
        
        // pre: desde <= hasta
        // post: devuelve valores en ese rango
        virtual void rango(T desde, T hasta) = 0;
};

#endif