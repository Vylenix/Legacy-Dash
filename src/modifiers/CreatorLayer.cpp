#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/CreatorLayer.hpp>

class $modify(CreatorLayerModifier, CreatorLayer)
{
    bool init()
    {
        if (!CreatorLayer::init())
        {
            return false;
        }
        auto style = Mod::get()->getSettingValue<std::string>("creator-layer-style");

        auto creatorButtonsMenu = this->getChildByID("creator-buttons-menu");
        auto createButton = creatorButtonsMenu->getChildByID("create-button");
        auto savedButton = creatorButtonsMenu->getChildByID("saved-button");
        auto scoresButton = creatorButtonsMenu->getChildByID("scores-button");
        auto questsButton = creatorButtonsMenu->getChildByID("quests-button");
        auto versusButton = creatorButtonsMenu->getChildByID("versus-button");
        auto mapButton = creatorButtonsMenu->getChildByID("map-button");
        auto dailyButton = creatorButtonsMenu->getChildByID("daily-button");
        auto weeklyButton = creatorButtonsMenu->getChildByID("weekly-button");
        auto eventButton = creatorButtonsMenu->getChildByID("event-button");
        auto gauntletsButton = creatorButtonsMenu->getChildByID("gauntlets-button");
        auto featuredButton = creatorButtonsMenu->getChildByID("featured-button");
        auto listsButton = creatorButtonsMenu->getChildByID("lists-button");
        auto pathsButton = creatorButtonsMenu->getChildByID("paths-button");
        auto mapPacksButton = creatorButtonsMenu->getChildByID("map-packs-button");
        auto searchButton = creatorButtonsMenu->getChildByID("search-button");

        if (style == "2.1") {
            versusButton->setVisible(false);
            mapButton->setVisible(false);
            eventButton->setVisible(false);
            listsButton->setVisible(false);
            pathsButton->setVisible(false);

            createButton->setContentSize({ 88.825f, 88.825f});
            createButton->setPosition({ 127.6f, 254.6f });
            static_cast<CCSprite *>(createButton->getChildren()->objectAtIndex(0))->setScale(0.85f);
            savedButton->setContentSize({ 88.825f, 88.825f});
            savedButton->setPosition({ 227.6f, 254.6f });
            static_cast<CCSprite *>(savedButton->getChildren()->objectAtIndex(0))->setScale(0.85f);
            scoresButton->setContentSize({ 88.825f, 88.825f});
            scoresButton->setPosition({ 327.6f, 254.6f });
            static_cast<CCSprite *>(scoresButton->getChildren()->objectAtIndex(0))->setScale(0.85f);
            questsButton->setContentSize({ 88.825f, 88.825f});
            questsButton->setPosition({ 77.7f, 157.6f });
            static_cast<CCSprite *>(questsButton->getChildren()->objectAtIndex(0))->setScale(0.85f);
            dailyButton->setContentSize({ 88.825f, 88.825f});
            dailyButton->setPosition({ 177.7f, 157.6f });
            static_cast<CCSprite *>(dailyButton->getChildren()->objectAtIndex(0))->setScale(0.85f);
            weeklyButton->setContentSize({ 88.825f, 88.825f});
            weeklyButton->setPosition({ 277.7f, 157.6f });
            static_cast<CCSprite *>(weeklyButton->getChildren()->objectAtIndex(0))->setScale(0.85f);
            gauntletsButton->setContentSize({ 88.825f, 88.825f});
            gauntletsButton->setPosition({ 377.7f, 157.6f });
            static_cast<CCSprite *>(gauntletsButton->getChildren()->objectAtIndex(0))->setScale(0.85f);
            featuredButton->setContentSize({ 88.825f, 88.825f});
            featuredButton->setPosition({ 77.7f, 60.6f });
            static_cast<CCSprite *>(featuredButton->getChildren()->objectAtIndex(0))->setScale(0.85f);
            mapPacksButton->setContentSize({ 88.825f, 88.825f});
            mapPacksButton->setPosition({ 277.7f, 60.6f });
            static_cast<CCSprite *>(mapPacksButton->getChildren()->objectAtIndex(0))->setScale(0.85f);
            searchButton->setContentSize({ 88.825f, 88.825f});
            searchButton->setPosition({ 377.7f, 60.6f });
            static_cast<CCSprite *>(searchButton->getChildren()->objectAtIndex(0))->setScale(0.85f);
        }

        return true;
    }
};
