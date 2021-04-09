#include "rent.h"

/* used for creating/manipulating properties */

int generateRandomNum( int randomType ) {
	switch(randomType) {
		case RAN_BASE_DISTANCE :
			return ( rand() % ( 36 ) + 5 ) * 100;
		case RAN_STREET_ARRAY_INDEX :
			return rand() % ( 10 );
		case RAN_STREET_NUMBER :
			return rand() % ( 200 ) + 1;
		case RAN_BEDROOM_NUMBER :
			return rand() % ( 4 ) + 1;
		case RAN_RENT_P_BEDROOM_NUMBER :
			return ( rand() % ( 9 ) + 4 ) * 50;
		case RAN_COINFLIP :
			return rand() % ( 2 );
		default :
			return 0;
	}
}

void randomizeBaseDistance( Street *streetArray ) {
	int i;
	for ( i = 0; i < 10; i++ )
		streetArray[i].baseDistance = generateRandomNum ( RAN_BASE_DISTANCE );
}

void printProperties( Node *pHead ) {
	if ( pHead == NULL )
		return;
	else {
		printf("\nAddress\t\t\t\t\t# Rooms  Rent/Room   Distance\n--------------------------\t\t-------  ---------  ---------\n");
		Node *pNode = pHead;
		while ( pNode != NULL ) {
			printf ( "%3d %-36s%7d %10d %7.2f km\n", pNode->pRental->nStreet, pNode->pRental->pStreet->streetName, pNode->pRental->nBedrooms, pNode->pRental->nRentPerBedroom, ( float ) ( calculateDistance ( pNode ) ) / 1000 );
			pNode = pNode->pNext;
		}
	}
}

void printProperty( Node *pHead ) {
	if ( pHead == NULL )
		return;
	else
		printf( "\nwhat do you think of this property?\n" );
		printf( "\tAddr: %d %s, # Rooms: %d, Rent/Room: $%d, Distance: %.2f km\n", pHead->pRental->nStreet, pHead->pRental->pStreet->streetName, pHead->pRental->nBedrooms, pHead->pRental->nRentPerBedroom, ( float ) ( calculateDistance ( pHead ) ) / 1000 );
}

int calculateDistance( Node * pNode ) {
	return ( pNode->pRental->pStreet->baseDistance + ( pNode->pRental->nStreet * 20 ) );
}

RentalProperty *createRentalProperty( Street *streetArray ) {
	RentalProperty *pRental = calloc( 1, sizeof ( RentalProperty ) );
	pRental->pStreet = &streetArray[ generateRandomNum ( RAN_STREET_ARRAY_INDEX ) ];
	pRental->nStreet = generateRandomNum ( RAN_STREET_NUMBER );
	pRental->nBedrooms = generateRandomNum ( RAN_BEDROOM_NUMBER );
	pRental->nRentPerBedroom = generateRandomNum ( RAN_RENT_P_BEDROOM_NUMBER );
	return pRental;
}

void destroyRentalProperty( RentalProperty *rentalProperty ) {
	free( rentalProperty );
}