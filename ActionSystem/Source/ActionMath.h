/****************************************************************************/
/*!
\file   ActionMath.h
\author Joshua Biggs
\par    Email: Joshua.B@Digipen.edu
\par    Developed: Summer 2015
\brief

Contains a templated math library for all the different easing equations
used in the ActionSystem.

The math used in the equations was found thanks to: http://gizma.com/easing/

© 2015 Joshua Biggs CC Attribution
*/
/****************************************************************************/


#include "math.h"
//Easing functions
//Linear
namespace ActionSystem
{
    namespace ActionMath
    {
        //This is Pi. Their are many Pi's like it but this one is mine.
        namespace
        {
            const long double Pi = 3.141592653589793238462643383279502884L;
        }

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
        
        //Sinusoidal
        template < typename T >
        T SinIn(long double currentTime, const T& startValue, const T& endValue, long double duration)
        {
            T change = endValue - startValue;
            
            return static_cast<T>((change * -1) * cos(currentTime / duration * (Pi / 2)) + change + startValue);
        }
        template < typename T >
        T SinOut(long double currentTime, const T& startValue, const T& endValue, long double duration)
        {
            T change = endValue - startValue;
            
            return static_cast<T>(change * sin(currentTime / duration * (Pi / 2)) + startValue);
        }
        template < typename T >
        T SinInOut(long double currentTime, const T& startValue, const T& endValue, long double duration)
        {
            T change = endValue - startValue;
            
            return static_cast<T>((change * -0.5) * (cos(Pi * currentTime / duration) - 1) + startValue);
        }

        //Exponential
        template < typename T >
        T ExpoIn(long double currentTime, const T& startValue, const T& endValue, long double duration)
        {
            T change = endValue - startValue;

            return static_cast<T>(change * pow(2, 10 * (currentTime / duration - 1)) + startValue);
        }
        template < typename T >
        T ExpoOut(long double currentTime, const T& startValue, const T& endValue, long double duration)
        {
            T change = endValue - startValue;
            
            return static_cast<T>(change * (-pow(2, -10 * currentTime / duration) + 1) + startValue);
        }
        template < typename T >
        T ExpoInOut(long double currentTime, const T& startValue, const T& endValue, long double duration)
        {
            T change = endValue - startValue;
            currentTime /= duration / 2;
            if (currentTime < 1)
            {
                return change / 2 * pow(2, 10 * (currentTime - 1)) + startValue;
            }
            --currentTime;

            return static_cast<T>(change/2 * (-pow(2, -10 * currentTime) + 2) + startValue);
        }

        //Circular
        template < typename T >
        T CircIn(long double currentTime, const T& startValue, const T& endValue, long double duration)
        {
            T change = endValue - startValue;
            currentTime /= duration;

            return static_cast<T>((change * -1) * (sqrt(1 - currentTime*currentTime) - 1) + startValue);
        }
        template < typename T >
        T CircOut(long double currentTime, const T& startValue, const T& endValue, long double duration)
        {
            T change = endValue - startValue;
            currentTime /= duration;
            --currentTime;

            return static_cast<T>(change * sqrt(1 - currentTime * currentTime) + startValue);
        }
        template < typename T >
        T CircInOut(long double currentTime, const T& startValue, const T& endValue, long double duration)
        {
            T change = endValue - startValue;
            currentTime /= duration / 2;
            if (currentTime < 1)
            {
                return (change * -1) / 2 * (sqrt(1 - currentTime * currentTime) - 1) + startValue;
            }
            currentTime -= 2;

            return static_cast<T>(change / 2 * (sqrt(1 - currentTime * currentTime) + 1) + startValue);
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
        SinIn,
        SinInOut,
        SinOut,
        ExpoIn,
        ExpoInOut,
        ExpoOut,
        CircIn,
        CircInOut,
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

