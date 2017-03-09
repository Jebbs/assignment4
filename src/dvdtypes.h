#ifndef DVDTYPES_H
#define DVDTYPES_H


enum DVDTypes
{
    None = -1,
    Comedy = 0,
    Drama,
    Classic
}

char DVDTypeToCode(DVDType type)
{
    switch(type)
    {
        case Comedy:
        {
            return 'F';
        }
        case Drama:
        {
            return 'D';
        }
        case Classic:
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
            return Comedy;
        }
        case 'D':
        {
            return Drama;
        }
        case 'C':
        {
            return Classic;
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
            return Comedy;
        }
        case 1:
        {
            return Drama;
        }
        case 2:
        {
            return Classic;
        }
        default:
        {
            return None;
        }
    }
}



#endif //DVDTYPES_H