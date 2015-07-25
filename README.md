# ActionSystem
A C++ templated Action System that can be used for animations and other sorts of interpolations over time. Supports 22 different types of eases.

To get started, simply download the project include 'ActionSystem.h'.

The ActionSystem Library contains the following features:

ActionBase:
    This class is what all actions are derived from. The user can make
    their own classes that derive from this one.

ActionProperty:
    This class interpolates a value passed in by pointer from its original
    value to an ending value over a specified duration of time.

ActionSequence:
    This class contains a queue of actions that happen one after the other.
    The next action does not happen until the previous one in the queue has
    been completed.

ActionGroup:
    This class contains a group of actions that are all updated simultaneously.

Note: An ActionGroup/Sequence CAN have other ActionGroups/Sequences inside of it.

ActionDelay:
    This class delays a sequence for a specified amount of time in 'seconds'.

ActionCall:
    This class calls a specified function when it is reached.

SampleCurve:
    This class is a wrapper around a std::function and can be passed into an 
    ActionProperty to affect how the property interpolates the value.
    Eases are one example of this in action.

Supported Eases:
    Linear, Quadratic, Cubic, Quartic, Quintic, Exponential, Circular, and Sinusoidal.

ActionSystem.h:
    This header file contains the namespace 'ActionSystem::Action' which holds
    several inline functions used to interface with the action system.

Helper Functions:

    Action::Sequence:
    -Adds and returns an ActionSequence which is added to the input ActionGroup or ActionSequence.

    Action::Group:
    -Adds and returns an ActionGroup which is added to the input ActionGroup or ActionSequence.

    Action::Property:
    -Adds an ActionProperty which is added to the input ActionGroup or ActionSequence.

    Action::Delay:
    -Adds an ActionDelay which is added to the input ActionGroup or ActionSequence.

    Action::Call:
    -Adds an ActionCall which is added to the input ActionGroup or ActionSequence.

Custom Classes:
    A custom class must have the binary operators + and - with it's own type
    overloaded as well as * and / overloaded to take in a long double in order
    to be properly interpolated with a high level of precision. The operators
    MUST be const correct.

Example Operators:
    Type operator+(const Type& rhs) const
    Type operator-(const Type& rhs) const
    Type operator*(const long double& rhs) const
    Type operator/(const long double& rhs) const

Output:
    This program outputs to a file called output.txt located in the ActionSystem 
    folder. The output shows the values being interpolated in a visual format.
    For best results, open the text file in a web browser and aoom all the way out.


© 2015 Joshua Biggs CC Attribution
You are free to:
    Share — Copy and redistribute the material in any medium or format.
    Adapt — Remix, transform, and build upon the material
            for any purpose, even commercially.

Under the following terms:
    Attribution — You must give appropriate credit, provide a link to the license, 
                  and indicate if changes were made. You may do so in any reasonable 
                  manner, but not in any way that suggests the licensor endorses you 
                  or your use.
