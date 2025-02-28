class Solution {
  public:
    int evaluate(vector<string>& arr) {
        stack<int> st;

        for (const string& s : arr) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                // Pop two elements
                if (st.size() < 2) return -1; // Invalid case
                
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                
                if (s == "+") st.push(a + b);
                else if (s == "-") st.push(a - b);
                else if (s == "*") st.push(a * b);
                else if (s == "/") {
                    if (b == 0) return -1; // Handle division by zero
                    st.push(a / b);
                }
            } else {
                // Convert string to integer and push
                st.push(stoi(s));
            }
        }

        return st.top(); // Final result
    }
};
