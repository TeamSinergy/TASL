/****************************************************************************/
/*!
\file   ActionCall.h
\author Joshua Biggs
\par    Email: Joshua.B@Digipen.edu
\par    Developed: Summer 2015
\brief

Contains the declaration for the ActionCall class. An action call simply
calls a function when it is updated. The functions can be static, global, or 
even member functions.

© 2015 Joshua Biggs CC Attribution
*/
/****************************************************************************/
#pragma once
#include "ActionBase.h"
#include <functional>

namespace ActionSystem
{
    class ActionCall : public Internal::ActionBase
    {
    public:
        ActionCall(const std::function<void(void)>& function) : Function(function){};
        //For member functions
        template <typename ClassType>
        ActionCall(void (ClassType::*function)(void), ClassType* thisPointer) : Function(std::bind(function, thisPointer)) {};
        
        void Update(const long double& dt) override;
        
    private:
        const std::function<void()> Function;
    };
}