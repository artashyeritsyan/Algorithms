class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if (stones.size() == 1) {
            return stones[0];
        }
        std::make_heap(stones.begin(), stones.end());

        int largest;
        int secondLargest;

        while (stones.size() > 1) {
            largest = stones[0];
            std::pop_heap(stones.begin(), stones.end());
            stones.pop_back();
            
            secondLargest = stones[0];
            std::pop_heap(stones.begin(), stones.end());
            stones.pop_back();

            int result = largest - secondLargest;
            if (result > 0) {
                stones.push_back(result);
                std::push_heap(stones.begin(), stones.end());
            }
        }
        
        if (stones.size() == 0) {
            return 0;
        }
        return stones[0];
    }
};