class Solution {
public:
    string getstring(int n) {
        std::stringstream newstr;
        newstr << n;
        return newstr.str();
    }

    vector<string> summaryRanges(vector<int>& nums) {
        int i, j, k, len = nums.size();
        vector<string> s;
        for(i = k = 0; i < len; i = j, k++) {
            string ss = getstring(nums[i]);
            for(j = i + 1; j < len && nums[j] - nums[j - 1] == 1; j++) {}
            if(j - i > 1)
                ss = ss + "->" + getstring(nums[j - 1]);
            s.insert(s.end(),1,ss);
        }
        return s;
    }
};
