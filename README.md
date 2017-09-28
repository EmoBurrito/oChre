# Ochrewood Tribute v0.0.3
**Ochrewood Tribute** is a project that I started to further explore deploying applications, broaden my use of different languages and experiment with cross platform GUIs. I am by no means an expert with C++. In fact, I chose C++ because I had worked with C and C# previously. I liked C for it's speed, and C# for being object oriented. C++ seemed to be a good middle ground for being a compiled language, object oriented, and cross platform. There are future plans to use [Ogre][1] for the GUI, but little has been done as of this point.

**Ochrewood Tribute** is inspired by games such as [Might and Magic][2], [Wizardry][3], [Ultima][4], and [Legend of Grimrock][5], in the sense that the player assumes control of a party of characters that all travel together with intense [personal space issues][6] (Characters may be removed/added to the party, but the party must travel as one entity). The player controls a party of 1-6 characters that may be added to/removed from the party at specific locations.

*TODO: Talk about how loved games as a kid, new ones different*

## Plot
*TBD: Rebellion/Uprising against corrupt ruling? Or perhaps misuse of magic? Corrupt magic government? OOH Greedy magic government~*

## Mechanics
### Attributes
Everyone has **six primary attributes** that will have the biggest impact on how they perform. *TODO: Explain them better. Attributes are divided into three categories, and then each of those into offensive and defensive.*
* Accuracy - How hard you swing ultimately means nothing if it doesn't connect. Accuracy affects your chance to land your hits, be they melee or ranged. Counters high speed. A must for Archers and melee users. Should be considered for arcanists looking to save some spells.
* Strength - Walk tall, and carry a big stick. Strength affects how hard you hit with melee physical attacks, and how well you resist physical attacks (both ranged and melee). I have chosen to omit an "endurance" like stat and roll it into strength, simply to reduce the number of statistics, and because typically if someone is big enough to intimidate me, chances are I couldn't hurt them as well either. It simply doesn't make sense to me to have someone incredibly strong who can't also take a good hit.
* Speed - Affects how frequently the creature can act. Each combat action will cause the associated creature to incur a "rest timer", with greater abilities incurring greater timers. That creature must then wait until their rest timer reaches 0 before they can act again. Speed influences how fast the rest timer deteriorates, allowing the creature to take more frequent actions. Also affects armour class, by the logic that a faster person may be harder to hit.
Intellect - Affects the potency of elemental and dark spells. Allows arcanists to cast more spells.
* Wisdom
  * The wise have typically been around the block more than a time or two, and are more difficult to persuade. They can recall the teachings of current and the past, the superior of which may be debatable so they draw from what they need. Bertering against the wise may prove difficult.
  * Affects the potency of divine spells. Allows divinists to cast more spells. Affects charisma related actions, such as bartering or knowing when someone is lying to you.
* Luck - Providing a percentage modifier to almost everything someone can do, luck is not to be ignored by anyone.

### Leveling
Character's won't have a static level so much as their individual attributes will level independently of one another. Skills will be leveled through use, so if you want a character's strength to increase, have them do things that require strength.

### Classes
Varying races will play mostly the same, with the exception that some equipment may be shaped for specific racial body types.

### Races
Races will have attribute differences, but not in the same sense as many other typical RPGs. Instead of races being "naturally stronger" and receiving a strength bonus, they will instead level their strength faster than other races. This will give them a benefit in early game over other characters that will scale better into late game. This also means that, given enough time, any character can max out any attribute.

Races will have different role play opportunities. For example, some characters may prefer or dislike other races and react differently to the party member talking to them. Take note of these tensions. It may mean that specific party members may be ganged up on in combat.

Some races may have special abilities, be able to equip (or lack there of) specific things. See below for examples.

Races will include (more to come):
* **Humans** make up more than a strong majority of the population, and as such craft the most plentiful equipment.
  They are able to use most equipment and are a fine balance amongst all stats.  
* **Half Orcs** are quite similar to humans but are often physically stronger and, as such, solve more problems in this manner. Although slightly heavier built from humans, they can still equip most, if not all, of what humans can. 
* **Elves** are every so slightly smaller than humans, but a bit quicker and more dexterous. Their belief is that the best way to withstand a hit is to not let it connect. Their size difference from humans is not great enough to warrant separate sizing.
  * **High Elves** spend much of their time studying the arcane arts to keep their opponents at bay. If you can defeat them from a distance or use spells to assist yourself, there is little reason to deal with them up close. 
  * **Dark Elves** prefer to stick to the shadows, and rely on their speed and accuracy to help them land their blows. If they can't hit it with an arrow before it sees them, get in close and slide it apart before it has a chance to even react.
* **Dwarves** are short, stocky, strong as an ox but smarter than one too,  and full of vigor. It takes a lot of force to push a dwarf over. Their short height and broad shape cause them to require special sized armour.
* **Halfling** *much like dark elves but different role play and harder to hit.*
* **Goblin** *worse version of human. Plentiful, seen as infestation. Cheap to recruit.*
* **Trolls** *more extreme half orc. Limited in equipment*
* **Draconic** *half dragon. Extreme unarmed damage, no equipment.*

### Combat
*Sleep system*

## How Can I Help?
**Ochrewood Tribute** is an open source project created for the purpose of learning and reliving old style dungeon crawlers.
If you wish to contribute, simply contact the maintainer to claim something that needs to be done (this is to ensure we don't have multiple people working on the same thing), create a new branch, go to town on it, and submit a pull request when you are ready to have it merged into master.

Documentation is generated by invoking [Doxygen][7] while in the *doc* directory and passing in the doxyfile.
You will then find a new *html* directory generated in the *doc*, which will have an *index.html*.
Open this in your internet browser of choice to see the documentation.
Because the documentation is generated via code comments, it is important that all code is documented according to the Doxygen standards.

### Getting Started
#### Compiling From Source
Compiling from source is recommended as it will ensure you always have the 
##### Linux
*TODO g++*
##### Windows
*TODO mingw*
##### Mac
None of the contributors to date own a Mac system, and have little interest in acquiring one.
As such, we are unable to provide instructions for such.

#### Pre-compiled Binaries
At this time, **Ochrewood Tribute** is not popular enough to host pre-compiled binaries anywhere.
If you have issues compiling from source, feel free to ask for assistance.
If we get a larger following and enough demand, we may consider hosting pre-compiled binaries at a later time.

### Code Standards
1. Tabs > Spaces. Don't be silly.
2. Variable names:
   * Use full variable names. No single letter variables unless it is a counter like *int i in ...*
   * Use "my_instance" to indicate that it is an instance, and there is only one instance
3. There is no character limit per line, but do not abuse this. If you need 90 characters on a line to work, fine, but obviously don't one-line an entire source file. This rule is even less strict with text/markdown files. This isn't the 80's. Wordwrap is a thing.
4. All source code must be documented according to Doxygen standards. This will allow Doxygen to generate an html manual.
5. Multiple return statements are fine.

### Version History
Versioning will be handled in a X.Y.Z format, where X is a major release, Y is the merging of a branch into master that a player will definetly notice, and Z is the merging of a branch into master that the player may not notice. See below for examples.
* ~~1: Inclusion of Ogre~~ 
* 0: Terminal based interaction
  * ~~0.4: Non-hostile conversation, commerce, quests~~
  * ~~0.3: Party~~
  * ~~0.2: Consumables~~
  * ~~0.1: Equipment~~
  * 0.0: Creatures
    * 0.0.3: Item class extends Thing and is then in turn extended by Equippable and Consumable.
    Equippable is then extended by weaponry and armour classes that currently do nothing.
    This is mostly to illustrate hierarchies.
    * 0.0.2: Statistics abstracted out of Hero class, allowing for items and other classes to branch off from it, illustrating how to inherit abstract classes.
    * 0.0.1: Heroes implemented. They have stats and attack each other. That's about it.

### TODO
#### Priority
* Create Statistic object with value and experience counter.
    Overload math operators.
* Create Stats object that is a specific collection of Statistics.
    Overload math operators. Replace Thing's statistic variables with this.
* Give creatures a leveling rate for each statistic based on race.
* Change Hero to Human and implement other races.
* Abstract Human into Creature so that it can be extended by rat, wolf, zombie, etc.

#### Back-Burner
* Give creatures two sets of stats: base and effective.
    Rather than subtracting at unequip, we will simply run a recalculation. 
* Get Creature interact working. This will involve a hostility measure of some sort.
  * Get converse working
  * Get attack working
    * Items only counting if they are the ones making contact, as discussed with Hunter
* Get items (both consumable and equipment) functioning
* Spells, and the hero's associated books
* Add "Neekohluhs" named NPC because I told someone I would

[1]: http://www.ogre3d.org/
[2]: https://en.wikipedia.org/wiki/Might_and_Magic
[3]: https://en.wikipedia.org/wiki/Wizardry
[4]: https://en.wikipedia.org/wiki/Ultima_(series)
[5]: http://www.grimrock.net/
[6]: https://youtu.be/vQs1uTTjTAM?t=76
[7]: http://www.stack.nl/~dimitri/doxygen/
