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
