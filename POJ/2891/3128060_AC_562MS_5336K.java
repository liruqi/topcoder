import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
   public static void main(String[] args) {
       Scanner ip=new Scanner (System.in);
       while(ip.hasNext()){
           int N=ip.nextInt();
           int i;
           BigInteger []m=new BigInteger[N];
           BigInteger []r=new BigInteger[N];
           for(i=0;i<N;i++){
               m[i]=ip.nextBigInteger();
               r[i]=ip.nextBigInteger();
           }
           BigInteger mr=m[0];
           BigInteger rr=r[0];
           BigInteger m3,m4,m5,r3,r4,a1,a2;
           for(i=1;i<N;i++){
               BigInteger cd=m[i].gcd(mr);
               if(rr.mod(cd).equals( r[i].mod(cd)) == false){
                   //System.out.println("-1");
                   rr=BigInteger.ONE.negate();
                   break;
               }
               m3=mr.divide(cd);
               m4=m[i].divide(cd);
               r3=rr.divide(cd);
               r4=r[i].divide(cd);
               m5=m3.multiply(m4);
               a1=r3.multiply(m4).multiply(m4.modInverse(m3));
               a2=r4.multiply(m3).multiply(m3.modInverse(m4));
               rr=a1.add(a2).mod(m5);
               rr=rr.multiply(cd).add(r[i].mod(cd));
               mr=m5.multiply(cd);
               rr=rr.mod(mr);
           }
           System.out.println(rr);
        }
    }
};
