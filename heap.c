#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

Heap* heap(int n){
    Heap *heap = (Heap*)malloc(sizeof(Heap));
    heap->head=NULL;
    heap->qtd=n;
    return heap;
}
hElem *creat_element(int key){
    hElem *h = (hElem*)malloc(sizeof(hElem));
    h->key = key;
    h->left = NULL;
    h->right = NULL;
    return h;
}

void Creat_heap(int v[],Heap *He,int n){
    int len=n;
    hElem *ve[len];
    for(int i = 0; i<len;i++){
        hElem *h = creat_element(v[i]);
        if(i==0) He->head=h;
        ve[i]=h;
        He->qtd+=1;
    }
    hElem *aux = He->head;
    for(int i = 0;i<len/2;i++){
        int aux_n = i + 1;
        aux->left = ve[(aux_n*2)-1];
        aux->right = ve[aux_n*2];
        aux = ve[aux_n];  
    }
}
int main(){
    int v[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int n = 12;
    Heap *H = heap(n);

    printf("\n");
    Creat_heap(v,H,n);
    int a = H->head->key;
    int t = H->head->right->key;
    int z = H->head->left->key;
    printf("\nchave:%d\n",a);
    printf("esquerda->%d\n",z);
    printf("diretia->%d\n",t);

    int q = H->head->left->key;
    int w = H->head->left->right->key;
    int e = H->head->left->left->key;
    printf("\nchave:%d\n",q);
    printf("esquerda->%d\n",e);
    printf("diretia->%d\n",w);

    int o = H->head->right->key;
    int s = H->head->right->right->key;
    int d = H->head->right->left->key;
    printf("\nchave:%d\n",o);
    printf("esquerda->%d\n",d);
    printf("diretia->%d\n",s);

    int o1 = H->head->left->left->key;
    int s1 = H->head->left->left->right->key;
    int d1 = H->head->left->left->left->key;
    printf("\nchave:%d\n",o1);
    printf("esquerda->%d\n",d1);
    printf("diretia->%d\n",s1);
return 0;    
}

#include <stdio.h>
#include <stdlib.h>

struct element{
   int key;
   struct element *left;
   struct element *right;
   struct element *father;
};
typedef struct element hElem;

hElem *creat_element(int);

hElem *creat_element(int key){
    hElem *h = (hElem*)malloc(sizeof(hElem));
    h->key = key;
    h->left = NULL;
    h->right = NULL;
    return h;
}

void Creat_heap(int v[],hElem* heap[],int n){
    for(int i = 0; i<n;i++){
        hElem *h = creat_element(v[i]);
        heap[i]=h;
    }
    hElem *aux = heap[0];
    for(int i = 0;i<n/2;i++){
        int aux_n = i + 1;
        aux->left = heap[(aux_n*2)-1];
        aux->right = heap[aux_n*2];
        aux = heap[aux_n];
    }
}
int main(){
    int v[] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
    int n = 13;
    hElem *H[n];
    Creat_heap(v,H,n);
    int c = n-1;
    for(int i=0;i<c/2;i++){
        printf("%d",H[i]->left->key);
        printf("<- ");
        printf("%d",H[i]->key);
        printf(" ->");
        printf("%d",H[i]->right->key);
        printf("\n");
    }
return 0;    
}
