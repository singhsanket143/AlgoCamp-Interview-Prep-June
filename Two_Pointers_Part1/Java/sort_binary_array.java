import java.util.Arrays;

public class sort_binary_array {
    public static void sortBinaryArray(int[] arr) {
        int left = 0;
        int right = arr.length - 1;

        while (left <= right) {
            while (left <= right && arr[left] == 0) {
                left++;
            }
            while (left <= right && arr[right] == 1) {
                right--;
            }

            if (left <= right) {
                int temp = arr[left];
                arr[left] = arr[right];
                arr[right] = temp;
                left++;
                right--;
            }
        }
    }

    public static void main(String[] args) {
        int[] arr = {0, 1, 0, 1, 1, 0, 0, 1};
        sortBinaryArray(arr);
        System.out.println("Sorted Array: " + Arrays.toString(arr));
    }
}
