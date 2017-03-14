/*******************************************************************************
 * DVDTypes
 *
 * Authors: 
 * Chantel Frizzell, Jeremy DeHaan
 *
 * Date Last Modified: 
 * 2017-03-13
 * 
 * DVDTypes sets the int associated with the type
 ******************************************************************************/
#ifndef DVDTYPES_H
#define DVDTYPES_H

#include <string>

enum DVDType
{
    None = -1,
    ComedyDVD = 0,
    DramaDVD = 1,
    ClassicDVD = 2
};

char DVDTypeToCode(DVDType type);

DVDType codeToDVDType(char code);

std::string intToDVDType(int code);

#endif //DVDTYPES_H