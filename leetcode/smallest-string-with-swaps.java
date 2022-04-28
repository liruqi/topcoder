// https://leetcode.com/problems/smallest-string-with-swaps/

import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.TreeSet;

import apple.laf.JRSUIUtils.Tree;

import java.util.Arrays;
import java.util.Collections;

class Solution {

    class DSU {
        int[] parent;
        int[] size;
        
        DSU(int n) {
            parent = new int[n];
            size = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }
        
        int getRootNode(int x) {
            if (x == parent[x]) return x;
            parent[x] = getRootNode(parent[x]);
            return parent[x];
        }
        
        void union(int x, int y) {
            int xR = getRootNode(x);
            int yR = getRootNode(y);
            if (xR == yR) return;
            if (size[xR] > size[yR]) {
                size[xR] += size[yR];
                parent[yR] = xR;
            } else {
                size[yR] += size[xR];
                parent[xR] = yR;
            }
        }
    }
    
    DSU dsu;
    Map<Integer, ArrayList<Integer>> indiceGroups;
    char[] charArr;
        int[] visited;

    public int updateIndiceGroups(int x) {
        if (visited[x] >= 0) {
            return -1;
        }
        Integer g = dsu.getRootNode(x);
        if (indiceGroups.containsKey(g)) {
            indiceGroups.get(g).add(x);
            return 0;
        }
        ArrayList<Integer> ts = new ArrayList<Integer>();
        ts.add(x);
        visited[x] = x;
        
        indiceGroups.put(g, ts);
        return ts.size();
    }
    
    public String smallestStringWithSwaps(String s, List<List<Integer>> pairs) {
        indiceGroups = new HashMap<Integer, ArrayList<Integer>>();
        dsu = new DSU(s.length());
        for (List<Integer> lx : pairs) {
            Integer y=lx.get(0);
            Integer z=lx.get(1);
            if (y == z) continue;
            dsu.union(z, y);
        }

        visited = new int[s.length()];
        Arrays.fill(visited, -1);
        for (int x=0; x<s.length(); x++) {
            updateIndiceGroups(x);
        }

        charArr = s.toCharArray();
        for (Map.Entry<Integer,ArrayList<Integer>> entry : indiceGroups.entrySet()) {            
            List<Integer> igl = entry.getValue();
            // Collections.sort(igl);
            // System.out.println(igl);
            int[] charList = new int[256];
            Arrays.fill(charList, 0);
            for (Integer x : igl) {
                charList[(int)charArr[x]] += 1;
            }
            char k='a';
            for (int j=0; j<igl.size(); j++) {
                while (charList[k] == 0 && k<'z') {
                    k += 1;
                }
                charArr[ igl.get(j) ] = k;
                charList[k] -= 1;
            }
            // // System.out.println(charArr);
        }
        return String.valueOf(charArr);
    }

    TreeSet<?>[] graph;
    int[] charSet = new int[256];
    public int addEdge(Integer x, Integer y) {
        if (graph[x] == null) {
            graph[x] = new TreeSet<Integer>();
        }
        ((TreeSet<Integer>)graph[x]).add(y);
        return 0;
    }

    public int dfs(int x, int gid) {
        visited[x] = gid;
        charSet[(int)charArr[x]] += 1;
        if (graph[x] == null) return 0;

        for (Integer i : (TreeSet<Integer>)graph[x]) {
            if (EMPTY_INDEX == visited[i]) {
                dfs(i, gid);
            }
        }
        return 1;
    }
    public String smallestStringWithSwapsGraphImp(String s, List<List<Integer>> pairs) {
        graph = new TreeSet<?>[s.length()];
        visited = new int[s.length()];
        Arrays.fill(visited, EMPTY_INDEX);
        for (List<Integer> lx : pairs) {
            Integer y=lx.get(0);
            Integer z=lx.get(1);
            if (y == z) continue;
            addEdge(y, z);
            addEdge(z, y);
        }
        charArr = s.toCharArray();
        for (int i=0; i<s.length(); i++) {
            if (EMPTY_INDEX == visited[i]) {
                Arrays.fill(charSet, 0);
                dfs(i, i);

                char k='a';
                System.out.print("\n" + i + " -> ");

                for (int j=0; j<visited.length; j++) if (visited[j] == i)
                {
                    System.out.print(j + " ");

                    while (charSet[k] == 0 && k<'z') {
                        k += 1;
                    }
                    charArr[j] = k;
                    charSet[k] -= 1;
                }
            }
        }
        return String.valueOf(charArr);
    }

// "dcab"
// [[0,3],[1,2],[0,2]]

    public static void main(String[] args) {
        Solution s = new Solution();
        List<List<Integer>> pairs = new ArrayList<>();
        {
            Integer[] a = {0,3};
            pairs.add(Arrays.asList(a));
        }
        {
            Integer[] a = {1,2};
            pairs.add(Arrays.asList(a));
        }
        {
            Integer[] a = {0,2};
            pairs.add(Arrays.asList(a));
        }
        
        
        System.out.print(s.smallestStringWithSwaps("dcab", pairs));
    }

}

