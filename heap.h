struct element{
   int key;
   struct element *left;
   struct element *right;
};
typedef struct element hElem;

struct vector{
    hElem *head;
    int qtd;
};
typedef struct vector Heap;

Heap* heap(int);
hElem *creat_element(int);
void Creat_heap(int v[],Heap*,int);
//void remove(hElem*, Heap*);
//void down(hElem*, Heap*);
//void up(hElem*, Heap*);