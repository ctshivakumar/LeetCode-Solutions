// Time:  O(n)
// Space: O(1)

// two pointers
class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int result = 0;
        for (int i = 0; i < size(s); ++i) {
            int left = i + 1, right = i;
            while (left - 1 >= 0 && right + 1 < size(s) && s[left - 1] == '0' && s[right + 1] == '1') {
                --left, ++right;
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(1)
// string
class Solution2 {
public:
    int findTheLongestBalancedSubstring(string s) {
        int result = 0, prev = 0;
        vector<int> cnt(2);
        for (int i = 0; i < size(s); ++i) {
            if (s[i] == '0') {
                ++cnt[0];
                cnt[1] = 0;
            } else {
                ++cnt[1];
                if (cnt[0]) {
                    prev = cnt[0];
                }
                cnt[0] = 0;
            }
            result = max(result, 2 * min(prev, cnt[1]));
        }
        return result;
    }
};
