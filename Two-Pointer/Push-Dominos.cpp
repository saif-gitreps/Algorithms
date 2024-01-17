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

class Solution {
// this was easy solution , we basically have two arrays and we mark seconds.
// one from left and one right right.
// then we compare based off some conditions.
public:
    string pushDominoes(string d) {
        int n = d.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        char prev = '.';
        int count = 1;
        for(int i = 0 ; i < n; i++){
            if(d[i] == 'R'){
                prev = 'R';
                count = 1;
                continue;
            }
            else if(d[i] == 'L'){
                prev = 'L';
            }
            else if(prev == 'R' && d[i] == '.'){
                right[i] = count;
                count++;
            }
        }
        count = 1; prev = '.';
        for(int i = n - 1; i >= 0; i--){
            if(d[i] == 'L'){
                prev = 'L';
                count = 1;
            }
            else if(d[i] == 'R'){
                prev = 'R';
            }
            else if(prev == 'L' && d[i] == '.'){
                left[i] = count;
                count++;
            }
        }
        for(int i = 0; i < n; i++){
            if(left[i] == 0 &&  right[i] == 0){
                continue;
            }
            else if(left[i] == 0){
                d[i] = 'R';
            }
            else if(right[i] == 0){
                d[i] = 'L';
            }
            else if(left[i] == right[i]){
                d[i] = '.';
            }
            else if(left[i] > right[i]){
                d[i] = 'R';
            }
            else{
                d[i] = 'L';
            }
        }
        return d;
    }
};
