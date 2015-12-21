/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int res = 0, same, vertical, slashmax;
        unordered_map<double, int> slash;
        for(int i = 0; i < points.size(); i++) {
            same = 0;
            slashmax = vertical = 1;
            for(int j = i + 1; j < points.size(); j++) {
                if(points[j].x == points[i].x && points[j].y == points[i].y)
                    same++;
                else if(points[j].x == points[i].x)
                    vertical++;
                else {
                    double k = (double)(points[j].y - points[i].y) / (points[j].x - points[i].x);
                    slash[k]++;
                    slashmax = max(slashmax, slash[k] + 1);
                }
            }
            res = max(res, max(slashmax, vertical) + same);
            slash.clear();
        }
        return res;
    }
};

//Another
class Solution {
public:
    int maxPoints(vector<Point> &points) {

        if(points.size()<2) return points.size();

        int result=0;

        for(int i=0; i<points.size(); i++) {

            map<pair<int, int>, int> lines;
            int localmax=0, overlap=0, vertical=0;

            for(int j=i+1; j<points.size(); j++) {

                if(points[j].x==points[i].x && points[j].y==points[i].y) {

                    overlap++;
                    continue;
                }
                else if(points[j].x==points[i].x) vertical++;
                else {

                    int a=points[j].x-points[i].x, b=points[j].y-points[i].y;
                    int gcd=GCD(a, b);

                    a/=gcd;
                    b/=gcd;

                    lines[make_pair(a, b)]++;
                    localmax=max(lines[make_pair(a, b)], localmax);
                }

                localmax=max(vertical, localmax);
            }

            result=max(result, localmax+overlap+1);
        }

        return result;
    }
/* improvement :
we can change the map to unordered_map by doing

struct hashfunc { size_t operator() (const pair<int,int>& l) const { return l.first ^ l.second; } };

unordered_map< pair< int,int >,int,hashfunc> lines;
*/
