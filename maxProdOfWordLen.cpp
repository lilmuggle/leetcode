class Solution {
public:
    int maxProduct(vector<string>& words) {
        int prod = 0;
        vector<int> bit(words.size(), 0);
        for(int i = 0; i < words.size(); i++)
            for(char c : words[i])
                bit[i] |= 1 << (c - 'a');
        for(int i = 0; i < words.size(); i++)
            for(int j = i + 1; j < words.size(); j++)
                if((num[i] & num[j]) == 0)
                    prod = max(prod, (int)words[i].size() * (int)words[j].size());
        return prod;
    }
};
