#pragma once
#include "PpmDocument.h"
class ImageEffect
{
public:
    virtual void processImage(PpmDocument &doc) = 0;
};