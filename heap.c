#include <stdio.h>
#include <stdlib.h>
//utilizando struct
struct element{
   int key;
   struct element *left;
   struct element *right;
};
typedef struct element hElem;

hElem *creat_element(int);
void creat_heap(int v[],hElem*,int);
void up(hElem*[],int, int);
void down(hElem*,int);
void remove_element(hElem*, int);

hElem *creat_element(int key){
    hElem *h = (hElem*)malloc(sizeof(hElem));
    h->key = key;
    h->left = NULL;
    h->right = NULL;
    return h;
}
void up(hElem* heap[],int i,int n){
    int j = 2*i;
    if(j<=n){
        if(heap[i]<heap[j]){
            if(j+1<=n){
                if(heap[j]<heap[j+1]){
                    j=j-1;
                }
                hElem *aux = heap[i];
                heap[i] = heap[j];
                heap[j] = aux;
            }
        }
    }
}
void Creat_heap(int v[],hElem* heap[],int n){
    for(int i = 0; i<n;i++){
        hElem *h = creat_element(v[i]);
        heap[i]=h;
    }
    //hElem *aux = heap[0];
    //for(int i = 0;i<n/2;i++){
     // int aux_n = i + 1;
      // if(aux_n*2>n) break;
      // aux->left = heap[(aux_n*2)-1];
      // aux->right = heap[aux_n*2];
      // aux = heap[aux_n];
    //}
    int j = n/2;
    for(;j>0;j--){
        if(j*2+1>n) break;
        if(heap[j-1]->key<heap[j*2]->key||heap[j-1]->key<heap[j*2-1]->key){
            if(heap[j*2]->key>heap[j*2-1]->key){
                hElem *aux1 = heap[j-1];
                heap[j-1] = heap[j*2];
                heap[j*2] = aux1;
            }if(heap[j*2]->key<heap[j*2-1]->key){
                hElem *aux1 = heap[j-1];
                heap[j-1] = heap[j*2-1];
                heap[j*2-1] = aux1;
            }
        }
        printf("%d direita-> ", heap[j-1]->key);
        printf("%d esquerda-> %d\n",heap[j*2]->key,heap[j*2-1]->key);
    }
}
int main(){
    int v[] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
    int n = 13;
    hElem *H[n];
    Creat_heap(v,H,n);
    printf("\n  HEAP\n");
    for(int i=0;i<n;i++){
        printf("%d ",H[i]->key);
    }
    printf("\n");
   
return 0;    
}
/*if(2*j>n) break;
        if(heap[j-1]<heap[2*(j-1)]){
            hElem *aux1 = heap[j-1]->left;
            heap[j-1]->left = heap[2*(j-1)]->left;
            heap[2*(j-1)]->left = aux1;
        }if(heap[j-1]>heap[2*(j-1)+1]){
            hElem *aux1 = heap[j-1]->right;
            heap[j-1]->right = heap[2*(j-1)]->right;
            heap[2*(j-1)]->right = aux1;
        }
*/

/*
int c = n-1;
for(int i=0;i<c/2;i++){
        printf("%d",H[i]->left->key);
       printf("<- ");
        printf("%d",H[i]->key);
        printf(" ->");
        printf("%d",H[i]->right->key);
        printf("\n");
    }

     //printf("\n%d\n",H[5]->key);
    //printf("\n%d\n",H[5]->left->key);
    //printf("\n%d\n",H[5]->right->key);
*/