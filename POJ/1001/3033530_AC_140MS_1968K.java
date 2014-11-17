import java.util.*;
import java.math.*;
import java.io.*;
public class Main{
	public static void main(String args[]){
		Scanner is=new Scanner(System.in);
		while(is.hasNext()){
			String str;
			str=is.next();
			int end=str.length();
			while(str.charAt(end-1)=='0')end--;
			BigDecimal base = new BigDecimal(str.substring(0,end));
			int pow=is.nextInt();
			String out=base.pow(pow).toPlainString();
			int stt=0;
			if(out.charAt(0)=='0')stt++;
			System.out.println(out.substring(stt));
		}
	}
}
