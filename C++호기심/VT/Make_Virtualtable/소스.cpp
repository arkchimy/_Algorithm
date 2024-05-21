#include <iostream>

using namespace std;

class Animal;
typedef void (*funcPtr)();

enum class Type
{
	ANIMAL =0, //Animal
	DOG //Dog
};
struct VTable
{
	funcPtr sound;
	Type type;
};

void AnimalSound()
{
	cout << "Animal Sound \n";
};

class Animal
{

public:
	Animal()
		:vtable({ AnimalSound ,Type(0)}) {};
	VTable vtable;

	void Sound();

	static Type ClassType;
};
Type Animal::ClassType = Type(0);

void Animal::Sound()
{
	vtable.sound();
}
void DogSound()
{
	cout << "Dog Sound\n";
}
class Dog : public Animal
{
public:
	
	Dog()
	{
		vtable = { DogSound ,Type(1) };
	};
	void Print()
	{
		cout << "Dog Print\n";
	}
	static Type ClassType;
};

Type Dog::ClassType = Type(1);

template <typename T, typename A>
T* dynamic_cast_custom(A* arg)
{
	return nullptr;
}
template<>
Dog* dynamic_cast_custom(Animal* arg)
{
	if (Dog::ClassType == arg->vtable.type)
		return static_cast<Dog*>(arg);
	return nullptr;
}
int main()
{
	Dog* dog = new Dog();
	dog->Sound();
	Animal* animal = new Animal();
	animal->Sound();

	animal = dog;

	dog = dynamic_cast_custom<Dog>(animal);
	dog->Print();

}