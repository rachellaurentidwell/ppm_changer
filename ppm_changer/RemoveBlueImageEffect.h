/*

Assignment: RemoveBlue.h 
Description: This program removes blue from the picture. 
Author: Rachel Tidwell 
HSU ID: 9492-53949
*/


#pragma once
#include "ImageEffect.h"

#ifndef REMOVE_BLUE_IMAGE_EFFECT
#define REMOVE_BLUE_IMAGE_EFFECT

//this image effect will remove all blue from a picture
class RemoveBlueImageEffect : public ImageEffect
{
    virtual void processImage(PpmDocument &doc)
    {
         for (int i = 0; i < doc.getHeight(); i++)
        {
            for (int j = 0; j < doc.getWidth(); j++)
            {
                Pixel *p = &doc.getPixel(i, j);
                p->setBlue(0);
            }
        }
    }

};

#endif 
