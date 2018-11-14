typedef struct nodo{
    int dato;
    struct nodo* hizq;
    struct nodo* hder;
}Nodo;

Nodo** raiz;

void init();
void insertar(Nodo** raiz, Nodo* nuevo);
void mostrar();
int eliminarNodo(Nodo** raiz, int id);
Nodo* encontrarNodo(Nodo** raiz, int id);
int getRecorrido();
void inOrden(Nodo** raiz);
void preOrden(Nodo** raiz);
void postOrden(Nodo** raiz);
int altura(Nodo** raiz);
int nivelNodo(Nodo** raiz, int id, int nivel);
int modificarNodo(Nodo** raiz, int nuevo, int id);
Nodo** minimo(Nodo** raiz);
void valorMaximo();
void valorMinimo();
Nodo** maximo(Nodo** raiz);
Nodo* crearNodo(int id);
Nodo* crearNodoPD();
void encontrarDato(int id);
