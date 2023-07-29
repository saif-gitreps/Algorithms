class Solution {
// i tried something lol.
public:
    int check(vector<int> a,vector<int> b,vector<int> c){
        int count = 0;
        pair<int,int> p1,p2;
        // a + b == a + c ?
        p1 = make_pair(abs(a[0]-b[0]),abs(a[1]-b[1]));
        p2 = make_pair(abs(a[0]-c[0]),abs(a[1]-c[1])); 
        if(p1==p2){
            count++;
        }
        // a + c == a + b ?
        p1 = make_pair(abs(a[0]-c[0]),abs(a[1]-c[1]));
        p2 = make_pair(abs(a[0]-b[0]),abs(a[1]-b[1]));
        if(p1==p2){
            count++;
        }
        // b + a == b + c ?
        p1 = make_pair(abs(b[0]-a[0]),abs(b[1]-a[1]));
        p2 = make_pair(abs(b[0]-c[0]),abs(b[1]-c[1]));
        if(p1==p2){
            count++;
        }
        // b + c == b + a ?
        p1 = make_pair(abs(b[0]-c[0]),abs(b[1]-c[1]));
        p2 = make_pair(abs(b[0]-a[0]),abs(b[1]-a[1]));
        if(p1==p2){
            count++;
        }
        // c + a == c + b ?
        p1 = make_pair(abs(c[0]-a[0]),abs(c[1]-a[1]));
        p2 = make_pair(abs(c[0]-b[0]),abs(c[1]-b[1]));
        if(p1==p2){
            count++;
        }
        // c + b == c + a ?
        p1 = make_pair(abs(c[0]-b[0]),abs(c[1]-b[1]));
        p2 = make_pair(abs(c[0]-a[0]),abs(c[1]-a[1]));
        if(p1==p2){
            count++;
        }
        return count;
    } 
    int numberOfBoomerangs(vector<vector<int>>& points) {
        if(points.size()<=2){
            return 0;
        }
        int count = 0;
        for(int i=0;i<points.size()-2;i++){
            count += check(points[i],points[i+1],points[i+2]);
        }
        return count;
    }
};
