#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/ListButtonBar.hpp>

class $modify(ListButtonBarModifier, ListButtonBar)
{
    static ListButtonBar *create(cocos2d::CCArray *items, cocos2d::CCPoint position, int columns, int rows, float columnOffset, float rowOffset, float offset, float arrowOffset, int arrowType)
    {
        auto ret = ListButtonBar::create(items, position, columns, rows, columnOffset, rowOffset, offset, arrowOffset, arrowType);
        if (ret && Mod::get()->getSettingValue<std::string>("icon-kit-style") != "2.2")
        {
            ret->setPositionY(29.f);
        }
        return ret;
    }
};
