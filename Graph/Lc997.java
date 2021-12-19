public class Lc997 {
    //  图的出度入度问题
    public int findJudge(int n, int[][] trust) {
        int[] inbound = new int[n+1];
        int[] outbound = new int[n+1];
        for (int[] t : trust) {
            int x = t[0], y = t[1];
            outbound[x]++;
            inbound[y]++;
        }
        for (int i = 1; i < n + 1; i++) {
            if (outbound[i] == 0 && inbound[i] == n - 1) {
                return i;
            }
        }
        return -1;
    }
}
