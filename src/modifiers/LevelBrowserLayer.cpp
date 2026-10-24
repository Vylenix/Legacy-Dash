#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/LevelBrowserLayer.hpp>

class $modify(LevelBrowserLayerModifier, LevelBrowserLayer)
{
    bool init(GJSearchObject *object)
    {
        if (!LevelBrowserLayer::init(object))
        {
            return false;
        }

        if (object && object->m_searchType == SearchType::HallOfFame)
        {
            auto headerSprite = CCSprite::create("hallOfFameLabel_001-old.png"_spr);
            headerSprite->setID("header-sprite"_spr);
            headerSprite->setZOrder(2);
            headerSprite->setPosition({284.5f, 294.f});
            this->addChild(headerSprite);
        }

        return true;
    }
};
