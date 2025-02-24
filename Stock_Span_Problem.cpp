class Solution{
    public:
            vector<int> calculateSpan(vector<int>& arr) {
            int n = arr.size();
            vector<int> span(n, 1); // Initialize all spans to 1
            stack<int> st; // Stack to store indices
    
            for (int i = 0; i < n; i++) {
                while (!st.empty() && arr[st.top()] <= arr[i]) {
                    st.pop(); // Pop elements that are smaller or equal
                }
                
                // If stack is empty, all previous elements are smaller
                span[i] = (st.empty()) ? (i + 1) : (i - st.top());
                
                // Push the current index onto the stack
                st.push(i);
            }
            
            return span;
  }
}
