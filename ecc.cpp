#include<iostream>
#include<math.h>
using namespace std;

long long int power(long long int a, long long int b, long long int P)
{
	if (b == 1)
		return a;

	else
		return (((long long int)pow(a, b)) % P);
}

int main()
{
	int P, G, x, a, y, b, ka, kb;
	cout<<"Done by Maitreyee\n\n";
		cout<<"Enter any 2 prime numbers: \n";
		cin>>P>>G;
		cout<<"Enter private key for Sender (a) : ";
		cin>>a;
		cout<<"Enter private key for Reciever (b) : ";
		cin>>b;

	x = power(G, a, P);
	y = power(G, b, P);
	ka = power(y, a, P);
	kb = power(x, b, P);

	cout<<"Secret key for the Sender is : "<<ka;
	cout<<"\nSecret Key for the Reciever is : "<<kb;

	return 0;
}
