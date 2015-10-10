//Original
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(k == 0)
            return false;
        int count = 1;
        unordered_map<int, int> m;
        for(int i: nums)
        {
            if(m[nums[i]] == 0)
                m[nums[i]] += count;
            else
            {
                if(count - m[nums[i]] <= k)
                    return true;
                else
                    m[nums[i]] = count;
            }
            count++;
        }
        return false;
    }
};

//Others
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
       unordered_set<int> s;

       if (k <= 0) return false;
       if (k >= nums.size()) k = nums.size() - 1;

       for (int i = 0; i < nums.size(); i++)
       {
           if (i > k) s.erase(nums[i - k - 1]);
           if (s.find(nums[i]) != s.end()) return true;
           s.insert(nums[i]);
       }

       return false;
    }
};
