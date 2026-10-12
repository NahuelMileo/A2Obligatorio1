#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/AVLImp.cpp"

using namespace std;

int main()
{
  int cantidad;
  cin >> cantidad;

  AVL<long long> monedas;
  AVL<string> pinturas;

  for(int i = 0; i < cantidad; i++)
  {
    string operacion;
    char coleccion;
    cin >> operacion >> coleccion;

    if(operacion == "ALTA")
    {
        if(coleccion == 'M')
        {
            long long c;
            cin >> c;
            monedas.insertar(c);
        }
        else
        {
            string t;
            cin >> t;
            pinturas.insertar(t);
        }
    }
    else if(operacion == "BUSCAR")
    {
        bool esta;
        if(coleccion == 'M')
        {
            long long c;
            cin >> c;
            esta = monedas.pertenece(c);
        }
        else
        {
            string t;
            cin >> t;
            esta = pinturas.pertenece(t);
        }
        cout << (esta ? "si" : "no") << "\n";
    }
    else{
        if(coleccion == 'M')
        {
            long long desde, hasta;
            cin >> desde >> hasta;
            monedas.rango(desde, hasta);
        }
        else
        {
            string desde, hasta;
            cin >> desde >> hasta;
            pinturas.rango(desde, hasta);
        }
    }
  }
  return 0;
};