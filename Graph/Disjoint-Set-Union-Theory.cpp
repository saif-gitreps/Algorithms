
/*

    three methods of Disjoint Set Union.
    - make() -> will add a new individual node. example 2<-4 5<-6,
    adding make(8) will result in 2<-4, 5<-6 , 8
    
    - find() -> This will return the head of a union, we pass in any child or root 
    as a param. Example: 2<-4, 5<-6, 8, find(4) is 2 (the root of this set).

    - union() -> This will join heads for two different sets, examples:
    2<-4 and 5<-6 will be joined as :
    2 <- 5
    ^    ^
    |    |
    4    6

    TC is amortized O(alpha(n)) [alpha(n) reverse ackerman function]
    Ackerman's function says it grows slowly.

    So overall operation cost is almost Constant time.


*/

const int N = 100000; 
int parent[N];
int size[N];

void make(int v){
    parent[v] = v;
    size[v] = 1;
}

void find(int v){
    if (v == parent[v]) {
        return v;
    }
    // instead of this-> return find(parent[v]);
    // We will do an extra step of path compression.
    // ultimately at the end of recursion we will receive the root
    // So it will backtrack and set every child on that tree to have a parent of 
    // returned root. 
    parent[v] = find(parent[v]);
}

void Union(int a, int b){
    // step 1: find the root of each node.
    a = find(a);
    b = find(b);

    // step 2: If their roots are the same that implies that they have already joined a set.
    if(a == b){
        return;
    }

    // step 3: Make the parent of b as a, a <- b (b is pointing to its parent).
    // We always make sure to join the largest tree on the left, and the smallest on the right.
    if(size[a] < size[b]){
        swap(a, b);
    }
    parent[b] = a;
    size[a] += size[b];
}
