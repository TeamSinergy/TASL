/****************************************************************************/
/*!
\file   SampleCurve.h
\author Joshua Biggs
\par    email: Joshua.B@Digipen.edu
\par    Developed: Summer 2015
\brief

Contains a SampleCurve class used to add eases to an Action/Interpolation.
The user can also specify their own custom easing function if they so wish.

© 2015 Joshua Biggs CC Attribution
*/
/****************************************************************************/
#pragma once
#include "ActionMath.h"
#include <functional>
#include <iostream>

namespace ActionSystem
{
    template < typename T >
    class SampleCurve
    {
        typedef std::function < T(long double currentTime, const T& startValue,
                                const T& endValue, long double duration)> SampleFunc;
    public:
        SampleCurve(const SampleFunc& function) : Sample(function) {};
        SampleCurve(const Ease& ease = Ease::Linear)
        {
            switch (ease)
            {
                case Ease::CircIn:
                {
                    Sample = ActionMath::CircIn<T>;
                    
                }break;
                case Ease::CircInOut:
                {
                    Sample = ActionMath::CircInOut<T>;
                }break;
                case Ease::CircOut:
                {
                    Sample = ActionMath::CircOut<T>;
                }break;
                case Ease::CubicIn:
                {
                    Sample = ActionMath::CubicIn<T>;
                }break;
                case Ease::CubicInOut:
                {
                    Sample = ActionMath::CubicInOut<T>;
                }break;
                case Ease::CubicOut:
                {
                    Sample = ActionMath::CubicOut<T>;
                }break;
                case Ease::ExpoIn:
                {
                    Sample = ActionMath::ExpoIn<T>;
                }break;
                case Ease::ExpoInOut:
                {
                    Sample = ActionMath::ExpoInOut<T>;
                }break;
                case Ease::ExpoOut:
                {
                    Sample = ActionMath::ExpoOut<T>;
                }break;
                case Ease::Linear:
                {
                    Sample = ActionMath::Linear<T>;
                }break;
                case Ease::QntIn:
                {
                    Sample = ActionMath::QuinticIn<T>;
                }break;
                case Ease::QntInOut:
                {
                    Sample = ActionMath::QuinticInOut<T>;
                }break;
                case Ease::QntOut:
                {
                    Sample = ActionMath::QuinticOut<T>;
                }break;
                case Ease::QuadIn:
                {
                    Sample = ActionMath::QuadIn<T>;
                }break;
                case Ease::QuadInOut:
                {
                    Sample = ActionMath::QuadInOut<T>;
                }break;
                case Ease::QuadOut:
                {
                    Sample = ActionMath::QuadOut<T>;
                }break;
                case Ease::QuarticIn:
                {
                    Sample = ActionMath::QuarticIn<T>;
                }break;
                case Ease::QuarticInOut:
                {
                    Sample = ActionMath::QuarticInOut<T>;
                }break;
                case Ease::QuarticOut:
                {
                    Sample = ActionMath::QuarticOut<T>;
                }break;
                case Ease::SinIn:
                {
                    Sample = ActionMath::SinIn<T>;
                }break;
                case Ease::SinInOut:
                {
                    Sample = ActionMath::SinInOut<T>;
                }break;
                case Ease::SinOut:
                {
                    Sample = ActionMath::SinOut<T>;
                }break;
                default:
                {
                    //No ease specified. Using linear.
                    std::cout << "This ease is not yet implemented. Using Linear as default." << std::endl;
                    Sample = ActionMath::Linear<T>;
                }
            }
        }
        //This is the delegate to the easing equation.
        //It is public because it doesn't really matter if the user changes it.
        SampleFunc Sample;
    };
}
