#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/ListButtonPage.hpp>

class $modify(ListButtonPageModifier, ListButtonPage)
{
    static ListButtonPage *create(cocos2d::CCArray *items, cocos2d::CCPoint position, int columns, int rows, float columnOffset, float rowOffset, float offset)
    {
        auto ret = ListButtonPage::create(items, position, columns, rows, columnOffset, rowOffset, offset);
        if (ret && Mod::get()->getSettingValue<std::string>("icon-kit-style") != "2.2")
        {
            for (auto obj : CCArrayExt<CCNode *>(items))
            {
                auto item = static_cast<GJItemIcon *>(obj->getChildren()->objectAtIndex(0));
                item->setScale(0.85f);
                if (auto lock = static_cast<CCSprite *>(item->getChildren()->objectAtIndex(1)))
                {
                    static_cast<CCSprite *>(item->getChildren()->objectAtIndex(0))->setVisible(false);
                    auto iconSprite = CCSprite::createWithSpriteFrameName("playerSquare_001.png");
                    iconSprite->setColor({175, 175, 175});
                    iconSprite->setAnchorPoint({0, 0});
                    item->addChild(iconSprite);
                    auto lockSprite = CCSprite::createWithSpriteFrameName("GJ_lock_001.png");
                    lock->setDisplayFrame(lockSprite->displayFrame());
                    lock->setColor({255, 255, 255});
                    lock->setOpacity(255);
                    lock->setScale(1.f);
                }
            }
        }
        return ret;
    }
};
