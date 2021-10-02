# Ochrewood Tribute
**Ochrewood Tribute** is a pet project for myself and some friends to cut our C++ teeth on.
We chose C++ because it iscompiled, object oriented, and cross platform.
There are future plans to use [Ogre](http://www.ogre3d.org/) for the GUI, but little has been done as of this point.

**Ochrewood Tribute** is a "blobber" inspired by games such as [Might and Magic](https://en.wikipedia.org/wiki/Might_and_Magic),
[Wizardry](https://en.wikipedia.org/wiki/Wizardry), and [Legend of Grimrock](http://www.grimrock.net/), 
in the sense that the player assumes control of a party of characters that all travel together with intense
[personal space issues](https://youtu.be/vQs1uTTjTAM?t=76). Characters may be removed/added to the party, but the party must travel as one entity.
The player controls a party of 1-6 characters that may be added to/removed from the party at specific locations.

## Installation
### Compile from Source
#### Linux
1. Install [CMake](https://cmake.org/download/) from the website, or check your repository for the package
2. In the Ochre directory, `cmake . && make`

#### Windows
1. Install [CMake](https://cmake.org/download/) from the website
2. Install [Visual Studio or Visual Studio Community with C++](https://visualstudio.microsoft.com/vs/features/cplusplus/), not Visual Studio Code
3. In the Ochre directory, `cmake .`
4. Open the `Ochre.sln` file that CMake generates in Visual Studio
5. Build in release mode

### Packages
Installing from [package](https://github.com/EmoBurrito?tab=packages&repo_name=oChre) is much simpler and easier
but will likely be a few versions behind HEAD.

## Documentation
1. Install [Doxygen](https://www.doxygen.nl/download.html). It might even be in your distro's repo.
2. Install graphviz, for dot functionality
3. Run `doxygen doc/doxyfile`
4. Open `doc/html/index.html` in your browser

## Style
1. Tabs > spaces
2. [1TBS](https://en.wikipedia.org/wiki/Indentation_style#Variant:_1TBS_(OTBS))

## Testing
1. Download single file header of [Catch2 2.12.2](https://github.com/catchorg/Catch2) to `src/tests`
2. Run `make exec_tests` to complile the tests
3. Run `bin/tests`
