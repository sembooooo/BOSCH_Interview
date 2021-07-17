/**
 * Modify this code using structs and function pointers
 */ 


boolean IsMainSupplyFailed,
    IsRedundantSupplyFailed,
    IsMainSupplyTestCompleted,
    IsRedundantSupplyTestCompleted;


boolean IsMainSupplyTestAllowedToRun(void)
{
    /**
     * some piece of code
     */ 
}

boolean IsRedundantSupplyTestAllowedToRun(void)
{
    /**
     * some piece of code
     */ 
}


void ExecuteMainSupplyTests(void)
{
    if(IsMainSupplyTestAllowedToRun() == TRUE)
    {
        /**
         * Some Test procedure is executed here
         */ 
        IsMainSupplyTestCompleted = TRUE;
    }
}
void ExecuteRedundantSupplyTests(void)
{
    if(IsRedundantSupplyTestAllowedToRun() == TRUE)
    {
        /**
         * Some Test procedure is executed here
         */ 
        IsRedundantSupplyTestCompleted = TRUE;
    }

}


void Task_SupplyTest(void)
{
    ExecuteMainSupplyTests();
    ExecuteRedundantSupplyTests();
}


