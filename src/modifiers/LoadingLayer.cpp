#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/LoadingLayer.hpp>

class $modify(LoadingLayerModifier, LoadingLayer)
{
    bool init(bool refresh)
    {
        if (!LoadingLayer::init(refresh))
        {
            return false;
        }

        if (Mod::get()->getSettingValue<bool>("loading-screen-remove-cocos2d-fmod"))
        {
            this->removeChildByID("cocos2d-logo");
            this->removeChildByID("fmod-logo");
        }

        return true;
    }
};
