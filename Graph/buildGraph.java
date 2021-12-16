public class buildGraph {
    //  第一种：链式前向星   add方法
    int N,M,idx;
    int[] headEdge,edge,nextEdge,weight;
    //  第二种：使用ArrayList类
    ArrayList<Integer>[] adjs;

    public buildGraph(int N,int M) {
        //  N顶点数量   N边数量
        this.N = N;
        this.M = M;
        //  第一种
        headEdge = new int[N];
        edge = new int[M];
        nextEdge = new int[M];
        weight = new int[M];
        //  第二种
        adjs = new ArrayList[N];
        for (int i = 0; i < N; i++) {
            adjs[i] = new ArrayList<>();
        }
    }

    private void add(int a, int b, int c) {
        //  a指向b —— 编号idx的边指向b
        edge[idx] = b;
        //  将顶点a的头边，作为    编号idx的边    的下一条边
        nextEdge[idx] = headEdge[a];
        //  更新顶点a的头边
        headEdge[a] = idx;
        //  记录这条边的权重    如果是无权图，就不需要这个数组
        weight[idx] = c;
        idx++;
    }

}
