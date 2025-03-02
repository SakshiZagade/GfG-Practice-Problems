class Solution {
   public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        vector<int> result;
        deque<int> dq; // Store indices of elements
        
        for (int i = 0; i < arr.size(); i++) {
            // Remove elements that are out of this window
            if (!dq.empty() && dq.front() == i - k)
                dq.pop_front();
            
            // Remove smaller elements from the back
            while (!dq.empty() && arr[dq.back()] <= arr[i])
                dq.pop_back();
            
            // Add the current element index
            dq.push_back(i);
            
            // The front of the deque is the largest element in the window
            if (i >= k - 1)
                result.push_back(arr[dq.front()]);
        }
        
        return result;
    }
