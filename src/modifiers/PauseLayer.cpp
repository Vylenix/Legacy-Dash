#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/PauseLayer.hpp>

class $modify(PauseLayerModifier, PauseLayer)
{
    void customSetup()
    {
        PauseLayer::customSetup();

        auto centerButtonsMenu = this->getChildByID("center-button-menu");

        if (!Mod::get()->getSettingValue<bool>("pause-menu-reset-button"))
        {
            centerButtonsMenu->removeChildByID("retry-button");
        }

        if (!Mod::get()->getSettingValue<bool>("pause-menu-pre-2.2-button-spacing"))
        {
            auto centerButtonsMenuLayout = typeinfo_cast<SimpleRowLayout *>(centerButtonsMenu->getLayout());
            centerButtonsMenuLayout->setGap(20.f);
        }
        centerButtonsMenu->updateLayout();

        if (Mod::get()->getSettingValue<bool>("pause-menu-pre-2.2-settings"))
        {
            this->removeChildByID("right-button-menu");
            auto bottomMenu = CCMenu::create();
            bottomMenu->setID("bottom-menu"_spr);
            bottomMenu->setPosition({0.f, 0.f});
            bottomMenu->setContentHeight(100.f);
            addChild(bottomMenu);

            auto gm = GameManager::sharedState();

            auto autoRetryToggle = CCMenuItemExt::createTogglerWithStandardSprites(
                1.f,
                [gm](CCMenuItemToggler *sender)
                {
                    GameManager::get()->setGameVariable("0026", !sender->isToggled());
                });
            autoRetryToggle->setID("auto-retry-toggle"_spr);
            autoRetryToggle->setScale(0.6f);
            autoRetryToggle->setPosition(124.5f, 25.f);
            autoRetryToggle->toggle(GameManager::get()->getGameVariable("0026"));

            auto autoCheckpointsToggle = CCMenuItemExt::createTogglerWithStandardSprites(
                1.f,
                [gm](CCMenuItemToggler *sender)
                {
                    GameManager::get()->setGameVariable("0027", !sender->isToggled());
                });
            autoCheckpointsToggle->setID("auto-checkpoints-toggle"_spr);
            autoCheckpointsToggle->setScale(0.6f);
            autoCheckpointsToggle->setPosition(254.5f, 25.f);
            autoCheckpointsToggle->toggle(GameManager::get()->getGameVariable("0027"));

            auto progressBarToggle = CCMenuItemExt::createTogglerWithStandardSprites(
                1.f,
                [gm](CCMenuItemToggler *sender)
                {
                    if (auto playLayer = PlayLayer::get())
                    {
                        if (auto progressBar = playLayer->getChildByID("progress-bar"))
                        {
                            progressBar->setVisible(!sender->isToggled());
                        }
                    }
                    gm->m_showProgressBar = !sender->isToggled();
                    gm->save();
                });
            progressBarToggle->setID("progress-toggle"_spr);
            progressBarToggle->setScale(0.6f);
            progressBarToggle->setPosition(374.5f, 25.f);
            progressBarToggle->toggle(gm->m_showProgressBar);

            auto autoRetryLabel = CCLabelBMFont::create("Auto-Retry", "bigFont.fnt");
            autoRetryLabel->setID("auto-retry-label"_spr);
            autoRetryLabel->setScale(0.4f);
            autoRetryLabel->setPosition(180.2f, 25.f);

            auto autoCheckpointsLabel = CCLabelBMFont::create("Auto-Checkpoints", "bigFont.fnt");
            autoCheckpointsLabel->setID("auto-checkpoints-label"_spr);
            autoCheckpointsLabel->setScale(0.261f);
            autoCheckpointsLabel->setPosition(311.f, 25.f);

            auto progressBarLabel = CCLabelBMFont::create("Progress Bar", "bigFont.fnt");
            progressBarLabel->setID("progress-bar-label"_spr);
            progressBarLabel->setScale(0.335f);
            progressBarLabel->setPosition(431.f, 25.f);

            bottomMenu->addChild(autoRetryToggle);
            bottomMenu->addChild(autoRetryLabel);
            bottomMenu->addChild(autoCheckpointsToggle);
            bottomMenu->addChild(autoCheckpointsLabel);
            bottomMenu->addChild(progressBarToggle);
            bottomMenu->addChild(progressBarLabel);
        }
    }
};
