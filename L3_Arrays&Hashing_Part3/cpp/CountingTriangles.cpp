
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Point {
    int x;
    int y;
    
    Point(int x, int y) : x(x), y(y) {}
};

int countRightAngledTriangles(vector<Point>& points) {
    int count = 0;
    unordered_map<int, int> xCount;
    unordered_map<int, int> yCount;
    
    // Count the occurrences of x and y coordinates
    for (const Point& point : points) {
        xCount[point.x]++;
        yCount[point.y]++;
    }
    
    // Count the triangles
    for (const Point& point : points) {
        int countX = xCount[point.x];
        int countY = yCount[point.y];
        count += (countX - 1) * (countY - 1);
    }
    
    return count % 10000;
}

int main() {
    int N;
    cin >> N;
    
    // Read the points
    vector<Point> points;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        points.emplace_back(x, y);
    }
    
    // Count the right-angled triangles
    int numTriangles = countRightAngledTriangles(points);
    
    // Print the result
    cout << numTriangles << endl;
    
    return 0;
}
