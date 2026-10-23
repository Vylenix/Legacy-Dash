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
    auto twitterButton = static_cast<CCMenuItemSpriteExtra*>(socialMediaMenu->getChildByID("twitter-button"));
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
    
    if (Mod::get()->getSettingValue<bool>("main-menu-pre-2.2-profile-button-placement"))
    {
      this->getChildByID("profile-menu")->getChildByID("profile-button")->setPositionX(26.f);
    }
    
    if (Mod::get()->getSettingValue<bool>("main-menu-pre-2.2-main-button-placements"))
    {
      auto mainMenu = this->getChildByID("main-menu");
      mainMenu->getChildByID("icon-kit-button")->setPositionX(106.75f);
      mainMenu->getChildByID("editor-button")->setPositionX(322.25f);
    }

    if (Mod::get()->getSettingValue<bool>("main-menu-remove-daily-chest"))
    {
      auto rightSideMenu = this->getChildByID("right-side-menu");
      rightSideMenu->removeChildByID("daily-chest-button");
    }

    return true;
  }
};
