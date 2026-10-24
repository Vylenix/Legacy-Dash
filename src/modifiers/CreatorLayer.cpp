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

        auto createSprite = static_cast<CCSprite *>(createButton->getChildren()->objectAtIndex(0));
        auto savedSprite = static_cast<CCSprite *>(savedButton->getChildren()->objectAtIndex(0));
        auto scoresSprite = static_cast<CCSprite *>(scoresButton->getChildren()->objectAtIndex(0));
        auto questsSprite = static_cast<CCSprite *>(questsButton->getChildren()->objectAtIndex(0));
        auto dailySprite = static_cast<CCSprite *>(dailyButton->getChildren()->objectAtIndex(0));
        auto weeklySprite = static_cast<CCSprite *>(weeklyButton->getChildren()->objectAtIndex(0));
        auto gauntletsSprite = static_cast<CCSprite *>(gauntletsButton->getChildren()->objectAtIndex(0));
        auto featuredSprite = static_cast<CCSprite *>(featuredButton->getChildren()->objectAtIndex(0));
        auto mapPacksSprite = static_cast<CCSprite *>(mapPacksButton->getChildren()->objectAtIndex(0));
        auto searchSprite = static_cast<CCSprite *>(searchButton->getChildren()->objectAtIndex(0));

        if (style == "2.1")
        {
            versusButton->setVisible(false);
            mapButton->setVisible(false);
            eventButton->setVisible(false);
            listsButton->setVisible(false);
            pathsButton->setVisible(false);

            createSprite->setScale(1.f);
            createSprite->setAnchorPoint({0.f, 0.f});
            createSprite->setPosition({0.f, 0.f});
            createButton->setContentSize(createSprite->getContentSize());
            createButton->setPosition({125.f, 252.f});
            createButton->setScale(0.85f);
            savedSprite->setScale(1.f);
            savedSprite->setAnchorPoint({0.f, 0.f});
            savedSprite->setPosition({0.f, 0.f});
            savedButton->setContentSize(savedSprite->getContentSize());
            savedButton->setPosition({225.f, 252.f});
            savedButton->setScale(0.85f);
            scoresSprite->setScale(1.f);
            scoresSprite->setAnchorPoint({0.f, 0.f});
            scoresSprite->setPosition({0.f, 0.f});
            scoresButton->setContentSize(scoresSprite->getContentSize());
            scoresButton->setPosition({325.f, 252.f});
            scoresButton->setScale(0.85f);
            questsSprite->setScale(1.f);
            questsSprite->setAnchorPoint({0.f, 0.f});
            questsSprite->setPosition({0.f, 0.f});
            questsButton->setContentSize(questsSprite->getContentSize());
            questsButton->setPosition({75.f, 155.f});
            questsButton->setScale(0.85f);
            dailySprite->setScale(1.f);
            dailySprite->setAnchorPoint({0.f, 0.f});
            dailySprite->setPosition({0.f, 0.f});
            dailyButton->setContentSize(dailySprite->getContentSize());
            dailyButton->setPosition({175.f, 155.f});
            dailyButton->setScale(0.85f);
            weeklySprite->setScale(1.f);
            weeklySprite->setAnchorPoint({0.f, 0.f});
            weeklySprite->setPosition({0.f, 0.f});
            weeklyButton->setContentSize(weeklySprite->getContentSize());
            weeklyButton->setPosition({275.f, 155.f});
            weeklyButton->setScale(0.85f);
            gauntletsSprite->setScale(1.f);
            gauntletsSprite->setAnchorPoint({0.f, 0.f});
            gauntletsSprite->setPosition({0.f, 0.f});
            gauntletsButton->setContentSize(gauntletsSprite->getContentSize());
            gauntletsButton->setPosition({375.f, 155.f});
            gauntletsButton->setScale(0.85f);
            featuredSprite->setScale(1.f);
            featuredSprite->setAnchorPoint({0.f, 0.f});
            featuredSprite->setPosition({0.f, 0.f});
            featuredButton->setContentSize(featuredSprite->getContentSize());
            featuredButton->setPosition({75.f, 58.f});
            featuredButton->setScale(0.85f);
            mapPacksSprite->setScale(1.f);
            mapPacksSprite->setAnchorPoint({0.f, 0.f});
            mapPacksSprite->setPosition({0.f, 0.f});
            mapPacksButton->setContentSize(mapPacksSprite->getContentSize());
            mapPacksButton->setPosition({275.f, 58.f});
            mapPacksButton->setScale(0.85f);
            searchSprite->setScale(1.f);
            searchSprite->setAnchorPoint({0.f, 0.f});
            searchSprite->setPosition({0.f, 0.f});
            searchButton->setContentSize(searchSprite->getContentSize());
            searchButton->setPosition({375.f, 58.f});
            searchButton->setScale(0.85f);

            auto hofSprite = CCSprite::create("GJ_fameBtn_001-old.png"_spr);
            auto hofButton = CCMenuItemExt::createSpriteExtra(
                hofSprite,
                [](CCMenuItemSpriteExtra *)
                {
                    auto searchObject = GJSearchObject::create(SearchType::HallOfFame);
                    auto browserLayer = LevelBrowserLayer::create(searchObject);
                    auto scene = CCScene::create();
                    scene->addChild(browserLayer);
                    CCDirector::get()->pushScene(CCTransitionFade::create(0.5f, scene));
                });
            hofSprite->setAnchorPoint({0.f, 0.f});
            hofSprite->setPosition({0.f, 0.f});
            hofButton->setID("hof-button"_spr);
            hofButton->setContentSize(hofSprite->getContentSize());
            hofButton->setPosition({175.f, 58.f});
            hofButton->setScale(0.85f);
            creatorButtonsMenu->addChild(hofButton);
        }

        if (style == "2.0")
        {
            questsButton->setVisible(false);
            versusButton->setVisible(false);
            mapButton->setVisible(false);
            dailyButton->setVisible(false);
            weeklyButton->setVisible(false);
            eventButton->setVisible(false);
            gauntletsButton->setVisible(false);
            listsButton->setVisible(false);
            pathsButton->setVisible(false);

            createSprite->setScale(1.f);
            createSprite->setAnchorPoint({0.f, 0.f});
            createSprite->setPosition({0.f, 0.f});
            createButton->setContentSize(createSprite->getContentSize());
            createButton->setPosition({105.f, 220.f});
            savedSprite->setScale(1.f);
            savedSprite->setAnchorPoint({0.f, 0.f});
            savedSprite->setPosition({0.f, 0.f});
            savedButton->setContentSize(savedSprite->getContentSize());
            savedButton->setPosition({225.f, 220.f});
            scoresSprite->setScale(1.f);
            scoresSprite->setAnchorPoint({0.f, 0.f});
            scoresSprite->setPosition({0.f, 0.f});
            scoresButton->setContentSize(scoresSprite->getContentSize());
            scoresButton->setPosition({345.f, 220.f});
            featuredSprite->setScale(1.f);
            featuredSprite->setAnchorPoint({0.f, 0.f});
            featuredSprite->setPosition({0.f, 0.f});
            featuredButton->setContentSize(featuredSprite->getContentSize());
            featuredButton->setPosition({105.f, 90.f});
            mapPacksSprite->setScale(1.f);
            mapPacksSprite->setAnchorPoint({0.f, 0.f});
            mapPacksSprite->setPosition({0.f, 0.f});
            mapPacksButton->setContentSize(mapPacksSprite->getContentSize());
            mapPacksButton->setPosition({225.f, 90.f});
            searchSprite->setScale(1.f);
            searchSprite->setAnchorPoint({0.f, 0.f});
            searchSprite->setPosition({0.f, 0.f});
            searchButton->setContentSize(searchSprite->getContentSize());
            searchButton->setPosition({345.f, 90.f});

            this->removeChildByID("top-right-menu");
            this->removeChildByID("bottom-right-menu");

            auto topRightCorner = CCSprite::createWithSpriteFrameName("GJ_sideArt_001.png");
            topRightCorner->setID("top-right-corner"_spr);
            topRightCorner->setPosition({570.f, 321.f});
            topRightCorner->setFlipX(true);
            topRightCorner->setFlipY(true);
            topRightCorner->setAnchorPoint({1, 1});
            this->addChild(topRightCorner);

            auto bottomRightCorner = CCSprite::createWithSpriteFrameName("GJ_sideArt_001.png");
            bottomRightCorner->setID("bottom-right-corner"_spr);
            bottomRightCorner->setPosition({570.f, -1.f});
            bottomRightCorner->setFlipX(true);
            bottomRightCorner->setAnchorPoint({1, 0});
            this->addChild(bottomRightCorner);
        }

        if (style == "2.1" || style == "2.0")
        {
            auto oldFeaturedSprite = CCSprite::create("GJ_featuredBtn_001-old.png"_spr);
            static_cast<CCSprite *>(featuredButton->getChildren()->objectAtIndex(0))->setDisplayFrame(oldFeaturedSprite->displayFrame());
        }

        return true;
    }
};
