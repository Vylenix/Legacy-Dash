#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/LevelSearchLayer.hpp>

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

    if (Mod::get()->getSettingValue<bool>("main-menu-pre-2.2-newgrounds-button"))
    {
      auto bottomMenu = this->getChildByID("bottom-menu");
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

    if (Mod::get()->getSettingValue<bool>("main-menu-remove-daily-chest"))
    {
      auto rightSideMenu = this->getChildByID("right-side-menu");
      rightSideMenu->removeChildByID("daily-chest-button");
    }

    return true;
  }
};

class $modify(LevelSearchLayerModifier, LevelSearchLayer)
{
  bool init(int p0)
  {
    if (!LevelSearchLayer::init(p0))
    {
      return false;
    }

    if (Mod::get()->getSettingValue<bool>("level-search-layer-pre-2.2-search"))
    {
      auto searchButtonMenu = this->getChildByID("search-button-menu");
      auto searchLevelButton = static_cast<CCMenuItemSpriteExtra *>(searchButtonMenu->getChildByID("search-level-button"));
      auto searchUserButton = static_cast<CCMenuItemSpriteExtra *>(searchButtonMenu->getChildByID("search-user-button"));
      searchButtonMenu->removeChildByID("clear-search-button");

      auto searchButtonSprite = CCSprite::createWithSpriteFrameName("GJ_longBtn02_001.png");
      auto searchButtonText = CCLabelBMFont::create("Search", "bigFont.fnt");
      searchButtonText->setScale(0.6f);
      searchButtonText->setAnchorPoint({0.5f, 0.5f});
      searchButtonText->setPosition({44.875f, 16.25f});
      searchButtonSprite->addChild(searchButtonText);

      auto searchButtonSpriteNode = CCNode::create();
      auto scaledSize = searchButtonSprite->getContentSize();
      searchButtonSpriteNode->setContentSize(scaledSize);
      searchButtonSprite->setPosition(scaledSize / 2);
      searchButtonSpriteNode->addChild(searchButtonSprite);
      searchLevelButton->setNormalImage(searchButtonSpriteNode);
      searchLevelButton->setContentSize(scaledSize);
      searchLevelButton->setPositionX(84.f);

      auto searchUserButtonSprite = CCSprite::create("GJ_longBtn05_001-old.png"_spr);
      auto searchUserButtonSpriteNode = CCNode::create();
      auto scaledSize2 = searchUserButtonSprite->getContentSize();
      searchUserButtonSpriteNode->setContentSize(scaledSize2);
      searchUserButtonSprite->setPosition(scaledSize2 / 2);
      searchUserButtonSpriteNode->addChild(searchUserButtonSprite);
      searchUserButton->setNormalImage(searchUserButtonSpriteNode);
      searchUserButton->setContentSize(scaledSize2);
      searchUserButton->setPositionX(156.f);
    }

    if (Mod::get()->getSettingValue<bool>("level-search-layer-pre-2.2-quick-search"))
    {
      auto quickSearchMenu = this->getChildByID("quick-search-menu");
      auto mostDownloadedButton = static_cast<CCMenuItemSpriteExtra *>(quickSearchMenu->getChildByID("most-downloaded-button"));
      auto mostLikedButton = static_cast<CCMenuItemSpriteExtra *>(quickSearchMenu->getChildByID("most-liked-button"));
      quickSearchMenu->removeChildByID("sent-button");

      auto mostDownloadedSprite = CCSprite::createWithSpriteFrameName("GJ_longBtn03_001.png");
      auto mostDownloadedText = CCLabelBMFont::create("Most Downloaded", "bigFont.fnt");
      mostDownloadedText->setScale(0.45f);
      mostDownloadedText->setAnchorPoint({0.5f, 0.5f});
      mostDownloadedText->setPosition({74.125f, 16.25f});
      mostDownloadedSprite->addChild(mostDownloadedText);

      auto mostDownloadedDownloadSprite = CCSprite::createWithSpriteFrameName("GJ_downloadsIcon_001.png");
      mostDownloadedDownloadSprite->setPosition({154.394f, 15.25f});
      mostDownloadedDownloadSprite->setScale(0.7f);

      auto mostDownloadedSpriteNode = CCNode::create();
      auto scaledSize = mostDownloadedSprite->getContentSize();
      mostDownloadedSpriteNode->setContentSize(scaledSize);
      mostDownloadedSprite->setPosition(scaledSize / 2);
      mostDownloadedSpriteNode->addChild(mostDownloadedSprite);
      mostDownloadedSpriteNode->addChild(mostDownloadedDownloadSprite);
      mostDownloadedButton->setNormalImage(mostDownloadedSpriteNode);
      mostDownloadedButton->setContentSize(scaledSize);
      mostDownloadedButton->setPositionX(-90.5f);

      auto mostLikedSprite = CCSprite::createWithSpriteFrameName("GJ_longBtn03_001.png");
      auto mostLikedText = CCLabelBMFont::create("Most Liked", "bigFont.fnt");
      mostLikedText->setScale(0.6f);
      mostLikedText->setAnchorPoint({0.5f, 0.5f});
      mostLikedText->setPosition({73.988f, 16.25f});
      mostLikedSprite->addChild(mostLikedText);

      auto mostLikedDownloadSprite = CCSprite::createWithSpriteFrameName("GJ_likesIcon_001.png");
      mostLikedDownloadSprite->setPosition({144.113f, 17.f});
      mostLikedDownloadSprite->setScale(0.7f);

      auto mostLikedSpriteNode = CCNode::create();
      auto scaledSize2 = mostLikedSprite->getContentSize();
      mostLikedSpriteNode->setContentSize(scaledSize2);
      mostLikedSprite->setPosition(scaledSize2 / 2);
      mostLikedSpriteNode->addChild(mostLikedSprite);
      mostLikedSpriteNode->addChild(mostLikedDownloadSprite);
      mostLikedButton->setNormalImage(mostLikedSpriteNode);
      mostLikedButton->setContentSize(scaledSize2);
      mostLikedButton->setPositionX(90.5f);
    }

    auto otherFilterMenu = this->getChildByID("other-filter-menu");
    if (Mod::get()->getSettingValue<bool>("level-search-layer-pre-2.2-top-right-menu-positioning"))
    {
      otherFilterMenu->setPosition(562.4f, 159.f);
      
      auto layout = typeinfo_cast<AxisLayout *>(otherFilterMenu->getLayout());
      layout->setGap(12.f);
      otherFilterMenu->updateLayout();
    }
    
    if (Mod::get()->getSettingValue<bool>("level-search-layer-remove-lists"))
    {
      otherFilterMenu->removeChildByID("lists-button");
    }

    return true;
  }
};
