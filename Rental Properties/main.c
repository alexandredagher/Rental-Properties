#include "rent.h"

/* declarations */
void createDefaultList( Node **ppHead, Street *pStreetArray );
void printHelp();
void displayAndQuery( Node *pHead, int i, char curList );

/* functions */
int main( void ) {

	/* init run setup */
	srand( time ( NULL ) );

	Street streetArray[] = {
		{ "Sussex Dr.", 0 },
		{ "Woodroffe Ave.", 0 },
		{ "Sparks St.", 0 },
		{ "Bank St.", 0 },
		{ "Eagleson Rd.", 0 },
		{ "Laurier Ave.", 0 },
		{ "University Ln.", 0 },
		{ "Somerset St.", 0 },
		{ "Rideau St.", 0 },
		{ "Montreal Rd.", 0 },
	};

	randomizeBaseDistance( streetArray );

	Node *pDefHead = NULL;
	Node *pFavHead = NULL;
	int (*pCompare)( Node *pNodeA, Node *pNodeB );
	int index = 0;
	char curList = 'd';

	createDefaultList( &pDefHead, streetArray );
	pCompare = &compareByRent;
	compareRentals( pDefHead, pCompare );
	displayAndQuery( pDefHead, index, curList );
	
	char buff[3];

	/* menu until end of session */
	while ( 1 ) {
		printf( "\nCommand ('h' for help): " );
		scanf("%3s%*[^\n]%*c", buff);
		/* print help */
		if ( strcmp ( "h", buff ) == 0 )
			printHelp();
		/* print all */
		else if ( strcmp ( "a", buff ) == 0 ) {
			pCompare = &compareByRent;
			if ( curList == 'd' && pDefHead == NULL )
				printf( "\nThere no more rental properties\n" );
			else if ( curList == 'f' && pFavHead == NULL )	
				printf( "\nYour favourites list is empty\n" );
			else if ( curList == 'd' ) {
				compareRentals( pDefHead, pCompare );
				displayAndQuery( pDefHead, index, curList );
			} else  {
				compareRentals( pFavHead, pCompare );
				displayAndQuery( pFavHead, index, curList );
			}
		/* go to favourites */
		} else if ( strcmp ( "f", buff ) == 0 ) {
			index = 0;
			curList = 'f';
			if ( pFavHead == NULL )
				printf( "\nYour favourites list is empty\n" );
			else {
				pCompare = &compareByRent;
				compareRentals( pFavHead, pCompare );
				displayAndQuery( pFavHead, index, curList );
			}
		}
		/* go to default */
		else if ( strcmp ( "d", buff ) == 0 ) {
			index = 0;
			curList = 'd';
			if ( generateRandomNum( RAN_COINFLIP ) == 0 )
				appendNode( &pDefHead, createNode( createRentalProperty( streetArray ) ) );
			displayAndQuery( pDefHead, index, curList );
		}
		/* delete property */
		else if ( strcmp ( "l", buff ) == 0 ) {
			if ( curList == 'd' && pDefHead == NULL )
				printf( "\nThere are no more rental properties\n" );
			else if ( curList == 'f' && pFavHead == NULL )
				printf( "\nYour favourites list is empty\n" );
			else if ( curList == 'd' && getLengthOfList(pDefHead) == 1 ) {
				destroyNode( removeNodeAtIndex( &pDefHead, index ) );
				printf( "\nRental property deleted\n" );
				printf( "\nThere are no more rental properties\n" );
				index = 0;
			} else if ( curList == 'd' ) {
				destroyNode( removeNodeAtIndex( &pDefHead, index ) );
				printf( "\nRental property deleted\n" );
				printProperty ( getNodeAtIndex( pDefHead, index ) );
			} else if ( curList == 'd' && getLengthOfList(pDefHead) == 1 ) {
				destroyNode( removeNodeAtIndex( &pFavHead, index ) );
				printf( "\nRental property deleted\n" );
				printProperty ( getNodeAtIndex( pFavHead, index ) );
			} else {
				destroyNode( removeNodeAtIndex( &pFavHead, index ) );
				printf( "\nRental property deleted\n" );
				printProperty ( getNodeAtIndex( pFavHead, index ) );
			}
		/* move property to favourites */
		} else if ( strcmp ( "r", buff ) == 0 ) {
			if ( curList == 'f' && pFavHead == NULL )
				printf( "\nYour favourites list is empty\n" );
			else if ( curList == 'f' )
				printf( "\nThis rental property is already on your favourites list\n" );
			else if ( pDefHead == NULL )
				printf( "\nThere are no more rental properties\n" );
			else {
				appendNode ( &pFavHead, removeNodeAtIndex( &pDefHead, index ) );
				printf( "\nRental property moved to your favourites list\n");
				if ( pDefHead == NULL ) {
					continue;
				}
				printProperty( getNodeAtIndex( pDefHead, index ) );
			}
		}
		/* skip a property */
		else if ( strcmp ( "n", buff ) == 0 ) {
			if ( curList == 'f' && pFavHead == NULL ) {
				printf( "\nYour favourites list is empty\n" );
				continue;
			}
			else if ( curList == 'd' && pDefHead == NULL ) {
				printf( "\nThere are no more rental properties\n" );
				continue;
			}
			else if ( curList == 'd' && index != getLengthOfList( pDefHead ) - 1 )
				index++;
			else if ( curList == 'f' && index != getLengthOfList( pFavHead ) - 1 )
				index++;
			else
				index = 0;
			if ( curList == 'f' )
				printProperty( getNodeAtIndex( pFavHead, index ) );
			else 
				printProperty( getNodeAtIndex( pDefHead, index ) );
		}
		/* end of sesion */
		else if ( strcmp ( "q", buff ) == 0 ) {
			break;
		}
		/* sort by address */
		else if ( strcmp ( "sa", buff ) == 0 ) {
			pCompare = &compareByAddress;
			if ( curList == 'd' ) {
				compareRentals( pDefHead, pCompare );
				displayAndQuery( pDefHead, index, curList );
			} else {
				compareRentals( pFavHead, pCompare );
				displayAndQuery( pFavHead, index, curList );	
			}
		}
		/* sort by number of rooms */
		else if ( strcmp ( "sn", buff ) == 0 ) {
			pCompare = &compareByRooms;
			if ( curList == 'd' ) {
				compareRentals( pDefHead, pCompare );
				displayAndQuery( pDefHead, index, curList );
			} else {
				compareRentals( pFavHead, pCompare );
				displayAndQuery( pFavHead, index, curList );	
			}
		}
		/* sort by rent */
		else if ( strcmp ( "sr", buff ) == 0 ) {
			pCompare = &compareByRent;
			if ( curList == 'd' ) {
				compareRentals( pDefHead, pCompare );
				displayAndQuery( pDefHead, index, curList );
			} else {
				compareRentals( pFavHead, pCompare );
				displayAndQuery( pFavHead, index, curList );	
			}
		}
		/* sort by distance */
		else if ( strcmp ( "sd", buff ) == 0 ) {
			pCompare = &compareByDistance;
			if ( curList == 'd' ) {
				compareRentals( pDefHead, pCompare );
				displayAndQuery( pDefHead, index, curList );
			} else {
				compareRentals( pFavHead, pCompare );
				displayAndQuery( pFavHead, index, curList );	
			}
		} else {
			printf("\nThat is not a supported command\n");
			printHelp();
		}
	}
}

void createDefaultList( Node **ppDefHead, Street *pStreetArray ) {
	int i;
	for (i = 0; i < 6; i++)
		appendNode( ppDefHead, createNode( createRentalProperty( pStreetArray ) ) );
}

void printHelp() {
	printf("\nValid commands are:\n"
			"\th  - display this help\n"
			"\ta  - display all the rental properties on the current list\n"
			"\tf  - switch to the favourites list\n"
			"\td  - switch to the default list\n"
			"\tl  - 'swipe left' on the current rental property\n"
			"\tr  - 'swipe right' on the current rental property\n"
			"\tn  - skip to the next rental property\n"
			"\tsa - set the sorting to 'by address'\n"
			"\tsn - set the sorting to 'by number of rooms'\n"
			"\tsr - set the sorting to 'by rent'\n"
			"\tsd - set the sorting to 'by distance'\n"
			 "\tq  - quit the program\n");
}

void displayAndQuery( Node *pHead, int index, char curList ) {
	if (pHead != NULL) {
		if ( curList == 'd' ) {
			printf("\nUndecided Rental Properties");
			printProperties( pHead );
			printProperty( getNodeAtIndex( pHead, index ) );
		} else {
			printf("\nFavourite Rental Properties");
			printProperties( pHead );
			printProperty( getNodeAtIndex( pHead, index ) );
		}		
	} else if ( pHead == NULL ) {
		if ( curList == 'd' )
			printf( "\nThere are no more rental properties\n" );
		else
			printf( "\nYour favourites list is empty\n" );
	}
}