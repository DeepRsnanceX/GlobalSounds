/*
//this is dev only and should always be commented out before releasing
//adds a button to menulayer to copy the generated mod.json string



#include "Geode/ui/Notification.hpp"
#include "Geode/utils/general.hpp"
#include <Geode/Enums.hpp>
#include <Geode/binding/CCMenuItemSpriteExtra.hpp>
#include <Geode/modify/MenuLayer.hpp>

#include <enchantum/enchantum.hpp>
#include <fmt/format.h>


constexpr const char* settings_start = R"(
	"settings": {
		"use-resources": {
			"type": "bool",
			"name": "Use Resources Folder",
			"description": "If enabled, will fetch all SFXs from the mod's Resources folder, instead of allowing for individual customization with all the settings listed here.\nEnable if you wanna use Texture Packs as your method to load SFX instead of individual settings.",
			"default": false
		},
)";

constexpr const char* option_string = R"(
        "{0}": {{
            "type": "file",
            "name": "{1} Sound",
            "description": "Sound file to play when the {1} event is triggered.",
            "default": "{{mod_resources_dir}}/unset.ogg",
            "enable-if": "!use-resources",
            "control": {{
                "dialog": "open",
                "filters": [
                    {{
                        "files": ["*.ogg"],
                        "description": "OGG Audio Files"
                    }}
                ]
            }}
        }},
)";

std::string addSpaceBeforeCapital(std::string_view input) {
    if (input.empty()) {
        return std::string{input};
    }
    
    std::string result;
    result.reserve(input.length() * 2); // Reserve space to avoid reallocations
    
    result += input[0]; // Always add the first character
    
    for (size_t i = 1; i < input.length(); ++i) {
        // Check if current character is uppercase
        if (std::isupper(input[i])) {
            // Add space only if the next character exists and is NOT uppercase
            if (i + 1 < input.length() && !std::isupper(input[i + 1])) {
                result += ' ';
            }
        }
        result += input[i];
    }
    
    return result;
}

class $modify(GenerateModJson, MenuLayer)
{

    void onGeneateModJson(CCObject*)
    {
        std::vector<GJGameEvent> eventsToIgnore = {
            GJGameEvent::None, GJGameEvent::TinyLanding, GJGameEvent::FeatherLanding, GJGameEvent::HardLanding, GJGameEvent::SoftLanding, GJGameEvent::NormalLanding,
            GJGameEvent::FallHigh, GJGameEvent::FallSpeedHigh, GJGameEvent::FallSpeedLow, GJGameEvent::FallSpeedMed,
            GJGameEvent::FallVHigh, GJGameEvent::FallLow, GJGameEvent::FallMed,
            GJGameEvent::JumpPush, GJGameEvent::RightRelease, GJGameEvent::RightPush, GJGameEvent::LeftRelease, GJGameEvent::LeftPush, GJGameEvent::JumpRelease
        };

        std::string settings(settings_start);

        for(const auto [event, name] : enchantum::entries_generator<GJGameEvent>)
        {
            if(std::find(eventsToIgnore.begin(), eventsToIgnore.end(), event) != eventsToIgnore.end()) continue;
            settings += fmt::format(option_string, name, addSpaceBeforeCapital(name));
        }
        settings.pop_back();
        settings.pop_back();
        settings += "\n    },";
        geode::utils::clipboard::write(settings);
        geode::Notification::create("Copied mod.json to clipboard", geode::NotificationIcon::Success)->show();
    }

    bool init() {
        if (!MenuLayer::init()) return false;
        auto spr = ButtonSprite::create("mod.json");
        auto btn = CCMenuItemSpriteExtra::create(spr, this, menu_selector(GenerateModJson::onGeneateModJson));
        auto menu = this->getChildByID("bottom-menu");
        menu->addChild(btn);
        menu->updateLayout();
        return true;
    }
};


*/