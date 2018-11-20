/**
  * @file app.c
  * @date 13/11/2018
  * @author Eddieson Cortés
  * @author Fernando Servín
  * @brief Menú y llamada de todos lo métodos de árbol
  */
#include <stdio.h>
#include <stdlib.h>
#include "Arbol.h"
#include "DatosLibreria.h"

/**
* @brief Captura el dato para ser usado en las funciones básicas del árbol
* @return int dato anotado por el usuario
*/
char* capturarDato(int);

/**
* @brief Captura la opción del menú
* @return int dato anotado por el usuario
*/
int capturarOpcion();

/**
* @brief Imprime el menú y pidel la opción al usuario
*/
void menu();

/**
 * @brief Función callback de tipo Nodo*
 * Crea un nodo pidiéndo al usuario ingresar el dato
 * @return Nodo* con valor asignado
 */
Nodo* (*cnsd)() = crearNodoPD;

/**
 * @brief Función callback de tipo int
 * Pide al usuario un entero para ser usado ya sea en el menú o en las operaciones básicas del árbol
 * @return Nodo* con valor asignado
 */
char* (*getDato)(int) = capturarDato;
/**
 * @brief Método main inicia el árbol y el menú
 * @return 0 o 1
 */
int main(){
    init();
    menu();
}

/**
* @brief Imprime el menú y pidel la opción al usuario
*/
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
                modificarNodo(raiz,(*getDato)(6), (*getDato)(3), (*getDato)(2));
                break;
            case 4:
                eliminarNodo(raiz, (*getDato)(4));
                break;
            case 5: 
                encontrarDato((*getDato)(5));
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
                printf("Nivel: %d\n", nivelNodo(raiz, (*getDato)(1), 1));
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

/**
* @brief Captura la opción del menú
* @return int dato anotado por el usuario
*/
int capturarOpcion(){
    printf("1. Insertar \n2. Mostrar\n3. Modificar\n4. Eliminar\n5. Encontrar valor\n6. Valor maximo\n7. Valor minimo\n8. Altura del arbol\n9. Nivel\n10.Limpiar\n11.Salir\n");
    int numero;
    scanf("%d",&numero);
    return numero;
}

/**
* @brief Captura el dato para ser usado en las funciones básicas del árbol
* @return int dato anotado por el usuario
*/
char* capturarDato(int i){
    if (i == 1)
        printf("Inserta la palabra\n");
    else if ( i == 2)
        printf("Inserta la palabra a modificar\n");
    else if( i == 3)
        printf("Inserta la nueva palabrar\n");
    else if( i == 4)
        printf("Inserte el dato a eliminar\n");
    else if( i == 5)
        printf("Inserta la palabra a encontrar\n");
    else if( i == 6)
        printf("Inserta el significado\n");
    char* s = NULL;
    s = getString();
    return s;
}
