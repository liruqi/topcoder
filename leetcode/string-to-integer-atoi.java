import java.math.BigInteger;

public class Solution {
    public int atoi(String str) {
        try {
            str = str.trim();
            for (int i=0; i<str.length(); i++) {
                if (str.charAt(i) == '-') continue;
                if (str.charAt(i) == '+') continue;
                if (str.charAt(i) >= '0' && str.charAt(i) <= '9') continue;
                str = str.substring(0, i);
            }
            BigInteger ret = new BigInteger(str);
            if (ret.compareTo(BigInteger.valueOf(Integer.MAX_VALUE)) == 1) return Integer.MAX_VALUE;
            if (ret.compareTo(BigInteger.valueOf(Integer.MIN_VALUE)) == -1) return Integer.MIN_VALUE;

            return ret.intValue();
        } catch (Exception e) {
            return 0;
        }
    }
}
