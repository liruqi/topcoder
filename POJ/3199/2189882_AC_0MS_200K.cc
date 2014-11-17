#include <iostream>
#include <cstring>
using namespace std;

typedef long long llong;
const int Base = 1000000000;
const int Capacity = 2000;
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
//poj 3199

int main()
{
	int N, D;
	
	while(cin>>N>>D && N) {
        BigInt A=1;
        while(D--){
            A=A*N;
        }
        cout<<A<<endl;
	}
    return 0;
}
