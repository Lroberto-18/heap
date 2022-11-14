#include <stdio.h>

void down(int* h[],int j,int n){
    printf("\nelemento %d ", h[j-1]);
    printf("\n");
    for(int i=0;i<n;i++){
        printf("%d ",h[i]);
    }printf("\n");
    int aux=2*j-1;
    if(aux<=n){
        if(h[j-1]<h[aux]){
            if(aux+1<=n){
                if(h[j-1]<h[aux+1]){
                    aux +=1;
                }
            }
            int troca = h[j-1];
            h[j-1] = h[aux];
            h[aux] = troca;
            printf("heap-> ");
            for(int i=0;i<n;i++){
                printf("%d ",h[i]);
            }printf("\n");
            down(h,aux,n);
        }
    }
}
int main(){
    int v[] = {1,2,3,4,5,6,7,8,9,10,11};
    int n=11;
    int *h[n];
    for(int i=0;i<n;i++){
        h[i]=v[i];
    }
    //int j=n/2;
    //for(;j>0;j--){
       // printf("\nValor de J = %d",j);
       // down(h,j,n);
    //}printf("\n");
    int j =2;
    down(h,j,n);
    printf("\nHEAP( ");
    for(int i=0;i<n;i++){
        printf("%d ",h[i]);
    }printf(")\n");
return 0;
}