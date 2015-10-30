class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        unordered_multimap<int, int> m;
        for(int i = 0; i < nums.size(); i++) {
            m.insert({nums[i], i});
        }
        for(int i = 0; i < nums.size(); i++) {
            if(target - nums[i] == nums[i]) {
                if(m.count(nums[i]) == 2) {
                    auto iter = m.find(nums[i]);
                    v.push_back(++iter->second);
                    iter++;
                    v.push_back(++iter->second);
                    sort(v.begin(), v.end());
                    return v;
                }
            }
            else {
                auto iter = m.find(target-nums[i]);
                if(iter != m.end()) {
                    v.push_back(i + 1);
                    v.push_back(++iter->second);
                    return v;
                }
            }
        }
    }
};

//After improvement
vector<int> twoSum(vector<int> &numbers, int target)
{
    //Key is the number and value is its index in the vector.
    unordered_map<int, int> hash;
    vector<int> result;
    for (int i = 0; i < numbers.size(); i++) {
        int numberToFind = target - numbers[i];

            //if numberToFind is found in map, return them
        if (hash.find(numberToFind) != hash.end()) {
                    //+1 because indices are NOT zero based
            result.push_back(hash[numberToFind] + 1);
            result.push_back(i + 1);
            return result;
        }

            //number was not found. Put it in the map.
        hash[numbers[i]] = i;
    }
    return result;
}
