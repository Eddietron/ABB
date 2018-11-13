#include <stdio.h>
#include <stdlib.h>
#include "Arbol.h"

// altura, nivel, minimo, maximo, insertar, modificar nodo, eliminar, mostrar
int pedirDato(char* texto){
    system("cls");
    int numero;
    printf(texto);
    scanf("%d",&numero);
    return numero;
}

void menu(){
    int op = 0;
    while(op != 4){
        op = pedirDato("1. Altura \n2. Nivel\n3. Mínimo\n4. Máximo\n5. Insertar\n6. Modificar\n7. Eliminar\n8. Mostrar");
        switch(op){
            case 
        }
    }
}

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



int main(){
    int op = 0;
    void (*funciones[])() = {PruebaOpcion1, PruebaOpcion2, PruebaOpcion3};
    while(op != 4){
        system("cls");
        printf("1. Algoritmos de busqueda\n2. Algoritmos de ordenamiento\n3. Algoritmos de fubonacci\n4. Salir\n");
        op = capturar();
        if(op == 4){
            printf("Saliendo...");
            return 1;
        }
        (*funciones[op-1])();
        system("pause");
    }
}





}
