class Solution {
  public:
    bool isPossible(vector<int>& arr, int k, int w, int target) {
        int n = arr.size();
        vector<int> diff(n + 1, 0);  // difference array
        long long used = 0;
        int currAdd = 0;

        for (int i = 0; i < n; i++) {
            currAdd += diff[i];  // Apply past effects
            int currHeight = arr[i] + currAdd;
            if (currHeight < target) {
                int delta = target - currHeight;
                used += delta;
                if (used > k) return false;
                currAdd += delta;
                if (i + w < n) diff[i + w] -= delta;
            }
        }

        return true;
    }

    int maxMinHeight(vector<int> &arr, int k, int w) {
        int low = *min_element(arr.begin(), arr.end());
        int high = low + k;
        int ans = low;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(arr, k, w, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
