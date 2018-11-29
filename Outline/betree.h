
/****************************************************************************/
/* DSA tree program example D.F.Ross                                        */
/****************************************************************************/
#ifndef BETREE_H
#define BETREE_H

/****************************************************************************/
/* function prototypes - operations on the AVL-Tree (a virtual machine)     */
/****************************************************************************/
void be_disp_2D();                  /* display AVL in 2 dimensions          */
void be_add(int v);                 /* add a node to the tree               */
void be_rem(int v);                 /* remove a node from the tree          */
int  be_is_memberb(int v);          /* find a node in the tree              */

void be_set_run_mode(int v);        /* toggle BE between demo/info mode     */
void be_set_bst_mode(int v);        /* toggle BE between AVL / BST mode     */

#endif
/****************************************************************************/
/* end of definitions                                                       */
/****************************************************************************/

