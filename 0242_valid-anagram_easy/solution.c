class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        vector<int> arr1(256, 0);
        vector<int> arr2(256, 0);
        for(auto i : s) arr1[i]++;
        for(auto i : t) arr2[i]++;
        return arr1 == arr2;
    }
};