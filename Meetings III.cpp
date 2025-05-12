class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        priority_queue<int, vector<int>, greater<int>> available;
        for (int i = 0; i < n; ++i) {
            available.push(i);
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> occupied;
        vector<int> count(n, 0);

        for (auto& m : meetings) {
            long long start = m[0], end = m[1];
            while (!occupied.empty() && occupied.top().first <= start) {
                available.push(occupied.top().second);
                occupied.pop();
            }

            if (!available.empty()) {
                int room = available.top(); available.pop();
                occupied.push({end, room});
                count[room]++;
            } else {
                long long end_time = occupied.top().first;
                int room = occupied.top().second;
                occupied.pop();
                long long duration = end - start;
                occupied.push({end_time + duration, room});
                count[room]++;
            }
        }

        int maxMeetings = 0, resultRoom = 0;
        for (int i = 0; i < n; ++i) {
            if (count[i] > maxMeetings) {
                maxMeetings = count[i];
                resultRoom = i;
            }
        }
        return resultRoom;
    }
};
