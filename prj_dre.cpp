/* Data Runtime Environment is a pool of global variables that can be shared through all the application.  It acts as a centralized data base for the functionality */

#include "gttc_types.h"
#include "prj_cfg.h"
#include "prj_dre.h"
#include "Arduino.h"
#include "gttc_timer.h"
#include "prj_pinout.h"

t_dre dre;

/* This function initializes the DRE contents to their default values */
void dreInit(void) {

  Serial.println("DRE Initialization");
  for (uint8_t cont=0;cont<CFG_NUMLEDS;cont++){
    dre.leds[cont]=false;
  }
  dre.ledCycle=true;
  dre.ledCyclePeriod=(CFG_LEDCYCLEPERIOD_MS/(CYCLE_TIME_IN_MICROS/1000));
  dre.ledCycleTime=dre.ledCyclePeriod;

  dre.contVueltas=0;
  dre.ledAssign[0]=CFG_LED1_PIN;
  dre.ledAssign[1]=CFG_LED2_PIN;
  dre.ledAssign[2]=CFG_LED3_PIN;
  dre.ledAssign[3]=CFG_LED4_PIN;
  
}





















