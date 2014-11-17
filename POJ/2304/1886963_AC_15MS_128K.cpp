      #include <iostream>
      using namespace std;
      int main()
      {
          int p, a, b, c;
          while(1)
          {
              cin>>p>>a>>b>>c;
              if(p+a+b+c==0)
                  break;
              int sum=120;
              sum+=(p>=a)?(p-a):(p+40-a);  
              sum+=(a>=b)?(40-(a-b)):(b-a);// c-close to the 2nd number
              sum+=(b>=c)?(b-c):(b+40-c);  //closewise to the 3rd number
              sum*=9;
              cout<<sum<<endl;
          }
          return 0;
      }