#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define SIZE 10001

vector<int> vec;
using namespace std;
vector<int> prime;

void sieve()
{
	for (int i = 0; i < SIZE; i++)
	{
		if (vec[i] == 0)
			continue;
		prime.push_back(i);
		for (int k = i * 2; k < SIZE; k += i)
			vec[k] = 0;
		
	}
}

void BFS()
{
	
}
int main()
{
	vec.resize(SIZE, 1);
	sieve();
	int n;
	cin >> n;

	while (n--)
	{
		int start, target;
		cin >> start >> target;
		while (start != target)
		{
			
		}
	}
}