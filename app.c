#include <stdio.h>
#include <stdlib.h>
#include "Arbol.h"


int capturarDato();
int capturarOpcion();
void menu();

Nodo* (*cnsd)() = crearNodoPD;
int (*getDato)(int) = capturarDato;

int main(){
    init();
    menu();
}

void menu(){
    int op = 0;
    while(op != 10){
        op = capturarOpcion();
        switch(op){
            case 1:
                insertar(raiz, (*cnsd)());
                break;
            case 2:
                mostrar();
                break;
            case 3:
                modificarNodo(raiz, (*getDato)(3), (*getDato)(2));
                break;
            case 4:
                eliminarNodo(raiz, (*getDato)(4));
                break;
            case 5: 
                valorMaximo();
                break;
            case 6: 
                valorMinimo();
                break;
            case 7:
                printf("Altura: %d\n", altura(raiz));
                break;
            case 8:
                printf("Nivel: %d\n", nivelNodo(raiz, (*getDato)(1), 0));
                break;
            case 9: 
                system("cls");
                break;
            case 10:
            printf("Saliendo...\n");
                break;
            default: 
                printf("Opcion no valida\n");
                break;
        }
    }
}

int capturarOpcion(){
    printf("1. Insertar \n2. Mostrar\n3. Modificar\n4. Eliminar\n5. Valor m%cximo\n6. Valor m%cnimo\n7. Altura del arbol\n8. Nivel\n9. Limpiar\n10. Salir\n", 160, 162);
    int numero;
    scanf("%d",&numero);
    return numero;
}

int capturarDato(int i){
    if (i == 1)
        printf("Inserta el dato\n");
    else if ( i == 2)
        printf("Inserta el dato a modificar\n");
    else if( i == 3)
        printf("Inserta el nuevo dato\n");
    else if( i == 4)
        printf("Inserte dato a eliminar");
    int n;
    scanf("%d", &n);
    return n;
}
