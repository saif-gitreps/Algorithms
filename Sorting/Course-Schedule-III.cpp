bool comparator(vector<int> &a, vector<int> &b){
    if(a[1] == b[1]){
        return a[0] < b[0];
    }
    else{
        return a[1] < b[1];
    }
}

https://www.youtube.com/watch?v=ey8FxYsFAMU


class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), comparator);
        int n = courses.size();
        int max_time = courses[n - 1][1];

        priority_queue<int> q;
        int time = 0;
        for(int i = 0; i < n; i++){
            if(courses[i][0] + time <= courses[i][1] &&
               courses[i][0] <= courses[i][1]
            ){
                time += courses[i][0];
                q.push(courses[i][0]);
            }
            else{
                if(!q.empty() and courses[i][0] < q.top()){
                    time -= q.top();
                    time += courses[i][0];
                    q.pop();
                    q.push(courses[i][0]);
                }
            }
        }
        return q.size();
    }
};
