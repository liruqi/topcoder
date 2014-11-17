import java.math.*;
import java.io.*;
import java.util.*;
public class Main{
public static void main(String a[]){
Scanner cin=new Scanner(System.in);int r;BigInteger p,m;String s;
while((r=cin.nextInt())>0){
s = cin.next();
p = new BigInteger(s,r);
s = cin.next();
m = new BigInteger(s,r);
System.out.println(p.mod(m).toString(r));
}
}
}