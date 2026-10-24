#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/LevelSearchLayer.hpp>

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
