import java.util.*;

public class BlackSlexAndShowering {

    public int solve(int [] arr, int n) {
        int [] max = new int[2];
        int sum = 0;

        for (int i = 1; i < arr.length; i++) {
            sum+=arr[i];
            int diff = difference(arr[i], arr[i-1]);

            if (diff > max[0]) {
                max[0] = diff;
                max[1] = i;
            }
        }

        if (max[1] == n-1) {
            return sum-max[0];
        } else if (max[1] == 1) {
            return sum - Math.min(sum)
        }


    }

    private int difference (int a, int b) {
        return Math.abs(a-b);
    }
}