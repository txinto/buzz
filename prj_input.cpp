/* This file perform the acquisition tasks of the inputs of the system */

/* Inclusion of the basic types of the GTTC osek */
#include "gttc_types.h"
/* Configuration of the project */
#include "prj_cfg.h"
/* Inclusion of its own header */
#include "prj_input.h"
/* Inclusion of the pinout information */
#include "prj_pinout.h"
/* Inclusion of the DRE */
#include "prj_dre.h"
/* Inclusion of the arduino methods */
#include "Arduino.h"


/* Initialization of the input routines.
WARNING: The pinout initialization is not done here.  
It is done in the prj_pinout.c file */
void prjInputInit(void) {

}

/* Routine to read all the inputs in the system 
EXCEPTION: The inputs coming through an I/O bus can be acquired in another module.*/
void prjInput(void) {

 
}


















































