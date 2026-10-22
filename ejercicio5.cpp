#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/MFSet.h"
#include "tads/HeapArista.cpp"

using namespace std;

int main()
{
    int v, e;
    cin >> v >> e;
    MinHeapAristas heap(e);
    for (int i = 0; i < e; i++)
    {
        int origen, destino, costo;
        cin >> origen >> destino >> costo;
        heap.insertar(Arista(origen, destino, costo));
    }
    MFSet *conjuntos = new MFSet(v + 1);
    long long costoTotal = 0;
    int enElArbol = 0;
    // Adaptado con Claude Code
    while (!heap.esVacio() && enElArbol < v - 1)
    {
        Arista a = heap.eliminarMinimo();
        if (conjuntos->unir(a.origen, a.destino))
        { // no cierra ciclo
            costoTotal += a.costo;
            enElArbol++;
        }
    }
    if (enElArbol < v - 1)
    {
        cout << "imposible\n";
    }
    else
    {
        cout << costoTotal << "\n";
    }
}