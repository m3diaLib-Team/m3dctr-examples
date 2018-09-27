#!/bin/bash
set -e
wget https://github.com/devkitPro/pacman/releases/download/devkitpro-pacman-1.0.1/devkitpro-pacman.deb
sudo dpkg -i devkitpro-pacman.deb
sudo dkp-pacman -S devkitARM picasso tex3ds 3dstools devkit-env libctru citro3d citro2d 3ds-zlib 3ds-tinyxml2 3ds-mpg123 3ds-libpng --noconfirm
if [ "$TRAVIS_BRANCH" = "master" ]; then
    wget https://github.com/StuntHacks/m3diaLib/releases/download/v0.1.2-beta/build-v0.1.2-beta.zip -O build.zip
    mkdir m3d-build
    unzip build.zip -d m3d-build/
    cd m3d-build/
    sudo make install
    cd ..
fi
if [ "$TRAVIS_BRANCH" = "develop" ]; then
    git clone https://github.com/StuntHacks/m3diaLib
    cd m3diaLib
    git checkout develop
    make -C m3dialib/
    sudo make -C m3dialib/ install
    cd ..
fi
