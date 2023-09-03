import java.util.List;

public class number_of_rectangles_with_area_less_than_b {
    public static int solve(List<Integer> A, int B) {
        long mod = 1000000007;
        long ans = 0;

        int l = 0;
        int r = A.size() - 1;

        while (l < A.size() && r >= 0) {
            if (1L * A.get(l) * A.get(r) >= B) {
                r--;
            } else {
                ans = (ans % mod + (r + 1) % mod) % mod;
                l++;
            }
        }
        return (int) (ans % mod);
    }

    public static void main(String[] args) {
        // Example usage:
        List<Integer> A = List.of(2,3,5);
        int B = 12;
        int result = solve(A, B);
        System.out.println("Result: " + result);
    }
}
