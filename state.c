#define SWITCH_GPIO_ADDRESS         (0X8000U)
#define GPIO_VALUE_HIGH             (0X01U)
#define GPIO_VALUE_LOW              (0X00U)

typedef struct {
    State_NoRequest,
    State_OFF,
    State_ON
}SwitchState_t;

/**
 * For those who use the below APIs
 * The following states can be requested to a Switch
 *  None
 *  ON
 *  OFF*
 * 
 * ON- #. Switch will only stay in ON state for 5msec. This unit will reset state to None
 *          after 5msec. The user need not worry about resetting.
 *      #. Before Requesting OFF to Switch one "must" check if it is possible
 *          using the API IsOFFReqToSwitchPossible().
 *      #. OFF shall be requested only  if the API IsOFFReqToSwitchPossible()
 *          returns "TRUE". if it returns "FALSE" one must wait until it returns "TRUE".
 */

void SetSwitchState(SwitchState_t Par_SwitchState)  /*Public API */
{
    switch(Par_SwitchState)
    {
        case State_OFF:        
            GPIO_Set_Vale(SWITCH_GPIO_ADDRESS,GPIO_VALUE_LOW);
        break;

        case State_ON:
            GPIO_Set_Vale(SWITCH_GPIO_ADDRESS,GPIO_VALUE_HIGH);
        break;

        default:
            GPIO_Set_Vale(SWITCH_GPIO_ADDRESS,GPIO_VALUE_LOW);
        break;
    }
}

boolean IsOnReqToSwitchPossible(void)  /*Public API */
{
    /* Complete it */
}


void Task_5mSec(void)
{
    /**
     * This task runs periodically every 5msec.
     * 1. After 5msec of ON request , the switch should be set to NoRequest
     * 2. After setting the switch to NoRequest another ON request is allowed only after 20mSec
     * 3. Only after completion of 20msec i.e., in 25thmsec a new On request should be allowed
     */
}
