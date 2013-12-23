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
    int maxPoints(vector<Point> &points) {
        vector<double> d;
        int max = 0, a, y;
        int tmax;
        for (auto &point : points) {
            a = 1;
            y = 0;
            for (auto &point1: points) {
                if (&point != &point1) {
                    if (point.x == point1.x) {
                        if (point.y == point1.y) {
                            a++;
                        } else {
                            y++;
                        }
                    } else {
                        d.push_back((point.y - point1.y) / (double) (point.x - point1.x));
                    }
                }
            }
            sort(d.begin(), d.end());
            for (auto it = d.begin(); it != d.end();) {
                double b = *it;
                tmax = a;
                do {
                    tmax++;
                    it++;
                } while ((it != d.end()) && (abs(*it - b) < 1e-9));
                max = tmax > max ? tmax : max;
            }
            max = max > (a + y) ? max : (a + y);
            d.clear();
        }
        return max;
    }
};