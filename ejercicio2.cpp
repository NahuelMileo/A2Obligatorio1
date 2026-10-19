#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/HASHImp.cpp"

using namespace std;

string etiquetaDe(string palabra)
{
    int contador[26] = {0};

    for (int i = 0; i < (int)palabra.size(); i++)
    {
        contador[palabra[i] - 'a']++;
    }

    string etiqueta = "";

    for (int letra = 0; letra < 26; letra++)
    {
        for (int j = 0; j < contador[letra]; j++)
        {
            etiqueta += (char)('a' + letra);
        }
    }
    return etiqueta;
}

int main()
{
    int n;
    string palabra;
    cin >> n;
    Hash tabla(n);
    for (int i = 0; i < n; i++)
    {
        cin >> palabra;
        tabla.insertar(etiquetaDe(palabra));
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> palabra;
        cout << tabla.consultar(etiquetaDe(palabra)) << "\n";
    }
    cout << tabla.getCantidadCajones() << " " << tabla.getCantidadPalabrasCajonMasLleno() << "\n";
    return 0;
}