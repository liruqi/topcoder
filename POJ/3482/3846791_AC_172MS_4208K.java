import java.io.*;
import java.util.*;
import java.math.*;

public class Main
{
	static String trim(String num)
	{
		while(num.length()>0 && num.charAt(0)<=0x20)
					num = num.substring(1);
		while(num.length()>0 && num.charAt(num.length()-1)<=0x20)
					num = num.substring(0,num.length()-1);
		return num;
	}
	public static void main(String args[]) throws Exception
	{
		Scanner in = new Scanner(System.in);
		while(in.hasNext())
		{
			String mother = in.nextLine();
			mother = trim(mother);
			if(mother.length() == 0)
				continue;
			int max_radix = mother.length();
			
			while(in.hasNext())
			{
				String num = in.nextLine();
				while(num.length()>0 && num.charAt(0)==' ')
					num = num.substring(1);
				while(num.length()>0 && num.charAt(num.length()-1)==' ')
					num = num.substring(0,num.length()-1);
				num = trim(num);
				if(num.length() == 0)
					break;
				int len = num.length();
				int dat[] = new int[len];
				int radix=0;
				for(int i=0;i<len;i++)
				{
					dat[i] = mother.indexOf(num.charAt(i));
					if(dat[i] > radix)
						radix = dat[i];
				}
				radix ++;
				//System.out.println("min radix = " + radix);
				BigInteger ret = BigInteger.ZERO;
				for(; radix<=max_radix; radix++)
				{
					BigInteger now = BigInteger.ZERO;
					BigInteger mul = BigInteger.ONE;
					for(int i=len-1; i>=0; i--)
					{
						now = now.add(mul.multiply(BigInteger.valueOf(dat[i])));
						mul = mul.multiply(BigInteger.valueOf(radix));
					}
					ret = ret.add(now);
				}
				System.out.println(ret);
			}

			System.out.println("");
			
		}
	}
}
/*

0123456789


0123456789
 90763
1


.1>C
CC.
>.1
1....

 */
