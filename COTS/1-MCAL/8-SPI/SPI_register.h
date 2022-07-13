/****************************************************************************/
/****************************************************************************/
/**** Author: Alaa Osama ****************************************************/
/**** Layer: MCAL ***********************************************************/
/**** SWC: Serial Peripheral Interface (SPI) ********************************/
/**** Version: 1.00 *********************************************************/
/**** Date: 29-6-2022 *******************************************************/
/****************************************************************************/
/****************************************************************************/

#ifndef SPI_REGISTER_H_
#define SPI_REGISTER_H_

#define SPCR          *((volatile u8*)0x2D)    /*SPI Control Register*/
#define SPCR_SPIE     7                        /*SPI interrupt enable*/
#define SPCR_SPE      6                        /*SPI Enable: when 1 the SPI is enabled*/
#define SPCR_DORD     5                        /*Data Order*/
#define SPCR_MSTR     4                        /*Master/slave select: '1': master SPI mode - '0': Slave SPI mode*/
#define SPCR_CPOL     3                        /*Clock Polarity: '1': SCK is high when idle - '0': SCK is low when idle*/
#define SPCR_CPHA     2                        /*Clock Phase: '0': sample in leading edge - '1': setup in leading edge*/
#define SPCR_SPR1     1                        /*SPI Clock Rate Select 1 and 0*/
#define SPCR_SPR0     0

#define SPSR          *((volatile u8*)0x2E)    /*SPI Status Register*/
#define SPSR_SPIF     7                        /*SPI interrupt flag*/
#define SPSR_WCOL     6                        /*Write COLision Flag*/
#define SPSR_SPI2X    0                        /*Double SPI Speed Bit*/

#endif