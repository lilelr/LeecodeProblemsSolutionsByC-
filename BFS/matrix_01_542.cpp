//
//https://leetcode.com/problems/01-matrix/discuss/171097/Java-BFS-O(n)-Solution-With-Explanation
// BFS
// We add all 0 elements to the queue, and set the res of all of their coordinates to 0 while 1s are Integer.MAX_VALUE. We BFS from all of 0s, and update the unvisited elements to the shortest distance if they are Integer.MAX_VALUE. You can also just check if it's a greater number than your current distance but a lot of people were getting confused with the time complexity. (BFS visits the shortest path to each node first so at most every node will only be visited once again)
// class Solution {
//public int[][] updateMatrix(int[][] matrix) {
//        Queue <int[]> bfs = new LinkedList<>();
//        final int M = matrix[0].length;
//        final int N = matrix.length;
//        int [][] res = new int[N][M];
//        for(int i=0; i<N;++i){
//            for(int j=0; j<M;++j){
//                if(matrix[i][j]==0){
//                    bfs.add(new int[]{i,j,0});
//                    res[i][j]=0;
//                }
//                else{
//                    res[i][j]=Integer.MAX_VALUE;
//                }
//            }
//        }
//        int [][] direct = new int[][]{{0,1},{1,0},{-1,0},{0,-1}};
//        while(!bfs.isEmpty()){
//            int [] pos = bfs.remove();
//            int nextVal =  pos[2]+1;
//            for(int[] dir:direct){
//                int nextRow = pos[0]+dir[0];
//                int nextCol = pos[1]+dir[1];
//                if(nextRow>=0 && nextCol>=0 && nextRow<N && nextCol<M && res[nextRow][nextCol]==Integer.MAX_VALUE){
//                    res[nextRow][nextCol]=nextVal;
//                    bfs.add(new int[]{nextRow,nextCol,nextVal});
//                }
//
//            }
//        }
//        return res;
//    }
//}


// DFS
//Using DFS method.

//Assigned a large value to all the positions with value 1 and don't have 0 neighbors
//Start dfs search from positions whose value is 1

//https://leetcode.com/problems/01-matrix/discuss/101060/Java-DFS-solution-beat-95

//class Solution {
//    int[][] dirs={{0,1},{0,-1},{1,0},{-1,0}};
//public int[][] updateMatrix(int[][] matrix) {
//        if(matrix.length==0) return matrix;
//        int m=matrix.length;
//        int n=matrix[0].length;
//
//        for(int i = 0; i<m; i++)
//            for(int j = 0; j<n; j++)
//                if(matrix[i][j]==1 &&!hasNeiberZero(i, j,matrix))
//                    matrix[i][j] = Integer.MAX_VALUE;
//
//        for(int i = 0; i<matrix.length; i++)
//            for(int j = 0; j<matrix[0].length; j++)
//                if(matrix[i][j]==1)
//                    dfs(matrix, i, j, -1);
//
//        return matrix;
//    }
//private void dfs(int[][] matrix, int x, int y, int val){
//        if(x<0||y<0||y>=matrix[0].length||x>=matrix.length||matrix[x][y]<=val)
//            return;
//        if(val>0) matrix[x][y] = val;
//        for(int[] dir: dirs){
//            int x1=x+dir[0];
//            int y1=y+dir[1];
//            dfs(matrix,x1,y1,matrix[x][y]+1);
//        }
//    }
//private boolean hasNeiberZero(int x, int y, int[][] matrix){
//        int m=matrix.length;
//        int n=matrix[0].length;
//        for (int[] dir:dirs){
//            int x1=x+dir[0];
//            int y1=y+dir[1];
//            if (x1>=0 && x1<m && y1>=0 && y1<n && matrix[x1][y1]==0){
//                return true;
//            }
//        }
//        return false;
//    }
