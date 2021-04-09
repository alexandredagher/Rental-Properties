/* used for creating/manipulating nodes */

typedef struct Node {
	RentalProperty *pRental;
	struct Node *pNext;
} Node;

extern int findLengthOfList( Node *pHead );
extern void appendNode( Node **ppHead, Node *pNewNode );
extern Node *createNode( RentalProperty *pRental );
extern void destroyNode( Node *pNode );
extern int getLengthOfList( Node *pHead );
extern Node *getNodeAtIndex( Node *pHead, int index );
extern Node *removeNodeAtIndex( Node **ppHead, int index );