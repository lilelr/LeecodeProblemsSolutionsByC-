
#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>
// https://leetcode.com/problems/max-points-on-a-line/description/
using namespace std;

class Solution {
public:
    // Definition for a point.
    struct Point {
        int x;
        int y;

        Point() : x(0), y(0) {}

        Point(int a, int b) : x(a), y(b) {}
    };

    int gcd(int a, int b) {
        if (b == 0) return a;
        else return gcd(b, a % b);
    }

    int maxPoints(vector<Point> &points) {
        if (points.size() < 2) return points.size();
        int result = 0;

        for (int i = 0; i < points.size(); i++) {
            map<pair<int, int>, int> lines;
            int localmax = 0, overlap = 0, vertical = 0;
            for (int j = i + 1; j < points.size(); j++) {
                if (points[j].x == points[i].x && points[j].y == points[i].y) {
                    overlap++;
                    continue;
                } else if (points[j].x == points[i].x) vertical++;
                else {
                    int a = points[j].x - points[i].x;
                    int b = points[j].y - points[i].y;
                    int t_gcd = gcd(a, b);
                    a /= t_gcd;
                    b /= t_gcd;
                    lines[make_pair(a, b)]++;
                    localmax = max( lines[make_pair(a, b)], localmax);
                }
                localmax = max(localmax,vertical);
            }
            result = max(result, localmax + overlap + 1);
        }
        return result;
    }
};

int main() {

}