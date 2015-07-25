/****************************************************************************/
/*!
\file   ActionProperty.h
\author Joshua Biggs
\par    Email: Joshua.B@Digipen.edu
\par    Developed: Summer 2015
\brief

Contains an action system that allows the user to interpolate between two
values over a specified duration of time.

© 2015 Joshua Biggs CC Attribution
*/
/****************************************************************************/
#pragma once
#include "ActionBase.h"
#include "SampleCurve.h"
#include <functional>

namespace ActionSystem
{
    template< typename T >
    class ActionProperty : public Internal::ActionBase
    {
        
    public:
        //I have the value passed in by pointer to make it clear that this value IS going to change.
        ActionProperty(T* startVal, const T& endVal, const long double& duration,const Ease& ease) :
            StartVal(*startVal), EndVal(endVal), CurrentVal(startVal), EndTime(duration),
            EasingCurve(SampleCurve<T>(ease))
        {
        }
        ActionProperty(T* startVal, const T& endVal, const long double& duration, SampleCurve<T> ease) :
            StartVal(*startVal), EndVal(endVal), CurrentVal(startVal), EndTime(duration),
            EasingCurve(ease)
        {
        }
        
        //Restarts the action, using the same memory location and the current starting value.
        void Restart() override
        {
            ActionBase::Restart();
            CurrentTime = 0;
            StartVal = *CurrentVal;
        }
        //Restarts the action, using the same memory location but a different starting value.
        void Restart(const T& startVal)
        {
            *CurrentVal = startVal;
            Restart();
        }
        //Restarts the action, using a different location and a the current starting value.
        void Restart(T* startVal)
        {
            CurrentVal = startVal;
            Restart(*startVal);
        }

        const T& EndValue() const { return EndVal; }
        //The user can modify the ending value on the fly if they so wish.
        T& EndValue() { return EndVal; }

        const long double& TimeElapsed() const { return CurrentTime; }
        //The user can modify the current time on the fly if they so wish.
        long double& TimeElapsed() { return CurrentTime; }

        const long double& Duration() const { return EndTime; }
        //The user can modify the end time on the fly if they so wish.
        long double& Duration() { return EndTime; }

        const SampleCurve<T>& Ease() const { return EasingCurve; }
        //The user can modify the easing curve on the fly if they so wish, may cause snapping.
        SampleCurve<T>& Ease() { return EasingCurve; }

        void Update(const long double& dt) override
        {
            if (IsPaused() || IsCompleted())
            {
                return;
            }

            *CurrentVal = EasingCurve.Sample(CurrentTime, StartVal, EndVal, EndTime);

            CurrentTime += dt;
            //Because the action is based entirely on duration, we do not need to worry
            //about precision errors.
            if (CurrentTime >= EndTime)
            {
                *CurrentVal = EndVal;
                CurrentTime = EndTime;
                Completed = true;
            }
        }
    private:
        //The user must restart to edit the starting value.
        T StartVal;
        T EndVal;
        T* CurrentVal;
        

        long double CurrentTime = 0;
        long double EndTime;
        
        SampleCurve<T> EasingCurve;
    };
}