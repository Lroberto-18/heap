#include <stdio.h>
#include <stdlib.h>

void down(int heap[],int j,int n){
    /*
    Função para descer elementos do heap.
    heap[] -> heap criado.
    j -> posição do elemento que irá descer. (0 até n-1)
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

void creat(int heap[],int v[],int n){
    //criar heap com o vetor informado
    for(int i=0;i<n;i++){
        heap[i]=v[i];
    }
    for(int j=n/2;j>0;j--){
        down(heap,j-1,n);
    }
}

void up(int heap[],int j,int value, int n){
    /*
    Função para aumentar prioridade elementos do heap.
    heap[] -> heap criado.
    j -> posição do elemento que irá descer. (0 até n-1)
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

void remove_element(int heap[],int *n){
    /*
    heap[] -> heap criado.
    n -> ponteiro do número de elementos do vetor.
    */
    heap[0] = heap[*n-1];
    heap[*n-1] = 0;
    *n-=1;
    int aux = *n;
    heap=(int*)realloc(heap,sizeof(int)*aux);
    down(heap,0,*n);
}

void show(int heap[], int *n){
    printf("\nHEAP ( ");
    for(int i=0;i<*n;i++){
        printf("%d ",heap[i]);
    }printf(")\n");
}

void insert(int heap[], int *n,int value){
    *n+=1;
    int aux = *n;
    heap=(int*)realloc(heap,sizeof(int)*aux);
    heap[aux-1] = value;
    show(heap, n);
    up(heap,aux-1,value,*n);
}

void heapsort(int vector[],int len){
    int vOut[len];
    int *h;
    h = malloc(sizeof(h)*len);
    creat(h,vector,len);
    int aux = len;
    for(int i=aux-1; i>=0;i--){
       vOut[i] = h[0];
       remove_element(h,&len);
    }printf("\nVetor ordenado -> ");
    for(int i=0;i<aux;i++){
        printf("%d ", vOut[i]);
    }printf("\n");
}

int main(){
    int v[] = {8, 23, 53, 41, 62, 36, 78, 7, 19, 10, 11, 67, 9, 123};
    int n= sizeof(v)/sizeof(v[0]); //tamanho do vetor v
    int *heap;
    heap = malloc(sizeof(heap)*n);

    //Testando todas as funções
    printf("\nCriando heap apartir do vetor V->( ");
    for(int i=0;i<n;i++)
        printf("%d ", v[i]);
    printf(")");
    creat(heap,v,n);  //criando o heap
    show(heap,&n);
    
    printf("\nAlterando o valor do 8° elemento do heap para 172");
    up(heap,7,172,11); 
    show(heap,&n);

    printf("\nRemovendo da raiz");
    remove_element(heap,&n);
    show(heap,&n);

    printf("\nRemovendo da raiz");
    remove_element(heap,&n);
    show(heap,&n);

    printf("\nInserindo o valor 99 ao heap");
    insert(heap,&n,99);
    show(heap,&n);

    printf("\nImplementando o headsort");
    int vector[] = {8, 23, 53, 41, 62, 36, 78, 7, 19, 10, 11, 49, 89, 123,99,14,1};
    int len= sizeof(vector)/sizeof(vector[0]);
    heapsort(vector, len);
return 0;
}