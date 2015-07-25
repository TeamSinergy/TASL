//#include "ActionProperty.h"
//#include "ActionSequence.h"
//#include "ActionGroup.h"
//#include "ActionSystem.h"
//namespace ActionSystem
//{
//    namespace Action
//    {
//        
//        ActionSequence& Sequence(ActionSequence& seq)
//        {
//            ActionSequence* newSequence = new ActionSequence();
//            seq.AddAction(newSequence);
//            return *newSequence;
//        }
//
//        ActionSequence& Sequence(ActionGroup& seq)
//        {
//            ActionSequence* newSequence = new ActionSequence();
//            seq.AddAction(newSequence);
//            return *newSequence;
//        }
//
//        ActionGroup& Group(ActionSequence& seq)
//        {
//            ActionGroup* newGroup = new ActionGroup();
//            seq.AddAction(newGroup);
//            return *newGroup;
//        }
//
//        ActionGroup& Group(ActionGroup& seq)
//        {
//            ActionGroup* newGroup = new ActionGroup();
//            seq.AddAction(newGroup);
//            return *newGroup;
//        }
//
//        
//
//    }//namespace Action
//}