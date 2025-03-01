class Solution {
    public:
 string decodedString(string &s) {
        stack<string> strStack;  
        stack<int> numStack;
        string currStr = "";
        int num = 0;

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');  // Forming multi-digit numbers
            } else if (c == '[') {
                numStack.push(num);
                strStack.push(currStr);
                num = 0;
                currStr = "";
            } else if (c == ']') {
                int repeatCount = numStack.top();
                numStack.pop();
                string temp = strStack.top();
                strStack.pop();
                
                while (repeatCount--) temp += currStr;  // Repeat and append
                currStr = temp;
            } else {
                currStr += c;
            }
        }

        return currStr;
    }
};
