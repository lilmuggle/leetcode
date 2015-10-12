class Solution {
public:
    int compareVersion(string version1, string version2) {
        int v1, v2;
        int i = 0, j = 0, len1 = version1.size(), len2 = version2.size();
        while(i < len1 || j < len2)
        {
            v1 = v2 = 0;
            while(version1[i] != '.' && i < len1)
                v1 = v1 * 10 + (version1[i++] - '0');
            while(version2[j] != '.' && j < len2)
                v2 = v2 * 10 + (version2[j++] - '0');
            if(v1 > v2)
                return 1;
            else if(v1 < v2)
                return -1;
            i++;
            j++;
        }
        return 0;
    }
};
