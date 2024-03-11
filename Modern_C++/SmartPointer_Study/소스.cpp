#include <iostream>

#include <memory>

using namespace std;

class Weapon
{
public:
    Weapon() = default;
    Weapon(float power):mPower(power)
    {}
    float GetPower() { return mPower; }
    
private:
    float mPower = 1.f;
};

class Player
{
public:
    Player()
    {
        causer = std::make_shared<Weapon>();
        level = std::make_unique<int>();
    }

    std::shared_ptr<Weapon> causer;
    std::unique_ptr<int> level;
};

int main()
{
    Player a;
    {
        Player b = a;
        cout << a.causer << " : " << b.causer << "\n";
        cout << a.causer.use_count();
    }
    cout << a.causer.use_count();

}
//

//class Enemy
//{
//    void TakeDamage(shared_ptr<Weapon> causer)
//    {
//        mHp -= causer->GetPower();
//    }
//
//private:
//    float mHp = 10.f;
//};
//
//
//
//int main()
//{
//    Player a;
//    {
//        Player b = a;
//        cout << a.causer << " : " << b.causer << "\n";
//        cout << a.causer.use_count();
//    }
//    cout << a.causer.use_count();
//    
//}