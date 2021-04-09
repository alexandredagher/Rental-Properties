/* extern definitions */

extern void compareRentals( Node *pHead, int (*pCompare)( Node *pNodeA, Node *pNodeB ) );
extern int compareByRent( Node *pNodeA, Node *pNodeB );
extern int compareByDistance( Node *pNodeA, Node *pNodeB );
extern int compareByRooms( Node *pNodeA, Node *pNodeB );
extern int compareByAddress( Node *pNodeA, Node *pNodeB );
extern void swapPayloadAddress( Node* pNodeA, Node* pNodeB );