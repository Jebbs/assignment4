#include "dvdtypes.h"

char DVDTypeToCode(DVDType type)
{
    switch(type)
    {
        case DVDType::ComedyDVD:
        {
            return 'F';
        }
        case DVDType::DramaDVD:
        {
            return 'D';
        }
        case DVDType::ClassicDVD:
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
            return DVDType::ComedyDVD;
        }
        case 'D':
        {
            return DVDType::DramaDVD;
        }
        case 'C':
        {
            return DVDType::ClassicDVD;
        }
        default:
        {
            return DVDType::None;
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
