#include <stdio.h>
#include <stdlib.h>
#include "Arbol.h"
int getOpcionMenu();
int getDato(int opcion);
void menu();
void limpiar();
/*Puntero a funcion*/
Nodo* (*nodo)() = nuevoNodo;
int (*dato)(int);
/*Menu de la aplicacion*/
void menu(){
    int op = 0;
    while(op != 6){
        op = getOpcionMenu();
        switch(op){
            case 1:
                insertar(raizArbol, (*nodo)());
                break;
            case 2:
                buscar(raizArbol, (*dato)(2));
                break;
            case 3:
            //se ejecutan de izquierda a derecha
                modificar(raizArbol, (*dato)(3), (*dato)(1));
                break;
            case 4:
                mostrar(raizArbol);
                break;
            case 5:
                limpiar();
                break;
            case 6:
                printf("Saliendo...\n");
                break;
        }
        
    }
}
int getDato(int opcion){
    int n = 0;
    if(opcion == 1)
        printf("Ingresa el dato a modificar: ");
    else if(opcion == 2)
        printf("Ingresa el dato a buscar: ");
    else if(opcion == 3)
        printf("Ingresa el nuevo dato: ");
        
    
    scanf("%d",&n);
    return n;
}

int getOpcionMenu(){
    printf("Seleccione la operacion:\n1. Insertar\n2. Buscar\n3. Modificar\n4. Mostrar\n5. Limpiar\n6. Salir\n");
    int n;
    scanf("%d", &n);
    if(n>=1 && n<=6)
        return n;
    return getOpcionMenu();
}


int main(){
    init();
    dato = getDato;
    menu();
}
void limpiar(){
    system("cls");
}
