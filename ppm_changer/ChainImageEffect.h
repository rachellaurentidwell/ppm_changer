
/*

Assignment: ChainImageEffect.h
Description: This program chains together the negate color effects. 
Author: Rachel Tidwell 
HSU ID: 9492-53949
*/



#pragma once
#include "ImageEffect.h"
#ifndef CHAIN_IMAGE_EFFECT
#define CHAIN_IMAGE_EFFECT 



 
class ChainImageEffect : public ImageEffect
{
    virtual void processImage(PpmDocument &doc)
    {
         for (int i = 0; i < doc.getHeight(); i++)
        {
            for (int j = 0; j < doc.getWidth(); j++)
            {
                 Pixel *p = &doc.getPixel(i, j);
                 p->setBlue(255- p->getBlue());
                 p->setRed(255 - p->getRed());
                 p->setGreen(255- p->getGreen());
            }
        }
    }

};


#endif  
