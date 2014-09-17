#include "../lib/union_find.h"

int main(void){
    UnionFind uf(10); uf.PrintID();
    uf.Union(1, 2);   uf.PrintID();
    uf.Union(4, 3);   uf.PrintID();
    uf.Union(2, 3);   uf.PrintID();
    uf.Union(6, 7);   uf.PrintID();
    uf.Union(7, 3);   uf.PrintID();

}