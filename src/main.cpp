#include <Geode/modify/GJBaseGameLayer.hpp>

using namespace geode::prelude;

class $modify(SoundsBaseLayer, GJBaseGameLayer) {

	std::string getEventName(GJGameEvent event) {
		switch(static_cast<int>(event)) {
			case 1: return "TinyLanding";
			case 2: return "FeatherLanding";
			case 3: return "SoftLanding";
			case 4: return "NormalLanding";
			case 5: return "HardLanding";
			case 6: return "HitHead";
			case 7: return "OrbTouched";
			case 8: return "OrbActivated";
			case 9: return "PadActivated";
			case 10: return "GravityInverted";
			case 11: return "GravityRestored";
			case 12: return "NormalJump";
			case 13: return "RobotBoostStart";
			case 14: return "RobotBoostStop";
			case 15: return "UFOJump";
			case 16: return "ShipBoostStart";
			case 17: return "ShipBoostEnd";
			case 18: return "SpiderTeleport";
			case 19: return "BallSwitch";
			case 20: return "SwingSwitch";
			case 21: return "WavePush";
			case 22: return "WaveRelease";
			case 23: return "DashStart";
			case 24: return "DashStop";
			case 25: return "Teleported";
			case 26: return "PortalNormal";
			case 27: return "PortalShip";
			case 28: return "PortalBall";
			case 29: return "PortalUFO";
			case 30: return "PortalWave";
			case 31: return "PortalRobot";
			case 32: return "PortalSpider";
			case 33: return "PortalSwing";
			case 34: return "YellowOrb";
			case 35: return "PinkOrb";
			case 36: return "RedOrb";
			case 37: return "GravityOrb";
			case 38: return "GreenOrb";
			case 39: return "DropOrb";
			case 40: return "CustomOrb";
			case 41: return "DashOrb";
			case 42: return "GravityDashOrb";
			case 43: return "SpiderOrb";
			case 44: return "TeleportOrb";
			case 45: return "YellowPad";
			case 46: return "PinkPad";
			case 47: return "RedPad";
			case 48: return "GravityPad";
			case 49: return "SpiderPad";
			case 50: return "PortalGravityFlip";
			case 51: return "PortalGravityNormal";
			case 52: return "PortalGravityInvert";
			case 53: return "PortalFlip";
			case 54: return "PortalUnFlip";
			case 55: return "PortalNormalScale";
			case 56: return "PortalMiniScale";
			case 57: return "PortalDualOn";
			case 58: return "PortalDualOff";
			case 59: return "PortalTeleport";
			case 60: return "Checkpoint";
			case 61: return "DestroyBlock";
			case 62: return "UserCoin";
			case 63: return "PickupItem";
			case 64: return "CheckpointRespawn";
			case 65: return "FallLow";
			case 66: return "FallMed";
			case 67: return "FallHigh";
			case 68: return "FallVHigh";
			case 69: return "JumpPush";
			case 70: return "JumpRelease";
			case 71: return "LeftPush";
			case 72: return "LeftRelease";
			case 73: return "RightPush";
			case 74: return "RightRelease";
			case 75: return "PlayerReversed";
			case 76: return "FallSpeedLow";
			case 77: return "FallSpeedMed";
			case 78: return "FallSpeedHigh";
			default: return "";
		}
	}

	void gameEventTriggered(GJGameEvent p0, int p1, int p2) {
		GJBaseGameLayer::gameEventTriggered(p0, p1, p2);

		std::string triggeredEvent = SoundsBaseLayer::getEventName(p0);
		if (triggeredEvent.empty()) return;

		auto soundToPlay = Mod::get()->getSettingValue<std::filesystem::path>(triggeredEvent);

		//log::info("trying to play: {}", soundToPlay);
		FMODAudioEngine::sharedEngine()->playEffect(fmt::format("{}", soundToPlay).c_str());
	}
};