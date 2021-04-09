#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define RAN_BASE_DISTANCE 0
#define RAN_STREET_ARRAY_INDEX 1
#define RAN_STREET_NUMBER 2
#define RAN_BEDROOM_NUMBER 3
#define RAN_RENT_P_BEDROOM_NUMBER 4
#define RAN_COINFLIP 5

/* used for creating and manipulating properties */

typedef struct {
	char streetName[18];
	int baseDistance;
} Street;

typedef struct {
	Street *pStreet;
	int nStreet;
	int nBedrooms;
	int nRentPerBedroom;
} RentalProperty;

#include "node.h"
#include "sort.h"

extern int generateRandomNum( int randomType );
extern void randomizeBaseDistance( Street *pStreetArray );
extern void printProperties( Node *pHead );
extern void printProperty( Node *pHead );
extern RentalProperty *createRentalProperty( Street *streetArray );
extern void destroyRentalProperty( RentalProperty *rentalProperty );
extern int calculateDistance( Node * pNode );