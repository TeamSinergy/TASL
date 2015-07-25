/****************************************************************************/
/*!
\file   ActionSequence.h
\author Joshua Biggs
\par    Email: Joshua.B@Digipen.edu
\par    Developed: Summer 2015
\brief

The ActionSequence contains a list of other actions (Properties, Groups, Calls,
Sequences, etc.) that are put into a queue and run one after the other.

© 2015 Joshua Biggs CC Attribution
*/
/****************************************************************************/
#pragma once
#include "ActionBase.h"
#include <queue>

namespace ActionSystem
{
    class ActionSequence : public Internal::ActionBase
    {
    public:
        ActionSequence(bool looping = false) : 
            LoopingSequence(looping),
            ActionQueue(){};
        ActionSequence(const std::deque<ActionBase*>& actionQueue, bool looping = false) :
            LoopingSequence(looping),
            ActionQueue(actionQueue){};

        
        void Update(const long double& dt) override;

        bool IsEmpty()const { return ActionQueue.empty(); };
        const bool& Looping()const { return LoopingSequence; };
        bool& Looping() { return LoopingSequence; };

        void Clear();

        void Restart() override;

        void AddAction(ActionBase* action);
        const ActionBase& GetCurrentAction() const { return (**CurrentAction); };

        ~ActionSequence() override;
    private:
        //A looping sequence is an optimized way to repeat
        //animations without reallocating a lot of memory.
        bool LoopingSequence;
        std::deque<ActionBase*>::iterator CurrentAction;
        std::deque<ActionBase*> ActionQueue;
        
    };
}