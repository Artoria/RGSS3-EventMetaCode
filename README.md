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

 - entity(*type*) : *type* can be 
    "switch" "var" "actor" "class" "skill" "item" "weapon" "armor" "state" "animation" "tileset" "commonevent"
    "color" "tone" "string"
   which means an entity to get or set or display ...
 

