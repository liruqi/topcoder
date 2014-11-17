import java.util.*;
import java.math.*;
public class Main{
public static void main(String args[]){
BigInteger a= new Scanner(System.in).nextBigInteger();System.out.println(BigInteger.ONE.shiftLeft(a.bitCount()).subtract(BigInteger.ONE));
}
}
