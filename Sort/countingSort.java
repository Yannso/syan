import java.util.Arrays;

public class countingSort {
    int n;  //  数组的大小
    int[] count;    //  计数数组
    int m;  //  arr数组中最大元素
    public countingSort(int[] arr) {
        //  arr数组中的元素必须全是正的
        this.n = arr.length;
        this.m = -1;
        for (int x : arr) {
            this.m = Math.max(this.m,x);
        }
        count = new int[m+1];
        for (int x : arr) {
            count[x]++;
        }
        sortv1(arr);
    }
    //  使用前缀和数组
    private void sortv1(int[] arr) {
        //  原数组 ->  计数数组    ->  计数数组的前缀和数组
        //  [1,2,2,3,3,4] -> [0,1,2,2,1] -> [0,1,3,5,6]
        int[] prefix = new int[m+1];
        prefix[0] = count[0];
        for (int i = 1; i < m+1; i++) {
            prefix[i] = prefix[i-1] + count[i];
        }
        int[] copyOfArr = new int[n];
        System.arraycopy(arr,0,copyOfArr,0,n);
        for (int i = n - 1; i >= 0; i--) {
            //  copy[i]元素可能有多个，其最后一个index位于prefex[copy[i]] - 1这个位置
            int pos = prefix[copyOfArr[i]] - 1;
            arr[pos] = copyOfArr[i];
            prefix[copyOfArr[i]]--;
        }
    }
    //  不使用前缀和
    private void sortv2(int[] arr) {
        int idx = 0;
        for (int i = 0; i < count.length; i++) {
            if (count[i] == 0) continue;
            while (count[i]-- != 0) {
                arr[idx++] = i;
            }
            if (idx == n) break;
        }
    }

    public static void main(String[] args) {
        int[] nums = {2,3,5,0,9,1,2,3,8,2};
        countingSort countingSort = new countingSort(nums);
        System.out.println(Arrays.toString(nums));
    }
}
