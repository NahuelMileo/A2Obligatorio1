// Basado en el MinHeap de la Clase 3 (clase-03-heap), adaptado a struct Modulo del ejercicio 4.
#include <iostream>
using namespace std;

struct Modulo
{
    int prioridad;
    int numero;
};

class MinHeapModulos
{
private:
    Modulo *datos;
    int cantidad;
    int capacidad;

    bool esMenor(Modulo a, Modulo b)
    {
        if (a.prioridad != b.prioridad)
        {
            return a.prioridad < b.prioridad;
        }
        return a.numero < b.numero;
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
        Modulo aux = datos[pos1];
        datos[pos1] = datos[pos2];
        datos[pos2] = aux;
    }

    void flotar(int pos)
    {
        while (pos > 0 && esMenor(datos[pos], datos[padre(pos)]))
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
                esMenor(datos[hijoDerecho(pos)], datos[hijoIzquierdo(pos)]))
            {

                hijoMenor = hijoDerecho(pos);
            }

            if (esMenor(datos[pos], datos[hijoMenor]))
            {
                return;
            }

            intercambiar(pos, hijoMenor);
            pos = hijoMenor;
        }
    }

public:
    MinHeapModulos(int capacidad)
    {
        this->capacidad = capacidad;
        this->cantidad = 0;
        this->datos = new Modulo[capacidad];
    }

    ~MinHeapModulos()
    {
        delete[] datos;
    }

    bool esVacio()
    {
        return cantidad == 0;
    }

    int tamanio()
    {
        return cantidad;
    }

    void insertar(Modulo m)
    {
        if (cantidad == capacidad)
        {
            return;
        }

        datos[cantidad] = m;
        flotar(cantidad);
        cantidad++;
    }

    Modulo eliminarMinimo()
    {
        Modulo minimo = datos[0];
        datos[0] = datos[cantidad - 1];
        cantidad--;
        if (cantidad > 0)
        {
            hundir(0);
        }
        return minimo;
    }
};