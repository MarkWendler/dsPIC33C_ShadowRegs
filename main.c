/*
© [2023] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/
#include "mcc_generated_files/system/system.h"
#include "mcc_generated_files/system/interrupt_types.h"
#include "mcc_generated_files/timer/sccp1.h"
#include "mcc_generated_files/timer/sccp2.h"

/*
    Main application
*/
void handler(void){
    
    if( (CTXTSTATbits.CCTXI == 1) &&  //if context 1
             (INTTREGbits.ILR == 4) && // and if Current  interrupt priority level 4
            (IFS0bits.CCP1IF == 1)
            ){                          // and SCCP1 int happen
        // SCCP1 is assigned to level 4
        // level 4 ipl assigned to CCTX1
        // So we should come here
        Nop();
        Nop();
        
    }
    else if( (CTXTSTATbits.CCTXI == 2) &&  //if context 2
             (INTTREGbits.ILR == 5) && // and if Current  interrupt priority level 5
            (IFS1bits.CCP2IF == 1)
            ){                          // and SCCP2 int happen
        // SCCP2 is assigned to level 5
        // level 5 ipl assigned to CCTX2
        // So we should come here
        Nop();
        Nop();
        
    }
    else{
        //If we come here then contexts, interrupt levels and interrupts are assigned wrongly
        Nop();
        __builtin_software_breakpoint();
    }

    
}


int main(void)
{
    SYSTEM_Initialize();

    Timer_SCCP1_LVL4_CTXT1.TimeoutCallbackRegister(handler);
    Timer_SCCP2_LVL5_CTXT2.TimeoutCallbackRegister(handler);
    
    while(1)
    {
    }    
}