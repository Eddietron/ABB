#include <stdio.h>
#include <stdlib.h>
#include "Arbol.h"

// altura, nivel, minimo, maximo, insertar, modificar nodo, eliminar, mostrar

int capturar(int menu){
    system("cls");
    switch(menu){
        case 1:printf("1. Altura \n2. Nivel\n3. Mínimo\n4. Máximo\n5. Insertar\n6. Modificar\n7. Eliminar\n 8. Mostrar\n");break;
        case 2:printf("1. Preorden \n2. Inorden\n3. Postorden\n");break;
        default: printf("No valido \n");break;
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
            case 1: /*ALTURA*/ break;
            case 2: /*NIVEL*/ break;
            case 3: /*MÍNIMO*/ break;
            case 4: /*MÁXIMO*/ break;
            case 5: /*INSERTAR*/ break;
            case 6: /*MODIFICAR*/ break;
            case 7: /*ELIMINAR*/ break;
            case 8:
                op2 = capturar(2);
                if(op2 == 1){
                    /*preoreden*/
                }else if(op2 == 2){
                    /*ihnorden*/
                }else if(op2 == 3){
                    /*postorden*/
                }
            break;
            default: break;
        }
    }
}

int main(){

    init();

    menu();

    
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
