#include "Primes.h"

Primes::Primes(ull N) {
	N = min((ull)Prime.max_size(), N);
	MakePrime(N); 
}
Primes::~Primes(){
	release();
}
void Primes::MakePrime(ull N)//膜改快速线性筛法
{
	release();
	ull m = N;
	--N;
	N /= 2;
	ull sn = (ull)(sqrt(2 * N) / 2);
	vector<bool> p(N, 1);
	for (ull i = 0; i < sn; i++) {
		if (p[i])
		{
			for (ull j = i*(2 * i + 6) + 3; j<N; j += 2 * i + 3)
				p[j] = false;
		}
	}
	set<ull>().swap(Prime);
	isPrime = new bool[m + 1];
	memset(isPrime, 0, sizeof(bool)*(m+1));
	Prime.insert(2);
	isPrime[2] = true;
	for (ull i = 0; i<N; ++i) {
		if (p[i]) {
			Prime.insert(i + i + 3);
			isPrime[i + i + 3] = true;
		}
	}
	vecPrime = new ull[Prime.size()];
	vecPrime[0]=2;
	for (ull i = 0,j=0; i<N; ++i) {
		if (p[i]) {
			vecPrime[++j] = i + i + 3;
		}
	}
	return;
}

void Primes::release(){
	if (isPrime != NULL)
		delete[] isPrime;
	if (vecPrime != NULL)
		delete[] vecPrime;
}
ull Primes::Number()
{
	return Prime.size();
}

ull Primes::at(ull n)
{
	if (n < Number() && n>0)
		return vecPrime[n-1];
	else
		return 0;
}
ull Primes::Number(ull n)
{
	/*auto it = Prime.begin();
	advance(it, n);*/
	return distance(Prime.begin(), Prime.upper_bound(n));;
}
bool Primes::isPrimeNumer(ull num)
{
	set<ull>::iterator it=Prime.find(num);
	if (it == Prime.end())
		return false;
	return true;
}
ull Primes::find(ull num)
{
	set<ull>::iterator it = Prime.find(num);
	if (it == Prime.end())
		return 0;
	return distance(Prime.begin(), Prime.upper_bound(num));
}
vector<pair<ull, ull>> Primes::factor(ull n)
{
	ull temp, i, now;
	vector<pair<ull, ull>> a;
	temp = Number((ull)(sqrt(n)));
	now = n;
	for (i = 0; now > 1 && i < temp; ++i)
		if (now%vecPrime[i] == 0) {
			a.push_back(make_pair(vecPrime[i], 0));
			while (now%vecPrime[i] == 0) {
				++get<1>(*(a.end() - 1));
				now /= vecPrime[i];
			}
		}
	if (now != 1)
		a.push_back(make_pair(now, 1));
	return a;
}
vector<ull> Primes::minfactor(ull n) {
	vector<ull> m(n + 1, 0);
	for (ull i = 2; i <= n; ++i)
	{
		if (isPrimeNumer(i))
			m[i] = i;
		else {
			for (ull j = 0; j < Number(); ++j) {
				if (i%vecPrime[j] == 0) {
					m[i] = vecPrime[j];
					break;
				}
				m[i] = i;
			}
				
		}
	}
	return m;
}