#include <iostream>
#include <vector>
using namespace std;

struct Point {
    int x, y;
};

// returns:
// 0 → collinear
// 1 → clockwise
// 2 → counter-clockwise
int orientation(const Point& a, const Point& b, const Point& c) {
    int cross = (b.y - a.y) * (c.x - b.x) -
                (b.x - a.x) * (c.y - b.y);

    if (cross == 0) return 0;
    return (cross > 0) ? 1 : 2;
}

vector<Point> jarvisHull(const vector<Point>& points) {
    int n = points.size();
    if (n < 3) return points;

    // 1. Find leftmost point
    int leftmost = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].x < points[leftmost].x) {
            leftmost = i;
        }
    }

    vector<Point> hull;
    int current = leftmost;

    while (true) {
        hull.push_back(points[current]);

        // 2. Assume next point is (current+1)
        int next = (current + 1) % n;

        // 3. Search for the most counter-clockwise point
        for (int i = 0; i < n; i++) {
            if (orientation(points[current], points[i], points[next]) == 2)
                next = i;
        }

        current = next;

        // stop when we wrap back to starting point
        if (current == leftmost) break;
    }

    return hull;
}

int main() {
    vector<Point> pts = {
        {0, 3}, {1, 1}, {2, 2}, {4, 4},
        {0, 0}, {1, 2}, {3, 1}, {3, 3}
    };

    vector<Point> hull = jarvisHull(pts);

    for (auto& p : hull)
        cout << "(" << p.x << "," << p.y << ") ";

    cout << "\n";
}
