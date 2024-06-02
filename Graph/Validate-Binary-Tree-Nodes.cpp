class Solution {
// best attempt from my side with DSU.
public:
    vector<int> parent;
    vector<int> size;

    void Make(int v){
        parent[v] = v;
        size[v] = 1;
    }

    int Find(int v){
        if (v == parent[v]) {
            return v;
        }
        return parent[v] = Find(parent[v]);
    }

    void Union(int a, int b){
        a = Find(a);
        b = Find(b);

        if(a == b){
            return;
        }

        if(size[a] < size[b]){
            swap(a, b);
        }
        parent[b] = a;
        size[a] += size[b];

    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        parent.resize(n);
        size.resize(n);

        for(int i = 0; i < n; i++){
            Make(i);
        }

        for(int i = 0; i < leftChild.size(); i++){
            if(leftChild[i] != -1){
                if (Find(leftChild[i]) == 0){
                    return false;
                }
                Union(i, leftChild[i]);
            }
            if(rightChild[i] != -1) {
                if (Find(rightChild[i]) == 0){
                    return false;
                }
                Union(i, rightChild[i]);
            }
        }
        return size[0] == n ? true : false;
    }
};
