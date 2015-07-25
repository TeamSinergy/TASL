/****************************************************************************/
/*!
\file   ActionGroup.cpp
\author Joshua Biggs
\par    Email: Joshua.B@Digipen.edu
\par    Developed: Summer 2015
\brief

The ActionGroup class stores a group of actions which are all updated at the
same time. When all of the stored actions are complete, the group completes.
Groups can be placed inside of sequences.

© 2015 Joshua Biggs CC Attribution
*/
/****************************************************************************/
#include "ActionGroup.h"

namespace ActionSystem
{
    void ActionGroup::Update(const long double& dt)
    {
        if (IsPaused() || IsCompleted())
        {
            return;
        }
        if (IsEmpty())
        {
            Completed = true;
        }

        Completed = true;
        while (CurrentAction != ActionQueue.end())
        {
            (*CurrentAction)->Update(dt);
            if ((*CurrentAction)->IsCompleted())
            {
                ++CurrentAction;
                continue;
            }
            //If we have not completed ALL of the actions in the group, the group has not finished.
            Completed = false;
            ++CurrentAction;
        }
        if (Completed)
        {
            if (Looping())
            {
                Restart();
            }
            else
            {
                Clear();
            }
        }
        CurrentAction = ActionQueue.begin();
    }

    void ActionGroup::AddAction(ActionBase* action)
    {
        ActionQueue.push_back(action);
        CurrentAction = ActionQueue.begin();
    }

    void ActionGroup::Restart()
    {
        ActionBase::Restart();
        CurrentAction = ActionQueue.begin();
    }

    void ActionGroup::Clear()
    {
        while (!ActionQueue.empty())
        {
            delete ActionQueue.back();
            ActionQueue.pop_back();
        }
    }

    ActionGroup::~ActionGroup()
    {
        Clear();
    }
}