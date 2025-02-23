class Solution{
  public:
       // Function to find the next greater element for each element of the array.
    vector<int> nextLargerElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> nge(n, -1); // Initialize result array with -1
        stack<int> st; // Stack to keep indices of elements

        for (int i = 0; i < n; i++) {
            // Check if the current element is greater than stack's top element
            while (!st.empty() && arr[i] > arr[st.top()]) {
                nge[st.top()] = arr[i]; // Update the NGE for stack's top index
                st.pop();
            }
            st.push(i); // Push current index onto stack
        }
        return nge;
    }
};
