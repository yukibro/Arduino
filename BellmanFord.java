import java.util.Arrays;

public class BellmanFord{

    public static final int INF = Integer.MAX_VALUE;

    public static void bellmanFord(int num, int[][] adj, int src){

        int[] dists = new int[num];
        Arrays.fill(dists, INF);
        dists[0]=0;
        for(int v = 0; v < num; v++){
            for(int i = 0; i < num; i++){
                for(int j = 0; j < num; j++){
                    if(adj[i][j] != INF){
                        dists[j] = Math.min(dists[j], dists[i] + adj[i][j]);
                    }
                }
            }
        }
        for(int i =0; i < num; i++){
            System.out.println(" "+ dists[i]);
        }
    }
    public static void main(String[] args) {
        System.out.println("Hello BellmanFord");
        int num=5;
        int[][] adj = new int[][]{
                {0, 6, INF, 7, INF},
                {INF, 0, 5, 9, -4},
                {INF, -2, 0, INF, INF},
                {INF, INF, -3, 0, 9},
                {2, INF, 7, INF, 0} };
        int src=0;
        bellmanFord(num, adj, src);
    }

}