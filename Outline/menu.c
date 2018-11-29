
/****************************************************************************/
/* DSA Example program - Donald F. Ross                                     */
/****************************************************************************/

/****************************************************************************/
/* include files and  global data objects                                   */
/****************************************************************************/
#include <stdio.h>
#include <string.h>
#include "betree.h"

#define   NAMELEN  30
#define   MAXLNC   80        /* max number of input line chars*/
#define   MAXLN    MAXLNC+1  /* max size of input line buffer */

#define   DEBUG    0         /* DEBUG ON/OFF                  */

/****************************************************************************/
/* define types                                                             */
/****************************************************************************/

/****************************************************************************/
/* global data objects                                                      */
/****************************************************************************/

static char       lnbuff[MAXLN];                    /* input line buffer    */
static int        echomode=1;                       /* echo mode on/off     */
static int        infomode=0;                       /* 0=demo 1=info mode   */
static int        bstmode =0;                       /* 0=AVL  1=BST mode    */

/*****************************************************************************/
/*  get_choice: get user input from keyboard (1 character)                   */
/*****************************************************************************/
static char get_choice() { scanf("%s", lnbuff); return(lnbuff[0]); }

/****************************************************************************/
/* here - a debugging function                                              */
/****************************************************************************/
static void here(char * msg) { if (DEBUG) printf("\n *** In %s ", msg); }

/****************************************************************************/
/* User dialog function                                                     */
/****************************************************************************/
static int dialog() {

  int i;

  printf(" Enter a value:  ");
  scanf("%d", &i);
  if (echomode) printf(" %d\n", i);
  return i;
  }

/****************************************************************************/
/* UI functions                                                             */
/****************************************************************************/
void ui_is_member() {
  if (be_is_memberb(dialog())) printf("\n *** Found!");
  else printf("\n *** Not found!");
  }
  
/****************************************************************************/
/* set run mode function                                                    */
/****************************************************************************/
static void set_run_mode() {
  infomode = infomode == 0 ? 1 : 0;   be_set_run_mode(infomode);
  if (infomode) printf("\n *** In Info Mode *** ");
  else          printf("\n *** In Demo Mode *** ");
  }

/****************************************************************************/
/* set avl mode function                                                    */
/****************************************************************************/
static void set_bst_mode() {
  bstmode = bstmode == 0 ? 1 : 0;   be_set_bst_mode(bstmode);
  if (bstmode) printf("\n *** In BST Mode *** ");
  else         printf("\n *** In AVL Mode *** ");
  }

/*****************************************************************************/
/*  dispmenu: display the user menu                                          */
/*****************************************************************************/
static void dispmenu()
{
   here( " IN  dispmenu() ");

   printf("\n");
   printf("***************************************************************\n");
   printf("***                                                         ***\n");
   printf("***   m:   display this menu                                ***\n");
   printf("***   t:   display the tree (2D)                            ***\n");
   printf("***                                                         ***\n");
   printf("***   a:   add a value to the tree                          ***\n");
   printf("***   r:   remove a value from the tree                     ***\n");
   printf("***   f:   find a value in the tree                         ***\n");
   printf("***                                                         ***\n");
   printf("***   q:   quit the program                                 ***\n");
   printf("***                                                         ***\n");
   printf("***************************************************************\n");
   printf("\n");

   here( " OUT dispmenu() ");
   }

/****************************************************************************/
/*  runmenu: execute the user menu                                          */
/****************************************************************************/
void runmenu()

{
   char   choice;                     /* user menu selection  */

   here( " IN  runmenu() ");
   dispmenu();
   do {
      printf("\n Enter choice => "); choice = get_choice();
      if (echomode) printf(" %c \n", choice);
      switch(choice) {
        
         /************************************************************/
         /* "hidden" options                                         */
         /************************************************************/
         case 'z': case 'Z': echomode=1;                        break;
         case '+':           set_run_mode();                    break;
         case '-':           set_bst_mode();                    break;
         /************************************************************/
         /* "public" options - shown in the menu text                */
         /************************************************************/
         case 'm': case 'M': dispmenu();                        break;
         case 't': case 'T': be_disp_2D();                      break;
         case 'a': case 'A': be_add(dialog());                  break;
         case 'r': case 'R': be_rem(dialog());                  break;
         case 'f': case 'F': ui_is_member();                    break;
         case 'q': case 'Q': printf(" *** BYE BYE! ***");       break;

         default:  printf("\n INVALID MENU CHOICE ***\n");
                   dispmenu();                                  break;
         }
      } while (choice != 'Q' && choice != 'q');
      printf("\n");
      here( " OUT runmenu() ");
   }
/****************************************************************************/
/* end of menu functions                                                    */
/****************************************************************************/

