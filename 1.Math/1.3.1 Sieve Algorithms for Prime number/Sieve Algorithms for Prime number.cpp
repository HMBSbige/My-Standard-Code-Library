#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <ctime>
#define ull unsigned long long//<=18446744073709551615
using namespace std;
vector<bool> isPrime;
vector<ull> Primes;
void _MakePrime(ull N)//һ������ɸ��
{
	isPrime = vector<bool>(N+1,true);
	vector<ull>().swap(Primes);
	isPrime[0] = false;
	isPrime[1] = false;
	for (ull i = 2; i<=N; ++i)
		if (isPrime[i]) {
			Primes.push_back(i);
			for (ull k = i*i; k<=N; k += i)
				isPrime[k] = false;
		}
}
void __MakePrime(ull N)//��������ɸ��
{
	++N;
	isPrime = vector<bool>(N + 1, true);
	vector<ull>().swap(Primes);
	isPrime[0] = false;
	isPrime[1] = false;

	for (ull i = 2; i <N; ++i)
	{
		if (isPrime[i])
			Primes.push_back(i);
		for (ull j = 0; j < Primes.size() && i * Primes[j] < N; j++)
		{
			isPrime[i * Primes[j]] = 0;
			if (!(i % Primes[j]))
				break;
		}
	}
}
void ___MakePrime(ull N)//ħ�Ŀ�������ɸ��
{
	--N;
	ull half = N / 2;
	ull sn = (ull)sqrt(N);
	vector<bool> p(half,1);// ��ʼ��ȫ������Ϊ������p[0]��Ӧ3����p[i]��Ӧ2*i+3   
	for (ull i = 0; i < sn; i++) {
		if (p[i])//��� 2*i+3 ������  
		{
			for (ull k = i + i + 3, j = k*i + k + i; j < half; j += k)
				// ɸ������� p[i]����Ӧ������ƽ�� k^2                                          
				// k^2�� p �е�λ���� k*i+k+i  
				//    �±� i         k*i+k+i  
				//��Ӧ��ֵ k=i+i+3   k^2           
				p[j] = false;
		}
	}
	//����������� p �����У�p[i]=true���� i+i+3 ��������  
	vector<ull>(1,2).swap(Primes);
	isPrime = vector<bool>(N + 1, true);
	for (ull i = 0;i<half;++i) {
		if (p[i]) {
			Primes.push_back(i + i + 3);
		}
	}
}
void ____MakePrime(ull N)//Ĥ�Ŀ�������ɸ��
{
	--N;
	N/= 2;
	ull sn = (ull)(sqrt(2*N)/2);
	vector<bool> p(N, 1);  
	for (ull i = 0; i < sn; i++) {
		if (p[i]) 
		{
			for (ull j=i*(2*i+6)+3;j<N;j+=2*i+3)          
				p[j] = false;
		}
	}

	vector<ull>(1, 2).swap(Primes);
	isPrime = vector<bool>(N + 1, true);
	for (ull i = 0; i<N; ++i) {
		if (p[i]) {
			Primes.push_back(i + i + 3);
		}
	}
}
void output() {
	/*for (ull &x : Primes)
		cout << x << " ";
	cout << endl;*/
	cout<< "������" << Primes.size() << endl;
}
int main()
{
	ull N = 5000000;
	clock_t start, finish;
	double totaltime;
	
	start = clock();
	_MakePrime(N);
	//output();
	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << totaltime << "�룡" << endl;

	start = clock();
	__MakePrime(N);
	//output();
	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << totaltime << "�룡" << endl;

	start = clock();
	___MakePrime(N);
	//output();
	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << totaltime << "�룡" << endl;

	start = clock();
	____MakePrime(N);
	//output();
	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << totaltime << "�룡" << endl;

	system("pause");
	return 0;
}