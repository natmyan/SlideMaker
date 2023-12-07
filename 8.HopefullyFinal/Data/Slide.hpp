#ifndef SLIDEE_HPP
#define SLIDEE_HPP

#include "ItemBase.hpp"
#include "ItemGroup.hpp"

#include <memory>
#include <vector>

class Slide {
    public:
        using ItemIterator = std::vector<std::shared_ptr<ItemBase> >::iterator;

    public:    
        void addItem(std::shared_ptr<ItemBase> itemPtr);
        void removeItem(int id);
        std::shared_ptr<ItemBase> getTopItem();
        ItemIterator begin();
        ItemIterator end();
        // void setItem(Type type, ID id, Position pos, Attributes attributes);
        //SlideType<std::shared_ptr<Item> > getSlide();     

    private:
        std::shared_ptr<ItemGroup> itemGroup_;
        // std::vector<std::shared_ptr<ItemBase> > slide_; 
        /// TODO: static or not?
        /// TODO: ID belongs to Item, not command or slide...
};

#endif // SLIDEE_HPP