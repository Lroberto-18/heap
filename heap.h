struct element{
   int key;
   struct element *left;
   struct element *right;
};
typedef struct element hElem;

struct vector{
    hElem *head;
    int qtd;
    hElem *vector[100000000];
};
typedef struct vector Heap;