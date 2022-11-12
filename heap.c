#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

Heap* heap(int n){
    Heap *heap = (Heap*)malloc(sizeof(Heap));
    heap->head=NULL;
    heap->qtd=n;
    for(int i =0; i<n;i++){
        heap->vector[i]=NULL;
    }
    return heap;
}
void Creat(int v[]){
    int len = sizeof(v)/sizeof(v[0]);
    Heap *He = heap(len); 
    for(int i = 0; i<len;i++){
        hElem *h = (hElem*)malloc(sizeof(hElem));
        if(i==0) He->head=h;
        He->vector[i]=h;
        He->qtd+=1;
        h->key=v[i];
        //h->left=He->vector[2*i]
    }
    //for(int i =0;i<len;i++){
        //int key = He->vector[i]->key;
    //}
}
int main(){
    int n =10;
    int v[n];
    Heap *H = heap(n);
    //criando o vetor com valores de 1 até 100 de acordo com o tamanho de n
    for(int i=0;i<n;i++){
        v[i]= 1 +rand() % 100;
        printf("%d ",v[i]);
    }
    //Creat(v);
    //int t =  H->head->key;
    int a = H->vector[2]->key;
    printf("%d",a);
return 0;    
}