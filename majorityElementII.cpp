class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int major1, major2, c1 = 0, c2 = 0;
        for(int i : nums) {
            if(!c1 || i == major1) {
                major1 = i;
                c1++;
            }
            else if(!c2 || i == major2) {
                major2 = i;
                c2++;
            }
            else {
                c1--;
                c2--;
            }
        }
        c1 = c2 = 0;
        for(int i : nums) {
            if(i == major1)
                c1++;
            else if(i == major2)
                c2++;
        }
        if(c1 > nums.size() / 3)
            res.push_back(major1);
        if(c2 > nums.size() / 3)
            res.push_back(major2);
        return res;
    }
};
