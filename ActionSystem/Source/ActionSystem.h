/****************************************************************************/
/*!
\file   ActionSystem.h
\author Joshua Biggs
\par    Email: Joshua.B@Digipen.edu
\par    Developed: Summer 2015
\brief

This file is the only thing another file needs to include in order to use 
the Action system. It contains a namespace of inline functions that can be
called to make using the action system simpler.

© 2015 Joshua Biggs CC Attribution
*/
/****************************************************************************/
#pragma once
#include "ActionSequence.h"
#include "ActionGroup.h"
#include "ActionProperty.h"
#include "ActionDelay.h"
#include "ActionCall.h"

namespace ActionSystem
{
    //I decided to use a namespace instead of static member functions because the user
    //can add additional custom helper functions to this namespace if they so wish.
    namespace Action
    {
        //Action::Sequence adds an ActionSequence to the given sequence or group.
        inline ActionSequence& Sequence(ActionSequence& seq)
        {
            ActionSequence* newSequence = new ActionSequence();
            seq.AddAction(newSequence);
            return *newSequence;
        }

        inline ActionSequence& Sequence(ActionGroup& seq)
        {
            ActionSequence* newSequence = new ActionSequence();
            seq.AddAction(newSequence);
            return *newSequence;
        }
        
        inline ActionGroup& Group(ActionSequence& grp)
        {
            ActionGroup* newGroup = new ActionGroup();
            grp.AddAction(newGroup);
            return *newGroup;
        }
        //Action::Group adds an ActionGroup to the given sequence or group.
        inline ActionGroup& Group(ActionGroup& grp)
        {
            ActionGroup* newGroup = new ActionGroup();
            grp.AddAction(newGroup);
            return *newGroup;
        }
        //Action::Group adds an ActionDelay to the given sequence or group.
        inline void Delay(ActionSequence& seq, const long double& duration)
        {
            seq.AddAction(new ActionDelay(duration));
        }

        inline void Delay(ActionGroup& grp, const long double& duration)
        {
            grp.AddAction(new ActionDelay(duration));
        }
        //Action::Group adds an ActionCall to the given sequence or group.
        inline void Call(ActionSequence& seq, const std::function<void(void)>& function)
        {
            seq.AddAction(new ActionCall(function));
        }

        inline void Call(ActionGroup& grp, const std::function<void(void)>& function)
        {
            grp.AddAction(new ActionCall(function));
        }
        //Action::Group adds an ActionProperty to the given sequence or group.
        template <typename ClassType>
        inline void Call(ActionSequence& seq, void (ClassType::*function)(void), ClassType* thisPointer)
        {
            seq.AddAction(new ActionCall(function, thisPointer));
        }
        template <typename ClassType>
        inline void Call(ActionGroup& grp, void (ClassType::*function)(void), ClassType* thisPointer)
        {
            grp.AddAction(new ActionCall(function, thisPointer));
        }
        

        template <typename T>
        inline void Property(ActionSequence& seq, T* startVal, const T& endVal, const long double& duration, const Ease& ease)
        {
            seq.AddAction(new ActionProperty<T>(startVal, endVal, duration, ease));
        }
        template <typename T>
        inline void Property(ActionSequence& seq, T* startVal, const T& endVal, const long double& duration, SampleCurve<T> ease)
        {
            seq.AddAction(new ActionProperty<T>(startVal, endVal, duration, ease));
        }
        template <typename T>
        inline void Property(ActionGroup& grp, T* startVal, const T& endVal, const long double& duration, const Ease& ease)
        {
            grp.AddAction(new ActionProperty<T>(startVal, endVal, duration, ease));
        }
        template <typename T>
        inline void Property(ActionGroup& grp, T* startVal, const T& endVal, const long double& duration, SampleCurve<T> ease)
        {
            grp.AddAction(new ActionProperty<T>(startVal, endVal, duration, ease));
        }
    }//namespace Action
}//namespace ActionSystem