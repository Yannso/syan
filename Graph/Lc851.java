import java.util.ArrayList;
import java.util.Arrays;

public class Lc851 {
    /*
    * https://leetcode-cn.com/problems/loud-and-rich/
    * 无权有向图问题
    */

    ArrayList<Integer>[] adjs;
    int N, M, idx;
    int[] edge, headEdge, nextEdge;
    int[] ans;
    int[] quiet;

    public int[] loudAndRich(int[][] richer, int[] quiet) {
        N = quiet.length;
        M = richer.length;
        headEdge = new int[N];
        Arrays.fill(headEdge,-1);
        edge = new int[M];
        nextEdge = new int[M];
        idx = 0;
        this.quiet = quiet;
        int[] map = new int[N + 1];
        for (int[] rich : richer) {
            add(rich[1], rich[0]);
        }

        for (int i = 0; i < N; i++) {
            map[quiet[i]] = i;
        }

        ans = new int[N];
        int[] memo = new int[N + 1];
        Arrays.fill(memo, -1);
        for (int i = 0; i < N; i++) {
            ans[i] = map[dfs(i, memo)];
        }
        return ans;
    }

    private void add(int x, int y) {
        //  头插法
        //  idx边指向y节点
        edge[idx] = y;
        //  idx边的下一条边，-1为中止
        nextEdge[idx] = headEdge[x];
        //  节点x的有若干条边，指向最近的一条边
        headEdge[x] = idx;
        idx++;
    }

    private int dfs(int x, int[] memo) {
        if (memo[x] != -1) return memo[x];
        int val = quiet[x];
        for (int y = headEdge[x]; y != -1; y = nextEdge[y]) {
            val = Math.min(val, dfs(edge[y], memo));
        }
        memo[x] = val;
        return val;
    }


    public static void main(String[] args) {
        Lc851 main = new Lc851();
        int[][] richer = {
                {1, 0}, {2, 1}, {3, 1}, {3, 7}, {4, 3}, {5, 3}, {6, 3}
        };
        int[] quiet = {3, 2, 5, 4, 6, 1, 7, 0};
        int[] res = main.loudAndRich(richer, quiet);
        System.out.println(Arrays.toString(res));
    }
}
