/*******************************************************************************
 * RentableType
 *
 * Authors: 
 * Jeremy DeHaan, Chantel Frizzell
 *
 * Date Last Modified: 
 * 2017-03-10
 * 
 * The RentableTypes class associates an integer with a type of rentable. 
 * A rentable type is anything that is rentable through the store. 
 ******************************************************************************/
#ifndef RENTABLETYPE_H
#define RENTABLETYPE_H

//All of the types of rentable items
enum RentableType
{
    DVD = 0,
    VHS,
    Music,
    Console,
    VideoGame,
    DVD_Player,
    Projector,
    NumberOfRentableTypes
};

#endif // RENTABLETYPE_H
