/****************************************************************************/
/*!
\file   SampleCurve.h
\author Joshua Biggs
\par    email: Joshua.B@Digipen.edu
\par    Course: GAM 255
\brief

Contains a SampleCurve class used to add eases to an Action/Interpolation.
The user can also specify their own custom easing function if they so wish.
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
                //case Ease::CircIn:
                //{
                //    //Not yet implemented.
                //    
                //}break;
                //case Ease::CircInOut:
                //{
                //    //Not yet implemented.
                //    ;
                //}break;
                //case Ease::CircOut:
                //{

                //}break;
                case Ease::CubicIn:
                {
                    Sample = &Math::CubicIn<T>;
                }break;
                case Ease::CubicInOut:
                {
                    Sample = &Math::CubicInOut<T>;
                }break;
                case Ease::CubicOut:
                {
                    Sample = &Math::CubicOut<T>;
                }break;
                /*case Ease::ExpoIn:
                {

                }break;
                case Ease::ExpoInOut:
                {

                }break;
                case Ease::ExpoOut:
                {

                }break;*/
                case Ease::Linear:
                {
                    Sample = &Math::Linear<T>;
                }break;
                case Ease::QntIn:
                {
                    Sample = &Math::QuinticIn<T>;
                }break;
                case Ease::QntInOut:
                {
                    Sample = &Math::QuinticInOut<T>;
                }break;
                case Ease::QntOut:
                {
                    Sample = &Math::QuinticOut<T>;
                }break;
                case Ease::QuadIn:
                {
                    Sample = &Math::QuadIn<T>;
                }break;
                case Ease::QuadInOut:
                {
                    Sample = &Math::QuadInOut<T>;
                }break;
                case Ease::QuadOut:
                {
                    Sample = &Math::QuadOut<T>;
                }break;
                case Ease::QuarticIn:
                {
                    Sample = &Math::QuarticIn<T>;
                }break;
                case Ease::QuarticInOut:
                {
                    Sample = &Math::QuarticInOut<T>;
                }break;
                case Ease::QuarticOut:
                {
                    Sample = &Math::QuarticOut<T>;
                }break;
                default:
                {
                    //No ease specified. Using linear.
                    std::cout << "This ease is not yet implemented. Using Linear as default." << std::endl;
                    Sample = &Math::Linear<T>;
                }
            }
        }
        //This is the delegate to the easing equation.
        //It is public because it doesn't really matter if the user changes it.
        SampleFunc Sample;
    };
}
