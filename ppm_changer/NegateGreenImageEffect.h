/*

Assignment: NegateGreenImageEffect.h
Description: This program negates green from the picture
Author: Rachel Tidwell 
HSU ID: 9492-53949
*/

#pragma once
#include "ImageEffect.h"
#ifndef NEGATE_GREEN_IMAGE_EFFECT
#define NEGATE_GREEN_IMAGE_EFFECT 


class NegateGreenImageEffect : public ImageEffect
{
    virtual void processImage(PpmDocument &doc)
    {
         for (int i = 0; i < doc.getHeight(); i++)
        {
            for (int j = 0; j < doc.getWidth(); j++)
            {
                Pixel *p = &doc.getPixel(i, j);
                p->setGreen(255- p->getGreen());
            }
        }
    }

};


#endif 
