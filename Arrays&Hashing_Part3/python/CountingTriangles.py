
class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

def count_right_angled_triangles(points):
    count = 0
    x_count = {}
    y_count = {}

    # Count the occurrences of x and y coordinates
    for point in points:
        x_count[point.x] = x_count.get(point.x, 0) + 1
        y_count[point.y] = y_count.get(point.y, 0) + 1

    # Count the triangles
    for point in points:
        count_x = x_count[point.x]
        count_y = y_count[point.y]
        count += (count_x - 1) * (count_y - 1)

    return count % 10000

if __name__ == '__main__':
    N = int(input())

    # Read the points
    points = []
    for _ in range(N):
        x, y = map(int, input().split())
        points.append(Point(x, y))

    # Count the right-angled triangles
    num_triangles = count_right_angled_triangles(points)

    # Print the result
    print(num_triangles)
