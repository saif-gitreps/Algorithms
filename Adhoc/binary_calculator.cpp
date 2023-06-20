 vector<int> add_binary(vector<int>& a1, vector<int>& a2) {
   // returns an array containing the binary sum of two binary numbers.
        int sum1 = 0;
        int sum2 = 0;
        int count = 0;
        for(int i=a1.size()-1;i>=0;i--){
            if(a1[i]==1){
                sum1 += pow(2,count);
            }
            count++;
        }
        count =0;
        for(int i=a2.size()-1;i>=0;i--){
            if(a2[i]==1){
                sum2 += pow(2,count);
            }
            count++;
        }
        sum1= sum1+sum2;
        vector<int> ans;
        while(sum1){
            int rem = sum1%2;
            ans.push_back(rem);
            sum1 /= 2;
        }
        return ans;
    }
