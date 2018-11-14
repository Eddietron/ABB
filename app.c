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
    while(op != 11){
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
                encontrarDato((*capturarDato)(5));
                break;
            case 6: 
                valorMaximo();
                break;
            case 7:
                valorMinimo();
                break;
            case 8:
                printf("Altura: %d\n", altura(raiz));
                break;
            case 9: 
                printf("Nivel: %d\n", nivelNodo(raiz, (*getDato)(1), 0));
                break;
            case 10:
                system("cls");
                break;
            case 11:
                printf("Saliendo...\n");
                break;
            default: 
                printf("Opcion no valida\n");
                break;
        }
    }
}
//captura la opcion que el usuario elige en e menu
int capturarOpcion(){
    printf("1. Insertar \n2. Mostrar\n3. Modificar\n4. Eliminar\n5. Encontrar valor\n6. Valor maximo\n7. Valor minimo\n8. Altura del arbol\n9. Nivel\n10.Limpiar\n11.Salir\n");
    int numero;
    scanf("%d",&numero);
    return numero;
}
//fuincion para capturar datos, desplega un mensaje  diferente cuando i tiene determinados valores
int capturarDato(int i){
    if (i == 1)
        printf("Inserta el dato\n");
    else if ( i == 2)
        printf("Inserta el dato a modificar\n");
    else if( i == 3)
        printf("Inserta el nuevo dato\n");
    else if( i == 4)
        printf("Inserte dato a eliminar\n");
    else if( i == 5)
        printf("Inserta el dato a encontrar\n");
    int n;
    scanf("%d", &n);
    return n;
}
