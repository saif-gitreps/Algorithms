bool compare1(vector<int> a, vector<int> b) {
    return a[0] < b[0];
}

bool compare2(vector<int> a, vector<int> b) {
    int n = a.size(), m = b.size();
    return a[n-1] > b[m-1];
}

class Solution {
// I mean the worset solution in terms of TC and SC. but it worked.
public:
    int maxDistance(vector<vector<int>>& arrays) {
        sort(arrays.begin(), arrays.end(), compare2);

        vector<int> temp1 = arrays[0], temp2 = arrays[1];

        sort(arrays.begin(), arrays.end(), compare1);
        
        int n = temp1.size(), m = temp2.size();

        if (arrays[0] == temp1) 
            return max(
                abs(arrays[1][0] - temp1[n-1]),
                abs(arrays[0][0] - temp2[m-1])
            );

        return max(
                abs(arrays[1][0] - temp2[m-1]),
                abs(arrays[0][0] - temp1[n-1])
            );
    }
};

/* 

Key Points to Understand
Local Minimum and Maximum:

localMin = curr.get(0) and localMax = curr.get(curr.size() - 1) extract the smallest 
and largest elements from the current array (curr), 
respectively. These are just the extreme values within the current array.
Global Minimum and Maximum:

globalMin and globalMax are variables that track the smallest and largest elements encountered so 
far across all previously processed arrays.
Ensuring Elements Come from Different Arrays
Here's how the code ensures that the elements used for calculating the 
maximum distance come from different arrays:

Distance Calculation:

java
Copy code
result = Math.max(result, Math.max(localMax - globalMin, globalMax - localMin));
This line calculates two potential distances:
localMax - globalMin: The distance between the current array's largest 
element (localMax) and the smallest element seen so far from any previous array (globalMin).
globalMax - localMin: The distance between the current array's smallest element (localMin) 
and the largest element seen so far from any previous array (globalMax).
These calculations ensure that at least one of the elements (globalMin or globalMax) comes 
from an array that has already been processed (not the current array), and the other element 
(localMin or localMax) comes from the current array. This naturally avoids the edge case where both 
elements are from the same array because globalMin and globalMax are updated after these distances are calculated.

Updating Global Extremes:

java
Copy code
globalMin = Math.min(globalMin, localMin);
globalMax = Math.max(globalMax, localMax);
After calculating the distances, the global minimum (globalMin) and maximum (globalMax) are updated. 
This ensures that when the next array is processed, the globalMin and globalMax values used 
in the distance calculations will include the extremes from all previously processed arrays.
Edge Case Prevention
The code structure ensures that:

Different Arrays: Since globalMin and globalMax are based on arrays processed before the current one,
the difference calculations inherently involve elements from different arrays.
Update After Calculation: By updating globalMin and globalMax only after the distance is calculated,
the code avoids using both localMin and localMax from the same 
array for the distance calculation in that particular iteration.

*/

class Solution {
    public int maxDistance(List<List<Integer>> arrays) {
        
        int globalMin = arrays.get(0).get(0);
        int globalMax = arrays.get(0).get(arrays.get(0).size() - 1);
        int result = 0;

        for (int i = 1; i < arrays.size(); i++) {
            List<Integer> curr = arrays.get(i);
            int localMin = curr.get(0);
            int localMax = curr.get(curr.size() - 1);

            result = Math.max(result, Math.max(localMax - globalMin, globalMax - localMin));

            globalMin = Math.min(globalMin, localMin);
            globalMax = Math.max(globalMax, localMax);
        }

        return result;
    }
}
