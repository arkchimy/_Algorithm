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
	

	// chk를 통해 메모리를 찾았는지 check함.
	// 0 ~ PoolSize를 찾으면서 공간을 찾음
	// used를 통해 사용 여부를 확인 함.
	// size만큼의 공간을 확보할 때까지 메모리 풀을 탐색.
	// 만약 끝까지 찾지 못한다면 err를 출력하고 예외처리를 알림.

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
			used[i + k] = true; //사용 표시
		return &memoryPool[i];
	}
	
	if(!chk)
		throw std::runtime_error("메모리 빈공간이 충분하지않음");

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
		cerr << "메모리 풀링 할당 되지않음" << e.what() << "\n";
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