#include <iostream>

#include <cstring>

using namespace std;



typedef long long llong;

const int Base = 1000000000;

const int Capacity = 200;

const int Radix = 10;



struct BigInt {

	int data[Capacity];

	int len;

	BigInt() : len(0) {}

	BigInt(int v) : len(0) { do{ data[len++] = v % Base; v /= Base; }while(v > 0); }

	BigInt(const BigInt& v) : len(v.len) { memcpy(data, v.data, len * sizeof *data); }

	BigInt& operator = (const BigInt& v) {

		if (this != &v) len = v.len, memcpy(data, v.data, len * sizeof *data);

		return *this;

	}

	int& operator [] (int index) { return data[index]; }

	int operator [] (int index) const { return data[index]; }

};



int compare (const BigInt& a, const BigInt& b) {

	if (a.len != b.len) return (a.len > b.len ? 1 : -1);

	int i;	for (i = a.len - 1; i >= 0 && a[i] == b[i]; i--) ;

	return (i < 0 ? 0 : (a[i] > b[i] ? 1 : -1));

}

BigInt operator + (const BigInt& a, const BigInt& b) {

	BigInt r; int i, carry = 0;

	for (i = 0; i < a.len || i < b.len || carry > 0; i++) {

		if (i < a.len) carry += a[i];

		if (i < b.len) carry += b[i];

		r[i] = carry % Base;

		carry /= Base;

	}

	r.len = i;

	return r;

}

BigInt operator - (const BigInt& a, const BigInt& b) {

	if (compare(a, b) < 0) return b-a;

	BigInt r; int i, carry = 0;

	for (i = 0; i < a.len; i++) {

		r[i] = a[i] - carry;

		if (i < b.len) r[i] -= b[i];

		if (r[i] < 0) r[i] += Base, carry = 1;

		else carry = 0;

	}

	r.len = a.len;

	while (r.len > 0 && r[r.len - 1] == 0) r.len--;

	return r;

}

BigInt operator * (const BigInt& a, int b) {

	if (b == 0) return 0;

	BigInt r; int i; llong carry = 0;

	for (i = 0; i < a.len || carry > 0; i++) {

		if (i < a.len) carry += llong(a[i]) * b;

		r[i] = carry % Base;

		carry /= Base;

	}

	r.len = i;

	return r;

}

BigInt operator / (const BigInt& a, int b) {

	BigInt r; int i; llong carry = 0;

	for (i = a.len - 1; i >= 0; i--) {

		carry = carry * Base + a[i];

		r[i] = carry / b;

		carry %= b;

	}

	r.len = a.len;

	while (r.len > 0 && r[r.len - 1] == 0) r.len--;

	return r;

}

llong operator % (const BigInt& a, int b) {

	BigInt r; int i; llong carry = 0;

	for (i = a.len - 1; i >= 0; i--) {

		carry = carry * Base + a[i];

		r[i] = carry / b;

		carry %= b;

	}

	r.len = a.len;

	while (r.len > 0 && r[r.len - 1] == 0) r.len--;

	return carry;

}

BigInt operator * (const BigInt& a, const BigInt& b) {

	BigInt r;

	for (int i = 0; i < a.len; i++) {

		llong carry = 0;

		for (int j = 0; j < b.len || carry > 0; j++) {

			if (i + j < r.len) carry += r[i + j];

			if (j < b.len) carry += llong(a[i]) * b[j];

			if (i + j < r.len) r[i + j] = carry % Base;

			else r[r.len++] = carry % Base;

			carry /= Base;

		}

	}

	return r;

}

BigInt operator / (const BigInt& a, const BigInt& b) {

	BigInt r, carry(0);

	int i, left, right, mid;

	for (i = a.len - 1; i >= 0; i--) {

		carry = carry * Base + a[i];

		left = 0; right = Base - 1;

		while (left < right) {

			mid = (left + right + 1) / 2;

			if (compare(b * mid, carry) <= 0) left = mid;

			else right = mid - 1;

		}

		r[i] = left;

		carry = carry - b * left;

	}

	r.len = a.len;

	while (r.len > 0 && r[r.len - 1] == 0) r.len--;

	return r;

}

BigInt operator % (const BigInt& a, const BigInt& b) {

	BigInt r, carry(0);

	int i, left, right, mid;

	for (i = a.len - 1; i >= 0; i--) {

		carry = carry * Base + a[i];

		left = 0; right = Base - 1;

		while (left < right) {

			mid = (left + right + 1) / 2;

			if (compare(b * mid, carry) <= 0) left = mid;

			else right = mid - 1;

		}

		r[i] = left;

		carry = carry - b * left;

	}

	r.len = a.len;

	while (r.len > 0 && r[r.len - 1] == 0) r.len--;

	return carry;

}

istream& operator >> (istream& is, BigInt& v) {

	char ch;

	for (v = 0; is >> ch; ) {

		v = v * Radix + (ch - '0');

		if ( is.peek() <= ' ') break;

	}

	return is;

}

ostream& operator << (ostream& os, const BigInt& v) {

	if (v.len == 0) return os << 0;

	os << v[v.len - 1];

	for (int i = v.len - 2; i >= 0; i--) for (int j = Base/Radix; j > 0; j /= Radix) 

		os << (v[i]/j)%Radix;

	return os;

}




///////////////////////////////////////

//poj 1737 dp
BigInt C[51][51],A[51],pow2[51];

void init(){
	int i,j;
	pow2[0]=0;

    for(i=1;i<51;i++){
    	pow2[i]=2*pow2[i-1] + 1;
        C[i][0]=1;
        C[i][i]=1;

    }

    for(i=2;i<51;i++){

        for(j=1;j<i;j++)

        C[i][j]=C[i-1][j] + C[i-1][j-1];

    }
    //cout<<"?"<<endl;
    A[1]=A[2]=1;
   	for(i=3;i<51;i++)
   		for(A[i]=0,j=1;j<i;j++){
   			A[0] = A[j]*A[i-j];
   			A[0] = A[0]*pow2[j]*C[i-2][j-1];
			A[i]=A[i]+A[0];
   		}
   	//cout<<"?"<<endl;
}


int main()

{
	int n;

	init();
	while(cin>>n&&n){
		cout<<A[n]<<endl;
	}

}
