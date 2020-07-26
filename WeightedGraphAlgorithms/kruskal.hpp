#ifndef KRUSKAL_HPP
#define KRUSKAL_HPP

#define SET_SIZE 1000
#include "../GraphTraversal/adjlist.hpp"

struct set_union{
    int p[SET_SIZE + 1];
    int size[SET_SIZE + 1];
    int n = 0;
};

void set_union_init(set_union *s, int n){
    for(int i = 1; i <= n; ++i){
        s->p[i] = i;
        s->size[i] = 1;
    }
    s->n = n;
}
int find(set_union *s, int x){
    if(s->p[x] == x)
        return x;
    else
        return find(s, s->p[x]);
}
void union_sets(set_union *s, int s1, int s2){
    int r1 = find(s, s1);
    int r2 = find(s, s2);
    if(r1 == r2)return;
    if(s->size[r1] >= s->size[r2]){
        s->size[r1] += s->size[r2];
        s->p[r2] = r1;
    }else{
        s->size[r2] += s->size[r1];
        s->p[r1] = r2;
    }
}
bool same_component(set_union *s, int s1, int s2){
    return find(s, s1) == find(s, s2);
}

void kruskal(graph *g){
}

#endif