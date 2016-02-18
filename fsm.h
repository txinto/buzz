/* ['Common headers' begin (DON'T REMOVE THIS LINE!)] */
#include "fsmCI.h"
/* ['Common headers' end (DON'T REMOVE THIS LINE!)] */

/* ['ledCycle' begin (DON'T REMOVE THIS LINE!)] */
/* State IDs */
#define ID_LEDCYCLE_INITIAL 5
#define ID_LEDCYCLE_OFF 6
#define ID_LEDCYCLE_LED1 7
#define ID_LEDCYCLE_LED2 8
#define ID_LEDCYCLE_LED4 9
#define ID_LEDCYCLE_LED3 10

void ledCycle(  );
/* ['ledCycle' end (DON'T REMOVE THIS LINE!)] */

/* ['ledCycle3' begin (DON'T REMOVE THIS LINE!)] */
/* State IDs */
#define ID_LEDCYCLE3_INITIAL 0
#define ID_LEDCYCLE3_OFF 1
#define ID_LEDCYCLE3_LED1 2
#define ID_LEDCYCLE3_LED2 3
#define ID_LEDCYCLE3_LED4 4
#define ID_LEDCYCLE3_LED3 5

void ledCycle3(  );
/* ['ledCycle3' end (DON'T REMOVE THIS LINE!)] */

/* ['ledCycle2' begin (DON'T REMOVE THIS LINE!)] */
/* State IDs */
#define ID_LEDCYCLE2_INITIAL 12
#define ID_LEDCYCLE2_OFF 13
#define ID_LEDCYCLE2_LED1 14
#define ID_LEDCYCLE2_LED2 15
#define ID_LEDCYCLE2_LED4 16
#define ID_LEDCYCLE2_LED3 17

void ledCycle2(  );
/* ['ledCycle2' end (DON'T REMOVE THIS LINE!)] */

/* ['dispatcher' begin (DON'T REMOVE THIS LINE!)] */
/* State IDs */
#define ID_DISPATCHER_INITIAL 0
#define ID_DISPATCHER_NORMAL 1
#define ID_DISPATCHER_R_PIDO 2
#define ID_DISPATCHER_VUELTA 3
#define ID_DISPATCHER_ESPERAR 4

void dispatcher(  );
/* ['dispatcher' end (DON'T REMOVE THIS LINE!)] */

