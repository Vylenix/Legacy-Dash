#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/MenuLayer.hpp>

class $modify(MenuLayerModifier, MenuLayer)
{
    bool init()
    {
        if (!MenuLayer::init())
        {
            return false;
        }

        auto socialMediaMenu = this->getChildByID("social-media-menu");
        auto twitterButton = static_cast<CCMenuItemSpriteExtra *>(socialMediaMenu->getChildByID("twitter-button"));
        if (Mod::get()->getSettingValue<bool>("main-menu-remove-discord-twitch-social-media"))
        {
            socialMediaMenu->removeChildByID("twitch-button");
            socialMediaMenu->removeChildByID("discord-button");
        }

        if (Mod::get()->getSettingValue<bool>("main-menu-old-socials-style"))
        {
            socialMediaMenu->getChildByID("robtop-logo-button")->setPositionY(10.25f);
            twitterButton->setPositionX(42.f);
            socialMediaMenu->getChildByID("youtube-button")->setPositionX(72.f);
        }

        if (Mod::get()->getSettingValue<bool>("main-menu-pre-2.2-twitter-icon"))
        {
            auto oldTwitterIcon = CCSprite::create("gj_twIcon_001-old.png"_spr);
            oldTwitterIcon->setScale(0.8f);
            auto oldTwitterIconNode = CCNode::create();
            auto scaledSize = oldTwitterIcon->getContentSize() * 0.8f;
            oldTwitterIconNode->setContentSize(scaledSize);
            oldTwitterIcon->setPosition(scaledSize / 2);
            oldTwitterIconNode->addChild(oldTwitterIcon);
            twitterButton->setNormalImage(oldTwitterIconNode);
            twitterButton->setContentSize(scaledSize);
        }

        auto bottomMenu = this->getChildByID("bottom-menu");
        if (Mod::get()->getSettingValue<bool>("main-menu-pre-2.2-newgrounds-button"))
        {
            auto newgroundsButton = static_cast<CCMenuItemSpriteExtra *>(bottomMenu->getChildByID("newgrounds-button"));
            auto oldNewgroundsIcon = CCSprite::create("GJ_ngBtn_001-old.png"_spr);
            auto oldNewgroundsIconNode = CCNode::create();
            auto scaledSize = oldNewgroundsIcon->getContentSize();
            oldNewgroundsIconNode->setContentSize(scaledSize);
            oldNewgroundsIcon->setPosition(scaledSize / 2);
            oldNewgroundsIconNode->addChild(oldNewgroundsIcon);
            newgroundsButton->setNormalImage(oldNewgroundsIconNode);
            newgroundsButton->setContentSize(scaledSize);
            bottomMenu->updateLayout();
        }

        if (Mod::get()->getSettingValue<bool>("main-menu-remove-newgrounds-button"))
        {
            bottomMenu->removeChildByID("newgrounds-button");
            bottomMenu->updateLayout();
        }

        if (Mod::get()->getSettingValue<bool>("main-menu-remove-daily-chest"))
        {
            auto rightSideMenu = this->getChildByID("right-side-menu");
            rightSideMenu->removeChildByID("daily-chest-button");
        }

        if (Mod::get()->getSettingValue<bool>("main-menu-pre-2.0-more-games-scale"))
        {
            this->getChildByID("more-games-menu")->getChildByID("more-games-button")->setScale(1.11f);
        }

        if (Mod::get()->getSettingValue<bool>("main-menu-remove-profile-button"))
        {
            this->removeChildByID("profile-menu");
            this->removeChildByID("player-username");
        }

        return true;
    }
};
