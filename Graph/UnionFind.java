import java.util.Arrays;

public class UnionFind {
    /*
    * 1 处理不相交集合的 合并 与 查询 问题
    * 2 回答 动态连通性 问题
    * 例如，图中的连通分量问题
    * 使用了quick-union路径压缩
    * 没有使用quick-union按秩压缩*/

    int[] parent;
    int N;      //  顶点数量
    int count;  //  连通分量个数
    public UnionFind(int n) {
        this.N = n + 1;
        this.count = n;
        parent = new int[N];    //  start from number   1
        for (int i = 1; i < N; i++) {
            parent[i] = i;
        }
    }
    public int find(int x) {
        //  终止条件是x等于parent[x]   说明找到了父节点
        //  更新沿途节点的父节点
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    public void union(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return;
        //  把rootY合并到rootX中  或者  把rootX合并到rootY中 视具体情况而定
        parent[rootY] = rootX;
        count--;
    }

    public static void main(String[] args) {
        UnionFind unionFind = new UnionFind(5);
        unionFind.union(1,2);
        unionFind.union(2,3);
        unionFind.union(3,4);
        unionFind.union(5,4);
        System.out.println(unionFind.count);
        System.out.println(Arrays.toString(unionFind.parent));
    }
}
