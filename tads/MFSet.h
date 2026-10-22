// Archivo sacado de clase-07-kruskal, adaptación del método unir, optimización por tamaño -> optimización por altura
class MFSet {
    private:
    int * padre;
    int * altura;
    int largo;

    public:
    MFSet(int n) {
        this->largo = n;
        this->padre = new int[this->largo];
        this->altura = new int[this->largo];
        for (int i = 0; i < this->largo; i ++) {
            this->padre[i] = i;
            this->altura[i] = 1;
        }
    }
    int representante(int a) {
        if (a == this->padre[a]) {
            return a;
        }
        this->padre[a] = representante(this->padre[a]); // compresion de caminos
        return this->padre[a];
    }
    // Método adaptado con Claude Code
    bool unir(int a, int b) { // devuelve si pudo unir o no
        int repA = representante(a);
        int repB = representante(b);
        if (repA == repB){
            return false;
        }
        if (this->altura[repA] > this->altura[repB]) { // Optimizacion por altura
            this->padre[repB] = repA;
        } else if (this->altura[repA] < this->altura[repB]){
            this->padre[repA] = repB;
        }else{
            this->padre[repB] = repA;
            this->altura[repA]++;
        }
        return true;
    }
};