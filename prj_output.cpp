/* This file perform the synthesis tasks of the output of the system */

/* Inclusion of the basic types of the GTTC osek */
#include "gttc_types.h"
/* Configuration of the project */
#include "prj_cfg.h"
/* Inclusion of its own header */
#include "prj_output.h"
/* Inclusion of the pinout information */
#include "prj_pinout.h"
/* Inclusion of the DRE */
#include "prj_dre.h"
/* Inclusion of the arduino methods */
#include "Arduino.h"

/* Initialization of the output routines.
WARNING: The pinout initialization is not done here.  
It is done in the prj_pinout.c file */
void prjOutputInit(void) {

  
}

/* Routine to read all the outputs in the system 
EXCEPTION: The inputs coming through an I/O bus can be synthesized in another module.*/
void prjOutput(void) {
/*
#ifdef DEBUG_LED_WIRING
  for (uint8_t cont=0;cont<CFG_NUMLEDS;cont++){
    dre.leds[cont]=true;
  }
#endif  
#ifdef DEBUG_LED_FORCE_OFF
  for (uint8_t cont=0;cont<CFG_NUMLEDS;cont++){
    dre.leds[cont]=false;
  }
#endif  */
  for (uint8_t cont=0;cont<CFG_NUMLEDS;cont++){
    //Serial.print(cont);Serial.print(":");Serial.println(dre.leds[cont]);
    if (dre.leds[cont]){
      digitalWrite(dre.ledAssign[cont],LOW);
    } else {
      digitalWrite(dre.ledAssign[cont],HIGH);
    }
  }
}




















