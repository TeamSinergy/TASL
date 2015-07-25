/****************************************************************************/
/*!
\file   ActionDelay.h
\author Joshua Biggs
\par    Email: Joshua.B@Digipen.edu
\par    Developed: Summer 2015
\brief

The ActionDelay class simply waits for the specified amount of time. Mainly 
useful in action sequences.

© 2015 Joshua Biggs CC Attribution
*/
/****************************************************************************/
#pragma once
#include "ActionBase.h"
#include <deque>

namespace ActionSystem
{
    class ActionDelay : public Internal::ActionBase
    {
    public:
        ActionDelay(const long double& duration = 0) : EndTime(duration){};


        void Update(const long double& dt) override;

        const long double& Duration() const { return EndTime; }
        //The user can modify the end time on the fly if they so wish.
        long double& Duration() { return EndTime; }

        const long double& TimeElapsed() const { return CurrentTime; }

        void Restart() override { ActionBase::Restart(); CurrentTime = 0; };
        void Restart(const long double& duration) { EndTime = duration; Restart(); }

    private:
        long double CurrentTime = 0;
        long double EndTime;
    };
}