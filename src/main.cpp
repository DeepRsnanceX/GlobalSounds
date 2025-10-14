#include "Geode/cocos/platform/CCFileUtils.h"
#include "Geode/loader/Dirs.hpp"
#include <Geode/Enums.hpp>
#include <Geode/modify/GJBaseGameLayer.hpp>
#include <filesystem>

using namespace geode::prelude;

#include <enchantum/enchantum.hpp>



class $modify(SoundsBaseLayer, GJBaseGameLayer) {

	struct Fields {
		std::unordered_map<GJGameEvent, std::filesystem::path> cachedFilePaths;
	}; 
	bool init() {
		if (!GJBaseGameLayer::init()) return false;

		//cache the events we need to check only
		auto fields = m_fields.self();
		bool useResources = Mod::get()->getSettingValue<bool>("use-resources");
		for(const auto& [event, event_name] : enchantum::entries_generator<GJGameEvent>) {
			if(useResources) {
				auto file = geode::dirs::getResourcesDir() / fmt::format("{}.ogg", event_name);
				if(std::filesystem::exists(file)) {
					fields->cachedFilePaths.insert({event, file});
				}
			}
			else {
				auto file = Mod::get()->getSettingValue<std::filesystem::path>(event_name);
				// @geode-ignore(unknown-resource)
				if(file.filename() != "unset.ogg" && std::filesystem::exists(file)) {
					fields->cachedFilePaths.insert({event, file});
				}
			}

		}

		return true;
	}
	void gameEventTriggered(GJGameEvent event, int input, int player) {
		//this function is called twice for almost all events
        //input == 0 and player == 0 events are unnecessary but some events dont have a player set for some reason
        //all events seem to be in order so this seems safe
        static bool ignoreNext = false;

		if(ignoreNext) {
            ignoreNext = false;
            return GJBaseGameLayer::gameEventTriggered(event, input, player);
        }
        if(player != 0) {
            ignoreNext = true;
        }

		GJBaseGameLayer::gameEventTriggered(event, input, player);
		auto& cachedFilePaths = m_fields->cachedFilePaths;
		if(auto it = m_fields->cachedFilePaths.find(event); it != m_fields->cachedFilePaths.end()) {
			FMODAudioEngine::sharedEngine()->playEffect(it->second.string());
		}
	}
};