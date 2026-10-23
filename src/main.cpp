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

    if (Mod::get()->getSettingValue<bool>("main-menu-remove-discord-twitch-social-media"))
    {
      auto socialMediaMenu = this->getChildByID("social-media-menu");
      socialMediaMenu->removeChildByID("twitch-button");
      socialMediaMenu->removeChildByID("discord-button");
    }

    if (Mod::get()->getSettingValue<bool>("main-menu-remove-daily-chest"))
    {
      auto rightSideMenu = this->getChildByID("right-side-menu");
      rightSideMenu->removeChildByID("daily-chest-button");
    }

    return true;
  }
};
