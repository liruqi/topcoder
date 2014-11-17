import java.io.*;
import java.util.*;
class Main
{
	public static void main(String args[]) throws Exception
	{
		Scanner cin=new Scanner(System.in);
		long s[] = new long [20000];
		long p1,p2,p3,k;
		s[0]=1;
		while (cin.hasNext())
		{
			int a=0,b=0,c=0,top=1;
			
			p1 = cin.nextLong();
			p2 = cin.nextLong();
			p3 = cin.nextLong();
			k = cin.nextLong();
			
			while (k-- > 0)
			{
				long va=s[a]*p1;
				long vb=s[b]*p2;
				long vc=s[c]*p3;
				if(va<=vb && va<=vc){
					s[top++]=va;
					a++;
					if(va==vb) b++;
					if(va==vc) c++;
				}
				else if(vb <= vc){
					s[top++]=vb;
					b++;
					if(vb==vc) c++;
				}
				else {
					s[top++]=vc;
					c++;
				}//System.out.println(s[top-1]);
			}
			System.out.println(s[top-1]);
		}		
	}
}