#include <iostream>
#include <vector>

std::vector<char> memoryPool(120);// 120Byte

void* Allocate(int size)
{
    static size_t nextIndex = 0;

    if (nextIndex + size <= memoryPool.size()) 
    {
        void* allocatedMemory = &memoryPool[nextIndex];
        nextIndex += size; // 24
        return allocatedMemory;
    }
    else 
    {
        std::cerr << "Error: Memory pool out of space\n";
        return nullptr;
    }
}
struct Student
{
    char name[5]; //5
    long long score; // 8
    int age; // 4
};
int main()
{
    int allocationSize = 4;

    Student* s1 = new Student(); // 이게 싫다  단편화 때문에
    Student* s2 = new Student(); // 이게 싫다  단편화 때문에

    std::vector<Student*> vec(5);

    for (int i = 0; i < 5; i++)
    {
        vec[i] = (Student*)Allocate(sizeof(Student));
        vec[i]->age = i;

        if (vec[i] != nullptr)
        {
            //std::cout << "ags : " << vec[i]->age << "\n";
        }
    }
    std::cout << "Sizeof" << sizeof(Student) << '\n';
    std::cout << "Dynamic address: " << int(s1) << "\n";
    std::cout << "Dynamic address: " << int(s2) << "\n";
    for(int i =0; i < 5 ; i++)
        std::cout << "Memory allocated at address: " << int(vec[i]) << " : \n";
    return 0;
}