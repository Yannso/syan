import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Lc1034 {
    /*
    * https://leetcode-cn.com/problems/coloring-a-border/
    * dfs 四联通、着色问题
    *  */
    int[][] directions = {{0,1},{0,-1},{-1,0},{1,0}};
    List<int[]> paths = new ArrayList<>();
    boolean[][] visited;
    public int[][] colorBorder(int[][] grid, int row, int col, int color) {
        int m = grid.length;
        int n = grid[0].length;
        visited = new boolean[m][n];
        int originalColor = grid[row][col];
        visited[row][col] = true;
        dfs(grid,row,col,originalColor);
        for (int[] path : paths) {
            int x = path[0];
            int y = path[1];
            grid[x][y] = color;
        }
        return grid;
    }

    private void dfs(int[][] grid, int row, int col, int originalColor) {
        int m = grid.length;
        int n = grid[0].length;
        boolean isBoard = false;
        for (int i = 0; i < 4; i++) {
            int nrow = row + directions[i][0];
            int ncol = col + directions[i][1];
            if (nrow < 0 || nrow >= m || ncol < 0 || ncol >= n || grid[nrow][ncol] != originalColor) {
                //  处在整个网格的边界，它是边界，它的上下左右四个方向任意一个方向的颜色和它不同，也算边界
                isBoard = true;
            } else if (!visited[nrow][ncol]) {
                visited[nrow][ncol] = true;
                dfs(grid,nrow,ncol,originalColor);
            }
        }
        if (isBoard) paths.add(new int[]{row,col});
    }

    public static void main(String[] args) {
        Lc1034 main = new Lc1034();
        int row = 0;
        int col = 0;
        int color = 3;
        int[][] grid = {
                {3,3},
                {3,2}
        };
        int[][] ans = main.colorBorder(grid,row,col,color);
        System.out.println(Arrays.deepToString(ans));
    }
}
