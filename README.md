# 42-Doom

[![CodeFactor](https://www.codefactor.io/repository/github/kibotrel/42-doom/badge)](https://www.codefactor.io/repository/github/kibotrel/42-doom)

This project was made to learn about graphics and physics engine techniques along with audio play-back and mixing using [SDL2](https://www.libsdl.org/), [libsndfile](http://www.mega-nerd.com/libsndfile/) and [libao](https://xiph.org/ao/).

## Install

Works on **macOS Mojave 10.14.6** and **Ubuntu Bionic Beaver 18.04.4**, not sure about portability on other operating systems. This project contains several submodules that you must initialize beforehand :

```shell
$> git clone --recurse-submodules https://github.com/kibotrel/42-Doom.git
$> cd 42-Doom && make
```

## Usage
### Run the program

Once the program is compiled, run it with the following command line :

```shell
$> ./doom-nukem
```

If you don't pass any argument to the program, it will allow you to play in an hard-coded map used as a tutorial that explains some of the mechanics implemented in the engine. You can play any well formatted map by passing it as argument like :

```shell
$> ./doom-nukem map.data
```

### Features

This program contains a three different sub-menus accessible through the main one :

* [**Game**]() Test-play either the tutorial or any map.
* [**Editor**]() Build levels and tweak parameters in real-time.
* [**Settings**]() Update game-rules and modify engine's behaviors.

For more information, click on each sub-menu to be redirected on its wiki or [here]() for the main wiki page.

### Error management

Whenever one error occurs during the process, it leads to a complete memory free before [`exit()`](https://linux.die.net/man/3/exit) with an error code and the correct error message displayed on the **standard output**. You can retrieve the code by running :

```shell
$> echo $?
```

More information available in the [Error management wiki page]() of this project.

## Screenshots

W.I.P

## Credits
### Ressources

* Audio
  * [Mick Gordon - The Only Thing They Fear is You (DOOM Eternal)](https://www.youtube.com/watch?v=Akx48dLnccQ).
  * [Shotgun (DOOM Original)](http://www.wolfensteingoodies.com/archives/olddoom/music.htm).
* Fonts
  * [Menu (Pricedown)](https://www.dafont.com/fr/pricedown.font).
  * [Game / Settings (Keep Calm)](https://www.dafont.com/fr/keep-calm.font).
  * [Editor (Open Sans)](https://www.fontsquirrel.com/fonts/open-sans).
* Animations
  * [Shotgun (Duke Nukem 3D)](https://www.spriters-resource.com/pc_computer/dukenukem3d/sheet/19003/).
  * [Coin spin](https://www.pngkey.com/detail/u2e6t4e6t4y3r5y3_26-color-pixel-art-coin-animation/).
* Images
  * [Menu Background (Doom 2016)](https://wallpaperscave.com/games/doom-2016/6773).
  * [Skybox](https://wallhere.com/fr/wallpaper/637649).
  * [Ammunation box / shells (Doom 64)](https://www.pngwave.com/png-clip-art-aqubd).
  * [Textures (Minecraft Ressources\-Pack)](https://minecraft.fr/categorie/resource-pack/).

### Helpful links

* [2D Raycasting - Texture mapping](https://lodev.org/cgtutor/raycasting.html).
* [Build Engine (Duke-Nukem 3D) review](http://fabiensanglard.net/duke3d/).
* [Partial Duke-like engine demonstration](https://www.youtube.com/watch?v=HQYsFshbkYw).
* [Frame by frame animation](https://gamedev.stackexchange.com/questions/150941/do-sprite-animations-usually-run-at-the-same-framerate-as-the-game-itself).
* [Sound mixing with clipped frequencies](https://stackoverflow.com/questions/5126169/programmatically-merging-two-pieces-of-audio/5126209#5126209).
* [Point in Polygon algorithm](https://en.wikipedia.org/wiki/Point_in_polygon).
* [Multithread implementation](https://randu.org/tutorials/threads/).
* [Pulse Code Modulation format (.PCM)](https://en.wikipedia.org/wiki/Pulse-code_modulation).
* [SDL2](https://wiki.libsdl.org/), [SDL2_ttf](https://www.libsdl.org/projects/SDL_ttf/docs/SDL_ttf_frame.html), [libsndfile](http://www.mega-nerd.com/libsndfile/api.html) and [libao](https://xiph.org/ao/doc/libao-api.html) APIs.

### Colaborators

* [@nde-jesu](https://github.com/nde-jesu) - Editor menu and map generation.
* [@reda-con](https://github.com/RemiDC) - Map parsing and user interactions.
* [@lojesu](https://github.com/lojesu) - Texture mapping and settings menu.
