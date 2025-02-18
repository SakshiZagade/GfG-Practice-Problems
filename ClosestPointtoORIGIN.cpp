//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    public:
     vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Max Heap (priority queue) with pair: {distance, point}
        priority_queue<pair<int, vector<int>>> maxHeap;

        for (auto& point : points) {
            int x = point[0], y = point[1];
            int dist = x * x + y * y; // No need to take sqrt
            
            maxHeap.push({dist, point});
            if (maxHeap.size() > k) {
                maxHeap.pop(); // Remove the farthest point
            }
        }

        // Extract k closest points
        vector<vector<int>> result;
        while (!maxHeap.empty()) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        int n;
        cin >> n;
        vector<vector<int>> points(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> points[i][0] >> points[i][1];
        }
        Solution ob;
        vector<vector<int>> ans = ob.kClosest(points, k);
        sort(ans.begin(), ans.end());
        for (const vector<int>& point : ans) {
            cout << point[0] << " " << point[1] << endl;
        }
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
