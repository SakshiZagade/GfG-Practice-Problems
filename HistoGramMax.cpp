class Solution
{
  public:
         int getMaxArea(vector<int> &arr) {
                int n = arr.size();
                stack<int> s;
                int max_area = 0;
                
                for (int i = 0; i <= n; i++) {
                    while (!s.empty() && (i == n || arr[s.top()] > arr[i])) {
                        int height = arr[s.top()];
                        s.pop();
                        int width = s.empty() ? i : (i - s.top() - 1);
                        max_area = max(max_area, height * width);
                    }
                    s.push(i);
                }
        
        return max_area;
    }
};
