#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/RewardsPage.hpp>

class $modify(RewardsPageModifier, RewardsPage)
{
    bool init()
    {
        if (!RewardsPage::init())
        {
            return false;
        }

        if (Mod::get()->getSettingValue<bool>("daily-rewards-pre-2.2-free-sprite"))
        {
            auto menu = static_cast<CCNode *>(this->getChildren()->objectAtIndex(0));
            auto freeButton = static_cast<CCMenuItemSpriteExtra *>(menu->getChildByID("main-menu")->getChildByID("free-button"));
            auto freeButtonSprite = CCSprite::create("GJ_freeStuffBtn_001-old.png"_spr);
            auto freeButtonSpriteNode = CCNode::create();
            auto scaledSize = freeButtonSprite->getContentSize();
            freeButtonSpriteNode->setContentSize(scaledSize);
            freeButtonSprite->setPosition(scaledSize / 2);
            freeButtonSpriteNode->addChild(freeButtonSprite);
            freeButton->setNormalImage(freeButtonSpriteNode);
            freeButton->setContentSize(scaledSize);
        }

        return true;
    }
};
