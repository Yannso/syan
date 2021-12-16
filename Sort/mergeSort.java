import java.util.Arrays;

public class mergeSort {
    private int[] temp; //  使用全局变量，减少时间复杂度

    public mergeSort(int[] arr) {
        int n = arr.length;
        temp = new int[n];
        sort(arr,0,n-1);
    }

    private void sort(int[] arr, int le, int ri) {
        if (le == ri) return;
        int mid = le + (ri - le) / 2;
        sort(arr,le,mid);
        sort(arr,mid+1,ri);
        merge(arr,le,mid,ri);
    }

    private void merge(int[] arr, int le, int mid, int ri) {
        int i = le;
        int j = mid + 1;
        //  定义每次归并的区间位置是[left,right]
        int k = le;
        System.arraycopy(arr,le,temp,le,ri - le + 1);
        while (i <= mid && j <= ri) {
            if (temp[i] <= temp[j]) {
                arr[k++] = temp[i++];
            } else {
                arr[k++] = temp[j++];
            }
        }
        while (i <= mid) {
            arr[k++] = temp[i++];
        }
        while (j <= ri) {
            arr[k++] = temp[j++];
        }
    }

    public static void main(String[] args) {
        int[] nums = {2,3,-1,5,0,9,1,2,3,-8,2};
        mergeSort mergeSort = new mergeSort(nums);
        System.out.println(Arrays.toString(nums));
    }
}
