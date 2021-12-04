import java.util.Arrays;
import java.util.Random;

public class quickSort {
    private static final Random random = new Random();
    public quickSort(int[] arr) {
        int n = arr.length;
        sort(arr,0,n-1);
    }

    private void sort(int[] arr, int le, int ri) {
        //  有大于号是因为划分返回的p有随机性，很可能比le小
        if (le >= ri) return;
        int p = partition(arr,le,ri);
        sort(arr,le,p-1);
        sort(arr,p+1,ri);
    }

    private int partition(int[] arr, int le, int ri) {
        //  random.nextInt  左闭右开
        int randomIndex = le + random.nextInt(ri - le + 1);
        swap(arr,le,randomIndex);
        int pivot = arr[le];
        //  [le+1,lt] < pivot
        //  [lt+1,i) >= pivot
        //  lt存放当前比pivot小的元素，初始情况必须设置为lt = le
        int lt = le;
        for (int i = le + 1; i <= ri; i++) {
            if (arr[i] < pivot) {
                lt++;
                swap(arr,lt,i);
            }
        }
        swap(arr,le,lt);
        return lt;
    }

    private void swap(int[] arr, int x, int y) {
        int temp = arr[x];
        arr[x] = arr[y];
        arr[y] = temp;
    }

    public static void main(String[] args) {
        int[] nums = {2,3,-1,5,0,9,1,2,23,-1,3,-8,2};
        quickSort quickSort = new quickSort(nums);
        System.out.println(Arrays.toString(nums));
    }
}
