# Ochrewood Tribute ![Version 0.0.4.2](https://img.shields.io/badge/version-0.0.4.2-brightgreen.svg) ![Mac Testers Needed](https://img.shields.io/badge/testers-mac%20needed-orange.svg)
**Ochrewood Tribute** is a project that I started to further explore deploying applications,
broaden my use of different languages and experiment with cross platform GUIs.
I am by no means an expert with C++. In fact, I chose C++ because I had worked with C and C# previously.
I liked C for it's speed, and C# for being object oriented.
C++ seemed to be a good middle ground for being a compiled language, object oriented, and cross platform.
There are future plans to use [Ogre][1] for the GUI, but little has been done as of this point.

**Ochrewood Tribute** is inspired by games such as [Might and Magic][2], [Wizardry][3], [Ultima][4], and [Legend of Grimrock][5], 
in the sense that the player assumes control of a party of characters that all travel together with intense [personal space issues][6]
(Characters may be removed/added to the party, but the party must travel as one entity).
The player controls a party of 1-6 characters that may be added to/removed from the party at specific locations.

*TODO: Talk about how loved games as a kid, new ones different*

## Plot
*Dragons like gold and shiny. Local kingdom borrows money from dragon's pile on promise of return with interest.
Corporate bwankster of a dragon essentially. King thinks "Why not break off? lol". Dragon is named Dhephnul.*

## Mechanics
### Attributes - TODO Move to source documentation
Everyone has **six primary attributes** that will have the biggest impact on how they perform. *TODO: Explain them 
better. Attributes are divided into three categories, and then each of those into offensive and defensive.*
* Accuracy - How hard you swing ultimately means nothing if it doesn't connect. Accuracy affects your chance to land 
your hits, be they melee or ranged. Counters high speed. A must for Archers and melee users. Should be considered for 
arcanists looking to save some spells.
* Strength - Walk tall, and carry a big stick. Strength affects how hard you hit with melee physical attacks, and how 
well you resist physical attacks (both ranged and melee). I have chosen to omit an "endurance" like stat and roll it 
into strength, simply to reduce the number of statistics, and because typically if someone is big enough to intimidate 
me, chances are I couldn't hurt them as well either. It simply doesn't make sense to me to have someone incredibly 
strong who can't also take a good hit.
* Speed - Affects how frequently the creature can act. Each combat action will cause the associated creature to incur a "rest timer", with greater abilities incurring greater timers. That creature must then wait until their rest timer reaches 0 before they can act again. Speed influences how fast the rest timer deteriorates, allowing the creature to take more frequent actions. Also affects armour class, by the logic that a faster person may be harder to hit.
Intellect - Affects the potency of elemental and dark spells. Allows arcanists to cast more spells.
* Wisdom
  * The wise have typically been around the block more than a time or two, and are more difficult to persuade. They can 
  recall the teachings of current and the past, the superior of which may be debatable so they draw from what they need. 
  Bertering against the wise may prove difficult.
  * Affects the potency of divine spells. Allows divinists to cast more spells. Affects charisma related actions, such as bartering or knowing when someone is lying to you.
* Luck - Providing a percentage modifier to almost everything someone can do, luck is not to be ignored by anyone.

### Classes and Leveling
Character's won't have a static level so much as their individual attributes will level independently of one another. 
Skills will be leveled through use, so if you want a character's strength to increase, have them do things that require strength.

Because of this, Ochrewood Tribute does not have set "classes" as many RPG's would. If you want to play a "mage" type class,
simply do mage like things to level mage related skills and attributes.

### Races
Races will have attribute differences, but not in the same sense as many other typical RPGs.
Instead of a race being "naturally stronger" and receiving a strength bonus, they will instead level their strength faster than other races.
This will give them a benefit in early game over other characters that will scale better into late game.
This also means that, given enough time, any character can max out any attribute.

Races will have different role play opportunities. For example, some characters may prefer or dislike other races and 
react differently to the party member talking to them. Take note of these tensions. It may mean that specific party 
members may be ganged up on in combat.

Races ages at different rates. This will mostly affect role play until age extremes are reached.

Races will include humans, orcs and goblins, high and dark elves, dwarves, gnomes, and draconics.
Some races may have special abilities, be able to equip (or lack there of) specific things.
See race class files for details.

### Combat
*TODO: Sleep system*

## How Can I Help?
**Ochrewood Tribute** is an open source project created for the purpose of learning and reliving old style dungeon crawlers.
If you wish to contribute, simply contact the maintainer to claim something that needs to be done (this is to ensure we 
don't have multiple people working on the same thing), create a new branch, go to town on it, and submit a pull request 
when you are ready to have it merged into master.

Documentation is generated by invoking [Doxygen][7] while in the *doc* directory and passing in the doxyfile.
You will then find a new *html* directory generated in the *doc*, which will have an *index.html*.
Open this in your internet browser of choice to see the documentation.
Because the documentation is generated via code comments, it is important that all code is documented according to the Doxygen standards.

### Installing oChre - Under Construction
To ensure users always have the latest version customized for their system, Ochrewood Tribute is distributed as source code
and compiled on the end users machine. Included with Ochrewood Tribute are some scripts to make this as easy as possible
for the end user. All you have to do is run the appropriate install script with root/administrator permissions to install.
If you already have a C++ compiler installed and do not want Ochrewood Tribute installed to its default location,
 elevated permissions are not necessary.

*TODO Write Windows batch script*

*TODO Write whatever Mac users use. Bash as well?* 

### Code Standards
1. Tabs > Spaces. Don't be silly.
2. Variable names:
   * Use full variable names. No single letter variables unless it is a counter like *int i in ...*
   * Use "my_instance" to indicate that it is an instance, and there is only one instance
3. There is no character limit per line, but do not abuse this.
If you need 90 characters on a line to work, fine, but obviously don't one-line an entire source file.
This rule is even less strict with text/markdown files. This isn't the 80's. Wordwrap is a thing.
4. All source code must be documented according to Doxygen standards. This will allow Doxygen to generate an html manual.
5. Multiple return statements are fine.

### Version History
Versioning will be handled in a W.X.Y.Z format, where W is a major release, X is an area of focus, Y is a new addition 
that the player may notice, and Z is a minor rewrite, such as an expanding upon the previous Y.
In retrospect, it is really rather arbitrary.
See below for examples.
* ~~1: Inclusion of Ogre~~ 
* 0: Terminal based interaction
  * ~~0.4: Non-hostile conversation, commerce, quests~~
  * ~~0.3: Party~~
  * ~~0.2: Consumables~~
  * ~~0.1: Equipment~~
  * 0.0: Creatures
    * 0.0.4: Dwarf and Goblin races implemented. Name generation is now delegated to children of Humanoid.
    Other races still need to be implemented. Discovered randomization isn't as random as we would like it to be.
    Install scripts started. Need to include other operating systems.
    * 0.0.3: Item class extends Thing and is then in turn extended by Equippable and Consumable.
    Equippable is then extended by weaponry and armour classes that currently do nothing.
    This is mostly to illustrate hierarchies.
    * 0.0.2: Statistics abstracted out of Hero class, allowing for items and other classes to branch off from it, 
    illustrating how to inherit abstract classes.
    * 0.0.1: Heroes implemented. They have stats and attack each other. That's about it.

If you wish to help out, please see the Projects tab as those listed items are priority.

[1]: http://www.ogre3d.org/
[2]: https://en.wikipedia.org/wiki/Might_and_Magic
[3]: https://en.wikipedia.org/wiki/Wizardry
[4]: https://en.wikipedia.org/wiki/Ultima_(series)
[5]: http://www.grimrock.net/
[6]: https://youtu.be/vQs1uTTjTAM?t=76
[7]: http://www.stack.nl/~dimitri/doxygen/
