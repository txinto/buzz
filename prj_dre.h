/* Data Runtime Environment is a pool of global variables that can be shared through all the application.  It acts as a centralized data base for the functionality */

#ifndef _PRJ_DRE_H
#define _PRJ_DRE_H


/* Inclusion of the basic types of the GTTC osek */
#include "gttc_types.h"
/* Configuration of the project */
#include "prj_cfg.h"

/* This structure type contains the DRE global variables */
typedef struct {
  bool leds[4];
  uint8_t ledAssign[4];
  bool ledCycle;
  uint16_t ledCycleTime;
  uint16_t ledCyclePeriod;
  uint16_t cycleCount;
  uint16_t cycleCountLimit;
  uint16_t contVueltas;
  uint16_t waitTime;
  uint16_t waitTimeLimit;
} t_dre;

/* This declaration make the dre visible to all the project modules */
extern t_dre dre;

/* This function initializes the DRE contents to their default values */
void dreInit(void);

#endif // _PRJ_DRE_H
































