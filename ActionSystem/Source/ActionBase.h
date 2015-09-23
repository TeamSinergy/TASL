/****************************************************************************/
/*!
\file   ActionBase.h
\author Joshua Biggs
\par    Email: Joshua.B@Digipen.edu
\par    Developed: Summer 2015
\brief

Contains the base ActionBase class that all derivitive action types inherit from.
All actions can be Paused, Resumed, Completed, and Restarted.

© 2015 Joshua Biggs CC Attribution
*/
/****************************************************************************/
#pragma once
namespace ActionSystem
{
    namespace Internal
    {
        class ActionBase
        {
        public:
            void Pause() { Paused = true; }
            void Resume() { Paused = false; }
            bool IsPaused() const { return Paused; };
            bool IsCompleted() const { return Completed; };

            //I have Update as a virtual function in order to make adding new action types
            //incredibly simple. I believe the added flexibility heavily outweighs the extra overhead.
            virtual void Update(const long double& dt) = 0;
            //Restart is virtual in the case that the user wants to ake their own custom 
            //derived Action class with different restart functionality.
            virtual void Restart(){ Completed = false; }

            virtual ~ActionBase(){};
        protected:
            //Booleans for different states of the current action.
            bool Paused = false;
            bool Completed = false;

            //Protected so that this class is always a base class.
            ActionBase(){};
            
            
        };
    }//namespace Internal
} //namespace ActionSystem
