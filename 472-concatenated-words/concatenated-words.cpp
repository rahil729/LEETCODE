class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> wordSet(words.begin(), words.end());
        vector<string> res;

        for (string& word : words) {
            int m = word.length();
            vector<bool> dp(m + 1, false);
            dp[0] = true;

            for (int i = 1; i <= m; i++) {
                for (int j = 0; j < i; j++) {
                    if (j == 0 && i == m) continue;
                    if (dp[j] && wordSet.count(word.substr(j, i - j))) {
                        dp[i] = true;
                        break;
                    }
                }
            }

            if (dp[m]) {
                res.push_back(word);
            }
        }
        return res;
    }
};