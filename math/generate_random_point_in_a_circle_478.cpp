
https://leetcode.com/problems/generate-random-point-in-a-circle/discuss/154405/C++-solution-polar-coordinates

//        r is the distance of the random point to the origin (in the unit circle). since Probability(r < A) = A^2 (The inner circle with radius A), so we can simly take sqrt(A) to get r.
//http://www.anderswallin.net/2009/05/uniform-random-points-in-a-circle-using-polar-coordinates/
class Solution {
public:
    const double PI = 3.14159265358979732384626433832795;
    double m_radius, m_x_center, m_y_center;

    double uniform() {
        return (double)rand() / RAND_MAX;
    }

    Solution(double radius, double x_center, double y_center) {
        m_radius = radius; m_x_center = x_center; m_y_center = y_center;
    }

    vector<double> randPoint() {
        double theta = 2 * 3.14159265358979323846264 * uniform();
        double r = sqrt(uniform());
        return vector<double>{
                m_x_center + r * m_radius * cos(theta),
                m_y_center + r * m_radius * sin(theta)
        };
    }
};