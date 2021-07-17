/**
 * Clean the following code
 */
#include "includeall.h"
#include "test.h"


/**
 * MotorStatus is
 * - true if Motor is healthy
 * - false if Motor is faulty
 *           
 * Additionally this is an interface provided to the other software components which would like to know 
 * Motor failure status
 * So basically an extern of this is present in a header file
 */ 
boolean MotorStatus;


/**
 * This task runs every 1msec.
 */  

void Task_MotorActuation(void)
{
    boolean v1low , v2low;
    float v1, v2;
    v1 = Motor_phase_1_Voltage();
    v2 = Motor_phase_2_Voltage();
    
    /* voltage should not be lower than 3.2 */    
    if(v1 < 3.2 )
    {
        v1low = TRUE;
    }
    /* voltage should not be lower than 3.2 */
    if(v2 < 3.2 )
    {
        v2low = TRUE;
    }
    
    /* if both the voltage are low then there is some problem with the motor */
    MotorStatus =  !(v1low&&v2low)
}



