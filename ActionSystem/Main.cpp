/****************************************************************************/
/*!
\file   Main.cpp
\author Joshua Biggs
\par    email: Joshua.B@Digipen.edu
\par    Course: GAM 255
\brief

Main.cpp : The driver for the ActionSystem application.
The user can also specify their own custom easing function if they so wish.

A custom class must have the binary operators + and - with it's own type
overloaded as well as * and / overloaded to take in a long double in order
to be properly interpolated with a high level of precision. The operators
MUST be const correct.
*/
/****************************************************************************/
#include <iostream>
#include <iomanip>
#include "Source/ActionSystem.h"

//Custom class Integer2
class Integer2
{
public:
    Integer2(int x = 0, int y = 0) : X(x), Y(y) {};
    int X;
    int Y;

    Integer2 operator+(const Integer2& rhs) const
    {
        return (Integer2(X + rhs.X, Y + rhs.Y));
    }
    Integer2 operator-(const Integer2& rhs) const
    {
        return (Integer2(X - rhs.X, Y - rhs.Y));
    }
    Integer2 operator*(const long double& rhs) const
    {
        return (Integer2(static_cast<int>(X * rhs), static_cast<int>(Y * rhs)));
    }
    Integer2 operator/(const long double& rhs) const
    {
        return Integer2(static_cast<int>(X / rhs), static_cast<int>(Y / rhs));
    }
};

//Custom class Real2
class Real2
{
public:
    Real2(float x = 0, float y = 0) : X(x), Y(y) {};
    float X;
    float Y;

    Real2 operator+(const Real2& rhs) const
    {
        return (Real2(X + rhs.X, Y + rhs.Y));
    }
    Real2 operator-(const Real2& rhs) const
    {
        return (Real2(X - rhs.X, Y - rhs.Y));
    }
    Real2 operator*(const long double& rhs) const
    {
        return (Real2(static_cast<float>(X * rhs), static_cast<float>(Y * rhs)));
    }
    Real2 operator/(const long double& rhs) const
    {
        return Real2(static_cast<float>(X / rhs), static_cast<float>(Y / rhs));
    }

    //Member function example for Action::Call
    void Print()
    {
        std::cout << '(' << X << ", " << Y << ')' << std::endl;
    }
};

//Non-Member function example for Action::Call
void HelloWorld()
{
    std::cout << "Hello World" << std::endl;
}

int main()
{
    const double Dt = 1.0f / 60.0f;
    double currentTime = 0;
    double endTime = 2;

    double startValue = 0;
    double currentValue = startValue;
    double endValue = 250;
    
    std::cout.setf(std::ios::fixed, std::ios::floatfield);
    //std::cout.precision(7);
    
    
    
    
    Real2 startInt2 = Real2(0, 20);
    Real2 endInt2 = Real2(100, 50);

    //Integer2 diff = startInt2 - endInt2;
    /*do
    {
        currentValue = ActionSystem::Math::QuinticInOut(currentTime, startValue, endValue, endTime);
        
        currentTime += Dt;
        if (currentTime > endTime)
        {
            currentValue = endValue;
        }
        
        std::cout << currentValue;
        int i = static_cast<int>(currentValue);
        while (i > 0)
        {
            std::cout << ' ';
            --i;
        }

        std::cout << "@" << std::endl;
    } while (currentTime <= endTime);*/
    ActionSystem::ActionGroup grp;

    ActionSystem::ActionSequence& seq = ActionSystem::Action::Sequence(grp);
    ActionSystem::Action::Property(seq, &startInt2, endInt2, endTime, ActionSystem::Ease::QuadInOut);
    ActionSystem::Action::Delay(seq, 0.5);
    ActionSystem::Action::Call(seq, &Real2::Print, &startInt2);
    ActionSystem::Action::Property(seq, &startInt2, Real2(0, 20), endTime, ActionSystem::Ease::QuadInOut);
    //seq.Looping() = true;

    while (!grp.IsCompleted())
    {
        grp.Update(Dt);
        std::cout.width(11);
        std::cout << startInt2.X << ", " << startInt2.Y << " |" << std::right;
        int i = static_cast<int>(startInt2.X);
        int j = static_cast<int>(startInt2.Y);
        int& o = j;
        int& k = i;
        int larger = i;
        if (i < j)
        {
            larger = j;
        }
        
        for (int l = 0; l <= larger; ++l)
        {
            bool skip = false;
            if (l == o)
            {
                skip = true;
                std::cout << "#";
            }
            if (l == k && !skip)
            {
                skip = true;
                std::cout << "@";
            }
            if (!skip)
            {
                std::cout << ' ';
            }
        }
        std::cout << std::endl;
        
    }
    
    return 0;
}

