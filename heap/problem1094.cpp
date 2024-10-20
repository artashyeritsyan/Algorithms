class Solution {
public:
    bool carPooling(std::vector<std::vector<int>>& trips, int capacity) {
        std::sort(trips.begin(), trips.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> temp_heap;
        int currentPassengers = 0;

        int numPassengers;
        int start;
        int end;

        for (int i = 0; i < trips.size(); i++) {
            numPassengers = trips[i][0];
            start = trips[i][1];
            end = trips[i][2];

            while (!temp_heap.empty() && temp_heap.top().first <= start) {
                currentPassengers -= temp_heap.top().second;
                temp_heap.pop();
            }

            currentPassengers += numPassengers;
            if (currentPassengers > capacity) {
                return false;
            }

            temp_heap.emplace(end, numPassengers);
        }
        return true;
    }
};
