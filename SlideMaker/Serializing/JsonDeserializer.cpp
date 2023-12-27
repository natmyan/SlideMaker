#include "JsonDeserializer.hpp"
#include "../Data/Item.hpp"

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>

JsonDeserializer::JsonDeserializer(std::shared_ptr<Document> doc, JSONDocument& jsonDoc) :
    jsonDoc_(jsonDoc),
    doc_(doc)
{}

void JsonDeserializer::relocateInfo() {
    QJsonObject document = jsonDoc_.getQJson().object();

    doc_ = std::make_shared<Document>();
    
    doc_->setFormatSize(document["format"].toString().toUtf8().constData());
    doc_->setOrientation(document["orientation"].toString().toUtf8().constData());

    QJsonArray groupArray = document["slides"].toArray();

    for (const auto& groupValue : groupArray) {
        QJsonObject groupObject = groupValue.toObject();
        auto slide = std::make_shared<Slide>();
        // auto group = doc_->createNewGroup(); 
        auto group = slide->getItemGroup();
        QJsonObject bboxObject = groupObject["bbox"].toObject();
        group->setBoundingBox({
            {bboxObject["l"].toDouble(), bboxObject["t"].toDouble()},
            {bboxObject["r"].toDouble(), bboxObject["b"].toDouble()}
        });

        QJsonObject attrObject = groupObject["attributes"].toObject();
        for (auto it = attrObject.begin(); it != attrObject.end(); ++it) {
            group->setAttribute(it.key().toUtf8().constData(), Value(std::string(it.value().toString().toUtf8().constData())));
        }

        QJsonArray itemArray = groupObject["items"].toArray();
        for (const auto& itemValue : itemArray) {
            QJsonObject itemObject = itemValue.toObject();
            
            std::string type = itemObject["type"].toString().toUtf8().constData();
            int id = itemObject["-id"].toInt();

            QJsonObject bboxObject2 = itemObject["bbox"].toObject();
            auto t = bboxObject2["t"].toDouble();
            auto l = bboxObject2["l"].toDouble();
            auto r = bboxObject2["r"].toDouble();
            auto b = bboxObject2["b"].toDouble();
            BoundingBox bbox = {{l, t}, {r, b}};

            Attributes attrs;
            QJsonObject attrObject2 = itemObject["attributes"].toObject();
            for (auto it = attrObject2.begin(); it != attrObject2.end(); ++it) {
                attrs.setPair(it.key().toUtf8().constData(), Value(std::string(it.value().toString().toUtf8().constData())));
                // item->setAttribute(it.key().toUtf8().constData(), Value(std::string(it.value().toString().toUtf8().constData())));
            }
            auto item = std::make_shared<Item>(type, id, bbox, attrs); 
            group->addItem(item);
        }
    }
}
    

