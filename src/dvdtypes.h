#ifndef DVDTYPES_H
#define DVDTYPES_H


enum DVDType
{
    None = -1,
    ComedyDVD = 0,
    DramaDVD,
    ClassicDVD
};

char DVDTypeToCode(DVDType type)
{
    switch(type)
    {
        case ComedyDVD:
        {
            return 'F';
        }
        case DramaDVD:
        {
            return 'D';
        }
        case ClassicDVD:
        {
            return 'C';
        }
        default:
        {
            return 0;
        }
    }
}

DVDType CodeToDVDType(char code)
{
    switch(code)
    {
        case 'F':
        {
            return ComedyDVD;
        }
        case 'D':
        {
            return DramaDVD;
        }
        case 'C':
        {
            return ClassicDVD;
        }
        default:
        {
            return None;
        }
    }
}

DVDType intToDVDType(int code)
{
    switch(code)
    {
        case 0:
        {
            return ComedyDVD;
        }
        case 1:
        {
            return DramaDVD;
        }
        case 2:
        {
            return ClassicDVD;
        }
        default:
        {
            return None;
        }
    }
}

#endif //DVDTYPES_H