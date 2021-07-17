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
 * ON- #. Switch shall only stay in ON state for 5msec. This unit shall reset state to None
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
     * 
     * 
     *                                    +----------15msec-------+-5msec--+ 
     *          +---5msec----+---5msec----+-----------------------+--------+-----------+
     *          a            b            c                       c'       d            
     * 
     *  a. A new On request is recieved.
     *  b. Task_5msec shall set the request to NoRequest and shall make sure IsOnReqToSwitchPossible()
     *     returns FALSE.
     *  c. Task_5msec shall wait for 15mSec. For all the 15mSec duration IsOnReqToSwitchPossible()
     *     should return FALSE.
     *  c`. At c` Task_5msec shall make sure IsOnReqToSwitchPossible() returns TRUE hinting
     *      it is possible switch ON the switch again.
     *  d. (just a marker in the graph.)
     * 
     */      
}
