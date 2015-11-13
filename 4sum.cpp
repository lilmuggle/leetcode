class Solution {
public:
     vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> vvi;
        if(nums.size() < 4)
            return  vvi;
        sort(nums.begin(), nums.end());
        unordered_map<int, vector<pair<int, int>> > mp;
        for(int i = 0; i < nums.size(); i++)
            for(int j = i + 1; j < nums.size(); j++)
                mp[nums[i]+nums[j]].push_back(make_pair(i,j));
        for(int i = 0; i < nums.size(); i++){
            if(i>0 && nums[i] == nums[i-1])
                continue;
            for(int j = i + 1; j < nums.size(); j++){
                if(j > i + 1 && nums[j] == nums[j-1])
                    continue;
                int res = target - nums[i] - nums[j];
                if(mp.count(res)){
                    for(auto it = mp[res].begin(); it != mp[res].end(); it++){
                        int k = (*it).first, l = (*it).second;
                        if(k > j){
                            if(!vvi.empty() && nums[i]==vvi.back()[0] && nums[j]==vvi.back()[1]
                            && nums[k]==vvi.back()[2] && nums[l] == vvi.back()[3]){
                                continue;
                            }
                            vector<int> vi={nums[i], nums[j], nums[k], nums[l]};
                            vvi.push_back(vi);
                        }
                    }
                }
            }
        }
        return vvi;
    }
};

//Another
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            while(i != 0 && i < nums.size() && nums[i] == nums[i - 1])
                i++;
            for(int j = i + 1; j < nums.size(); j++) {
                while(j != i + 1 && j < nums.size() && nums[j] == nums[j - 1])
                    j++;
                int start = j + 1, end = nums.size() - 1;
                while(start < end) {
                    if(nums[start] + nums[end] + nums[i] + nums[j] == target) {
                        vector<int> solution;
                        solution.push_back(nums[i]);
                        solution.push_back(nums[j]);
                        solution.push_back(nums[start]);
                        solution.push_back(nums[end]);
                        res.push_back(solution);
                        start++, end--;
                        while(start < end && nums[start] == nums[start - 1])
                            start++;
                        while(end > start && nums[end] == nums[end + 1])
                            end--;
                    }
                    else if(nums[start] + nums[end] + nums[i] + nums[j] > target)
                        end--;
                    else
                        start++;
                }
            }
        }
        return res;
    }
};

//After improvement
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> total;
        int n = nums.size();
        if(n<4)  return total;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++)
        {
            if(i>0&&nums[i]==nums[i-1]) continue;
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
            if(nums[i]+nums[n-3]+nums[n-2]+nums[n-1]<target) continue;
            for(int j=i+1;j<n-2;j++)
            {
                if(j>i+1&&nums[j]==nums[j-1]) continue;
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
                if(nums[i]+nums[j]+nums[n-2]+nums[n-1]<target) continue;
                int left=j+1,right=n-1;
                while(left<right){
                    int sum=nums[left]+nums[right]+nums[i]+nums[j];
                    if(sum<target) left++;
                    else if(sum>target) right--;
                    else{
                        total.push_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});
                        do{left++;}while(nums[left]==nums[left-1]&&left<right);
                        do{right--;}while(nums[right]==nums[right+1]&&left<right);
                    }
                }
            }
        }
        return total;
    }
};
