// Basado en el grafo con lista de adyacencia de la clase 6 Kahn.
#include <cstddef> // para NULL

class Arista {
    public:
    int destino;
    Arista * sig; // es para la lista encadenada no para el grafo
    Arista(int d): destino(d), sig(NULL) {}
};

class GrafoLA {
    private:
    Arista ** lista;
    int n;
    public:
    GrafoLA(int nodos) {
        this->n = nodos;
        this->lista = new Arista*[this->n+1];
        for (int i = 0; i <= this->n; i ++) {
            this->lista[i] = NULL; // arranca sin vecinos: lista vacia
        }
    }
    void agregarArista(int origen, int destino) {
        Arista * nueva = new Arista(destino);
        nueva->sig = lista[origen];
        lista[origen] = nueva;
    }
    Arista * vecinosNodo(int nodo) {
        return this->lista[nodo];
    }
};