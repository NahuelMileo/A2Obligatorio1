#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/HeapImp.cpp"

using namespace std;

int main()
{
    int n;
    cin >> n;
    MinHeap heap(n);
    for (int i = 0; i < n; i++)
    {
        long long tamanio;
        cin >> tamanio;
        heap.insertar(tamanio);
    }
    long long costo = 0;
    while(heap.tamanio() > 1)
    {
        long long a = heap.eliminarMinimo();
        long long b = heap.eliminarMinimo();
        long long nuevo = a+b;
        costo+=nuevo;
        heap.insertar(nuevo);
    }
    cout << costo << "\n";
    return 0;
}