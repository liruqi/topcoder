// https://leetcode.com/problems/smallest-string-with-swaps/

import java.util.ArrayList;
import java.util.List;
import java.util.TreeSet;

import apple.laf.JRSUIUtils.Tree;

import java.util.Arrays;
import java.util.Collections;

class Solution {
    public static int EMPTY_INDEX = -1;
    List<TreeSet<Integer>> indiceGroups = new ArrayList<TreeSet<Integer>>();

    Integer[] disjointSet;
    public int updateIndiceGroups(int x) {
        Integer g=x;
        for (; g != disjointSet[g]; g=disjointSet[g]) {
        }
        
        for (int i=0; i<indiceGroups.size(); i++) {
            TreeSet<Integer> ig = indiceGroups.get(i);
            if (ig.contains(g)) {
                ig.add(x);
                    disjointSet[x] = g;
                
                return i;
            }
        }
            
            TreeSet<Integer> ig = new TreeSet<Integer>();
            ig.add(x);
            ig.add(g);
            indiceGroups.add(ig);
            return EMPTY_INDEX;
    }
    
    public String smallestStringWithSwapsWithDisjointSet(String s, List<List<Integer>> pairs) {
        indiceGroups = new ArrayList<TreeSet<Integer>>();
        disjointSet = new Integer[s.length()];
        Arrays.fill(disjointSet, EMPTY_INDEX);

        for (List<Integer> lx : pairs) {
            Integer y=lx.get(0);
            Integer z=lx.get(1);
            if (y == z) continue;
            int dz = 0;
            if (disjointSet[z] == EMPTY_INDEX) {
                disjointSet[z] = z;
            } else {
                for (; disjointSet[z] >= 0 && disjointSet[z] != z; z=disjointSet[z]) {
                    dz += 1;
                }
            }
            
            if (disjointSet[y] != EMPTY_INDEX) {
                for (; disjointSet[y] != y; y=disjointSet[y]) {
                }
            }
            disjointSet[y] = z;
        }

        for (int x=0; x<disjointSet.length; x++) {
            if (disjointSet[x] == EMPTY_INDEX) {
                continue;
            }
            
            updateIndiceGroups(x);
        }

        char[] charArr = s.toCharArray();
        for (int i=0; i<indiceGroups.size(); i++) {
            TreeSet<Integer> ig = indiceGroups.get(i);
            List<Integer> igl = new ArrayList<Integer>(ig);
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
    boolean[] visited;
    int[] charSet = new int[256];

    public int addEdge(Integer x, Integer y) {
        if (graph[x] == null) {
            graph[x] = new TreeSet<Integer>();
        }
        graph[x].add(y);
        return 0;
    }

    public TreeSet<Integer> dfs(int x) {
        visited[x] = true;
        charSet[(int)charArr[x]] += 1;
        TreeSet<Integer> indiceGroup = new TreeSet<Integer>();
        indiceGroup.add(x);
        if (graph[x] == null) return indiceGroup;

        int c = 1;
        for (Integer i : graph[x]) {
            if (! visited[i]) {
                indiceGroup.addAll(dfs(i));
            }
        }
        return indiceGroup;
    }
    public String smallestStringWithSwaps(String s, List<List<Integer>> pairs) {
        graph = new TreeSet<?>[s.length()];
        visited = new char[s.length()];
        for (List<Integer> lx : pairs) {
            Integer y=lx.get(0);
            Integer z=lx.get(1);
            if (y == z) continue;
            addEdge(y, z);
            addEdge(z, y);
        }
        char[] charArr = s.toCharArray();
        for (int i=0; i<s.length(); i++) {
            if (! visited[i]) {
                Arrays.fill(charSet, 0);
                TreeSet<Integer> igl = dfs(i);
                if (igl.size() <= 1) {
                    continue;
                }

                char k='a';
                
                for (Integer j : igl) {
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

