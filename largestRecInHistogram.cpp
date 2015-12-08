class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int h, maxarea = 0;
        stack<int> stk;
        height.push_back(0);
        for(int i = 0; i < height.size(); i++) {
            while(!stk.empty() && height[stk.top()] > height[i]) {
               h = height[stk.top()];
               stk.pop();
               maxarea = max(maxarea, h * (i - (stk.empty() ? - 1 : stk.top()) - 1));
            }
            stk.push(i);
        }
        return maxarea;
    }
};
