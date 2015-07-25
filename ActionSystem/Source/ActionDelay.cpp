/****************************************************************************/
/*!
\file   ActionDelay.cpp
\author Joshua Biggs
\par    Email: Joshua.B@Digipen.edu
\par    Developed: Summer 2015
\brief

The ActionDelay class simply waits for the specified amount of time. Mainly
useful in action sequences.

© 2015 Joshua Biggs CC Attribution
*/
/****************************************************************************/
#include "ActionDelay.h"

namespace ActionSystem
{
    void ActionDelay::Update(const long double& dt)
    {
        if (IsCompleted() || IsPaused())
        {
            return;
        }

        CurrentTime += dt;
        if (CurrentTime >= EndTime)
        {
            Completed = true;
        }
    }
}