class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() < 3)
            return 0;
        int start, h, water, i = 0, rain = 0;
        while(i < height.size()) {
            while(i < height.size() - 1 && height[i] <= height[i + 1])
                i++;
            start = i++;
            water = 0;
            while(i < height.size() && height[i] < height[start])
                water += height[start] - height[i++];
            if(i == height.size()) {
                vector<int> h;
                for(int j = height.size() - 1; j >= start; j--)
                h.push_back(height[j]);
                water = trap(h);
            }
            rain += water;
        }
        return rain;
    }
};

//Another
class Solution {
public:
    int trap(int A[], int n) {
        int left=0; int right=n-1;
        int res=0;
        int maxleft=0, maxright=0;
        while(left<=right){
            if(A[left]<=A[right]){
                if(A[left]>=maxleft) maxleft=A[left];
                else res+=maxleft-A[left];
                left++;
            }
            else{
                if(A[right]>=maxright) maxright= A[right];
                else res+=maxright-A[right];
                right--;
            }
        }
        return res;
    }
};
