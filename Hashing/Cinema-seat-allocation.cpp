#include <bits/stdc++.h>
using namespace std;
//attempt one.
const int MAXN = 100010;
int maxNumberOfFamilies(int n, vector<vector<int>>& a) {
        int count= 0;
        int aisle_count = 0;
        int k = 0;
        sort(a.begin(),a.end());
        for(int i=1;i<=n;i++){
            aisle_count = 0;
            if(a[k][0]==i){
               for(int j=1;j<=10;j++){
                  if(a[k][0]>i){
                     break;
                  }
                  if(aisle_count==4){
                     count++;
                     aisle_count = 0;
                  }
                  if(j==a[k][1]){
                     aisle_count =0;
                     k++;
                  }
                  else if(j!=a[k][1]){
                     aisle_count++;
                  }
                  // if(a[k][1]>=2 && a[k][1]<=3){
                  //    aisle_count=0;
                  // }
                  // if(a[k][1]>=8 && a[k][1]<=10){
                  //    aisle_count = 0;
                  // }
               }
            }
        }
        return count;
    }

int main(){

   vector<vector<int>> a ={{2,1},{1,8},{2,6}}; 
   //a = {{1,2},{1,3},{1,8},{2,6},{3,1},{3,10}};
   cout<<maxNumberOfFamilies(2,a);
   
}


#include <bits/stdc++.h>
using namespace std;
//attempt 2 , idk why it is not working aaaaaaa


const int MAXN = 100010;
int maxNumberOfFamilies(int n, vector<vector<int>>& a) {
        int count= 0;
        int aisle_count = 0;
        int k = 0;
        sort(a.begin(),a.end());
        for(int i=0;i<a.size();i++){
            int s = 0;
            aisle_count = 0;
            for(int j=1;j<=10;j++){
               if(j%2!=0 && aisle_count==0){
                  continue;
               }
               if(a[i][1]!=j){
                  aisle_count++;
               }
               else if(a[i][1]==j){
                  i++;
                  if((aisle_count==4)){
                     count++;
                  }
                  aisle_count = 0;
               }
               if(aisle_count==4){
                  aisle_count = 0;
               }
            }
        }
        return count;
    }

int main(){

   vector<vector<int>> a = {{1,2},{1,3},{1,8},{2,6},{3,1},{3,10}};
   //a ={{2,1},{1,8},{2,6}}; 
   //a = {{1,2},{1,3},{1,8},{2,6},{3,1},{3,10}};
   cout<<maxNumberOfFamilies(2,a);
   
}
