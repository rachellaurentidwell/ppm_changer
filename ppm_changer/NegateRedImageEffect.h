
/*

Assignment: NegateRedImageEffect.h 
Description: This program negates red from the picture. 
Author: Rachel Tidwell 
HSU ID: 9492-53949
*/

#pragma once
#include "ImageEffect.h"
#ifndef NEGATE_RED_IMAGE_EFFECT
#define NEGATE_RED_IMAGE_EFFECT 




class NegateRedImageEffect : public ImageEffect
{
    virtual void processImage(PpmDocument &doc)
    {
         for (int i = 0; i < doc.getHeight(); i++)
        {
            for (int j = 0; j < doc.getWidth(); j++)
            {
                Pixel *p = &doc.getPixel(i, j);
                p->setRed(255- p->getRed());
            }
        }
    }

};


#endif 
