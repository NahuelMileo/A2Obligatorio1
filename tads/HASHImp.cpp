#include <iostream>
using namespace std;

class Cajon
{
public:
    string etiqueta;
    int contador;
    Cajon *sig;
    Cajon(string etiqueta) : etiqueta(etiqueta), contador(1), sig(NULL) {}
};

class Hash
{
private:
    Cajon **datos;
    int largo;
    int cantidadCajones;
    int cantidadPalabrasCajonMasLleno;
    bool esPrimo(int num)
    {
        if (num < 2)
            return false;
        for (int i = 2; i * i <= num; i++)
        {
            if (num % i == 0)
                return false;
        }
        return true;
    }

    int primoSup(int num)
    {
        while (!esPrimo(++num))
            ;
        return num;
    }

    int hash(string etiqueta)
    {
        int h = 0;
        for (int i = 0; i < (int)etiqueta.size(); i++)
        {
            h = (h * 13 + etiqueta[i]) % this->largo;
        }
        return h;
    }

    Cajon *buscar(string etiqueta)
    {
        int pos = hash(etiqueta);

        Cajon *actual = this->datos[pos];
        bool encontre = false;
        while (actual != NULL && !encontre)
        {
            if (actual->etiqueta == etiqueta)
            {
                encontre = true;
            }
            else
            {
                actual = actual->sig;
            }
        }
        return actual;
    }

public:
    Hash(int esperados)
    {
        this->largo = primoSup(esperados);
        this->cantidadCajones = 0;
        this->cantidadPalabrasCajonMasLleno = 0;
        this->datos = new Cajon *[this->largo];
        for (int i = 0; i < this->largo; i++)
        {
            this->datos[i] = NULL;
        }
    }

    void insertar(string etiqueta)
    {
        Cajon *actual = buscar(etiqueta);
        if (actual)
        {
            actual->contador++;
        }
        else
        {
            int pos = hash(etiqueta);
            Cajon *c = new Cajon(etiqueta);
            c->sig = this->datos[pos];
            this->datos[pos] = c;
            this->cantidadCajones++;
            actual = c;
        }

        if (actual->contador > this->cantidadPalabrasCajonMasLleno)
        {
            this->cantidadPalabrasCajonMasLleno = actual->contador;
        }
    }

    int consultar(string etiqueta)
    {
        Cajon *actual = buscar(etiqueta);
        if (actual)
        {
            return actual->contador;
        }
        else
        {
            return 0;
        }
    }

    int getCantidadCajones()
    {
        return this->cantidadCajones;
    }
    int getCantidadPalabrasCajonMasLleno()
    {
        return this->cantidadPalabrasCajonMasLleno;
    }
    ~Hash()
    {
        for(int i = 0; i<largo; i++)
        {
            Cajon *actual = this->datos[i];
            while(actual)
            {   
                Cajon *sig = actual->sig;
                delete actual;
                actual = sig;
            }
        }
        delete[] datos;
    }
};