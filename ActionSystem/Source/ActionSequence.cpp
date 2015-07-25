/****************************************************************************/
/*!
\file   ActionSequence.cpp
\author Joshua Biggs
\par    Email: Joshua.B@Digipen.edu
\par    Developed: Summer 2015
\brief

The ActionSequence contains a list of other actions (Properties, Groups, Calls,
Sequences, etc.) that are put into a queue and run one after the other.

© 2015 Joshua Biggs CC Attribution
*/
/****************************************************************************/
#include "ActionSequence.h"

namespace ActionSystem
{

    void ActionSequence::Update(const long double& dt)
    {
        if (IsPaused() || IsCompleted())
        {
            return;
        }
        if (IsEmpty())
        {
            Completed = true;
            return;
        }

        if ((*CurrentAction)->IsCompleted())
        {
            if (!Looping())
            {
                delete (*CurrentAction);
                ActionQueue.erase(CurrentAction);
                CurrentAction = ActionQueue.begin();
                if (ActionQueue.empty())
                {
                    Completed = true;
                    return;
                }
            }
            else
            {
                ++CurrentAction;
                if (CurrentAction == ActionQueue.end())
                {
                    CurrentAction = ActionQueue.begin();
                }
            }
            //Restart the action to ensure that the starting value is 
            //equivelent to the last action's ending value.
            (*CurrentAction)->Restart();
        }

        (*CurrentAction)->Update(dt);
    }

    void ActionSequence::AddAction(ActionBase* action)
    {
        ActionQueue.push_back(action);
        CurrentAction = ActionQueue.begin();
    }

    void ActionSequence::Restart()
    {
        ActionBase::Restart();
        CurrentAction = ActionQueue.begin();
        while (CurrentAction != ActionQueue.end())
        {
            (*CurrentAction)->Restart();
            ++CurrentAction;
        }
        CurrentAction = ActionQueue.begin();
    }

    void ActionSequence::Clear()
    { 
        while (!ActionQueue.empty())
        {
            delete ActionQueue.back();
            ActionQueue.pop_back();
        }
        Restart();
    }

    ActionSequence::~ActionSequence() 
    {
        Clear();
    }
}