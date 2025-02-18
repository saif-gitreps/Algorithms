class ProductOfNumbers {
public:
    vector<int> nums;
    ProductOfNumbers() {
    }
    
    void add(int num) {
        nums.push_back(num);
    }
    
    int getProduct(int k) {
        int prod = 1;
        for (int i = nums.size()-1; i >= 0 && k; i--) {
            prod *= nums[i];
            k--;
        }
        return prod;
    }
};

