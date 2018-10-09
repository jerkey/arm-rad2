
/* Interrupt Controller */

extern unsigned int INTBASE;
extern unsigned int IRQSTA;
extern unsigned int IRQSIG;
extern unsigned int IRQEN;
extern unsigned int IRQCLR;
extern unsigned int SWICFG;
extern unsigned int IRQBASE;
extern unsigned int IRQVEC;
extern unsigned int IRQP0;
extern unsigned int IRQP1;
extern unsigned int IRQP2;
extern unsigned int IRQP3;
extern unsigned int IRQCONN;
extern unsigned int IRQCONE;
extern unsigned int IRQCLRE;
extern unsigned int IRQSTAN;
extern unsigned int FIQSTA;
extern unsigned int FIQSIG;
extern unsigned int FIQEN;
extern unsigned int FIQCLR;
extern unsigned int FIQVEC;
extern unsigned int FIQSTAN;

extern unsigned int REMAPBASE;
extern unsigned int REMAP;
extern unsigned int RSTSTA;
extern unsigned int RSTCLR;

/* TIMER 0 */

extern unsigned int T0BASE;
extern unsigned int T0LD;
extern unsigned int T0VAL;
extern unsigned int T0CON;
extern unsigned int T0CLRI;
extern unsigned int T0CAP;

/* WAKE UP TIMER */

extern unsigned int T1BASE;
extern unsigned int T1LD;
extern unsigned int T1VAL;
extern unsigned int T1CON;
extern unsigned int T1CLRI;

/* WATCHDOG TIMER */

extern unsigned int T2BASE;
extern unsigned int T2LD;
extern unsigned int T2VAL;
extern unsigned int T2CON;
extern unsigned int T2CLRI;
extern unsigned int T2RCFG;

/* TIMER 3 */

extern unsigned int T3BASE;
extern unsigned int T3LD;
extern unsigned int T3VAL;
extern unsigned int T3CON;
extern unsigned int T3CLRI;
extern unsigned int T3CAP;

/* PLL AND OSCILLATOR CONTROL */

extern unsigned int PLLBASE;
extern unsigned int PLLSTA;
extern unsigned int POWKEY1;
extern unsigned int POWCON0;
extern unsigned int POWKEY2;
extern unsigned int PLLKEY1;
extern unsigned int PLLCON;
extern unsigned int PLLKEY2;
extern unsigned int POWKEY3;
extern unsigned int POWCON1;
extern unsigned int POWKEY4;
extern unsigned int GP0KEY1;
extern unsigned int GP0CON1;
extern unsigned int GP0KEY2;

/* ADC INTERFACE REGISTERS */

extern unsigned int ADCBASE;
extern unsigned int ADCSTA;
extern unsigned int ADCMSKI;
extern unsigned int ADCMDE;
extern unsigned int ADC0CON;
extern unsigned int ADC1CON;
extern unsigned int ADCFLT;
extern unsigned int ADCCFG;
extern unsigned int ADC0DAT;
extern unsigned int ADC1DAT;
extern unsigned int ADC0OF;
extern unsigned int ADC1OF;
extern unsigned int ADC0GN;
extern unsigned int ADC1GN;
extern unsigned int ADCORCR;
extern unsigned int ADCORCV;
extern unsigned int ADCOTH;
extern unsigned int ADCOTHC;
extern unsigned int ADCOTHV;
extern unsigned int ADCOACC;
extern unsigned int ADCOATH;
extern unsigned int IEXCON;

/* DAC INTERFACE REGISTERS */

extern unsigned int DACBASE;
extern unsigned int DACCON;
extern unsigned int DACDAT;

/* 450 COMPATIABLE UART CORE REGISTERS */

extern unsigned int UARTBASE;
extern unsigned int COMTX;
extern unsigned int COMRX;
extern unsigned int COMDIV0;
extern unsigned int COMIEN0;
extern unsigned int COMDIV1;
extern unsigned int COMIID0;
extern unsigned int COMCON0;
extern unsigned int COMCON1;
extern unsigned int COMSTA0;
extern unsigned int COMSTA1;
extern unsigned int COMSCR;
extern unsigned int COMDIV2;

/* I2C BUS PERIPHERAL DEVICE  */

extern unsigned int I2CBASE;
extern unsigned int I2CMCON;
extern unsigned int I2CMSTA;
extern unsigned int I2CMRX;
extern unsigned int I2CMTX;
extern unsigned int I2CMCNT0;
extern unsigned int I2CMCNT1;
extern unsigned int I2CADR0;
extern unsigned int I2CADR1;
extern unsigned int I2CREP;
extern unsigned int I2CDIV;
extern unsigned int I2CSCON;
extern unsigned int I2CSSTA;
extern unsigned int I2CSRX;
extern unsigned int I2CSTX;
extern unsigned int I2CALT;
extern unsigned int I2CID0;
extern unsigned int I2CID1;
extern unsigned int I2CID2;
extern unsigned int I2CID3;
extern unsigned int I2CFSTA;
extern unsigned int I2CRCON;

/* SERIAL PORT INTERFACE PERIPHERAL */

extern unsigned int SPIBASE;
extern unsigned int SPISTA;
extern unsigned int SPIRX;
extern unsigned int SPITX;
extern unsigned int SPIDIV;
extern unsigned int SPICON;

/* GPIO AND SERIAL PORT MUX */

extern unsigned int GPIOBASE;
extern unsigned int GP0CON0;
extern unsigned int GP1CON;
extern unsigned int GP2CON;
extern unsigned int GP0DAT;
extern unsigned int GP0SET;
extern unsigned int GP0CLR;
extern unsigned int GP0PAR;
extern unsigned int GP1DAT;
extern unsigned int GP1SET;
extern unsigned int GP1CLR;
extern unsigned int GP1PAR;
extern unsigned int GP2DAT;
extern unsigned int GP2SET;
extern unsigned int GP2CLR;
extern unsigned int GP2PAR;

/* FLASH CONTROL INTERFACE */

extern unsigned int FLASHBASE;
extern unsigned int FEESTA;
extern unsigned int FEEMOD;
extern unsigned int FEECON;
extern unsigned int FEEDAT;
extern unsigned int FEEADR;
extern unsigned int FEESIGN;
extern unsigned int FEEPRO;
extern unsigned int FEEHIDE;

/* PWM */

extern unsigned int PWMBASE;
extern unsigned int PWMCON;
extern unsigned int PWM0COM0;
extern unsigned int PWM0COM1;
extern unsigned int PWM0COM2;
extern unsigned int PWM0LEN;
extern unsigned int PWM1COM0;
extern unsigned int PWM1COM1;
extern unsigned int PWM1COM2;
extern unsigned int PWM1LEN;
extern unsigned int PWM2COM0;
extern unsigned int PWM2COM1;
extern unsigned int PWM2COM2;
extern unsigned int PWM2LEN;
extern unsigned int PWMCLRI;

