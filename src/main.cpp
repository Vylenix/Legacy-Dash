#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/LevelSearchLayer.hpp>
#include <Geode/modify/RewardsPage.hpp>
#include <Geode/modify/FollowRewardPage.hpp>
#include <Geode/modify/OptionsLayer.hpp>

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
  bool init(int type)
  {
    if (!LevelSearchLayer::init(type))
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

    auto lengthFilterMenu = this->getChildByID("length-filter-menu");
    if (Mod::get()->getSettingValue<bool>("level-search-layer-pre-2.2-clock-star-positioning"))
    {
      lengthFilterMenu->getChildByID("clock-icon")->setPositionX(-162.938f);
      lengthFilterMenu->getChildByID("star-filter-button")->setPositionX(162.688f);
    }

    if (Mod::get()->getSettingValue<bool>("level-search-layer-remove-plat-filter"))
    {
      auto lengthTiny = lengthFilterMenu->getChildByID("tiny-filter-button");
      lengthTiny->setPositionX(-117.625f);
      static_cast<CCNode *>(lengthTiny->getChildren()->objectAtIndex(0))->setScale(0.5f);

      auto lengthShort = lengthFilterMenu->getChildByID("short-filter-button");
      lengthShort->setPositionX(-57.562f);
      static_cast<CCNode *>(lengthShort->getChildren()->objectAtIndex(0))->setScale(0.5f);

      auto lengthMedium = lengthFilterMenu->getChildByID("medium-filter-button");
      lengthMedium->setPositionX(13.125f);
      static_cast<CCNode *>(lengthMedium->getChildren()->objectAtIndex(0))->setScale(0.5f);

      auto lengthLong = lengthFilterMenu->getChildByID("long-filter-button");
      lengthLong->setPositionX(77.812f);
      static_cast<CCNode *>(lengthLong->getChildren()->objectAtIndex(0))->setScale(0.5f);

      auto lengthXL = lengthFilterMenu->getChildByID("xl-filter-button");
      lengthXL->setPositionX(124.5f);
      static_cast<CCNode *>(lengthXL->getChildren()->objectAtIndex(0))->setScale(0.5f);

      lengthFilterMenu->removeChildByID("plat-filter-button");
    }

    return true;
  }
};

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

class $modify(FollowRewardPageModifier, FollowRewardPage)
{
  bool init()
  {
    if (!FollowRewardPage::init())
    {
      return false;
    }

    if (Mod::get()->getSettingValue<bool>("daily-rewards-pre-2.2-free-socials"))
    {
      if (this->m_mainLayer)
      {
        auto children = this->m_mainLayer->getChildren();

        // Okay tiny rant here! Never fucking make a game again Robtop. This took me like 30 minutes to figure out because devtools cant figure out the fuckery that robtop made here. It made no sense and was entirely out of order and I had to figure this out myself by RANDOMLY entering a number to see if the index was valid. I love you robtop but I hate you robtop. Also yes it's a little unoptimized, I did try to optimize it a little bit but that resulted in more unreadable code. Oh well.
        auto chestMenu = static_cast<CCNode *>(children->objectAtIndex(7));
        auto youtubeChest = static_cast<CCNode *>(chestMenu->getChildren()->objectAtIndex(1));
        auto twitterChest = static_cast<CCNode *>(chestMenu->getChildren()->objectAtIndex(2));
        auto facebookChest = static_cast<CCNode *>(chestMenu->getChildren()->objectAtIndex(3));

        youtubeChest->setPosition({85.f, -150.f});                                               // youtube
        (static_cast<CCNode *>(youtubeChest->getChildren()->objectAtIndex(0)))->setScale(0.7f);  // youtube
        twitterChest->setPosition({200.f, -150.f});                                              // twitter
        (static_cast<CCNode *>(twitterChest->getChildren()->objectAtIndex(0)))->setScale(0.7f);  // twitter
        facebookChest->setPosition({315.f, -150.f});                                             // facebook
        (static_cast<CCNode *>(facebookChest->getChildren()->objectAtIndex(0)))->setScale(0.7f); // facebook

        static_cast<CCNode *>(chestMenu->getChildren()->objectAtIndex(4))->setVisible(false); // twitch
        static_cast<CCNode *>(chestMenu->getChildren()->objectAtIndex(5))->setVisible(false); // discord
        static_cast<CCNode *>(chestMenu->getChildren()->objectAtIndex(6))->setVisible(false); // reddit

        auto youtubeLabel = static_cast<CCNode *>(children->objectAtIndex(8));
        auto twitterLabel = static_cast<CCNode *>(children->objectAtIndex(10));
        auto twitterIcon = static_cast<CCSprite *>(children->objectAtIndex(11));
        auto facebookLabel = static_cast<CCNode *>(children->objectAtIndex(12));

        youtubeLabel->setPosition({169.5f, 200.f});                                       // youtube label
        youtubeLabel->setScale(0.6f);                                                     // youtube label
        static_cast<CCNode *>(children->objectAtIndex(9))->setPosition({169.5f, 142.f});  // youtube icon
        twitterLabel->setPosition({284.5f, 200.f});                                       // twitter label
        twitterLabel->setScale(0.6f);                                                     // twitter label
        twitterIcon->setPosition({284.5f, 142.f});                                        // twitter icon
        facebookLabel->setPosition({399.5f, 200.f});                                      // facebook label
        facebookLabel->setScale(0.6f);                                                    // facebook label
        static_cast<CCNode *>(children->objectAtIndex(13))->setPosition({399.5f, 142.f}); // facebook icon

        static_cast<CCNode *>(children->objectAtIndex(14))->setVisible(false); // twitch label
        static_cast<CCNode *>(children->objectAtIndex(15))->setVisible(false); // twitch icon
        static_cast<CCNode *>(children->objectAtIndex(16))->setVisible(false); // discord label
        static_cast<CCNode *>(children->objectAtIndex(17))->setVisible(false); // discord icon
        static_cast<CCNode *>(children->objectAtIndex(18))->setVisible(false); // reddit label
        static_cast<CCNode *>(children->objectAtIndex(19))->setVisible(false); // reddit icon

        auto oldTwitterIcon = CCSprite::create("gj_twIcon_001-old.png"_spr);
        twitterIcon->setDisplayFrame(oldTwitterIcon->displayFrame());
      }
    }

    return true;
  }
};

class $modify(OptionsLayerModifier, OptionsLayer)
{
  void customSetup()
  {
    OptionsLayer::customSetup();
    
    auto menu = static_cast<CCNode *>(this->getChildren()->objectAtIndex(0));
    if (Mod::get()->getSettingValue<bool>("settings-remove-menu-music-option"))
    {
      menu->removeChildByID("menu-music-label");
      menu->getChildByID("vault-menu")->removeChildByID("menu-music-toggle");
    }
    
    if (Mod::get()->getSettingValue<bool>("settings-pre-2.2-back-button"))
    {
      menu->getChildByIDRecursive("exit-button")->setPosition({24.f, 17.f});
    }
  }
};
