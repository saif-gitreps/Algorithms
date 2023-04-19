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
