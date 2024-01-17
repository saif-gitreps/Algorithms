class Solution {
// i'was a good first try cant lie bout dah.
// edge case was starting from left triggers one edge , starting from right triggers left edge case.
public:
    string pushDominoes(string d) {
        int L = -1;
        int R = -1;
        int n = d.size();
        for(int i = 0; i < n; i++){
            if(L != -1 && R != -1){
                while(R < L){
                    d[L--] = 'L';
                    d[R++] = 'R';
                }
                L = -1;
                R = -1;
            }
            if(d[i] == 'L'){
                L = i;
            }
            if(d[i] == 'R'){
                R = i;
            }
        }

        for(int i = n - 1; i >= 0; i--){
            if(
                (i-2 >= 0 && d[i] == 'L' && d[i-1] == '.' && d[i-2] == 'R') ||
                (i-1 >= 0 && d[i] == 'L' && d[i-1] == 'L')){
                continue;
            }
            while(i-1 >=0 && d[i] == 'L' && d[i-1] == '.'){
                d[--i] = 'L'; 
            } 
        }
        for(int i = 0; i < n; i++){
            if(
                (i+2 < n && d[i] == 'R' && d[i+1] == '.' && d[i+2] == 'L') ||
                (i+1 < n && d[i] == 'R' && d[i+1] == 'R')){
                continue;
            }
            while(i+1 < n && d[i] == 'R' && d[i+1] == '.'){
                d[++i] = 'R'; 
            } 
        }
        return d;
    }
};
