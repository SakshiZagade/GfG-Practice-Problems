class Solution {
  public:
    int binarysearch(vector<int> &arr, int k) {
        // code here
       int start = 0, end = arr.size() - 1;
    int result = -1; // To store the first occurrence

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == k) {
            result = mid; // Store the index of found element
            end = mid - 1; // Keep searching in the left half for first occurrence
        } 
        else if (arr[mid] < k) {
            start = mid + 1;
        } 
        else {
            end = mid - 1;
        }
    }

    return result; // Return the first occurrence index
    }
};
