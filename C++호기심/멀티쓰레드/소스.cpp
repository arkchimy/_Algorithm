#include <iostream>
#include <mutex>
#include <thread>


struct Student
{
	int score;
	std::mutex mtx;
};
void Add(Student& s)
{
	//std::lock_guard<std::mutex> lock(s.mtx);
	//s.mtx.lock();
	if (s.score >= 30000)
		return;
	for(int i =0; i < 100; i++)
		s.score++;
	
	//s.mtx.unlock();
}
int main()
{
	Student s1;
	s1.score = 0;
	std::thread t1(Add, std::ref(s1));
	std::thread t2(Add, std::ref(s1));
	std::thread t3(Add, std::ref(s1));

	t1.join();
	t2.join();
	t3.join();
	std::cout << s1.score << "\n";
}