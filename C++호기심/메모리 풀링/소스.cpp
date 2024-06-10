#include <iostream>
#include <list>
#include <stdexcept>

#define PoolSize 400

using namespace std;

char memoryPool[PoolSize];
bool used[PoolSize];

void* Allocation(size_t size)
{
	
	bool chk = false;
	

	// chk�� ���� �޸𸮸� ã�Ҵ��� check��.
	// 0 ~ PoolSize�� ã���鼭 ������ ã��
	// used�� ���� ��� ���θ� Ȯ�� ��.
	// size��ŭ�� ������ Ȯ���� ������ �޸� Ǯ�� Ž��.
	// ���� ������ ã�� ���Ѵٸ� err�� ����ϰ� ����ó���� �˸�.

	for(int i =0; i < PoolSize; i++)
	{
		for (int k = i; k < i + size; k++)
		{
			if (used[k])
			{
				chk = false;
				break;
			}
			else
				chk = true;
		}
		if (!chk) 
			continue;
		for (int k = 0; k < size; k++)
			used[i + k] = true; //��� ǥ��
		return &memoryPool[i];
	}
	
	if(!chk)
		throw std::runtime_error("�޸� ������� �����������");

	return nullptr;
}

void Deallocation(void* ptr,size_t size)
{
	int idx = (char*)ptr - memoryPool;
	for (int i = idx; i < idx + size; i++)
		used[i] = false;
}
void InitMemoryfull()
{
	std::fill(std::begin(used), std::end(used), false);
}

int main()
{
	InitMemoryfull();

	list<int*> nums;

	try
	{
		for (int i = 0; i < 100; i++)
		{
			int* temp = static_cast<int*>(Allocation(sizeof(int)));
			*temp = i;
			nums.emplace_back(temp);
			
		}
	}
	catch (const std::runtime_error& e)
	{
		cerr << "�޸� Ǯ�� �Ҵ� ��������" << e.what() << "\n";
	}

	auto iter = nums.begin();
	iter++;
	Deallocation(*iter, sizeof(int));
	nums.erase(iter);

	int* temp = static_cast<int*>(Allocation(sizeof(int)));
	*temp = 10202;
	nums.emplace_back(temp);

	for(int* num : nums)
		cout <<"Address : " << num  << "value : " << *num << "\n";
};