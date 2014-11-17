
import java.math.*;
import java.io.*;
import java.util.*;

public class Main{
public static void main(String argu[]){
Scanner cin=new Scanner(System.in);
int radix;
BigInteger p,m;
while((radix=cin.nextInt()) > 0){
String s;
s = cin.next();
p = new BigInteger(s,radix);
s = cin.next();
m = new BigInteger(s,radix);
System.out.println(p.mod(m).toString(radix));
}//end while
}//end main
}