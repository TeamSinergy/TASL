/****************************************************************************/
/*!
\file   ActionMath.h
\author Joshua Biggs
\par    Email: Joshua.B@Digipen.edu
\par    Developed: Summer 2015
\brief

Contains a templated math library for all the different easing equations
used in the ActionSystem.
*/
/****************************************************************************/

#pragma once
//Easing functions
//Linear
namespace ActionSystem
{
    namespace Math
    {
        template < typename T >
        T Linear(long double currentTime, const T& startValue, const T& endValue, long double duration)
        {
            T change = endValue - startValue;

            return static_cast<T>( change * currentTime / duration + startValue);
        }

        //Quadratic
        template < typename T >
        T QuadIn(long double currentTime, const T& startValue, const T& endValue, long double duration)
        {
            T change = endValue - startValue;

            currentTime /= duration;

            return static_cast<T>( change * currentTime * currentTime + startValue);
        }
        template < typename T >
        T QuadOut(long double currentTime, const T& startValue, const T& endValue, long double duration)
        {
            T change = endValue - startValue;

            currentTime /= duration;
            //I multiply by -1 on the right hand side so the user does not need to implement the
            //unary operator-.
            return static_cast<T>( (change * -1) * currentTime * (currentTime - 2) + startValue);
        }
        template < typename T >
        T QuadInOut(long double currentTime, const T& startValue, const T& endValue, long double duration)
        {
            T change = endValue - startValue;

            currentTime /= duration / 2;
            if (currentTime < 1)
            {
                return static_cast<T>( change / 2 * currentTime * currentTime + startValue);
            }

            currentTime -= 1;
            return static_cast<T>( (change * -1) / 2 * (currentTime * (currentTime - 2) - 1) + startValue);
        }

        //Cubic
        template < typename T >
        T CubicIn(long double currentTime, const T& startValue, const T& endValue, long double duration)
        {
            T change = endValue - startValue;

            currentTime /= duration;
            return static_cast<T>( change * currentTime * currentTime * currentTime + startValue);
        }
        template < typename T >
        T CubicOut(long double currentTime, const T& startValue, const T& endValue, long double duration)
        {
            T change = endValue - startValue;

            currentTime /= duration;
            currentTime -= 1;
            return static_cast<T>( change * (currentTime * currentTime * currentTime + 1) + startValue);
        }
        template < typename T >
        T CubicInOut(long double currentTime, const T& startValue, const T& endValue, long double duration)
        {
            T change = endValue - startValue;

            currentTime /= duration / 2;
            if (currentTime < 1)
            {
                return static_cast<T>( change / 2 * currentTime * currentTime * currentTime + startValue);
            }

            currentTime -= 2;
            return static_cast<T>( change / 2 * (currentTime * currentTime * currentTime + 2) + startValue);
        }

        //Quartic
        template < typename T >
        T QuarticIn(long double currentTime, const T& startValue, const T& endValue, long double duration)
        {
            T change = endValue - startValue;

            currentTime /= duration;
            return static_cast<T>( change * currentTime * currentTime * currentTime * currentTime + startValue);
        }
        template < typename T >
        T QuarticOut(long double currentTime, const T& startValue, const T& endValue, long double duration)
        {
            T change = endValue - startValue;

            currentTime /= duration;
            currentTime -= 1;
            return static_cast<T>( (change * -1) * (currentTime * currentTime * currentTime * currentTime - 1) + startValue);
        }
        template < typename T >
        T QuarticInOut(long double currentTime, const T& startValue, const T& endValue, long double duration)
        {
            T change = endValue - startValue;

            currentTime /= duration / 2;
            if (currentTime < 1)
            {
                return static_cast<T>( change / 2 * currentTime * currentTime * currentTime * currentTime + startValue);
            }

            currentTime -= 2;
            return static_cast<T>((change * -1) / 2 * (currentTime * currentTime * currentTime * currentTime - 2) + startValue);
        }

        //Quintic
        template < typename T >
        T QuinticIn(long double currentTime, const T& startValue, const T& endValue, long double duration)
        {
            T change = endValue - startValue;

            currentTime /= duration;
            return static_cast<T>( change * currentTime * currentTime * currentTime * currentTime * currentTime + startValue);
        }
        template < typename T >
        T QuinticOut(long double currentTime, const T& startValue, const T& endValue, long double duration)
        {
            T change = endValue - startValue;

            currentTime /= duration;
            currentTime -= 1;
            return static_cast<T>( change * (currentTime * currentTime * currentTime * currentTime * currentTime + 1) + startValue);
        }
        template < typename T >
        T QuinticInOut(long double currentTime, const T& startValue, const T& endValue, long double duration)
        {
            T change = endValue - startValue;

            currentTime /= duration / 2;
            if (currentTime < 1)
            {
                return static_cast<T>( change / 2 * currentTime * currentTime * currentTime * currentTime * currentTime + startValue);
            }

            currentTime -= 2;
            return static_cast<T>( change / 2 * (currentTime * currentTime * currentTime * currentTime * currentTime + 2) + startValue);
        }
    }//namespace Math

    //All the various ease types.
    enum Ease
    {
        Linear,
        QuadIn,
        QuadInOut,
        QuadOut,
        //Not Yet Implemented
        SinIn,
        //Not Yet Implemented
        SinInOut,
        //Not Yet Implemented
        SinOut,
        //Not Yet Implemented
        ExpoIn,
        //Not Yet Implemented
        ExpoInOut,
        //Not Yet Implemented
        ExpoOut,
        //Not Yet Implemented
        CircIn,
        //Not Yet Implemented
        CircInOut,
        //Not Yet Implemented
        CircOut,
        CubicIn,
        CubicInOut,
        CubicOut,
        QuarticIn,
        QuarticInOut,
        QuarticOut,
        QntIn,
        QntInOut,
        QntOut
    };
}//namespace ActionSystem

