#include <stdio.h>
#include <stdlib.h>
#include "Arbol.h"

// altura, nivel, minimo, maximo, insertar, modificar nodo, eliminar, mostrar

int capturar(int menu){
    switch(menu){
        case 1:printf("1. Altura \n2. Nivel\n3. M%cnimo\n4. M%cximo\n5. Insertar\n6. Modificar\n7. Eliminar\n8. Mostrar\n", 162, 160);break;
        case 2:printf("1. Preorden \n2. Inorden\n3. Postorden\n");break;
    }
    int numero;
    scanf("%d",&numero);
    return numero;
}

void menu(){
    int op = 0;
    int op2 = 0;
    while(1){
        op = capturar(1);
        switch(op){
            case 1: printf("altura \n"); break;
            case 2: printf("nivel \n"); break;
            case 3: printf("minimo \n"); break;
            case 4: printf("maximo \n"); break;
            case 5: printf("insertar \n"); break;
            case 6: printf("modificar \n"); break;
            case 7: printf("eliminar \n"); break;
            case 8:
                op2 = capturar(2);
                if(op2 == 1){
                    printf("preorden \n");
                }else if(op2 == 2){
                    printf("inorden \n");
                }else if(op2 == 3){
                    printf("postorden \n");
                }
            break;
            default: printf("No valido \n");break;
        }
    }
}

int main(){

    //init();

    menu();

    
    // int a[] = {5,3,4,2};
    // int i = 0;
    // for(;i<4;i++){
    //     Nodo* ad = crearNodo(a[i]);
    //     insertar(raiz, ad);
    // }
    // inOrden(raiz);
    // printf("\n");
    // eliminarNodo(raiz, 3);
    // inOrden(raiz);
    // printf("\n");



    //eliminarNodo(raiz, 20);
    //inOrden(raiz);
    //printf("\n");




}
