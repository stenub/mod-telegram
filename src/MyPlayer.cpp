/**
    This plugin can be used for common player customizations
 */

#include "ScriptMgr.h"
#include "Player.h"
#include "Config.h"
#include "Chat.h"

class MyPlayer : public PlayerScript{
public:

    MyPlayer() : PlayerScript("MyPlayer") { }

    void OnLogin(Player* player) override {
        if (sConfigMgr->GetBoolDefault("Telegram.enableGreeting", false)) {
            ChatHandler(player->GetSession()).SendSysMessage("Hello from mod-Telegram!");
        }
    }
};


void AddMyTelegramScripts() {
    new MyPlayer();
}

