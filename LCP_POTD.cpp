class Solution{
public:
    string LCP(string ar[], int n)
    {
       if (n == 0) return "-1";
        
        // Sort the array
        sort(ar, ar + n);
        
        string first = ar[0];
        string last = ar[n - 1];
        
        int minLength = min(first.length(), last.length());
        int i = 0;
        
        // Find the common prefix between first and last string
        while (i < minLength && first[i] == last[i]) {
            i++;
        }
        
        // If no common prefix found
        if (i == 0) return "-1";
        
        return first.substr(0, i);
    }
};
