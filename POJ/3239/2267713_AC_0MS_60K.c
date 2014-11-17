/*
一、当n mod 6 != 2 或 n mod 6 != 3时，有一个解为：

2,4,6,8,...,n,1,3,5,7,...,n-1       (n为偶数)

2,4,6,8,...,n-1,1,3,5,7,...,n       (n为奇数)

(上面序列第i个数为ai，表示在第i行ai列放一个皇后；... 省略的序列中，相邻两数以2递增。下同)

二、当n mod 6 == 2 或 n mod 6 == 3时，

(当n为偶数,k=n/2；当n为奇数,k=(n-1)/2)

k,k+2,k+4,...,n,2,4,...,k-2,k+3,k+5,...,n-1,1,3,5,...,k+1         (k为偶数,n为偶数)

k,k+2,k+4,...,n-1,2,4,...,k-2,k+3,k+5,...,n-2,1,3,5,...,k+1,n       (k为偶数,n为奇数)

k,k+2,k+4,...,n-1,1,3,5,...,k-2,k+3,...,n,2,4,...,k+1               (k为奇数,n为偶数)

k,k+2,k+4,...,n-2,1,3,5,...,k-2,k+3,...,n-1,2,4,...,k+1,n           (k为奇数,n为奇数)

程序清单：
*/

int main()

{

       int i,n;

       while (scanf("%d",&n),n)

       {

              if (n%6!=2&&n%6!=3)

              {

                     for (i=2;i<=n;i+=2)

                            printf("%d ",i);

                     for (i=1;i<n-1;i+=2)

                            printf("%d ",i);

                     printf("%d\n",i);

              }

              else

                     if ((n/2)&1)

                     {

                            for (i=n/2;i<n;i+=2)

                                   printf("%d ",i);

                            for (i=1;i<(n/2)-1;i+=2)

                                   printf("%d ",i);

                            for (i=n/2+3;i<=n;i+=2)

                                   printf("%d ",i);

                            for (i=2;i<n/2;i+=2)

                                   printf("%d ",i);

                            printf("%d\n",i);

                     }

                     else

                     {

                            for (i=n/2;i<=n;i+=2)

                                   printf("%d ",i);

                            for (i=2;i<(n/2)-1;i+=2)

                                   printf("%d ",i);

                            for (i=n/2+3;i<n;i+=2)

                                   printf("%d ",i);

                            for (i=1;i<n/2;i+=2)

                                   printf("%d ",i);

                            printf("%d\n",i);

                     }

       }

       return 0;

}

