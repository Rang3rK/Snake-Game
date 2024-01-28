//
// Created by Nu lar on 11/14/23.
//

#include "Font.h"

std::string Font::getPath(FontEnum font)
{
    switch(font)
    {
        case OPEN_SANS:
            return "Font/OpenSans-Bold.ttf";
        case ARIAL:
            return "Font/arial.ttf";
        case STARMONK:
            return "Font/STARMONK.TTF";
    }
}

void Font::loadFont(FontEnum font)
{
    fonts[font].loadFromFile(getPath(font));
}

//must return reference to avoid copying the font or else program will crash
sf::Font& Font::getFont(FontEnum font)
{
    loadFont(font);
    return fonts[font];
}