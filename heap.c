#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

Heap* heap(int n){
    Heap *heap = (Heap*)malloc(sizeof(Heap));
    heap->head=NULL;
    heap->qtd=n;
    //for(int i =0; i<n;i++){
       // heap->vector[i]=NULL;
   // }
    return heap;
}
hElem *criar_element(int key){
    hElem *h = (hElem*)malloc(sizeof(hElem));
    h->key = key;
    h->left = NULL;
    h->right = NULL;
    return h;
}
typedef struct vector Heap;
void Creat(int v[],Heap *He){
    int len=10;
    hElem *ve[len];
    //int len = sizeof(v)/sizeof(v[0]);
    //Heap *He = heap(len);
    for(int i = 0; i<len;i++){
        hElem *h = criar_element(v[i]);
        if(i==0) He->head=h;
        ve[i]=h;
        He->qtd+=1;
        //h->left=He->vector[2*i]
    }
    hElem *aux = He->head;
    for(int i = 0;i<len/2;i++){
        aux->left = ve[2*i]; //esquerda
        aux->right = ve[((2*i)+1)]; //direita
        aux = ve[i];
    }
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
    Creat(v,H);
    int t =  H->head->right->key;
    int a = H->head->key;
    int z = H->head->left->key;
    printf("\n1->%d\n",a);
    printf("\n2->%d\n",t);
    printf("\n3->%d\n",z);
return 0;    
}