/* Inclusion of the basic types of the GTTC osek */
#include "gttc_types.h"
/* Configuration of the project */
#include "prj_cfg.h"
/* Inclusion of the DRE of the project */
#include "prj_dre.h"
/* Inclusion of its own header */
#include "prj_pinout.h"

/* Prepares the pinout for project use */
void pinoutInit(void){
  pinMode(CFG_LED1_PIN,OUTPUT);
  pinMode(CFG_LED2_PIN,OUTPUT);
  pinMode(CFG_LED3_PIN,OUTPUT);
  pinMode(CFG_LED4_PIN,OUTPUT);
}
















































