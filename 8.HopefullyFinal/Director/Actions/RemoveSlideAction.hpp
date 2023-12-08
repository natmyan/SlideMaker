#ifndef REMOVE_SLIDE_ACTION_HPP
#define REMOVE_SLIDE_ACTION_HPP

#include "IAction.hpp"
#include "../../Data/Document.hpp"

class RemoveSlideAction : public IAction {
    public:
        RemoveSlideAction(std::shared_ptr<Document> doc, int slideIdx);
    
    public:
        void doAction();
        int getSlideIdx();
        std::shared_ptr<Document> getDocumentPtr();
    
    private:
        std::shared_ptr<Document> doc_;
        int slideIdx_;
};

#endif // REMOVE_SLIDE_ACTION_HPP