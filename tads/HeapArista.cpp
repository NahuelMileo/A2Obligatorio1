// Basado en el MinHeap de la Clase 3 (clase-03-heap), adaptado a aristas del ejercicio 5.
#include <iostream>
using namespace std;

class Arista{
    public:
    int origen;
    int destino;
    int costo;
    Arista(int o, int d, int c): origen(o), destino(d), costo(c){};
    Arista(): origen(0), destino(0), costo(0){};
};

class MinHeapAristas
{
private:
    Arista* aristas;
    int cantidad;
    int capacidad;

    bool esMenor(Arista a, Arista b)
    {
       return a.costo < b.costo;
    }

    int padre(int pos)
    {
        return (pos - 1) / 2;
    }

    int hijoIzquierdo(int pos)
    {
        return 2 * pos + 1;
    }

    int hijoDerecho(int pos)
    {
        return 2 * pos + 2;
    }

    void intercambiar(int pos1, int pos2)
    {
        Arista aux = aristas[pos1];
        aristas[pos1] = aristas[pos2];
        aristas[pos2] = aux;
    }

    void flotar(int pos)
    {
        while (pos > 0 && esMenor(aristas[pos], aristas[padre(pos)]))
        {
            intercambiar(pos, padre(pos));
            pos = padre(pos);
        }
    }

    void hundir(int pos)
    {
        while (hijoIzquierdo(pos) < cantidad)
        {

            int hijoMenor = hijoIzquierdo(pos);

            if (hijoDerecho(pos) < cantidad &&
                esMenor(aristas[hijoDerecho(pos)], aristas[hijoIzquierdo(pos)]))
            {

                hijoMenor = hijoDerecho(pos);
            }

            if (esMenor(aristas[pos], aristas[hijoMenor]))
            {
                return;
            }

            intercambiar(pos, hijoMenor);
            pos = hijoMenor;
        }
    }

public:
    MinHeapAristas(int capacidad)
    {
        this->capacidad = capacidad;
        this->cantidad = 0;
        this->aristas = new Arista[capacidad];
    }

    ~MinHeapAristas()
    {
        delete[] aristas;
    }

    bool esVacio()
    {
        return cantidad == 0;
    }

    int tamanio()
    {
        return cantidad;
    }

    void insertar(Arista a)
    {
        if (cantidad == capacidad)
        {
            return;
        }

        aristas[cantidad] = a;
        flotar(cantidad);
        cantidad++;
    }

    Arista eliminarMinimo()
    {
        Arista minimo = aristas[0];
        aristas[0] = aristas[cantidad - 1];
        cantidad--;
        if (cantidad > 0)
        {
            hundir(0);
        }
        return minimo;
    }
};