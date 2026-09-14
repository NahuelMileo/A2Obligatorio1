#ifndef AVL_IMP
#define AVL_IMP

#include "AVL.h"

using namespace std;

template <class T>

class AVLImp : public AVL<T>
{
    public:
        void insertar(T dato){
            raiz = insertar(raiz, dato);
        }
private:
    class Nodo
    {
    public:
        T dato;
        int altura;
        Nodo *izq;
        Nodo *der;
        Nodo(T dato) : dato(dato), altura(1), izq(NULL), der(NULL) {}
    };
    Nodo *raiz;
    void ActualizarAltura(Nodo *t)
    {
        int alturaIzq = t->izq ? t->izq->altura : 0;
        int alturaDer = t->der ? t->der->altura : 0;
        t->altura = std::max(alturaIzq, alturaDer) + 1;
    }
    int calcularBalance(Nodo *t)
    {
        int alturaIzq = t->izq ? t->izq->altura : 0;
        int alturaDer = t->der ? t->der->altura : 0;
        int diferencia = alturaDer - alturaIzq;
        return diferencia;
    }
    Nodo *rotacionIzquierda(Nodo *A, Nodo *B)
    {
        A->der = B->izq;
        B->izq = A;
        ActualizarAltura(A);
        ActualizarAltura(B);
        return B;
    }
    Nodo *rotacionDerecha(Nodo *A, Nodo *B)
    {
        A->izq = B->der;
        B->der = A;
        ActualizarAltura(A);
        ActualizarAltura(B);
        return B;
    }
    Nodo *insertar(Nodo *t, T dato)
    {
        if (!t)
        {
            return new Nodo(dato);
        }
        if (t->dato == dato)
            return t;
        else if (t->dato > dato)
        {
            t->izq = insertar(t->izq, dato);
        }
        else
        {
            t->der = insertar(t->der, dato);
        }
        ActualizarAltura(t);
        // Toca balancear
        // der - izq
        int balance = calcularBalance(t);
        // DD
        if (balance > 1 && t->der->dato < dato)
        {
            return rotacionIzquierda(t, t->der);
        }
        // DI
        if (balance > 1 && t->der->dato > dato)
        {
            t->der = rotacionDerecha(t->der, t->der->izq); // nos deja en DD
            return rotacionIzquierda(t, t->der);
        }
        // ID
        if (balance < -1 && t->izq->dato < dato)
        {
            t->izq = rotacionIzquierda(t->izq, t->izq->der);
            return rotacionDerecha(t, t->izq);
        }
        // II
        if (balance < -1 && t->izq->dato > dato)
        {
            return rotacionDerecha(t, t->izq);
        }
        return t;
    }

public:
    AVLImp() : raiz(NULL) {}
    ~AVLImp()
    { // Destructores
      // Liberamos la memoria
    }
};

#endif