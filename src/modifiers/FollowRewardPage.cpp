#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/FollowRewardPage.hpp>

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
            auto youtubeChest = this->getChildByIDRecursive("youtube-chest");
            auto twitterChest = this->getChildByIDRecursive("twitter-chest");
            auto facebookChest = this->getChildByIDRecursive("facebook-chest");

            youtubeChest->setPosition({85.f, -150.f});
            (static_cast<CCNode *>(youtubeChest->getChildren()->objectAtIndex(0)))->setScale(0.7f);
            twitterChest->setPosition({200.f, -150.f});
            (static_cast<CCNode *>(twitterChest->getChildren()->objectAtIndex(0)))->setScale(0.7f);
            facebookChest->setPosition({315.f, -150.f});
            (static_cast<CCNode *>(facebookChest->getChildren()->objectAtIndex(0)))->setScale(0.7f);

            this->getChildByIDRecursive("twitch-chest")->setVisible(false);
            this->getChildByIDRecursive("discord-chest")->setVisible(false);
            this->getChildByIDRecursive("reddit-chest")->setVisible(false);
            this->getChildByIDRecursive("spotlight-chest")->setVisible(false);

            auto youtubeLabel = this->getChildByIDRecursive("youtube-label");
            auto youtubeIcon = static_cast<CCSprite *>(this->getChildByIDRecursive("youtube-icon"));
            auto twitterLabel = this->getChildByIDRecursive("twitter-label");
            auto twitterIcon = static_cast<CCSprite *>(this->getChildByIDRecursive("twitter-icon"));
            auto facebookLabel = this->getChildByIDRecursive("facebook-label");
            auto facebookIcon = static_cast<CCSprite *>(this->getChildByIDRecursive("facebook-icon"));
            auto twitchIcon = static_cast<CCSprite *>(this->getChildByIDRecursive("twitch-icon"));
            auto discordIcon = static_cast<CCSprite *>(this->getChildByIDRecursive("discord-icon"));
            auto redditIcon = static_cast<CCSprite *>(this->getChildByIDRecursive("reddit-icon"));
            auto spotlightIcon = static_cast<CCSprite *>(this->getChildByIDRecursive("spotlight-icon"));

            youtubeLabel->setPosition({169.5f, 200.f});
            youtubeLabel->setScale(0.6f);
            if (youtubeIcon)
                youtubeIcon->setPosition({169.5f, 142.f});
            twitterLabel->setPosition({284.5f, 200.f});
            twitterLabel->setScale(0.6f);
            if (twitterIcon)
                twitterIcon->setPosition({284.5f, 142.f});
            facebookLabel->setPosition({399.5f, 200.f});
            facebookLabel->setScale(0.6f);
            if (facebookIcon)
                facebookIcon->setPosition({399.5f, 142.f});

            this->getChildByIDRecursive("twitch-label")->setVisible(false);
            if (twitchIcon)
                twitchIcon->setVisible(false);
            this->getChildByIDRecursive("discord-label")->setVisible(false);
            if (discordIcon)
                discordIcon->setVisible(false);
            this->getChildByIDRecursive("reddit-label")->setVisible(false);
            if (redditIcon)
                redditIcon->setVisible(false);
            this->getChildByIDRecursive("spotlight-label")->setVisible(false);
            if (spotlightIcon)
                spotlightIcon->setVisible(false);

            if (twitterIcon)
            {
                auto oldTwitterIcon = CCSprite::create("gj_twIcon_001-old.png"_spr);
                twitterIcon->setDisplayFrame(oldTwitterIcon->displayFrame());
            }
        }

        return true;
    }
};
