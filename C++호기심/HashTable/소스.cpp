#include <iostream>
#include <vector>
#include <list>

class HashTable
{
public:
	static int TABLE_SIZE;
	std::vector<std::list<std::pair<std::string, int >>> table;

	HashTable() {
		table.resize(TABLE_SIZE);
	}
	int hash_function(const std::string& str)
	{
		int hash = 0;
		for (char c : str) {
			hash += static_cast<int>(c);
		}
		return hash % HashTable::TABLE_SIZE;
	}

	void insert(const std::string& key,int val)
	{
		int hash = hash_function(key);
		std::list<std::pair<std::string,int>> cell = table[hash];
		for (auto& pair : cell)
		{
			if (pair.first == key)
			{
				pair.second = val;
				return;
			}
		}
		cell.push_back({ key,val });
	}

};
int HashTable::TABLE_SIZE = 10;





int main()
{
		
}