import java.util.Scanner;

public class vasyaandstrings {
    public static int maxBeauty(String str, int k, char ch) {
        int count = 0;
        int ans = Integer.MIN_VALUE;
        int l = 0, r = 0;
        while (r < str.length()) {
            while (r < str.length() && str.charAt(r) == ch) {
                ans = Math.max(ans, r - l + 1);
                r++;
            }
            while (r < str.length() && str.charAt(r) != ch && count < k) {
                count++;
                ans = Math.max(ans, r - l + 1);
                r++;
            }
            while (l <= r && r < str.length() && str.charAt(r) != ch && count >= k) {
                if (k == 0) {
                    l = ++r;
                    break;
                }
                count -= (str.charAt(l) != ch) ? 1 : 0;
                l++;
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        String str = scanner.next();
        int x = maxBeauty(str, k, 'a');
        int y = maxBeauty(str, k, 'b');
        System.out.println(Math.max(x, y));
    }
}
