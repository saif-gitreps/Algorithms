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

// normal prefix sum is prefixSum[i] = A[0] + A[1] +....+ A[i] and  sum(k) = prefixSum[n] − prefixSum[n−k]
// we modify it to prefixProduct[i] = A[0] × A[1]× ⋯ ×A[i] and product(k)=  prefixProduct[n] / prefixProduct[n-k]
// just try to brainstorm it to understand.
class ProductOfNumbers {
private:
    vector<int> prefixProducts;  // Stores cumulative product

public:
    ProductOfNumbers() {
        prefixProducts = {1};  // Initialize with 1 for easy division
    }
    
    void add(int num) {
        if (num == 0) {
            prefixProducts = {1};  // Reset the prefix product list
        } else {
            prefixProducts.push_back(prefixProducts.back() * num);
        }
    }
    
    int getProduct(int k) {
        int size = prefixProducts.size();
        if (k >= size) return 0;  // If k exceeds available elements, return 0
        return prefixProducts.back() / prefixProducts[size - k - 1];
    }
};

​
