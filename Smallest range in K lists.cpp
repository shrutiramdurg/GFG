class Solution {
  public:
    vector<int> findSmallestRange(vector<vector<int>>& arr) {
        int k = arr.size(); // number of lists

        // Custom comparator for min-heap
        auto comp = [](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
            return get<0>(a) > get<0>(b); // min-heap based on value
        };

        // Priority queue: (value, row, col)
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(comp)> pq(comp);
        int maxi = INT_MIN;

        // Initialize heap with first element of each list
        for (int i = 0; i < k; ++i) {
            pq.push(make_tuple(arr[i][0], i, 0));
            maxi = max(maxi, arr[i][0]);
        }

        int start = 0, end = INT_MAX;

        while (!pq.empty()) {
            int mini, row, col;
            std::tie(mini, row, col) = pq.top();
            pq.pop();

            if (maxi - mini < end - start) {
                start = mini;
                end = maxi;
            }

            // If more elements in the row, push next
            if (col + 1 < arr[row].size()) {
                int nextVal = arr[row][col + 1];
                pq.push(make_tuple(nextVal, row, col + 1));
                maxi = max(maxi, nextVal);
            } else {
                break;
            }
        }

        return {start, end};
    }
};