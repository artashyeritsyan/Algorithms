class Solution {
public:
    int fillCups(vector<int>& amount) {
        std::make_heap(amount.begin(), amount.end());
        int seconds = 0;

        while (amount[0] != 0 || amount[1] != 0 || amount[2] != 0) {
            std::pop_heap(amount.begin(), amount.end());
            
            if(amount[0] != 0) {
                --amount[0];
            }
            if(amount[2] != 0) {
                --amount[2];
            }

            std::pop_heap(amount.begin(), amount.end());
            ++seconds;
        }
        return seconds;
    }
};