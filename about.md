# GlobalSounds
Global Sounds is a very simple mod which allows you to play any SFX of your choice when various Events happen in-game! Similarly to the editor's **Event Trigger**, but for the whole game!

# How do i use it?
GlobalSounds allows you to customize the SFX to play on each Game Event very easily! However, PLEASE know that simply installing the mod will not do anything. The mod is meant to be entirely configured and tweaked by ***YOU!*** The mod by default will not play any SFX on any events, it's up to you to decide which sounds to play on what event!

That said, there's 2 ways to customize your SFX:

### In-Game Mod Settings
By accessing this mod's **Settings Menu**, you can customize each and every SFX individually!
You can choose your own .ogg files to be played on each game event there! If you wish to have a blank slate from where you can add SFX only for certain events and have the rest not play anything, you can click the "Reset All" button at the bottom left corner of the Mod's Settings Popup to reset all the SFX back to playing nothing. 
You can set as many SFX as you want, no need to set all of them! If you only want some events to play a sound, you can set only those few and have the rest unset!

### Via Texture Packs
At the very top of the Settings List, you will find a setting called "Use Resources Folder", if you enable this, the mod will look in the GD Resources folder for the SFX to play. This way, you can create your own Sound Packs by simply creating a folder named `saritahhh.globalsounds` in your Texture Pack, and placing your Sound Effects there! 
Simply make sure that folder exists in your Texture Pack, and name your sound effect the same as the Event you want it to play on! For example:

- RedOrb.ogg -> Will play when a Red Orb is activated.
- YellowPad.ogg -> Will play when a Yellow Pad is activated.
- BallSwitch.ogg -> Will play when changing gravity with the Ball gamemode.

### Texture Loader compatibility
The mod is compatible with Texture Packs using the Texutre Loader mod. You add sounds the same way as in the GD Resources, by creating a folder named `saritahhh.globalsounds` at the root of the texture pack 

## Available events
The full list of available events is as follows:

- HitHead
- OrbTouched
- OrbActivated
- PadActivated
- GravityInverted
- GravityRestored
- NormalJump
- RobotBoostStart
- RobotBoostStop
- UFOJump
- ShipBoostStart
- ShipBoostEnd
- SpiderTeleport
- BallSwitch
- SwingSwitch
- WavePush
- WaveRelease
- DashStart
- DashStop
- Teleported
- PortalNormal
- PortalShip
- PortalBall
- PortalUFO
- PortalWave
- PortalRobot
- PortalSpider
- PortalSwing
- YellowOrb
- PinkOrb
- RedOrb
- GravityOrb
- GreenOrb
- DropOrb
- CustomOrb
- DashOrb
- GravityDashOrb
- SpiderOrb
- TeleportOrb
- YellowPad
- PinkPad
- RedPad
- GravityPad
- SpiderPad
- PortalGravityFlip
- PortalGravityNormal
- PortalGravityInvert
- PortalFlip
- PortalUnFlip
- PortalNormalScale
- PortalMiniScale
- PortalDualOn
- PortalDualOff
- PortalTeleport
- Checkpoint
- DestroyBlock
- UserCoin
- PickupItem
- CheckpointRespawn
- PlayerReversed

### So, how do i switch from Resources to Individual Customization?

- If the "Use Resources Folder" setting is **enabled**, the mod will use its Resources folder. AKA, you can use Texture Packs to set your sounds.
- If the "Use Resources Folder" setting is **disabled**, the mod will only use the individual Sound files you have set on your mod's Settings Page.

# CREDITS
- gdjayy: Idea for the mod.
- iAndyHD3: Greatly improved the mod's code and performance, original creator of 2.1 mod.