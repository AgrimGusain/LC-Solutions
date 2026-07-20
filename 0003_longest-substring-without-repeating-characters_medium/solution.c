class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1) return s.size();

        vector<int> ch(256, 0);  // frequency array
        int count = 0;
        int left = 0;

        for (int right = 0; right < s.size(); right++) {
            ch[s[right]]++;

            // If duplicate, shrink window
            while (ch[s[right]] > 1) {
                ch[s[left]]--;
                left++;
            }

            count = max(count, right - left + 1);
        }
        return count;
    }
};
