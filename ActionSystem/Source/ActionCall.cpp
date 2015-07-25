/****************************************************************************/
/*!
\file   ActionCall.cpp
\author Joshua Biggs
\par    Email: Joshua.B@Digipen.edu
\par    Developed: Summer 2015
\brief

Contains the implementation for the ActionCall class. An action call simply
calls a function when it is updated.

© 2015 Joshua Biggs CC Attribution
*/
/****************************************************************************/
#include "ActionCall.h"
namespace ActionSystem
{
    void ActionCall::Update(const long double& dt)
    {
        if (IsCompleted() || IsPaused())
        {
            return;
        }

        Function();

        Completed = true;
    }
}