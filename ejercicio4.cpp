#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/GrafoImp.cpp"
#include "tads/HeapGrafos.cpp"

using namespace std;

int main()
{
    int v, a;
    cin >> v >> a;
    int *prioridad = new int[v + 1];
    for (int i = 1; i <= v; i++)
    {
        cin >> prioridad[i];
    }

    GrafoLA *g = new GrafoLA(v);
    int *grado = new int[v + 1]();
    for (int i = 0; i < a; i++)
    {
        int u, w;
        cin >> u >> w;
        g->agregarArista(u, w);
        grado[w]++;
    }

    MinHeapModulos heap(v);
    for (int nodo = 1; nodo <= v; nodo++)
    {
        if (grado[nodo] == 0)
        {
            Modulo m;
            m.prioridad = prioridad[nodo];
            m.numero = nodo;
            heap.insertar(m);
        }
    }

    int *orden = new int[v];
    int procesados = 0;
    // Función adaptada por Claude
    while (!heap.esVacio())
    {
        Modulo actual = heap.eliminarMinimo();
        orden[procesados] = actual.numero;
        procesados++;

        Arista *vec = g->vecinosNodo(actual.numero);
        while (vec)
        {
            grado[vec->destino]--;
            if (grado[vec->destino] == 0)
            {
                Modulo m;
                m.prioridad = prioridad[vec->destino];
                m.numero = vec->destino;
                heap.insertar(m);
            }
            vec = vec->sig;
        }
    }
    if (procesados == v)
    {
        for (int i = 0; i < v; i++)
        {
            cout << orden[i] << "\n";
        }
    }
    else
    {
        cout << "imposible\n";
    }

    return 0;
}