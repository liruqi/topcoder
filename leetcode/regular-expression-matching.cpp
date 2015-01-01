// Solution for https://oj.leetcode.com/problems/regular-expression-matching/
// By liruqi@gmail.com

public class Solution {
    class Node {
        char c;
        int cnt; // 0 = any
        public Node (char cc, int ii) {
            c = cc; cnt = ii;
        }
    }
    
    public boolean found(int textp, int pp) {
        if (pp >= pattern.size()) {
            if (textp == text.length()) return true;
            return false;
        }
        if (textp >= text.length()) {
            return pp >= endIndex;
        }
        char c = text.charAt(textp);
        Node node = pattern.get(pp);
        if (node.cnt == 0) {
            if (found(textp, pp+1)) return true;
        }
        if (c != node.c && node.c!='.') return false;
        if (node.cnt == 1) return found(textp+1, pp+1);
        return found(textp+1, pp+1) || found(textp+1, pp);
    }
    
    ArrayList<Node> pattern = new ArrayList<Node>();
    String text = "";
    int endIndex = 0;
    public boolean isMatch(String s, String p) {
        int ri = 0;
        char c = 0;
        for(; ri < p.length() ; ri++) {
            char cc = p.charAt(ri);
            if (cc == '*') {
                if (c>0) {
                    Node node = new Node(c, 0);
                    if (pattern.size() == 0) {
                        pattern.add(node);
                    } else {
                        Node ln =  pattern.get(pattern.size()-1);
                        if (ln.c == node.c && ln.cnt==0) {
                            ln.cnt = 0;
                        } else {
                            pattern.add(node);
                        }
                    }
                }
                c = 0;
                
            } else {
                if (c>0) {
                    Node node = new Node(c, 1);pattern.add(node);
                    endIndex = pattern.size();
                }
                c = cc;
            }
        } 
        if (c > 0) {
            Node node = new Node(c, 1);
            pattern.add(node);
            endIndex = pattern.size();
        }
        text = s;
        return found(0, 0);
    }
}

