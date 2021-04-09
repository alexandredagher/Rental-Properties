#include "rent.h"
/* used for creating/manipulating nodes */


void appendNode( Node **ppHead, Node *pNewNode ) {
	if ( *ppHead == NULL ) {
		*ppHead = pNewNode;
	} else {
		Node *pNode = *ppHead;
		while ( pNode->pNext != NULL ) {
			pNode = pNode->pNext;
		}
		pNode->pNext = pNewNode;
	}
	pNewNode->pNext = NULL;
}

Node *createNode( RentalProperty *pRental ) {
	Node *pNode = calloc( 1, sizeof ( Node ) );
	pNode->pRental = pRental;
	pNode->pNext = NULL;
	return pNode;
}

void destroyNode( Node *pNode ) {
	destroyRentalProperty ( pNode->pRental );
	free ( pNode );
}

int getLengthOfList( Node *pHead ) {
	Node *pNode = pHead;
	int nNodes = 0;
	while ( pNode != NULL ) {
		pNode = pNode->pNext;
		nNodes++;
	}
	return nNodes;
}

Node *getNodeAtIndex( Node *pHead, int index ) {
	Node *pNode = pHead;
	int i = 0;
	if ( index == i)
		return pHead;
	while ( i != index ) {
		pNode = pNode->pNext;
		i++;
	}
	return pNode;
}

Node *removeNodeAtIndex( Node **ppHead, int index ) {
	Node *pNodeToDelete = NULL;
	if ( *ppHead == NULL )
		return pNodeToDelete;
	if ( (*ppHead)->pNext == NULL ) {
		pNodeToDelete = *ppHead;	
		*ppHead = NULL;
		pNodeToDelete->pNext = NULL;
	} else if ( index == 0 ) {
		pNodeToDelete = *ppHead;
		*ppHead = (*ppHead)->pNext;
		pNodeToDelete->pNext = NULL;
	} else {
		Node *pPrevNode = getNodeAtIndex( *ppHead, index-1 );
		pNodeToDelete = pPrevNode->pNext;
		if ( pNodeToDelete->pNext == NULL )
			pPrevNode->pNext = NULL;
		else 
			pPrevNode->pNext = pNodeToDelete->pNext;
	}
	return pNodeToDelete;
}