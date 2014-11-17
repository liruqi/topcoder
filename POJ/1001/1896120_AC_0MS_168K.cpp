#include<iostream>
using namespace std;
int Length(int a)
{   

	int k=0;
    while(a/10!=0){k++;a=a/10;}
	return k+1;
}
int main()
{ 
	double a;
	int n;
	while(cin>>a>>n)
	{
		
		long int at[5000],bt[5000];
		int btl;
		int dot=0;
                  double ae=a;
		
        if(Length((int)a)==1){dot=4;a=a*10000;}
		else {dot=3;a=a*1000;}
        
        
		dot=dot*n;
	    
		int k=a;
		long int g=a;
	
		int i=Length(k),j=4999;
        btl=i;
		while(i>0)
		{
			bt[j--]=k%10;
			k=k/10;
			i--;
		}
		if(n==1){ cout<<ae<<endl;continue;}
		else n--;
		while(n-->0)
		{   
               
			k=0;
			j=4999;
			j=j-btl+1;
            while(k<btl){at[k++]=bt[j];bt[j]=0;j++;}
			k--;
			j=4999;
			while(k>=0)
			{
				bt[j-1]=(at[k]*g+bt[j])/10;
				bt[j]=(at[k]*g+bt[j])%10;
				k--;
				j--;
			}
            int m=bt[j];
			while(m>0)
			{   
				bt[j--]=m%10;
				m=m/10;
			}
			btl=4999-j;
		}
        if(j+1>4999-dot)
			{   cout<<".";
				for(int t=0;t<dot+j-4999;t++)
					cout<<0;
				
			}

        int te=4999;
		while(bt[te]==0&&te>4999-dot)te--; 
		int ie=te;
	
		for(int it=j+1;it<=ie;it++)
		{
			
		
			if(it==4999-dot&&ie!=4999-dot)
			{
				cout<<bt[it]<<".";
			}
			else cout<<bt[it];
		

		}
				
		cout<<endl;
	}
	
return 0;
}
