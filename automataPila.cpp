#include <iostream>
#include <string.h>
#include <iomanip>
#include <cstdlib>
using namespace std;

struct nodo{
 
    char a;//campo donde se almacenara el caracter
    struct nodo *sgte;
};
 
typedef struct nodo *pila;
 
/*---------------Funcion para Apilar un Caracter--------*/
void apila(pila &p,const char a){
 
    pila q=new (struct nodo) ;
    q->a=a;
    q->sgte=p;
    p=q;
 }
 
/*------------- Funcion para Desapilar un elemento -----*/
void desapila(pila &p){
 
    int n=p->a;
 
    pila q=p;
    p=p->sgte;
    delete(q);
}






