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
hElem *creat_element(int key){
    hElem *h = (hElem*)malloc(sizeof(hElem));
    h->key = key;
    h->left = NULL;
    h->right = NULL;
    return h;
}
typedef struct vector Heap;
void Creat_heap(int v[],Heap *He){
    int len=25;
    hElem *ve[len];
    //int len = sizeof(v)/sizeof(v[0]);
    //Heap *He = heap(len);
    for(int i = 0; i<len;i++){
        hElem *h = creat_element(v[i]);
        if(i==0) He->head=h;
        ve[i]=h;
        He->qtd+=1;
    }
    hElem *aux = He->head;
    for(int i = 0;i<len/2;i++){
        aux->left = ve[(i*2)-1]; //esquerda
        aux->right = ve[(i*2)]; //direita
        aux = ve[i];
    }
}
int main(){
    int n =25;
    int v[n];
    Heap *H = heap(n);
    //criando vetor "v" com valores pseudoaleatórios de 1 até 100 de acordo com o tamanho de n
    for(int i=0;i<n;i++){
        v[i]= 1 +rand() % 120;
        printf("%d ",v[i]);
    }
    printf("\n");
    Creat_heap(v,H);
    int a = H->head->key;
    int t = H->head->right->key;
    int z = H->head->left->key;
    printf("\nchave->%d\n",a);
    printf("esquerda->%d\n",z);
    printf("diretia->%d\n",t);

    int f = H->head->right->key;
    int g = H->head->right->right->key;
    int h = H->head->right->left->key;
    printf("\nchave->%d\n",f);
    printf("diretia->%d\n",g);
    printf("esquerda->%d\n",h);

    int j = H->head->right->left->key;
    int k = H->head->right->right->left->key;
    int l = H->head->right->left->left->key;
    printf("\nchave->%d\n",j);
    printf("diretia->%d\n",k);
    printf("esquerda->%d\n",l);

return 0;    
}