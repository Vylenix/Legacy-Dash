#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/OptionsLayer.hpp>

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
