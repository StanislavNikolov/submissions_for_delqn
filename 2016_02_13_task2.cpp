#include <iostream>
#include <vector>

int n, k;

unsigned long long fact(int n, int m)
{
	if(n == m)
		return m;
	int a = 1;
	for(int i = m;i <= n;++ i)
		a *= i;
	return a;
}

int main()
{
	std::cin >> n >> k;

	int cycle = 1;
	std::vector<char> sym;
	for(int i = 0;i < 26;++ i)
		sym.push_back((char)(i+'A'));

	while(true)
	{
		int first = 0;

		while(k > fact(26-cycle,26-n+1))
		{
			k -= fact(26-cycle,26-n+1);
			first ++;
		}

		std::cout << sym[first];
		auto it = sym.begin();
		for(int i = 0;i < first;++ i)
			it ++;
		sym.erase(it);

		cycle ++;
		if(cycle == n+1)
		{
			std::cout << std::endl;
			return 0;
		}
	}
}
