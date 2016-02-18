/* ['Common headers' begin (DON'T REMOVE THIS LINE!)] */
#include "fsm.h"
/* ['Common headers' end (DON'T REMOVE THIS LINE!)] */
#include "prj_cfg.h"
#include "prj_dre.h"
#include "prj_pinout.h"

/* ['ledCycle' begin (DON'T REMOVE THIS LINE!)] */
void ledCycle(  )
{
    /* set initial state */
    static STATE_T state = ID_LEDCYCLE_INITIAL;

    switch( state )
    {
        /* State ID: ID_LEDCYCLE_INITIAL */
        case ID_LEDCYCLE_INITIAL:
        {
            /* Transition ID: ID_LEDCYCLE_TRANSITION_CONNECTION */
            /* Actions: */
            /* ['<global>::led1off' begin] */
            dre.leds[0]=false;
            /* ['<global>::led1off' end] */
            /* ['<global>::led2off' begin] */
            dre.leds[1]=false;
            /* ['<global>::led2off' end] */
            /* ['<global>::led3off' begin] */
            dre.leds[2]=false;
            /* ['<global>::led3off' end] */
            /* ['<global>::led4off' begin] */
            dre.leds[3]=false;
            /* ['<global>::led4off' end] */
            state = ID_LEDCYCLE_OFF;
            break;
        }
        /* State ID: ID_LEDCYCLE_OFF */
        case ID_LEDCYCLE_OFF:
        {
            if( (dre.ledCycle==true && dre.ledCycleTime>0) )
            {
                /* Transition ID: ID_LEDCYCLE_TRANSITION_CONNECTION */
                /* Actions: */
                /* ['<global>::led1on' begin] */
                dre.leds[0]=true;
                /* ['<global>::led1on' end] */
                /* ['<global>::ledCycleTimeReset' begin] */
                dre.ledCycleTime=dre.ledCyclePeriod;
                /* ['<global>::ledCycleTimeReset' end] */
                state = ID_LEDCYCLE_LED1;
            }
            break;
        }
        /* State ID: ID_LEDCYCLE_LED1 */
        case ID_LEDCYCLE_LED1:
        {
            if( (dre.ledCycle==true && dre.ledCycleTime>0) )
            {
                /* Transition ID: ID_LEDCYCLE_TRANSITION_CONNECTION */
                /* Actions: */
                /* ['<global>::ledCycleTimerIncr' begin] */
                dre.ledCycleTime--;
                /*
                Serial.print("cycle ");
                Serial.print(dre.ledCycleTime);
                Serial.print(" period ");
                Serial.println(dre.ledCyclePeriod);
                */
                /* ['<global>::ledCycleTimerIncr' end] */
            }
            else if( (dre.ledCycleTime<=0 && dre.ledCycle==true) )
            {
                /* Transition ID: ID_LEDCYCLE_TRANSITION_CONNECTION */
                /* Actions: */
                /* ['<global>::led1off' begin] */
                dre.leds[0]=false;
                /* ['<global>::led1off' end] */
                /* ['<global>::led2on' begin] */
                dre.leds[1]=true;
                /* ['<global>::led2on' end] */
                /* ['<global>::ledCycleTimeReset' begin] */
                dre.ledCycleTime=dre.ledCyclePeriod;
                /* ['<global>::ledCycleTimeReset' end] */
                state = ID_LEDCYCLE_LED2;
            }
            else if( dre.ledCycle==false )
            {
                /* Transition ID: ID_LEDCYCLE_TRANSITION_CONNECTION */
                /* Actions: */
                /* ['<global>::led1off' begin] */
                dre.leds[0]=false;
                /* ['<global>::led1off' end] */
                state = ID_LEDCYCLE_OFF;
            }
            break;
        }
        /* State ID: ID_LEDCYCLE_LED2 */
        case ID_LEDCYCLE_LED2:
        {
            if( dre.ledCycle==false )
            {
                /* Transition ID: ID_LEDCYCLE_TRANSITION_CONNECTION */
                /* Actions: */
                /* ['<global>::led2off' begin] */
                dre.leds[1]=false;
                /* ['<global>::led2off' end] */
                state = ID_LEDCYCLE_OFF;
            }
            else if( (dre.ledCycle==true && dre.ledCycleTime>0) )
            {
                /* Transition ID: ID_LEDCYCLE_TRANSITION_CONNECTION */
                /* Actions: */
                /* ['<global>::ledCycleTimerIncr' begin] */
                dre.ledCycleTime--;
                /*
                Serial.print("cycle ");
                Serial.print(dre.ledCycleTime);
                Serial.print(" period ");
                Serial.println(dre.ledCyclePeriod);
                */
                /* ['<global>::ledCycleTimerIncr' end] */
            }
            else if( (dre.ledCycleTime<=0 && dre.ledCycle==true) )
            {
                /* Transition ID: ID_LEDCYCLE_TRANSITION_CONNECTION */
                /* Actions: */
                /* ['<global>::led2off' begin] */
                dre.leds[1]=false;
                /* ['<global>::led2off' end] */
                /* ['<global>::led3on' begin] */
                dre.leds[2]=true;
                /* ['<global>::led3on' end] */
                /* ['<global>::ledCycleTimeReset' begin] */
                dre.ledCycleTime=dre.ledCyclePeriod;
                /* ['<global>::ledCycleTimeReset' end] */
                state = ID_LEDCYCLE_LED3;
            }
            break;
        }
        /* State ID: ID_LEDCYCLE_LED3 */
        case ID_LEDCYCLE_LED3:
        {
            if( dre.ledCycle==false )
            {
                /* Transition ID: ID_LEDCYCLE_TRANSITION_CONNECTION */
                /* Actions: */
                /* ['<global>::led3off' begin] */
                dre.leds[2]=false;
                /* ['<global>::led3off' end] */
                state = ID_LEDCYCLE_OFF;
            }
            else if( (dre.ledCycleTime<=0 && dre.ledCycle==true) )
            {
                /* Transition ID: ID_LEDCYCLE_TRANSITION_CONNECTION */
                /* Actions: */
                /* ['<global>::led3off' begin] */
                dre.leds[2]=false;
                /* ['<global>::led3off' end] */
                /* ['<global>::led4on' begin] */
                dre.leds[3]=true;
                /* ['<global>::led4on' end] */
                /* ['<global>::ledCycleTimeReset' begin] */
                dre.ledCycleTime=dre.ledCyclePeriod;
                /* ['<global>::ledCycleTimeReset' end] */
                state = ID_LEDCYCLE_LED4;
            }
            else if( (dre.ledCycle==true && dre.ledCycleTime>0) )
            {
                /* Transition ID: ID_LEDCYCLE_TRANSITION_CONNECTION */
                /* Actions: */
                /* ['<global>::ledCycleTimerIncr' begin] */
                dre.ledCycleTime--;
                /*
                Serial.print("cycle ");
                Serial.print(dre.ledCycleTime);
                Serial.print(" period ");
                Serial.println(dre.ledCyclePeriod);
                */
                /* ['<global>::ledCycleTimerIncr' end] */
            }
            break;
        }
        /* State ID: ID_LEDCYCLE_LED4 */
        case ID_LEDCYCLE_LED4:
        {
            if( (dre.ledCycle==true && dre.ledCycleTime>0) )
            {
                /* Transition ID: ID_LEDCYCLE_TRANSITION_CONNECTION */
                /* Actions: */
                /* ['<global>::ledCycleTimerIncr' begin] */
                dre.ledCycleTime--;
                /*
                Serial.print("cycle ");
                Serial.print(dre.ledCycleTime);
                Serial.print(" period ");
                Serial.println(dre.ledCyclePeriod);
                */
                /* ['<global>::ledCycleTimerIncr' end] */
            }
            else if( (dre.ledCycleTime<=0 && dre.ledCycle==true) )
            {
                /* Transition ID: ID_LEDCYCLE_TRANSITION_CONNECTION */
                /* Actions: */
                /* ['<global>::led4off' begin] */
                dre.leds[3]=false;
                /* ['<global>::led4off' end] */
                /* ['<global>::led1on' begin] */
                dre.leds[0]=true;
                /* ['<global>::led1on' end] */
                /* ['<global>::ledCycleTimeReset' begin] */
                dre.ledCycleTime=dre.ledCyclePeriod;
                /* ['<global>::ledCycleTimeReset' end] */
                /* ['<global>::cycleCountIncr' begin] */
                dre.cycleCount++;
                Serial.print("ciclos: ");
                Serial.println(dre.cycleCount);
                /* ['<global>::cycleCountIncr' end] */
                state = ID_LEDCYCLE_LED1;
            }
            else if( dre.ledCycle==false )
            {
                /* Transition ID: ID_LEDCYCLE_TRANSITION_CONNECTION */
                /* Actions: */
                /* ['<global>::led4off' begin] */
                dre.leds[3]=false;
                /* ['<global>::led4off' end] */
                state = ID_LEDCYCLE_OFF;
            }
            break;
        }
    }
}
/* ['ledCycle' end (DON'T REMOVE THIS LINE!)] */

/* ['dispatcher' begin (DON'T REMOVE THIS LINE!)] */
void dispatcher(  )
{
    /* set initial state */
    static STATE_T state = ID_DISPATCHER_INITIAL;

    switch( state )
    {
        /* State ID: ID_DISPATCHER_INITIAL */
        case ID_DISPATCHER_INITIAL:
        {
            /* Transition ID: ID_DISPATCHER_TRANSITION_CONNECTION */
            /* Actions: */
            /* ['<global>::setCycleNormal' begin] */
            dre.ledCycle=true;
            
            /* Numero de ciclos a hacer */
            dre.cycleCountLimit=CFG_CYCLECOUNT_LIMIT_NORMAL;  
            dre.cycleCount=0;
            
            /* Periodo de cada led */
            dre.ledCyclePeriod=(CFG_LEDCYCLEPERIOD_MS/(CYCLE_TIME_IN_MICROS/1000));
            dre.ledCycleTime=dre.ledCyclePeriod;
            
            /* Orden de los leds */
            dre.ledAssign[0]=CFG_LED1_PIN;
            dre.ledAssign[1]=CFG_LED2_PIN;
            dre.ledAssign[2]=CFG_LED3_PIN;
            dre.ledAssign[3]=CFG_LED4_PIN;
            /* ['<global>::setCycleNormal' end] */
            state = ID_DISPATCHER_NORMAL;
            break;
        }
        /* State ID: ID_DISPATCHER_NORMAL */
        case ID_DISPATCHER_NORMAL:
        {
            if( ((dre.cycleCount>=dre.cycleCountLimit) && (dre.contVueltas<CFG_CONTVUELTAS_LIMIT)) )
            {
                /* Transition ID: ID_DISPATCHER_TRANSITION_CONNECTION */
                /* Actions: */
                /* ['<global>::setCycleFast' begin] */
                dre.ledCycle=true;
                
                /* Numero de ciclos a hacer */
                dre.cycleCountLimit=CFG_CYCLECOUNT_LIMIT_FAST;  
                dre.cycleCount=0;
                
                /* Periodo de cada led */
                dre.ledCyclePeriod=(CFG_LEDCYCLEFASTPERIOD_MS/(CYCLE_TIME_IN_MICROS/1000));
                dre.ledCycleTime=dre.ledCyclePeriod;
                
                /* Orden de los leds */
                dre.ledAssign[0]=CFG_LED1_PIN;
                dre.ledAssign[1]=CFG_LED2_PIN;
                dre.ledAssign[2]=CFG_LED3_PIN;
                dre.ledAssign[3]=CFG_LED4_PIN;
                /* ['<global>::setCycleFast' end] */
                /* ['<global>::resetVueltasCounter' begin] */
                dre.contVueltas=0;
                Serial.println("Reset cuentas");
                /* ['<global>::resetVueltasCounter' end] */
                state = ID_DISPATCHER_R_PIDO;
            }
            break;
        }
        /* State ID: ID_DISPATCHER_R_PIDO */
        case ID_DISPATCHER_R_PIDO:
        {
            if( ((dre.cycleCount>=dre.cycleCountLimit) && (dre.contVueltas<CFG_CONTVUELTAS_LIMIT)) )
            {
                /* Transition ID: ID_DISPATCHER_TRANSITION_CONNECTION */
                /* Actions: */
                /* ['<global>::led4off' begin] */
                dre.leds[3]=false;
                /* ['<global>::led4off' end] */
                /* ['<global>::led1off' begin] */
                dre.leds[0]=false;
                /* ['<global>::led1off' end] */
                /* ['<global>::setCycleVuelta' begin] */
                dre.ledCycle=true;
                
                /* Numero de ciclos a hacer */
                dre.cycleCountLimit=1;
                dre.cycleCount=0;
                
                /* Periodo de cada led */
                dre.ledCyclePeriod=(CFG_LEDCYCLEFASTPERIOD_MS/(CYCLE_TIME_IN_MICROS/1000));
                dre.ledCycleTime=dre.ledCyclePeriod;
                
                /* Orden de los leds */
                dre.ledAssign[0]=CFG_LED4_PIN;
                dre.ledAssign[1]=CFG_LED3_PIN;
                dre.ledAssign[2]=CFG_LED2_PIN;
                dre.ledAssign[3]=CFG_LED1_PIN;
                /* ['<global>::setCycleVuelta' end] */
                state = ID_DISPATCHER_VUELTA;
            }
            else if( dre.contVueltas>=CFG_CONTVUELTAS_LIMIT )
            {
                /* Transition ID: ID_DISPATCHER_TRANSITION_CONNECTION */
                /* Actions: */
                /* ['<global>::resetWaitTimer' begin] */
                dre.waitTime=0;
                dre.waitTimeLimit=(CFG_WAIT_TIME_MS/(CYCLE_TIME_IN_MICROS/1000));
                /* ['<global>::resetWaitTimer' end] */
                /* ['<global>::stopLedCycle' begin] */
                dre.ledCycle=false;
                /* ['<global>::stopLedCycle' end] */
                state = ID_DISPATCHER_ESPERAR;
            }
            break;
        }
        /* State ID: ID_DISPATCHER_VUELTA */
        case ID_DISPATCHER_VUELTA:
        {
            if( ((dre.cycleCount>=dre.cycleCountLimit) && (dre.contVueltas<CFG_CONTVUELTAS_LIMIT)) )
            {
                /* Transition ID: ID_DISPATCHER_TRANSITION_CONNECTION */
                /* Actions: */
                /* ['<global>::led1off' begin] */
                dre.leds[0]=false;
                /* ['<global>::led1off' end] */
                /* ['<global>::led4off' begin] */
                dre.leds[3]=false;
                /* ['<global>::led4off' end] */
                /* ['<global>::setCycleIda' begin] */
                dre.ledCycle=true;
                
                /* Numero de ciclos a hacer */
                dre.cycleCountLimit=1;
                dre.cycleCount=0;
                
                /* Periodo de cada led */
                dre.ledCyclePeriod=(CFG_LEDCYCLEFASTPERIOD_MS/(CYCLE_TIME_IN_MICROS/1000));
                dre.ledCycleTime=dre.ledCyclePeriod;
                
                /* Orden de los leds */
                dre.ledAssign[0]=CFG_LED1_PIN;
                dre.ledAssign[1]=CFG_LED2_PIN;
                dre.ledAssign[2]=CFG_LED3_PIN;
                dre.ledAssign[3]=CFG_LED4_PIN;
                /* ['<global>::setCycleIda' end] */
                /* ['<global>::incrContadorVueltas' begin] */
                dre.contVueltas++;
                Serial.print("vueltas: ");
                Serial.println(dre.contVueltas);
                /* ['<global>::incrContadorVueltas' end] */
                state = ID_DISPATCHER_R_PIDO;
            }
            break;
        }
        /* State ID: ID_DISPATCHER_ESPERAR */
        case ID_DISPATCHER_ESPERAR:
        {
            if( (dre.waitTime<dre.waitTimeLimit) )
            {
                /* Transition ID: ID_DISPATCHER_TRANSITION_CONNECTION */
                /* Actions: */
                /* ['<global>::incrWaitTime' begin] */
                dre.waitTime++;
                /* ['<global>::incrWaitTime' end] */
            }
            else if( (dre.waitTime>=dre.waitTimeLimit) )
            {
                /* Transition ID: ID_DISPATCHER_TRANSITION_CONNECTION */
                /* Actions: */
                /* ['<global>::led1on' begin] */
                dre.leds[0]=true;
                /* ['<global>::led1on' end] */
                /* ['<global>::setCycleNormal' begin] */
                dre.ledCycle=true;
                
                /* Numero de ciclos a hacer */
                dre.cycleCountLimit=CFG_CYCLECOUNT_LIMIT_NORMAL;  
                dre.cycleCount=0;
                
                /* Periodo de cada led */
                dre.ledCyclePeriod=(CFG_LEDCYCLEPERIOD_MS/(CYCLE_TIME_IN_MICROS/1000));
                dre.ledCycleTime=dre.ledCyclePeriod;
                
                /* Orden de los leds */
                dre.ledAssign[0]=CFG_LED1_PIN;
                dre.ledAssign[1]=CFG_LED2_PIN;
                dre.ledAssign[2]=CFG_LED3_PIN;
                dre.ledAssign[3]=CFG_LED4_PIN;
                /* ['<global>::setCycleNormal' end] */
                /* ['<global>::resetVueltasCounter' begin] */
                dre.contVueltas=0;
                Serial.println("Reset cuentas");
                /* ['<global>::resetVueltasCounter' end] */
                state = ID_DISPATCHER_NORMAL;
            }
            break;
        }
    }
}
/* ['dispatcher' end (DON'T REMOVE THIS LINE!)] */

