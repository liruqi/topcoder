import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class Main {
    static Scanner cin;
    static int len;
    public Main() {
        int k;
        k=cin.nextInt();
        String funk=cin.next();
        int []res=new int[k];
        BigInteger []up=new BigInteger[k+1];
        BigInteger []low=new BigInteger[k+1];
        BigInteger cu=BigInteger.ZERO, cl=BigInteger.ZERO, n=cin.nextBigInteger();
        int i;
        up[k]=BigInteger.ZERO;
        low[k]=BigInteger.ZERO;
        for(i=k-1;i>=0;i--){
            if(funk.charAt(i)=='p'){
                cu=cu.add(BigInteger.ONE.shiftLeft(k-i-1));
            }
            else {
                cl=cl.add(BigInteger.ONE.shiftLeft(k-i-1).negate());
            }
            up[i]=cu;
            low[i]=cl;
            if(cu.compareTo(n)>=0 && cl.compareTo(n)<=0)
                break;
        }
        if(i<0) {
            System.out.println("Impossible");
            return;
        }
        boolean ok=false;
        for(; i<=k; i++){
            if(i>=k){
                ok=n.equals(BigInteger.ZERO);
                continue;
            }
            if(up[i+1].compareTo(n)>=0 && low[i+1].compareTo(n)<=0){
                res[i]=0;
            } else {
                res[i]=1;
                if(funk.charAt(i)=='n')
                    n=n.add(BigInteger.ONE.shiftLeft(k-i-1));
                else 
                    n=n.add(BigInteger.ONE.shiftLeft(k-i-1).negate());
            }
        }
        if(!ok) {
            System.out.println("Impossible");
            return;
        }
        String ret="";
        for(i=0;i<k;i++) ret=ret+res[i];
        System.out.println(ret);
    }
    
    public static void main(String[] args) {
        cin=new Scanner(System.in);
	int ks=cin.nextInt();
        while(ks>0){
            ks--;
            new Main();
        }
    }
    
}
