import java.io.*;
import java.util.*;
import java.lang.*;

public class Main
{
	public static void main(String args[]) throws Exception
	{
        int []A = new int [10001];
        boolean []P = new boolean [10001];
        Arrays.fill(P,true);
        for(int i=2;i*i<P.length;i++)if(P[i])
            for(int j=i*i;j<P.length;j++)
                P[j]=false;
		Scanner cin=new Scanner(System.in);
        for(int i=0;i<10;i++)
		{
			int T=cin.nextInt();
			for(int j=2;j*j<=T;j++)if(T%j==0){
                int cnt=0;
                do{
                    T/=j;
                    cnt++;
                } while(T%j==0);
                A[j]+=cnt;
            } 
            if(T>1) {
                A[T]+=1;
            } 
        }
        int N=1;
        for(int i=2;i<10001;i++) {
            if(A[i]>0){
                N*=(A[i]+1);
            }
        }    
        System.out.println(N%10);
	}
}