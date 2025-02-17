
class Solution {
   public:
    vector<int> kLargest(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int i = 0; i < arr.size(); i++) {
            minHeap.push(arr[i]);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top());
            minHeap.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
