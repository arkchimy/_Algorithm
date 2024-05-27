#include <iostream>


using namespace std;

class Cat;
class Animal;

typedef void (*funcPtr)();

struct VTable
{
    funcPtr ptr;
    int type_id;
};



class Animal
{
  public:
    Animal() 
    {
        vtable = {Animal::Animal_Sound, 0};
    };
    static void Animal_Sound()
    {
        cout << "Animal sound\n";
    } 
    void Sound()
    {
        vtable.ptr();
    }
  public:
   VTable vtable;
};


class Cat : public Animal
{

  public:
    Cat()
    {
        vtable = {Cat::Cat_Sound, 1};
    }
    static void Cat_Sound()
    {
        cout << "Cat Sound\n";
    }
    void Sound()
    {
        vtable.ptr();
    }
 
};

template <typename T, typename T2> 
T *dynamic_cast_custom(T2 *a)
{
}
template <> 
Cat *dynamic_cast_custom<Cat>(Animal *a)
{
    if (Animal::vtable.type_id == a->vtable.type_id)
        return static_cast<Cat *>(a);
    return nullptr;
}

int main()
{
    Animal *animal = new Cat();
    animal->Sound();

    Cat *cat;
    cat = dynamic_cast_custom<Cat>(animal);

    cat->Sound();
}