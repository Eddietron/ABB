#include <stdio.h>
#include <stdlib.h>
#include "Arbol.h"
// altura, nivel, minimo, maximo, insertar, modificar nodo, eliminar, mostrar, encontrar

/*
    Cosas que faltan: altura y nivel
    Cosas con errores: 
*/
Nodo* (*cndd)(int) = crearNodo;
void init(){
    raiz = (Nodo**)malloc(sizeof(Nodo*));
    *raiz = NULL;
}

void insertar(Nodo** raiz, Nodo* nuevo){
    if ( !(*raiz))
        *(raiz) = nuevo;
    else if((*raiz)->dato == nuevo->dato){
        printf("Ese valor ya existe\n");
        return;
    }else{
        if ((*raiz)->dato < nuevo->dato)
            insertar(&((*raiz)->hder), nuevo);
        else if ((*raiz)->dato > nuevo->dato)
            insertar(&((*raiz)->hizq), nuevo);
    }
}

void mostrar(Nodo** raiz){
    int recorrido = getRecorrido();
    switch(recorrido){
        case 1:
            inOrden(raiz);
            break;
        case 2:
            preOrden(raiz);
            break;
        case 3:
            postOrden(raiz);
            break;
        case 4:
            //niveles(raiz);
            break;
    }
    printf("\n");
}

int eliminarNodo(Nodo** raiz, int id){
    if(*raiz == NULL)
        return 0;
    if((*raiz)->dato == id){
        if((*raiz)->hizq == NULL && (*raiz)->hder == NULL){
            Nodo* aux = *raiz;
            *raiz = NULL;
            free(aux);
        }else if((*raiz)->hizq == NULL && (*raiz)->hder != NULL){
            Nodo* aux = *raiz;
            *raiz = aux->hder;
            free(aux);
        }else if((*raiz)->hizq != NULL && (*raiz)->hder == NULL){
            Nodo* aux = *raiz;
            *raiz = aux->hizq;
            free(aux);
        }else{
            Nodo** min = minimo(&(*raiz)->hder);
            Nodo* aux = *min;
            *min = aux->hder;
            aux->hder = NULL;
            aux->hder = (*raiz)->hder;
            aux->hizq = (*raiz)->hizq;
            free(raiz);
            *raiz = aux;
        }
    }else if((*raiz)->dato < id)
        return eliminarNodo(&(*raiz)->hder, id);
    else
        return eliminarNodo(&(*raiz)->hizq, id);
    return 1;
}

int modificarNodo(Nodo** raiz, int id, int nuevo){
    Nodo* target = encontrarNodo(raiz, id);
    Nodo* buscador = encontrarNodo(raiz, nuevo);
    if(buscador != NULL){
        printf("El nuevo valor del nodo ya existe\n");
        return 0;
    }
    if(target == NULL){
        printf("Nodo no encontrado\n");
        return 0;
    }
    if(target->hizq->dato < id && target->hder->dato > id)
        target->dato = nuevo;
    else{
        eliminarNodo(&target, target->dato);
        insertar(raiz, (*cndd)(nuevo));
    }
    
}

Nodo* encontrarNodo(Nodo** raiz, int id){
    if(*(raiz) != NULL){
        if((*raiz)->dato == id)
            return *raiz;
        return encontrarNodo(&(*raiz)->hizq, id);
        return encontrarNodo(&(*raiz)->hder, id);
    }
    return NULL;
}

void inOrden(Nodo** raiz){
    if(*(raiz) != NULL){
        inOrden(&(*raiz)->hizq);
        printf("%d, ", (*(raiz))->dato);
        inOrden(&(*raiz)->hder);
    }
}
void preOrden(Nodo** raiz){
    if(*(raiz) != NULL){
        printf("%d, ", (*(raiz))->dato);
        preOrden(&(*raiz)->hizq);
        preOrden(&(*raiz)->hder);
    }
}

void postOrden(Nodo** raiz){
    if(*(raiz) != NULL){  
        postOrden(&(*raiz)->hizq);
        postOrden(&(*raiz)->hder);
        printf("%d, ", (*(raiz))->dato);
    }
}

int altura(Nodo** raiz){
    if(*(raiz) != NULL){
        
    }
}

Nodo** minimo(Nodo** raiz){
    if(*raiz == NULL)
        return NULL;
    if((*raiz)->hizq == NULL)
        return raiz;
    return minimo(&((*raiz)->hizq));
}

Nodo** maximo(Nodo** raiz){
    if(*raiz == NULL)
        return  NULL;
    if((*raiz)->hder == NULL)
        return raiz;
    return maximo(&((*raiz)->hder));
}

int getRecorrido(){
    int n;
    printf("Selecciona la forma recorrer el arbol:\n1. InOrden\n2. PreOrden\n3. PostOrden\n");
    scanf("%d", &n);
    if(n>=1 && n<=3)
        return n;
    return getRecorrido();
}

Nodo* crearNodo(int id){
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->dato = id;
    nuevo->hizq = NULL;
    nuevo->hder = NULL;
    return nuevo;
}

Nodo* crearNodoPD(){
    int n;
    printf("inserta el dato");
    scanf("%d", &n);
    return crearNodo(n);
}
