# dsPIC33C_ShadowRegs
Example usage of shadow registers with dsPIC33C MCUs

Set-up 2 timer interrupt SCCP1 and SCCP2.
        * SCCP2 is assigned to level 5
        * level 5 ipl assigned to CCTX2
        * SCCP1 is assigned to level 4
        * level 4 ipl assigned to CCTX1

## SW:
MPLAB X v6.10
MCC/Melody is used to generate basic firmware. https://www.microchip.com/en-us/tools-resources/configure/mplab-code-configurator

