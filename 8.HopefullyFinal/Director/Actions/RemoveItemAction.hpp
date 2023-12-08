#ifndef REMOVE_ITEM_ACTION_HPP
#define REMOVE_ITEM_ACTION_HPP

#include "IAction.hpp"
#include "../../Data/Slide.hpp"

class RemoveItemAction : public IAction {
    public:
        RemoveItemAction(std::shared_ptr<Slide> slide, int itemID);
    
    public:
        void doAction();
    
    private:
        std::shared_ptr<Slide> slide_;
        int itemID_;
};

#endif // REMOVE_ITEM_ACTION_HPP