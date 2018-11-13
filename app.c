#include <stdio.h>
#include <stdlib.h>
#include "Arbol.h"

int main(){
    init();
    int a[] = {5,3,4,2};
    int i = 0;
    for(;i<4;i++){
        Nodo* ad = crearNodo(a[i]);
        insertar(raiz, ad);
    }
    inOrden(raiz);
    printf("\n");
    eliminarNodo(raiz, 3);
    inOrden(raiz);
    printf("\n");
    //eliminarNodo(raiz, 20);
    //inOrden(raiz);
    //printf("\n");
}
