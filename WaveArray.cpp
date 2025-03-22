class Solution {
  public:
    // arr: input array
    // Function to sort the array into a wave-like array.
    void convertToWave(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        // Swap adjacent elements in pairs
        for (int i = 0; i < n - 1; i += 2) {
            swap(arr[i], arr[i + 1]);
        }
    }
    
    
};
