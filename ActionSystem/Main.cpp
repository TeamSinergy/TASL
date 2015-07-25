/****************************************************************************/
/*!
\file   Main.cpp
\author Joshua Biggs
\par    email: Joshua.B@Digipen.edu
\par    Developed: Summer 2015
\brief

Main.cpp : The driver for the ActionSystem application.

To get started, simply include 'ActionSystem.h'.

The ActionSystem Library contains the following features:

ActionBase:
    This class is what all actions are derived from. The user can make
    their own classes that derive from this one.

ActionProperty:
    This class interpolates a value passed in by pointer from its original
    value to an ending value over a specified duration of time.

ActionSequence:
    This class contains a queue of actions that happen one after the other.
    The next action does not happen until the previous one in the queue has
    been completed.

ActionGroup:
    This class contains a group of actions that are all updated simultaneously.

Note: An ActionGroup/Sequence CAN have other ActionGroups/Sequences inside of it.

ActionDelay:
    This class delays a sequence for a specified amount of time in 'seconds'.

ActionCall:
    This class calls a specified function when it is reached.

SampleCurve:
    This class is a wrapper around a std::function and can be passed into an 
    ActionProperty to affect how the property interpolates the value.
    Eases are one example of this in action.

Supported Eases:
    Linear, Quadratic, Cubic, Quartic, Quintic, Exponential, Circular, and Sinusoidal.

ActionSystem.h:
    This header file contains the namespace 'ActionSystem::Action' which holds
    several inline functions used to interface with the action system.

Helper Functions:
    Action::Sequence:
    -Adds and returns an ActionSequence which is added to the input ActionGroup or ActionSequence.

    Action::Group:
    -Adds and returns an ActionGroup which is added to the input ActionGroup or ActionSequence.

    Action::Property:
    -Adds an ActionProperty which is added to the input ActionGroup or ActionSequence.

    Action::Delay:
    -Adds an ActionDelay which is added to the input ActionGroup or ActionSequence.

    Action::Call:
    -Adds an ActionCall which is added to the input ActionGroup or ActionSequence.

Custom Classes:
    A custom class must have the binary operators + and - with it's own type
    overloaded as well as * and / overloaded to take in a long double in order
    to be properly interpolated with a high level of precision. The operators
    MUST be const correct.

Example Operators:
    Type operator+(const Type& rhs) const
    Type operator-(const Type& rhs) const
    Type operator*(const long double& rhs) const
    Type operator/(const long double& rhs) const

Output:
    This program outputs to a file called output.txt located in the ActionSystem 
    folder. The output shows the values being interpolated in a visual format.
    For best results, open the text file in a web browser and aoom all the way out.


© 2015 Joshua Biggs CC Attribution
You are free to:
    Share — Copy and redistribute the material in any medium or format.
    Adapt — Remix, transform, and build upon the material
            for any purpose, even commercially.

Under the following terms:
    Attribution — You must give appropriate credit, provide a link to the license, 
                  and indicate if changes were made. You may do so in any reasonable 
                  manner, but not in any way that suggests the licensor endorses you 
                  or your use.
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
    /*A hard-coded delta-time value. In an engine this would be replaced
      by an actual Dt value in the engine's logic update loop.*/
    const double Dt = 1.0f / 60.0f;
    
    /*How long the action is going to take.*/
    double duration = 2;
    /*The starting value of the action.*/
    Real2 startReal2 = Real2(0, 20);
    /*The value being modified.*/
    Real2 modifiedReal2 = startReal2;
    /*The final value after the action is completed.*/
    Real2 endReal2 = Real2(100, 50);

    /*Creating an group of Actions/ActionSequences.*/
    ActionSystem::ActionGroup grp;
    /*Adding a new ActionSequence to the group.*/
    ActionSystem::ActionSequence& seq = ActionSystem::Action::Sequence(grp);
    /*Add an ActionProperty to the new sequence which interpolates the modifiedReal2 from its original
      value to the ending value over the specified duration.*/
    ActionSystem::Action::Property(seq, &modifiedReal2, endReal2, duration, ActionSystem::Ease::QuadInOut);
    /*Delay the sequence for 0.5 'seconds'. (Would be actual seconds in a game engine)*/
    //ActionSystem::Action::Delay(seq, 0.5);
    /*Call the member function 'Print' on the value startReal2.*/
    //ActionSystem::Action::Call(seq, &Real2::Print, &startReal2);
    /*Call the global 'HelloWorld' function.*/
    //ActionSystem::Action::Call(seq, &HelloWorld);
    /*Add an ActionProperty to the new sequence which interpolates the modifiedReal2 from its final
      value to the original value over the specified duration.*/
    ActionSystem::Action::Property(seq, &modifiedReal2, startReal2, duration, ActionSystem::Ease::QuadInOut);
    /*If this was turned on, the executable would run forever.*/
    //grp.Looping() = true;

    /*For output alignment*/
    std::cout.setf(std::ios::fixed, std::ios::floatfield);
    /*Below is simply some formatting code to output the current values being interpolated as well as
      a character for each interpolated value indented a number of spaces equal to the current value.
      
      Open 'output.txt' in a web browser and scroll all the way out for best viewing results.*/
    while (!grp.IsCompleted())
    {
        grp.Update(Dt);
        std::cout.width(11);
        std::cout << modifiedReal2.X << ", " << modifiedReal2.Y << " |" << std::right;
        int i = static_cast<int>(modifiedReal2.X);
        int j = static_cast<int>(modifiedReal2.Y);
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

