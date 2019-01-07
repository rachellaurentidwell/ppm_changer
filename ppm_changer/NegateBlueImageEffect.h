/*
Assignment: NegateBlueImageEffect.h
Description: This program negates blue from the picture
Author: Rachel Tidwell
HSU ID: 9492-53949
*/

#pragma once
#include "ImageEffect.h"
#ifndef NEGATE_BLUE_IMAGE_EFFECT
#define NEGATE_BLUE_IMAGE_EFFECT 


class NegateBlueImageEffect : public ImageEffect
{
    virtual void processImage(PpmDocument &doc)
    {
         for (int i = 0; i < doc.getHeight(); i++)
        {
            for (int j = 0; j < doc.getWidth(); j++)
            {

                //using pointers (preferred)
                Pixel *p = &doc.getPixel(i, j);
                 p->setBlue(255- p->getBlue());
            }
        }
    }

};


#endif //  NEGATE_BLUE_IMAGE_EFFECT 
