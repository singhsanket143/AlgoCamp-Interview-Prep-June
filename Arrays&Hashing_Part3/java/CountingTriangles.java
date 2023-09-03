import java.util.*;

public class RightAngledTriangles {
    
    static class Point {
        int x;
        int y;
        
        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    
    public static int countRightAngledTriangles(Point[] points) {
        int count = 0;
        Map<Integer, Integer> xCount = new HashMap<>();
        Map<Integer, Integer> yCount = new HashMap<>();
        
        // Count the occurrences of x and y coordinates
        for (Point point : points) {
            xCount.put(point.x, xCount.getOrDefault(point.x, 0) + 1);
            yCount.put(point.y, yCount.getOrDefault(point.y, 0) + 1);
        }
        
        // Count the triangles
        for (Point point : points) {
            int countX = xCount.get(point.x);
            int countY = yCount.get(point.y);
            count += (countX - 1) * (countY - 1);
        }
        
        return count % 10000;
    }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of points
        int N = scanner.nextInt();
        
        // Read the points
        Point[] points = new Point[N];
        for (int i = 0; i < N; i++) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            points[i] = new Point(x, y);
        }
        
        scanner.close();
        
        // Count the right-angled triangles
        int numTriangles = countRightAngledTriangles(points);
        
        // Print the result
        System.out.println(numTriangles);
    }
}
