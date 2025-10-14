#include "Geode/cocos/platform/CCFileUtils.h"
#include "Geode/loader/Dirs.hpp"
#include <Geode/Enums.hpp>
#include <Geode/modify/GJBaseGameLayer.hpp>
#include <filesystem>
#include <enchantum/enchantum.hpp>
#include "TextureLoader.hpp"

constexpr const char* RESOURCES_SOUNDS_FOLDER_NAME = "saritahhh.globalsounds";

using namespace geode::prelude;


namespace fs = std::filesystem;

std::vector<fs::path> getAllResourceDirs() {
	auto packs = texture_loader::getAppliedPacks();
	std::vector<fs::path> ret;
	ret.reserve(packs.size());
	ret.push_back(geode::dirs::getResourcesDir());
	for(const auto& pack : packs) {
		ret.push_back(pack.resourcesPath);
	}
	return ret;
}
class $modify(SoundsBaseLayer, GJBaseGameLayer) {

	struct Fields {
		std::unordered_map<GJGameEvent, fs::path> cachedFilePaths;
	}; 
	bool init() {
		if (!GJBaseGameLayer::init()) return false;

		//cache the events we need to check only
		auto fields = m_fields.self();
		bool useResources = Mod::get()->getSettingValue<bool>("use-resources");
		if(useResources) {
			auto packs = texture_loader::getAppliedPacks();
			for(const auto& [event, event_name] : enchantum::entries_generator<GJGameEvent>) {
				std::string file_name = fmt::format("{}.ogg", event_name);
				for(auto dir : getAllResourceDirs()) {

					//if there is a single folder in the pack then texture loader treats that as the root route for resources...
					if(dir.filename() != RESOURCES_SOUNDS_FOLDER_NAME) {
						dir /= RESOURCES_SOUNDS_FOLDER_NAME;
					}
					fs::path file = dir / file_name;
					if(fs::exists(file)) {
						fields->cachedFilePaths.insert({event, file});
					}
				}

			}
		}
		else {
			for(const auto& [event, event_name] : enchantum::entries_generator<GJGameEvent>) {
				auto file = Mod::get()->getSettingValue<fs::path>(event_name);
				// @geode-ignore(unknown-resource)
				if(file.filename() != "unset.ogg" && fs::exists(file)) {
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