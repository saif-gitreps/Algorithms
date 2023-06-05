class Solution {
public:
	vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& a, int b) {

        sort(a.begin(),a.end());

        set<int> s(a.begin(),a.end());
        a.assign(s.begin(),s.end());
        vector<int> v;
        fnc(a,b,v,0);
        return ans;
    }
    
void fnc(vector<int> &a,int b,vector<int> &v, int i){
	if(b==0){
		ans.push_back(v);	
	}
	if(i==a.size()){
		return;
	}
	while(i<a.size() && b-a[i]>=0){
		
			v.push_back(a[i]);
			fnc(a,b-a[i],v,i);	
			i++;
			v.pop_back();		
	}
}
};

class Solution {
	// attempt 2 : working on it , let me finish this stpupid bangla assignment first.
    // SUIIIIIIIIIIIIIIII, i did , my intention worked , i am a proooo;
public:
    class Solution {
public:
    vector<vector<int>> final_ds;
    void rev(int i,vector<int> a,vector<int> &ds,int sum,int target){
        if(i==a.size() || sum==target || sum>target){
            if(sum==target){
                final_ds.push_back(ds);
                return;
            }
            return;
        }
        sum += a[i];
        ds.push_back(a[i]);
        rev(i,a,ds,sum,target);
        ds.pop_back();
        sum -= a[i];
        rev(i+1,a,ds,sum,target);

    }
    vector<vector<int>> combinationSum(vector<int>& a, int b) {
        vector<int> ds;
        rev(0,a,ds,0,b);
        return final_ds;
    }
};
};

class Solution {
public:
    vector<vector<int>> final_ds;
    void rev(int i,int sum,vector<int>& ds,vector<int> a){
        if(sum==0){
            final_ds.push_back(ds);
            return;
        }
        if(i==a.size() || sum<0){
            return;
        }
        ds.push_back(a[i]);
        rev(i,sum-a[i],ds,a);
        ds.pop_back();
        rev(i+1,sum,ds,a);
    }
    vector<vector<int>> combinationSum(vector<int>& a, int b) {
        vector<int> ds;
        rev(0,b,ds,a);
        return final_ds;
    }
};