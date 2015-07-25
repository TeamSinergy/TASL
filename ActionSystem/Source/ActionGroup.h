/****************************************************************************/
/*!
\file   ActionGroup.h
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
#pragma once
#include "ActionBase.h"
#include <deque>

namespace ActionSystem
{
    class ActionGroup : public Internal::ActionBase
    {
    public:
        ActionGroup(bool looping = false) :
            LoopingSequence(looping),
            ActionQueue(){};
        ActionGroup(const std::deque<ActionBase*>& actionQueue, bool looping = false) :
            LoopingSequence(looping),
            ActionQueue(actionQueue){};


        void Update(const long double& dt) override;

        bool IsEmpty()const { return ActionQueue.empty(); };
        const bool& Looping()const { return LoopingSequence; };
        bool& Looping() { return LoopingSequence; };

        void Clear();

        void Restart() override;

        void AddAction(ActionBase* action);
        
        ~ActionGroup() override;
    private:
        //A looping group does not clear 
        //itself when it completes
        bool LoopingSequence;
        std::deque<ActionBase*>::iterator CurrentAction;
        std::deque<ActionBase*> ActionQueue;
        
    };
}