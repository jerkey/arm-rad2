
/* Interrupt Controller */

unsigned int INTBASE __attribute__((section(".sfr_INTBASE")));
unsigned int IRQSTA __attribute__((section(".sfr_IRQSTA")));
unsigned int IRQSIG __attribute__((section(".sfr_IRQSIG")));
unsigned int IRQEN __attribute__((section(".sfr_IRQEN")));
unsigned int IRQCLR __attribute__((section(".sfr_IRQCLR")));
unsigned int SWICFG __attribute__((section(".sfr_SWICFG")));
unsigned int IRQBASE __attribute__((section(".sfr_IRQBASE")));
unsigned int IRQVEC __attribute__((section(".sfr_IRQVEC")));
unsigned int IRQP0 __attribute__((section(".sfr_IRQP0")));
unsigned int IRQP1 __attribute__((section(".sfr_IRQP1")));
unsigned int IRQP2 __attribute__((section(".sfr_IRQP2")));
unsigned int IRQP3 __attribute__((section(".sfr_IRQP3")));
unsigned int IRQCONN __attribute__((section(".sfr_IRQCONN")));
unsigned int IRQCONE __attribute__((section(".sfr_IRQCONE")));
unsigned int IRQCLRE __attribute__((section(".sfr_IRQCLRE")));
unsigned int IRQSTAN __attribute__((section(".sfr_IRQSTAN")));
unsigned int FIQSTA __attribute__((section(".sfr_FIQSTA")));
unsigned int FIQSIG __attribute__((section(".sfr_FIQSIG")));
unsigned int FIQEN __attribute__((section(".sfr_FIQEN")));
unsigned int FIQCLR __attribute__((section(".sfr_FIQCLR")));
unsigned int FIQVEC __attribute__((section(".sfr_FIQVEC")));
unsigned int FIQSTAN __attribute__((section(".sfr_FIQSTAN")));

unsigned int REMAPBASE __attribute__((section(".sfr_REMAPBASE")));
unsigned int REMAP __attribute__((section(".sfr_REMAP")));
unsigned int RSTSTA __attribute__((section(".sfr_RSTSTA")));
unsigned int RSTCLR __attribute__((section(".sfr_RSTCLR")));

/* TIMER 0 */

unsigned int T0BASE __attribute__((section(".sfr_T0BASE")));
unsigned int T0LD __attribute__((section(".sfr_T0LD")));
unsigned int T0VAL __attribute__((section(".sfr_T0VAL")));
unsigned int T0CON __attribute__((section(".sfr_T0CON")));
unsigned int T0CLRI __attribute__((section(".sfr_T0CLRI")));
unsigned int T0CAP __attribute__((section(".sfr_T0CAP")));

/* WAKE UP TIMER */

unsigned int T1BASE __attribute__((section(".sfr_T1BASE")));
unsigned int T1LD __attribute__((section(".sfr_T1LD")));
unsigned int T1VAL __attribute__((section(".sfr_T1VAL")));
unsigned int T1CON __attribute__((section(".sfr_T1CON")));
unsigned int T1CLRI __attribute__((section(".sfr_T1CLRI")));

/* WATCHDOG TIMER */

unsigned int T2BASE __attribute__((section(".sfr_T2BASE")));
unsigned int T2LD __attribute__((section(".sfr_T2LD")));
unsigned int T2VAL __attribute__((section(".sfr_T2VAL")));
unsigned int T2CON __attribute__((section(".sfr_T2CON")));
unsigned int T2CLRI __attribute__((section(".sfr_T2CLRI")));
unsigned int T2RCFG __attribute__((section(".sfr_T2RCFG")));

/* TIMER 3 */

unsigned int T3BASE __attribute__((section(".sfr_T3BASE")));
unsigned int T3LD __attribute__((section(".sfr_T3LD")));
unsigned int T3VAL __attribute__((section(".sfr_T3VAL")));
unsigned int T3CON __attribute__((section(".sfr_T3CON")));
unsigned int T3CLRI __attribute__((section(".sfr_T3CLRI")));
unsigned int T3CAP __attribute__((section(".sfr_T3CAP")));

/* PLL AND OSCILLATOR CONTROL */

unsigned int PLLBASE __attribute__((section(".sfr_PLLBASE")));
unsigned int PLLSTA __attribute__((section(".sfr_PLLSTA")));
unsigned int POWKEY1 __attribute__((section(".sfr_POWKEY1")));
unsigned int POWCON0 __attribute__((section(".sfr_POWCON0")));
unsigned int POWKEY2 __attribute__((section(".sfr_POWKEY2")));
unsigned int PLLKEY1 __attribute__((section(".sfr_PLLKEY1")));
unsigned int PLLCON __attribute__((section(".sfr_PLLCON")));
unsigned int PLLKEY2 __attribute__((section(".sfr_PLLKEY2")));
unsigned int POWKEY3 __attribute__((section(".sfr_POWKEY3")));
unsigned int POWCON1 __attribute__((section(".sfr_POWCON1")));
unsigned int POWKEY4 __attribute__((section(".sfr_POWKEY4")));
unsigned int GP0KEY1 __attribute__((section(".sfr_GP0KEY1")));
unsigned int GP0CON1 __attribute__((section(".sfr_GP0CON1")));
unsigned int GP0KEY2 __attribute__((section(".sfr_GP0KEY2")));

/* ADC INTERFACE REGISTERS */

unsigned int ADCBASE __attribute__((section(".sfr_ADCBASE")));
unsigned int ADCSTA __attribute__((section(".sfr_ADCSTA")));
unsigned int ADCMSKI __attribute__((section(".sfr_ADCMSKI")));
unsigned int ADCMDE __attribute__((section(".sfr_ADCMDE")));
unsigned int ADC0CON __attribute__((section(".sfr_ADC0CON")));
unsigned int ADC1CON __attribute__((section(".sfr_ADC1CON")));
unsigned int ADCFLT __attribute__((section(".sfr_ADCFLT")));
unsigned int ADCCFG __attribute__((section(".sfr_ADCCFG")));
unsigned int ADC0DAT __attribute__((section(".sfr_ADC0DAT")));
unsigned int ADC1DAT __attribute__((section(".sfr_ADC1DAT")));
unsigned int ADC0OF __attribute__((section(".sfr_ADC0OF")));
unsigned int ADC1OF __attribute__((section(".sfr_ADC1OF")));
unsigned int ADC0GN __attribute__((section(".sfr_ADC0GN")));
unsigned int ADC1GN __attribute__((section(".sfr_ADC1GN")));
unsigned int ADCORCR __attribute__((section(".sfr_ADCORCR")));
unsigned int ADCORCV __attribute__((section(".sfr_ADCORCV")));
unsigned int ADCOTH __attribute__((section(".sfr_ADCOTH")));
unsigned int ADCOTHC __attribute__((section(".sfr_ADCOTHC")));
unsigned int ADCOTHV __attribute__((section(".sfr_ADCOTHV")));
unsigned int ADCOACC __attribute__((section(".sfr_ADCOACC")));
unsigned int ADCOATH __attribute__((section(".sfr_ADCOATH")));
unsigned int IEXCON __attribute__((section(".sfr_IEXCON")));

/* DAC INTERFACE REGISTERS */

unsigned int DACBASE __attribute__((section(".sfr_DACBASE")));
unsigned int DACCON __attribute__((section(".sfr_DACCON")));
unsigned int DACDAT __attribute__((section(".sfr_DACDAT")));

/* 450 COMPATIABLE UART CORE REGISTERS */

unsigned int UARTBASE __attribute__((section(".sfr_UARTBASE")));
unsigned int COMTX __attribute__((section(".sfr_COMTX")));
unsigned int COMRX __attribute__((section(".sfr_COMRX")));
unsigned int COMDIV0 __attribute__((section(".sfr_COMDIV0")));
unsigned int COMIEN0 __attribute__((section(".sfr_COMIEN0")));
unsigned int COMDIV1 __attribute__((section(".sfr_COMDIV1")));
unsigned int COMIID0 __attribute__((section(".sfr_COMIID0")));
unsigned int COMCON0 __attribute__((section(".sfr_COMCON0")));
unsigned int COMCON1 __attribute__((section(".sfr_COMCON1")));
unsigned int COMSTA0 __attribute__((section(".sfr_COMSTA0")));
unsigned int COMSTA1 __attribute__((section(".sfr_COMSTA1")));
unsigned int COMSCR __attribute__((section(".sfr_COMSCR")));
unsigned int COMDIV2 __attribute__((section(".sfr_COMDIV2")));

/* I2C BUS PERIPHERAL DEVICE  */

unsigned int I2CBASE __attribute__((section(".sfr_I2CBASE")));
unsigned int I2CMCON __attribute__((section(".sfr_I2CMCON")));
unsigned int I2CMSTA __attribute__((section(".sfr_I2CMSTA")));
unsigned int I2CMRX __attribute__((section(".sfr_I2CMRX")));
unsigned int I2CMTX __attribute__((section(".sfr_I2CMTX")));
unsigned int I2CMCNT0 __attribute__((section(".sfr_I2CMCNT0")));
unsigned int I2CMCNT1 __attribute__((section(".sfr_I2CMCNT1")));
unsigned int I2CADR0 __attribute__((section(".sfr_I2CADR0")));
unsigned int I2CADR1 __attribute__((section(".sfr_I2CADR1")));
unsigned int I2CREP __attribute__((section(".sfr_I2CREP")));
unsigned int I2CDIV __attribute__((section(".sfr_I2CDIV")));
unsigned int I2CSCON __attribute__((section(".sfr_I2CSCON")));
unsigned int I2CSSTA __attribute__((section(".sfr_I2CSSTA")));
unsigned int I2CSRX __attribute__((section(".sfr_I2CSRX")));
unsigned int I2CSTX __attribute__((section(".sfr_I2CSTX")));
unsigned int I2CALT __attribute__((section(".sfr_I2CALT")));
unsigned int I2CID0 __attribute__((section(".sfr_I2CID0")));
unsigned int I2CID1 __attribute__((section(".sfr_I2CID1")));
unsigned int I2CID2 __attribute__((section(".sfr_I2CID2")));
unsigned int I2CID3 __attribute__((section(".sfr_I2CID3")));
unsigned int I2CFSTA __attribute__((section(".sfr_I2CFSTA")));
unsigned int I2CRCON __attribute__((section(".sfr_I2CRCON")));

/* SERIAL PORT INTERFACE PERIPHERAL */

unsigned int SPIBASE __attribute__((section(".sfr_SPIBASE")));
unsigned int SPISTA __attribute__((section(".sfr_SPISTA")));
unsigned int SPIRX __attribute__((section(".sfr_SPIRX")));
unsigned int SPITX __attribute__((section(".sfr_SPITX")));
unsigned int SPIDIV __attribute__((section(".sfr_SPIDIV")));
unsigned int SPICON __attribute__((section(".sfr_SPICON")));

/* GPIO AND SERIAL PORT MUX */

unsigned int GPIOBASE __attribute__((section(".sfr_GPIOBASE")));
unsigned int GP0CON0 __attribute__((section(".sfr_GP0CON0")));
unsigned int GP1CON __attribute__((section(".sfr_GP1CON")));
unsigned int GP2CON __attribute__((section(".sfr_GP2CON")));
unsigned int GP0DAT __attribute__((section(".sfr_GP0DAT")));
unsigned int GP0SET __attribute__((section(".sfr_GP0SET")));
unsigned int GP0CLR __attribute__((section(".sfr_GP0CLR")));
unsigned int GP0PAR __attribute__((section(".sfr_GP0PAR")));
unsigned int GP1DAT __attribute__((section(".sfr_GP1DAT")));
unsigned int GP1SET __attribute__((section(".sfr_GP1SET")));
unsigned int GP1CLR __attribute__((section(".sfr_GP1CLR")));
unsigned int GP1PAR __attribute__((section(".sfr_GP1PAR")));
unsigned int GP2DAT __attribute__((section(".sfr_GP2DAT")));
unsigned int GP2SET __attribute__((section(".sfr_GP2SET")));
unsigned int GP2CLR __attribute__((section(".sfr_GP2CLR")));
unsigned int GP2PAR __attribute__((section(".sfr_GP2PAR")));

/* FLASH CONTROL INTERFACE */

unsigned int FLASHBASE __attribute__((section(".sfr_FLASHBASE")));
unsigned int FEESTA __attribute__((section(".sfr_FEESTA")));
unsigned int FEEMOD __attribute__((section(".sfr_FEEMOD")));
unsigned int FEECON __attribute__((section(".sfr_FEECON")));
unsigned int FEEDAT __attribute__((section(".sfr_FEEDAT")));
unsigned int FEEADR __attribute__((section(".sfr_FEEADR")));
unsigned int FEESIGN __attribute__((section(".sfr_FEESIGN")));
unsigned int FEEPRO __attribute__((section(".sfr_FEEPRO")));
unsigned int FEEHIDE __attribute__((section(".sfr_FEEHIDE")));

/* PWM */

unsigned int PWMBASE __attribute__((section(".sfr_PWMBASE")));
unsigned int PWMCON __attribute__((section(".sfr_PWMCON")));
unsigned int PWM0COM0 __attribute__((section(".sfr_PWM0COM0")));
unsigned int PWM0COM1 __attribute__((section(".sfr_PWM0COM1")));
unsigned int PWM0COM2 __attribute__((section(".sfr_PWM0COM2")));
unsigned int PWM0LEN __attribute__((section(".sfr_PWM0LEN")));
unsigned int PWM1COM0 __attribute__((section(".sfr_PWM1COM0")));
unsigned int PWM1COM1 __attribute__((section(".sfr_PWM1COM1")));
unsigned int PWM1COM2 __attribute__((section(".sfr_PWM1COM2")));
unsigned int PWM1LEN __attribute__((section(".sfr_PWM1LEN")));
unsigned int PWM2COM0 __attribute__((section(".sfr_PWM2COM0")));
unsigned int PWM2COM1 __attribute__((section(".sfr_PWM2COM1")));
unsigned int PWM2COM2 __attribute__((section(".sfr_PWM2COM2")));
unsigned int PWM2LEN __attribute__((section(".sfr_PWM2LEN")));
unsigned int PWMCLRI __attribute__((section(".sfr_PWMCLRI")));

