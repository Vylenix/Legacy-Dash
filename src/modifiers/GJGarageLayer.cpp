#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/GJGarageLayer.hpp>

class $modify(GJGarageLayerModifier, GJGarageLayer)
{
    bool init()
    {
        if (!GJGarageLayer::init())
        {
            return false;
        }
        auto style = Mod::get()->getSettingValue<std::string>("icon-kit-style");

        if (style == "2.0")
        {
            this->removeChildByID("top-left-menu");

            auto topRightCorner = CCSprite::createWithSpriteFrameName("GJ_sideArt_001.png");
            topRightCorner->setID("top-right-corner"_spr);
            topRightCorner->setPosition({570.f, 321.f});
            topRightCorner->setFlipX(true);
            topRightCorner->setFlipY(true);
            topRightCorner->setAnchorPoint({1, 1});
            this->addChild(topRightCorner);

            if (GJAccountManager::sharedState()->m_accountID > 0)
            {
                auto infoButtonSprite = CCSprite::createWithSpriteFrameName("GJ_infoIcon_001.png");
                infoButtonSprite->setScale(0.8f);
                auto infoButton = CCMenuItemSpriteExtra::create(
                    infoButtonSprite,
                    this,
                    menu_selector(GJGarageLayerModifier::onInfoButton));
                infoButton->setID("info-button"_spr);
                infoButton->setPosition({269.5f, 145.f});

                auto topRightMenu = CCMenu::create();
                topRightMenu->setID("top-right-menu"_spr);
                topRightMenu->addChild(infoButton);
                this->addChild(topRightMenu);
            }

            auto iconTypeMenu = this->getChildByID("category-menu");
            iconTypeMenu->setPosition({117.6f, 192.f});
            iconTypeMenu->setScale(1.1f);

            auto iconTypeMenuLayout = typeinfo_cast<AxisLayout *>(iconTypeMenu->getLayout());
            iconTypeMenuLayout->setGap(3.f);
            iconTypeMenu->updateLayout();

            this->getChildByID("tap-more-hint")->setPosition({404.5f, 186.f});
            this->removeChildByID("shards-menu");

            auto starsIcon = this->getChildByID("stars-icon");
            starsIcon->setPosition(529.f, 282.f);
            starsIcon->setScale(1.f);
            auto starsLabel = this->getChildByID("stars-label");
            starsLabel->setPosition(511.f, 282.f);
            starsLabel->setScale(0.5f);

            auto moonsIcon = this->getChildByID("moons-icon");
            moonsIcon->setPosition(529.f, 256.f);
            moonsIcon->setScale(1.f);
            auto moonsLabel = this->getChildByID("moons-label");
            moonsLabel->setPosition(511.f, 256.f);
            moonsLabel->setScale(0.5f);

            auto coinsIcon = this->getChildByID("coins-icon");
            coinsIcon->setPosition(529.f, 230.f);
            coinsIcon->setScale(0.85f);
            auto coinsLabel = this->getChildByID("coins-label");
            coinsLabel->setPosition(511.f, 230.f);
            coinsLabel->setScale(0.5f);

            auto userCoinsIcon = this->getChildByID("user-coins-icon");
            userCoinsIcon->setPosition(529.f, 204.f);
            userCoinsIcon->setScale(0.85f);
            auto userCoinsLabel = this->getChildByID("user-coins-label");
            userCoinsLabel->setPosition(511.f, 204.f);
            userCoinsLabel->setScale(0.5f);

            auto orbsIcon = this->getChildByID("orbs-icon");
            orbsIcon->setPosition(529.f, 178.f);
            orbsIcon->setScale(1.f);
            auto orbsLabel = this->getChildByID("orbs-label");
            orbsLabel->setPosition(511.f, 178.f);
            orbsLabel->setScale(0.5f);

            auto diamondsIcon = this->getChildByID("diamonds-icon");
            diamondsIcon->setPosition(529.f, 152.f);
            diamondsIcon->setScale(1.f);
            auto diamondsLabel = this->getChildByID("diamonds-label");
            diamondsLabel->setPosition(511.f, 152.f);
            diamondsLabel->setScale(0.5f);

            auto diamondShardsIcon = this->getChildByID("diamond-shards-icon");
            diamondShardsIcon->setPosition(529.f, 126.f);
            diamondShardsIcon->setScale(0.85f);
            auto diamondShardsLabel = this->getChildByID("diamond-shards-label");
            diamondShardsLabel->setPosition(511.f, 126.f);
            diamondShardsLabel->setScale(0.5f);
        }

        if (style == "2.1")
        {
            auto iconTypeMenu = this->getChildByID("category-menu");
            iconTypeMenu->setPosition({184.8f, 192.f});

            auto iconTypeMenuLayout = typeinfo_cast<AxisLayout *>(iconTypeMenu->getLayout());
            iconTypeMenuLayout->setGap(2.4f);
            iconTypeMenu->updateLayout();

            this->getChildByID("tap-more-hint")->setPosition({434.5f, 186.f});
            this->getChildByID("shards-menu")->removeChildByID("color-button");

            auto starsIcon = this->getChildByID("stars-icon");
            starsIcon->setPosition(549.f, 306.f);
            starsIcon->setScale(0.72f);
            auto starsLabel = this->getChildByID("stars-label");
            starsLabel->setPosition(533.f, 306.f);
            starsLabel->setScale(0.45f);

            auto moonsIcon = this->getChildByID("moons-icon");
            moonsIcon->setPosition(549.f, 286.f);
            moonsIcon->setScale(0.72f);
            auto moonsLabel = this->getChildByID("moons-label");
            moonsLabel->setPosition(533.f, 286.f);
            moonsLabel->setScale(0.45f);

            auto coinsIcon = this->getChildByID("coins-icon");
            coinsIcon->setPosition(549.f, 266.f);
            coinsIcon->setScale(0.68f);
            auto coinsLabel = this->getChildByID("coins-label");
            coinsLabel->setPosition(533.f, 266.f);
            coinsLabel->setScale(0.45f);

            auto userCoinsIcon = this->getChildByID("user-coins-icon");
            userCoinsIcon->setPosition(549.f, 246.f);
            userCoinsIcon->setScale(0.68f);
            auto userCoinsLabel = this->getChildByID("user-coins-label");
            userCoinsLabel->setPosition(533.f, 246.f);
            userCoinsLabel->setScale(0.45f);

            auto orbsIcon = this->getChildByID("orbs-icon");
            orbsIcon->setPosition(549.f, 226.f);
            orbsIcon->setScale(0.72f);
            auto orbsLabel = this->getChildByID("orbs-label");
            orbsLabel->setPosition(533.f, 226.f);
            orbsLabel->setScale(0.45f);

            auto diamondsIcon = this->getChildByID("diamonds-icon");
            diamondsIcon->setPosition(549.f, 206.f);
            diamondsIcon->setScale(0.8f);
            auto diamondsLabel = this->getChildByID("diamonds-label");
            diamondsLabel->setPosition(533.f, 206.f);
            diamondsLabel->setScale(0.45f);

            auto diamondShardsIcon = this->getChildByID("diamond-shards-icon");
            diamondShardsIcon->setPosition(549.f, 186.f);
            diamondShardsIcon->setScale(0.68f);
            auto diamondShardsLabel = this->getChildByID("diamond-shards-label");
            diamondShardsLabel->setPosition(533.f, 186.f);
            diamondShardsLabel->setScale(0.45f);
        }

        if (style == "2.1" || style == "2.0")
        {
            static_cast<CCSprite *>(this->getChildByID("background"))->setColor({175, 175, 175});
            this->getChildByID("select-background")->setPositionY(124.f);
            this->getChildByID("icon-selection-bar")->setPositionY(29.f);
            this->getChildByID("prev-page-menu")->setPositionY(124.f);
            this->getChildByID("next-page-menu")->setPositionY(124.f);
            this->getChildByID("navdot-menu")->setVisible(false);
            this->removeChildByID("bottom-left-corner");
            this->removeChildByID("bottom-right-corner");

            auto usernameLock = this->getChildByID("username-lock");
            usernameLock->setPositionX(usernameLock->getPositionX() + 15.75f);
            auto usernameLabel = static_cast<CCLabelBMFont *>(this->getChildByID("username-label")->getChildren()->objectAtIndex(1));
            usernameLabel->setFntFile("bigFont.fnt");
            usernameLabel->setColor({255, 170, 50});
        }

        return true;
    }

    void onInfoButton(CCObject *)
    {
        int userID = GameManager::sharedState()->m_playerUserID;
        FLAlertLayer::create("User Info", fmt::format("<cy>UserID:</c> {}", userID), "OK")->show();
    }

    void onArrow(cocos2d::CCObject *sender)
    {
        GJGarageLayer::onArrow(sender);
        if (Mod::get()->getSettingValue<std::string>("icon-kit-style") != "2.2")
            this->getChildByID("navdot-menu")->setVisible(false);
    }

    void onSelectTab(cocos2d::CCObject *sender)
    {
        GJGarageLayer::onSelectTab(sender);
        if (Mod::get()->getSettingValue<std::string>("icon-kit-style") != "2.2")
            this->getChildByID("navdot-menu")->setVisible(false);
    }
};
