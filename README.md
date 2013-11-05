RGSS3-EventMetaCode
===================

RGSS3 Event Meta Code(RGSS3EMC)

RGSS3EMC uses a C-language-like syntax to describe RGSS3event code.

You can use it for varied purposes like:

 - Event Editor written in C#

 - In-Game Event Editor written in Ruby

 - Event Displayer written in Ruby
 
 - Command Event Tool written in C

 - Event Graphic displayer written in Javascript(HTML5)
 
 - Event to HTML preprocessor written in Perl/ERb


Usage
=====

just redefine several "functions" or "macros"(i.e. they are just like "abc(def)", s-expressions)

assuming each of the event commands is like an array 'void* event_items[]', and its index is like 'int pos'

 - end_item() : should return an end sign, in C it's NULL, in Ruby it can be nil
 - start()    : should increment the index, like '++pos'; in Ruby it can be @event_pos += 1
 - stop()     : should decrement the index, like '--pos'; in Ruby it can be @event_pos -= 1
 - cmd(id)    : to tell the meta system the command id to describe is *id*
 - selectcase(*items*, *end_item()*) : to tell the meta system there is a branch here, like "Direct"/"By Variable" 
   
which will change the event command structure, often it means you will need to change the editor UI when this changed.

 - enumcase(*items*, *end_item()*): to tell the meta
 
which will not change the event command structure, often it means you just select a value in a combobox of the editor.

 - switchid() : to get or set a game switch by id.
 - varid()    : to get or set a game variable by id.
 - actorid()  : to get or set a game actor by id.
 - classid()  : to get or set a game class by id.
 - skillid()  : to get or set a game skill by id.
 - itemid()   : to get or set a game item by id.
 - weaponid() : to get or set a game weapon by id.
 - armorid()  : to get or set a game armor by id.
 - enemyid()  : to get or set a game enemy by id.
 - troopid()  : to get or set a game troop by id.
 - stateid()  : to get or set a game state by id.
 - animaid()  : to get or set a game animation by id.
 - tilesetid(): to get or set a game tileset by id.
 - ceventid() : to get or set a game commonevent by id.
 
 - color()    : to get or set a color.
 - tone()     : to get or set a tone.
 - string()   : to get or set a string.
 

