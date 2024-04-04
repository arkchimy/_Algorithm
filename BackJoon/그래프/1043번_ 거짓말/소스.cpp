#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

vector<int> nodes;

vector<pair<vector<int>, bool>> graph;

int GetParent(int n)
{
	if (nodes[n] == n)
		return n;
	return nodes[n] = GetParent(nodes[n]);
}

int main()
{
	int n, m;
	cin >> n >> m;
	nodes.resize(n + 1);
	for(int i = 1; i <= n; i++)
	{
		nodes[i] = i; // 자기 자신으로 초기화
	}
	
	int fact , idx;
	cin >> fact;

	vector<int> facts;
	facts.reserve(fact);
	while (fact--)
	{
		int temp;
		cin >> temp;
		facts.emplace_back(temp);
	}

	if(facts.size() != 0 )
		fact = *min_element(facts.begin(), facts.end()); //해당 노드와 연결확인
	for (int i = 0; i < facts.size(); i++)
		nodes[facts[i]] = fact;

	int result = 0;

	graph.reserve(m);
	while (m--)
	{
		cin >> n;
		bool lier = false;
		vector<int> member;
		member.reserve(n);
		while (n--)
		{
			int temp;
			cin >> temp;
			if (GetParent(temp) == fact)
			{
				lier = true;
			}
			member.emplace_back(temp);
		}
		
		if (lier)
		{
			graph.emplace_back(member, true);
			stack<vector<int>> s;
			s.push(member);
			while (!s.empty())
			{
				vector<int> top = s.top();
				s.pop();
				for (int idx : top)
				{
					for (int i = 0; i < graph.size(); i++)
					{
						if (graph[i].second == false)
						{
							if (find(graph[i].first.begin(), graph[i].first.end(), idx) != graph[i].first.end())
							{
								graph[i].second = true;
								s.push(graph[i].first);
							}
						}
					}
					nodes[idx] = fact;
				}
			}
		}
		else
		{
			graph.emplace_back(member, false);
		}
	}
	for (int i = 0; i < graph.size(); i++)
	{
		if (!graph[i].second)
			result++;
	}
	
	cout << result;
}