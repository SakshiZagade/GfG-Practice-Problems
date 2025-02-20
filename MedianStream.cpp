class Solution{
  public:
        vector<double> getMedian(vector<int> &arr) {
        vector<double> result;
        priority_queue<int> maxHeap; // Max Heap for the left half
        priority_queue<int, vector<int>, greater<int>> minHeap; // Min Heap for the right half
        
        for (int num : arr) {
            if (maxHeap.empty() || num <= maxHeap.top()) {
                maxHeap.push(num);
            } else {
                minHeap.push(num);
            }
            
            // Balance the heaps
            if (maxHeap.size() > minHeap.size() + 1) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            } else if (minHeap.size() > maxHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
            
            // Compute the median
            if (maxHeap.size() > minHeap.size()) {
                result.push_back(maxHeap.top());
            } else {
                result.push_back((maxHeap.top() + minHeap.top()) / 2.0);
            }
        }
        
        return result;
    }
};
