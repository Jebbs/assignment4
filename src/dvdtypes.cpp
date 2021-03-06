#include "dvdtypes.h"

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

DVDType codeToDVDType(char code)
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

std::string intToDVDType(int code)
{
    switch(code)
    {
        case 0:
        {
            return "DVD Comedy ";
        }
        case 1:
        {
            return "DVD Drama  ";
        }
        case 2:
        {
            return "DVD Classic";
        }
        default:
        {
            return "None";
        }
    }
}
