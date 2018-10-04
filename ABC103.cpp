#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <math.h>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> queries(m);
	for(int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		queries[i] = {a - 1, b - 1};
	}

	sort(queries.begin(), queries.end());

	pair<int, int> segment = queries[0];
	int count = 0;
	for(int i = 1; i < m; i++)
	{
		if(queries[i].first < segment.second)
		{
			segment.first = queries[i].first;
			if(queries[i].second < segment.second)
			{
				segment.second = queries[i].second;
			}
		}else{
			count++;
			segment = queries[i];
		}
	}
	count++;
	cout << count << endl;
	return 0;
}
