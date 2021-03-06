/************************************************************************************************
 This program expects a voltage between 0 and 1.20V to be connected differentially to AIN3/AIN2.
 It will measure the voltage between AIN3 (pin 8) as - and AIN2 (pin 9) as + and send the
 measured voltage to the UART (115200 baud).
*************************************************************************************************/
// Bit Definitions
#define BIT0  0x01
#define BIT1  0x02
#define BIT2  0x04
#define BIT3  0x08
#define BIT4  0x10
#define BIT5  0x20
#define BIT6  0x40
#define BIT7  0x80
#define BIT8  0x100
#define BIT9  0x200
#define BIT10 0x400
#define BIT11 0x800
#define BIT12 0x1000
#define BIT13 0x2000
#define BIT14 0x4000
#define BIT15 0x8000
#define BIT16 0x10000
#define BIT20 0x100000
#define BIT22 0x400000
#define BIT24 0x1000000
#define BIT28 0x10000000
#define BIT30 0x40000000

#include<aduc7060.h>
# include "stdio.h"
# include "string.h"

void clearCapacitor(int duration);
void sendPacket(long whattosend);
void sendText(long whattosend);
void ADC0Init(void);						
void UARTInit(void);
void SendString(void);                  // Used to send strings to the UART
void delay(int);                        // Simple delay
void SystemZeroCalibration(void);       // Calibrate using external inputs
void SystemFullCalibration(void);
void fillBuf(void);                     // send a byte if there's one to send
void sendChar(char toSend);             // put a character into send buffer


// global variable declarations....
volatile unsigned char ucComRx = 0;            // variable that ComRx is read into in UART IRQ
volatile unsigned char bSendResultToUART = 0;  // Flag used to indicate ADC0 resutl ready to send to UART
unsigned char szTemp[64] = "";                 // Used to store ADC0 result before printing to UART
unsigned char ucTxBufferEmpty  = 0;            // Used to indicate that the UART Tx buffer is empty
unsigned char newADCdata;                      // Used to indicate that new ADC data is available
unsigned char ucWaitForUart = 0;               // Used to check that user has indicated that correct voltage was set
volatile long A2data = 0;                      // Variable that ADC0DAT is read into when reading from Analog Input 2
volatile unsigned long ulADC0_RTD = 0;         // Variable that ADC0DAT is read into, this is the ADC0 reading of the RTD
unsigned char ucADCInput;                      // Used to indicate what channel the ADC0 is sampling

unsigned char i = 0;
unsigned char nLen = 0;
signed int j = 0;
unsigned char sendBuf[512];  // serial output buffer
const int sendBufSize = 512; // serial output buffer size (for wrapping)
int sendBufIndex = 0;        // serial output buffer index used by sendChar
int sendBufUartIndex = 0;    // serial output buffer index used by UART IRQ handler

unsigned long threshold = 0x185000;  // ADC value above which indicates an event to record
// 0x1F0000 threshold corresponds to 154.6 millivolts at ADC input
int capacitorDuration = 5000;  // duration to clear capacitor (empirically 50000)
// 50000 duration corresponds to 53 milliseconds

int main(void)
{		
	POWKEY1 = 0x1;
	POWCON0 = 0x78;          // Set core to max CPU speed of 10.24Mhz
	POWKEY2 = 0xF4;
	UARTInit();              // Init UART
	ADC0Init();              // Init ADC0
	IRQEN = BIT11 + BIT10;   // Enable UART interrupt (BIT11) and ADC0 interrupt (BIT10)
	
	// bit 15 = ADC ON, 14:13 current source 00, 12 HIGHEXTREF, 11 AMP_CM, 10 unipolar, 9:6 input select,
	// bit 5:4 reference select, 3:0 PGA gain select 0000=gain of 1.  page 45 of PDF
	// ADC0CON = 0x8540 ;    //  ADC on, ADC2/ADC3 (differential mode), Int ref, gain = 1
	ADC0CON = BIT15 + BIT10 + BIT8 + BIT7 + BIT4 + BIT5;  //  ADC on/config, see page 45
	ADCMDE  = 0x81;          // ADCMDE bit 7 = fullpower, bits 2:0 = 001 continous conversion mode
	
	GP0DAT |= BIT28;  // MAKE P0.4 AN OUTPUT (page 102)
	// GP0DAT |= BIT20;  // turn on P0.4 (pin 25) Note that this pin is inverted
	GP0DAT &= 0xFFEFFFFF;  // turn OFF BIT20 P0.4 (pin 25)

	while (1)
	{
		A2data = ADC0DAT;	// Read ADC0 instant approximation
//		while (newADCdata == 0); // wait until new ADC data is available		
//		newADCdata = 0;  // Indicate that data has been read
		if (A2data >= threshold) {
//			clearCapacitor(capacitorDuration);  // FOR TESTING			
//			delay(400000);  // FOR TESTING
			while (newADCdata == 0); // wait until new ADC data is available
			newADCdata = 0;  // Indicate that data has been read

//			sendText(A2data);  // send data in text hexadecimal format via serials
			sendPacket(A2data);  // send three-byte A2data packet via serial
			clearCapacitor(capacitorDuration);  // clear capacitor for (duration) counts and return
//		  while (newADCdata == 0);		// wait for ADC to go back down
			} // if (A2data >= threshold)
		}  // while (1)
	} // main(void)


void clearCapacitor(int duration) {
	GP0DAT |= BIT20;  // turn on P0.4 (pin 25)
	delay(duration);
	GP0DAT &= 0xFFEFFFFF;  // turn OFF BIT20 P0.4 (pin 25)	
//	GP0DAT ^= BIT20;  // toggle off P0.4 (pin 25)
}

void sendPacket(long whattosend)
{
				sendChar(0x80 | (whattosend >> 17));  // send 128 plus MS7B
				sendChar((whattosend >> 10) & 0x7F);  // send next 7 bits
				sendChar((whattosend >> 3) & 0x7F);		// send next 7 bits (3 thrown away)
//     12345678 12345678 12345678  entire 24 bit ADC return
//		 -------- -------- -1234567  shifted right 17 bits
//     -------- --123456 78123456  shifted right 10 bits
//		 ---12345 67812345 67812345  shifted right 3 bits			
}	

void sendText(long whattosend)
{
			sprintf((char*)szTemp, "x%07.7LX\r\n",whattosend );  // pad left with zeroes, 6 width, 6 precision, Long Double, HEX
			nLen = strlen((char*)szTemp);
			if (nLen <64)	for ( i = 0 ; i < nLen ; i++ ) sendChar(szTemp[i]);;
      delay(1000); // breather
}

void ADC0Init()
{
	ADCMSKI = BIT0;						// Enable ADC0 result ready interrupt source
  // ADCFLT = 0xFF1F;					// Chop on, Averaging, AF=63, SF=31, 4Hz					
//	ADCFLT = BIT14;  // Bit 14 = RAVG2 running average /2, sample rate = 8kHz
	ADCFLT = 22;  //		Sinc3 factor of 64, chop off, ravg2 off
	
	ADCORCR = 3;
 	ADCCFG = 0;
	//ADC0CON = 0x8145;					// For system calibration set the gain that will be used
										// for measurements to ensure the best calibration is achieved,
										// In this case gain is 32 therefore Full Scale is 0.0375v
	//SystemZeroCalibration();			// For best results use a system zero scale calibration 
	//SystemFullCalibration();			// and a system full calibration instead of the self calibrations
										// AIN -ne has to be biased using the DAC
	ADC0CON = BIT10 + BIT15;	    	// Gain = 1, Unipolar, enable ADC0, Int Reference
	ADCMDE  = 0x94;						// Offest Self Calibration
  	while((ADCSTA & BIT15) == BIT15){}	// Wait for Calibration routine to complete
	ADCMDE  = 0x95;						// Gain Self Calibration
  	while((ADCSTA & BIT15) == BIT15){}	// Wait for Calibration routine to complete
}
void UARTInit()
{
// Initialize the UART for 9600-8-N
	GP1CON = 0x11;  			// Select UART functionality for P1.0/P1.1
	COMCON0 = 0x80;				// Enable access to COMDIV registers
	// baud rate = 320000 / ( DL * (M + (N / 2048)))
	// 9600 baud => DL = 0x21, M = 1, N = 21
	// 19200 baud => DL = 0x10, M = 1, N = 85
	// 115200 baud => DL = 0x02, M = 1, N = 796
	COMDIV0 = 0x02;				// DL low byte (Divisor Latch)
	COMDIV1 = 0x00;				// DL high byte (Divisor Latch)
	// COMDIV2 Bit 15 = Fractional Baud enable, bits 12:11 is M (00=4), bits 10:0 = N (page 80)
	// COMDIV2 = BIT15 + BIT11 + 21;	  // 9600 baud if COMDIV = 0x21
	// COMDIV2 = BIT15 + BIT11 + 85;	  // 19200 baud if COMDIV = 0x10
	COMDIV2 = BIT15 + BIT11 + 796;	  // 115200 baud if COMDIV = 0x02
	
	COMCON0 = BIT0 + BIT1 + BIT2;	// 8 data bits 2 stop bits
	COMIEN0 = BIT0 + BIT1;	 	// Enable UART interrupts when Rx full and Tx buffer empty.	
}
void SendString (void)
{
   	for ( i = 0 ; i < nLen ; i++ ) sendChar(szTemp[i]);
}
void sendChar(char toSend)
{
	if (((sendBufIndex + 1) % sendBufSize) == sendBufUartIndex) return;  // buffer is full
	sendBuf[sendBufIndex++] = toSend;  // put the char in the buffer and ++ the index
	sendBufIndex %= sendBufSize; // wrap buffer index if needed
	if (0x020==(COMSTA0 & 0x020)) fillBuf();  //if we can, send it now.
}
void fillBuf() {  // send a byte if there's one to send
			if (sendBufUartIndex == sendBufIndex) return;  // nothing to send
				COMTX = sendBuf[sendBufUartIndex++];  // send the next char and ++ the index
				sendBufUartIndex %= sendBufSize; // wrap buffer index if needed
}
void IRQ_Handler(void) __irq
{
	volatile unsigned long IRQSTATUS = IRQSTA;	   					// Read off IRQSTA register
	if ((IRQSTATUS & BIT11) == BIT11)		//UART interrupt source
	{
	  unsigned char ucCOMIID0 = COMIID0;  // read serial port status register
		//if ((ucCOMIID0 & 0x2) == 0x2)	  	// Transmit buffer is empty
		if (0x020==(COMSTA0 & 0x020))
		fillBuf();  // send a byte if there's one to send
		if ((ucCOMIID0 & 0x4) == 0x4)	  			// A byte has been received
		{
			ucComRx	= COMRX;
			ucWaitForUart = 0;
		} 	
	}

	if ((IRQSTATUS & BIT10) == BIT10)		//If ADC0 interrupt source
		{
		A2data = ADC0DAT;	// Read ADC0 conversion result
		newADCdata = 1;
  	}
	}

// Simple Delay routine
void delay (int length)
{
	while (length >0)
    	length--;
}

void SystemZeroCalibration(void)
{
	
	ucWaitForUart = 1;
	sprintf ( (char*)szTemp, "Set Zero Scale Voltage - Press return when ready \r\n");                         
	nLen = strlen((char*)szTemp);
 	if (nLen <64)
		 	SendString();
	while (ucWaitForUart == 1)
	{}
	ADCMDE	= 0x96;							// ADC System Zero scale calibration
	while ((ADCSTA & BIT15) != BIT15)		// bit 15 set by adc when calibration is complete
	{}
}
void SystemFullCalibration(void)
{
	ucWaitForUart = 1;
	sprintf ( (char*)szTemp, "Set Full Scale Voltage (0.0375) - Press return when ready \r\n");                         
	nLen = strlen((char*)szTemp);
 	if (nLen <64)
		 	SendString();
	while (ucWaitForUart == 1)
	{}
	ADCMDE	= 0x97;							// ADC System Full scale calibration
	while ((ADCSTA & BIT15) != BIT15)		// bit 15 set by adc when calibration is complete
	{}
}

