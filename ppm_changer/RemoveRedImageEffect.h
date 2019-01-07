#pragma once
#include "ImageEffect.h"

/*
Assignment: RemoveRedImageEffect.h
	Description : This program removes red from the image.
	Author : Rachel Tidwell
	HSU ID : 9492 - 53949
*/

class RemoveRedImageEffect : public ImageEffect
{
    virtual void processImage(PpmDocument &doc)
    {
        for (int i = 0; i < doc.getHeight(); i++)
        {
            for (int j = 0; j < doc.getWidth(); j++)
            {
                Pixel *p = &doc.getPixel(i, j);
                p->setRed(0);
            }
        }
    }

};
