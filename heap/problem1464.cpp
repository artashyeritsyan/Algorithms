class Solution {
public:
    int maxProduct(vector<int>& nums) {
        std::make_heap(nums.begin(), nums.end());
        std::pop_heap(nums.begin(), nums.end());

        return (nums[0] - 1) * (nums[nums.size() -1] - 1);
    }
};