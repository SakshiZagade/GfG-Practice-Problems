class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        int candidate = -1, count = 0;

        // Step 1: Find the candidate
        for (int num : arr) {
            if (count == 0) {
                candidate = num;
                count = 1;
            } else if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }

        // Step 2: Verify if candidate is actually the majority element
        count = 0;
        for (int num : arr) {
            if (num == candidate) {
                count++;
            }
        }

        return (count > arr.size() / 2) ? candidate : -1;
    }
};
