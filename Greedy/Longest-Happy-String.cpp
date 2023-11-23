class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        //Correctly guessed we had to use Priority queue.
        priority_queue<pair<int,char>> pq;
        pq.push({a,'a'});
        pq.push({b,'b'});
        pq.push({c,'c'});
        //Correctly guessed till this much.
        int i = 0;
        string str = "";
        while(true){
            if(i >= 1){
                if(str[i-1] == str[i] && pq.top().second == str[i]){
                    pair<int,int> pick = pq.top();
                    pq.pop();
                    pair<int,int> temp = pq.top();
                    str += temp.second;
                    i++;
                    int val = temp.first-1;
                    temp = {val, temp.second};
                    pq.push(temp); pq.push(pick);
                }
                if(str[i-1] == str[i]){
                    break;
                }
            }
            else if(i < 2){
                pair<int,int> temp = pq.top();
                str += temp.second;
                i++;
                int val = temp.first-1;
                temp = {val, temp.second};
                pq.push(temp);
            } 
        }
        return str;
    }
};


class Solution {
// working solution.
public:
    string longestDiverseString(int a, int b, int c) {
        //Correctly guessed we had to use Priority queue.
        priority_queue<pair<int,char>> pq;
        char ch = 'a';
        if(a) pq.push({a,'a'});
        if(b) pq.push({b,'b'});
        if(c) pq.push({c,'c'});
        int i = 0;
        string str = "";
        while(pq.size() > 1){
            pair<int,char> one = pq.top();pq.pop();
            pair<int,char> two = pq.top();pq.pop();
            if(one.first >= 2){
                str += one.second;
                str += one.second;
                one.first -= 2;
            }
            else{
                str += one.second;
                one.first -= 1;
            }
            // the and condition is to avoid a dual condition.
            // if our second one is lesser than first one
            // then at the next loop we can avoid aaa or bbb condition. We can implement the aabaabb sequence.
            if(two.first >= 2 && two.first >= one.first){
                str += two.second;
                str += two.second;
                two.first -= 2;
            }
            else{
                str += two.second;
                two.first -= 1; 
            }
            // update the value , put back in if theyre not 0.
            if(two.first > 0){
                pq.push(two);
            }
            if(one.first > 0){
                pq.push(one);
            }
        }
        if(pq.empty() == true){
            return str;
        }
        if(pq.top().first>=2){
            str += pq.top().second;
            str += pq.top().second;
        }
        else{
            str += pq.top().second;
        }
        return str;
    }
};


string longestDiverseString(int a, int b, int c) {
    // better intuitive solution.
        int total=a+b+c;
        int currA=0, currB=0, currC=0;
        string res = "";
        while(total--){
            
            if((a>=b && a>=c && currA!=2) || (a>0 && (currB==2|| currC==2))){
                res+='a'; 
                a--;
                currA++;
                currB=currC=0;
            }
            else if((b>=a && b>=c && currB!=2) || (b>0 && (currA==2|| currC==2))){
                res+='b';
                b--;
                currB++;
                currA=currC=0;
            }
            else if((c>=a && c>=b && currC!=2) || (c>0 && (currA==2|| currB==2))){
                res+='c';
                c--;
                currC++;
                currA=currB=0;
            }
        }
        return res;
    }
