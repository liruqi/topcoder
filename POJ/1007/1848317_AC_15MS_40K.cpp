#include <stdio.h>

#include <iostream.h>

#include <stdlib.h>

#define M 5000

char dna[100][51];

int inv[100],r,c,i,j,k,n;

int t[50];

void main(void)

{

	/*

	FILE *fp=fopen("dat.txt","r");

	fscanf(fp,"%d %d",&c,&r);

	for(i=0;i<r;i++)

		fscanf(fp,"%s",dna[i]);

	*/

	cin>>c>>r;



	for(i=0;i<r;i++)

		cin>>dna[i];

	for(i=0;i<r;i++)

	{	

		for(j=0;j<c-1;j++)

			for(t[j]=0,k=j+1;k<c;k++)

			{

				if(dna[i][j] > dna[i][k])

					t[j]++;

			}

		for(inv[i]=0,k=0;k<c-1;k++)

			inv[i]+=t[k];

	}

	for(i=0;i<r;i++)

	{

		k=inv[0];

		n=0;

		for(j=1;j<r;j++)

			if(k>inv[j])

			{

				k=inv[j];

				n=j;

			}

		inv[n]=M;

		cout<<dna[n]<<endl;

	}

}

