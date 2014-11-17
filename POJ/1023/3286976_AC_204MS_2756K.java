/*
 * Main.java
 *
 * Created on April 11, 2008, 4:11 PM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */


import java.io.*;
import java.util.*;
import java.math.BigInteger;

/**
 *
 * @author root
 */
public class Main {
    static Scanner cin;
    static int len;
    /** Creates a new instance of Main */
    public Main() {
        int k;
        k=cin.nextInt();
        String funk=cin.next();
        int []res=new int[k];
        BigInteger []up=new BigInteger[k];
        BigInteger []low=new BigInteger[k];
        BigInteger cu=BigInteger.ZERO, cl=BigInteger.ZERO, n=cin.nextBigInteger();
        int i;
        for(i=k-1;i>=0;i--){
            if(funk.charAt(i)=='p'){
                cu=cu.add(BigInteger.ONE.shiftLeft(k-i-1));
            }
            else {
                cl=cl.add(BigInteger.ONE.shiftLeft(k-i-1).negate());
            }
            //System.out.println(cl+", "+cu);
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
        for(; i<k; i++){
            if(i==k-1){
                if(n.equals(BigInteger.ZERO)) {
                    ok=true;
                    res[i]=0;
                } else if(n.equals(BigInteger.ONE)){
                    ok=(funk.charAt(i)=='p');
                    if(ok) res[i]=1;
                } else if(n.equals(BigInteger.ONE.negate())){
                    ok=(funk.charAt(i)=='n');
                    if(ok) res[i]=1;
                }
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
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        cin=new Scanner(System.in);
	int ks=cin.nextInt();
        while(ks>0){
            ks--;
            new Main();
        }
    }
    
}
