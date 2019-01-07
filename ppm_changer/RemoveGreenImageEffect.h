/*

Assignment: RemoveGreenImageEffect.h
Description: This program removes green from the image. 
Author: Rachel Tidwell 
HSU ID: 9492-53949
*/



#pragma once
#include "ImageEffect.h"

#ifndef REMOVE_GREEN_IMAGE_EFFECT
#define REMOVE_GREEN_IMAGE_EFFECT

class RemoveGreenImageEffect : public ImageEffect
{
    virtual void processImage(PpmDocument &doc)
    {
         for (int i = 0; i < doc.getHeight(); i++)
        {
            for (int j = 0; j < doc.getWidth(); j++)
            {
                Pixel *p = &doc.getPixel(i, j);
                p->setGreen(0);
            }
        }
    }

};

#endif 





