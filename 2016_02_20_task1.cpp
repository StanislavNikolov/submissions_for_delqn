#include <iostream>
#include <vector>
#include <cmath>

std::vector<std::pair<int, int>> polygons[102400];

double surface(unsigned idx)
{
	double s = 0;

	while(polygons[idx].size() >= 3)
	{
		int x1 = polygons[idx][0].first;
		int y1 = polygons[idx][0].second;
		int x2 = polygons[idx][1].first;
		int y2 = polygons[idx][1].second;
		int x3 = polygons[idx][2].first;
		int y3 = polygons[idx][2].second;
		s += abs(0.5*((x1-x2)*(y1+y2)+(x2-x3)*(y2+y3)+(x3-x1)*(y3+y1)));
		auto it = polygons[idx].begin();
		it ++;
		polygons[idx].erase(it);
	}

	return s;
}

int main()
{
	unsigned n;
	double result = 0;
	std::cin >> n;
	for(unsigned i = 0;i < n;++ i)
	{
		unsigned m;
		std::cin >> m;
		for(unsigned j = 0;j < m;++ j)
		{
			int x, y;
			std::cin >> x >> y;
			polygons[i].push_back({x, y});
		}
		result += surface(i);
	}
	std::cout << result << std::endl;
	return 0;
}
