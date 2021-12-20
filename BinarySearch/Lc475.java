import java.util.Arrays;

public class Lc475 {
    public int findRadius(int[] houses, int[] heaters) {
        /*
        * https://leetcode-cn.com/problems/heaters/
        * 这题想错思路了
        * */
        int ans = 0;
        Arrays.sort(heaters);
        for (int house : houses) {
            //  找到每个房子的左边和右边
            int i = BinarySearch(house,heaters);    //  左边，heaters[i] <= house
            int j = i + 1;                          //  右边,heaters[i] > house
            //  边界情况    左边没有heater
            int left = i < 0 ? Integer.MAX_VALUE : house - heaters[i];
            //  边界情况    右边没有heater
            int right = j >= heaters.length ? Integer.MAX_VALUE : heaters[j] - house;
            int cur = Math.min(left,right);
            ans = Math.max(ans,cur);
        }
        return ans;
    }

    private int BinarySearch(int target, int[] arr) {
        int le = 0;
        int ri = arr.length - 1;
        if (arr[le] > target) {
            return -1;
        }
        while (le < ri) {
            //  heaters[i] <= house     是可以接受的（满足条件）
            //  那么heaters[i] > house 肯定是不可以接受的(不满足条件)，所以ri = mid - 1;
            int mid = (le + ri + 1) >> 1;
            if (arr[mid] > target) {
                ri = mid - 1;
            } else {
                le = mid;
            }
        }
        return le;
    }


    public static void main(String[] args) {
        Lc475 t = new Lc475();
        int[] houses = {1,2,3,4};
        int[] heaters = {1,4};
        int res = t.findRadius(houses,heaters);
        System.out.println(res);
    }
}
