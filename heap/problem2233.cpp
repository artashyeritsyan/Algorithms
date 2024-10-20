class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        const int MOD = 1000000007;
        std::priority_queue<int, std::vector<int>, std::greater<int>> heap(nums.begin(), nums.end());

        for (int i = 0; i < k; i++) {
            int min = heap.top();
            heap.pop();  
            heap.push(min + 1); 
        }

        long long mul = 1;
        while (!heap.empty()) {
            mul = (mul * heap.top()) % MOD;
            heap.pop();  
        }

        return mul;
    }
};

