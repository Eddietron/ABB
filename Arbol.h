typedef struct nodo{
    int dato;
    struct nodo* hizq;
    struct nodo* hder;
}Nodo;

Nodo** raiz;

void init();
void insertar(Nodo** raiz, Nodo* nuevo);
void mostrar(Nodo** raiz);
int eliminarNodo(Nodo** raiz, int id);

int getRecorrido();
void inOrden(Nodo** raiz);
void preOrden(Nodo** raiz);
void postOrden(Nodo** raiz);
int altura(Nodo** raiz);
Nodo** minimo(Nodo** raiz);
Nodo** maximo(Nodo** raiz);
Nodo* crearNodo(int dato);
