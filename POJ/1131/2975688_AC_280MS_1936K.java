import java.math.*;
import java.io.*;
import java.util.*;

public class Main {
	public static void main(String args[])throws Exception {
		Scanner cin = new Scanner(System.in);
		while (cin.hasNext()) {
			String str = cin.next();
			BigInteger oct = new BigInteger(str.substring(2), 8);
                        int n=str.length()-2;
                        BigInteger mul = new BigInteger("5").pow(3*n);
                        BigInteger oit = oct.multiply(mul);
                        BigDecimal dec = new BigDecimal(oit,3*n);
                        System.out.println(str + " [8] = " + dec + " [10]");
		}
	}
}
