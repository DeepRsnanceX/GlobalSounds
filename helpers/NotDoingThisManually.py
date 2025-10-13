import re
import json

# see it's funny bc it's already readable
# but if the user sees RobotBoostStart they'll die
# but if they see Robot Boost Start they'll understand
def toReadable(original):
    spaced = re.sub(r'([A-Z])', r' \1', original)
    return spaced.strip()

def modJson():
    with open('TweakedEvents.txt', 'r') as f:
        lines = f.readlines()
    
    settings = {}
    eventList = []
    
    for line in lines:
        line = line.strip()
        if not line or line.startswith('//'):
            continue
            
        match = re.match(r'(\w+)\s*=\s*(\d+)', line)
        if match:
            eventName = match.group(1)
            eventNum = match.group(2)
            
            readableName = toReadable(eventName)
            
            settingId = eventName
            settings[settingId] = {
                "type": "file",
                "name": f"{readableName} Sound",
                "description": f"Sound file to play when the {readableName} event is triggered.",
                "default": "{mod_resources_dir}/unset.ogg",
                "enable-if": "!use-resources",
                "control": {
                    "dialog": "open",
                    "filters": [
                        {
                            "files": ["*.ogg"],
                            "description": "OGG Audio Files"
                        }
                    ]
                }
            }
            
            eventList.append((eventName, eventNum))
    
    with open('settings.json', 'w') as f:
        json.dump(settings, f, indent=4)
    
    print(f"{len(settings)} settings done")
    return eventList

def getSwitch(eventList):
    cases = []
    for eventName, eventNum in eventList:
        cases.append(f'        case {eventNum}: return "{eventName}";')
    
    switchCode = "switch(static_cast<int>(event)) {\n"
    switchCode += "\n".join(cases)
    switchCode += '\n        default: return "";\n    }'
    
    with open('switch.txt', 'w') as f:
        f.write(switchCode)
    
    print(f"{len(cases)} cases done")

def main():    
    eventList = modJson()
    getSwitch(eventList)
    
    print("\nfiles done :3")

if __name__ == "__main__":
    main()