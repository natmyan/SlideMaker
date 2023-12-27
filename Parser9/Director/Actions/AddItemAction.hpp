#ifndef ADD_ITEM_ACTION_HPP
#define ADD_ITEM_ACTION_HPP

#include "IAction.hpp"
#include "../../Data/Slide.hpp"

namespace dir {

class AddItemAction : public IAction {
    public:
        AddItemAction(std::shared_ptr<Slide> slidePtr, std::shared_ptr<Item> itemPtr);
    
    public:
        std::shared_ptr<IAction> doAction();
    
    private:
        std::shared_ptr<Slide> slidePtr_;
        std::shared_ptr<Item> itemPtr_;
};

}

#endif // ADD_ITEM_ACTION_HPP