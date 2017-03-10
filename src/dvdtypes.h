#ifndef DVDTYPES_H
#define DVDTYPES_H

enum DVDType
{
    None = -1,
    ComedyDVD = 0,
    DramaDVD,
    ClassicDVD
};

char DVDTypeToCode(DVDType type);

DVDType codeToDVDType(char code);

DVDType intToDVDType(int code);

#endif //DVDTYPES_H