#include <stdio.h>

void down(int* heap[],int j,int n){
    /*
    Função para descer elementos do heap.
    heap[] -> heap criado.
    j -> posição do elemento que irá descer.
    n -> numero de elementos do vetor.
    */
    int aux = j*2+1;
    if(aux<=n){
        if(heap[j]<heap[aux]){
            if(aux+1<n){
                if(heap[j]<heap[aux+1]){
                    if(heap[aux]<heap[aux+1]) aux +=1;
                }
            }
            int swap = heap[j];
            heap[j] = heap[aux];
            heap[aux] = swap;
            down(heap,aux,n);
        }
    }
}
void creat(int *heap[],int v[],int n){
    //criar heap com o vetor informado
    for(int i=0;i<n;i++){
        heap[i]=v[i];
        printf("%d ", heap[i]);
    }
    for(int j=n/2;j>0;j--){
        down(heap,j-1,n);
    }
}
void up(int* heap[],int j,int value, int n){
    /*
    Função para aumentar prioridade elementos do heap.
    heap[] -> heap criado.
    j -> posição do elemento que irá descer.
    value -> novo valor
    n -> numero de elementos do vetor.
    */
    int aux = j/2;
    heap[j] = value;
    if(heap[j]>heap[aux] && j>=1){
        int swap = heap[j];
        heap[j] = heap[aux];
        heap[aux] = swap;
        up(heap,aux,value,n);
    }
}
int main(){
    int v[] = {1,2,3,4,5,6,7,8,9,10,11};
    int n= sizeof(v)/sizeof(v[0]);//tamanho do vetor v
    int *heap[n];
    creat(heap,v,n); //criando o heap
    printf("\n");
    printf("\no HEAP criado é ( ");
    for(int i=0;i<n;i++){
        printf("%d ",heap[i]);
    }printf(")\n");
    up(heap,5,100,11);
    printf("\no HEAP criado é ( ");
    for(int i=0;i<n;i++){
        printf("%d ",heap[i]);
    }printf(")\n");
return 0;
}