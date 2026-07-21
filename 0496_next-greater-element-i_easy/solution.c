class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        stack<int> st;
        vector<int> nxt(n2, -1);
        vector<int> ans(n1, -1);
        st.push(nums2[n2-1]);
        for(int i = n2-2; i>=0; i--){
            while(!st.empty() && st.top() < nums2[i]){
                st.pop();
                if(st.empty()) break;
            }
            if(!st.empty() && nums2[i] < st.top()){
                nxt[i] = st.top();
            }
            st.push(nums2[i]);
        }

        for(int i = 0; i<n1; i++){
            int index = find(nums2.begin(), nums2.end(), nums1[i]) - nums2.begin();
            ans[i] = nxt[index];
        }

        return ans;
        
    }
};