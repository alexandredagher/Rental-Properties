#include "rent.h"

/* used for sorting properties */

void compareRentals( Node *pHead, int (*pCompare)( Node *pNodeA, Node *pNodeB ) ) {
	if ( pHead == NULL || pHead->pNext == NULL )
		return;

	Node *pNodeA = pHead;
	Node *pNodeB;
	int cmp;

	while ( pNodeA != NULL && pNodeA->pNext != NULL ) {
		pNodeB = pNodeA->pNext;
		while ( pNodeB != NULL ) {
			cmp = (*pCompare) ( pNodeA, pNodeB );
			if (cmp > 0)
				swapPayloadAddress( pNodeA, pNodeB );
			pNodeB = pNodeB->pNext;
		}
		pNodeA = pNodeA->pNext;
	}
}

void swapPayloadAddress( Node* pNodeA, Node* pNodeB ) {
	RentalProperty *tmp = pNodeA->pRental;
	pNodeA->pRental = pNodeB->pRental;
	pNodeB->pRental = tmp;
}

int compareByRent( Node *pNodeA, Node *pNodeB ) {
	int cmp;
	cmp = pNodeA->pRental->nRentPerBedroom - pNodeB->pRental->nRentPerBedroom;
	if (cmp == 0)
		cmp = pNodeA->pRental->nBedrooms - pNodeB->pRental->nBedrooms;
	return cmp;
}

int compareByDistance( Node *pNodeA, Node *pNodeB ) {
	int cmp;
	cmp = calculateDistance ( pNodeA ) - calculateDistance ( pNodeB );
	if (cmp == 0)
		cmp = strcmp( pNodeA->pRental->pStreet->streetName, pNodeB->pRental->pStreet->streetName );
	if (cmp == 0)
		cmp = pNodeA->pRental->nStreet - pNodeB->pRental->nStreet;
	return cmp;
}

int compareByRooms( Node *pNodeA, Node *pNodeB ) {
	int cmp;
	cmp = pNodeA->pRental->nBedrooms - pNodeB->pRental->nBedrooms;
	if (cmp == 0)
		cmp = strcmp( pNodeA->pRental->pStreet->streetName, pNodeB->pRental->pStreet->streetName );
	if (cmp == 0)
		cmp = pNodeA->pRental->nStreet - pNodeB->pRental->nStreet;
	return cmp;
}

int compareByAddress( Node *pNodeA, Node *pNodeB ) {
	int cmp;
	cmp = strcmp( pNodeA->pRental->pStreet->streetName, pNodeB->pRental->pStreet->streetName );
	if (cmp == 0)
		cmp = pNodeA->pRental->nStreet - pNodeB->pRental->nStreet;
	return cmp;
}