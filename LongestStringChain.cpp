class Solution {
    public:
    int longestStringChain(vector<string>& words) {
        // Sort words based on length (ascending order)
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.size() < b.size();
        });

        unordered_map<string, int> dp;  // Stores longest chain ending at each word
        int maxLength = 1;

        for (const string &word : words) {
            dp[word] = 1;  // Every word is a chain of at least length 1
            for (int i = 0; i < word.size(); i++) {
                string predecessor = word.substr(0, i) + word.substr(i + 1);  // Remove one character
                if (dp.find(predecessor) != dp.end()) {
                    dp[word] = max(dp[word], dp[predecessor] + 1);
                }
            }
            maxLength = max(maxLength, dp[word]);  // Update max chain length
        }

        return maxLength;
    }
