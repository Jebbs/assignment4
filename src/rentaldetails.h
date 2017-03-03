#ifndef RENTALDETAILS_H
#define RENTALDETAILS_H


/*
 * RentalDetails describes the detail of something being rented.
 * That is, it will store, the rental data, what was rented, and how
 * many were rented.
 */
struct RentalDetails
{
public:
    Rentable rental;
    int rentDate;
}

#endif //RENTALDETAILS_H
