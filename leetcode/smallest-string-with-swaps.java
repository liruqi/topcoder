import java.util.ArrayList;
import java.util.List;
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
    
    public String smallestStringWithSwaps(String s, List<List<Integer>> pairs) {
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

