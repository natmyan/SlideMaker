#ifndef LINE_SHAPE_HPP
#define LINE_SHAPE_HPP

#include "VisualShapeBase.hpp"
#include "../IVisualDisplayable.hpp"

namespace ren {

class LineShape : public VisualShapeBase { //, public IVisualDisplayable {
    public:
        void draw(QPainter* painter, std::shared_ptr<Item> item) override;
        /*std::shared_ptr<IShape> clone(std::shared_ptr<Item> item) const override;
    
    public:
        void setType(std::string type);
        void setBBox(BoundingBox bbox);
        void setAttrs(Attributes attrs);
        
    private:
        std::string type_;
        BoundingBox bbox_;
        Attributes attrs_;*/
};

}

#endif // LINE_SHAPE_HPP