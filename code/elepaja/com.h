/*
 * source.h
 *
 *  Created on: 10 Dec 2016
 *      Author: Reaktor Space Lab
 */

#ifndef COM_H_
#define COM_H_
#include <stdint.h>
//
#define SPI_CTL0_SEQUENCE UCCKPL + UCMSB + UCMST + UCSYNC
#define SPI_CTL1_SEQUENCE UCSSEL1
#define SPI_CLOCKRATE 0x31F //

#define SPI_SELECT_TX() {P1SEL |= BIT1; P1SEL &= ~BIT1;}
#define SPI_SELECT_RX() {P1SEL |= BIT2; P1SEL &= ~BIT2;}
#define SPI_SELECT_CLK() {P1SEL |= BIT3; P1SEL &= ~BIT3;}
#define SPI_SELECT_CS() P1DIR |= BIT4

#define SPI_RESET_USCI() UCA0CTL1 |= UCSWRST
#define SPI_RELEASE_USCI() UCA0CTL1 &= ~UCSWRST

#define SPI_TRANSMIT UCA0TXBUF
#define SPI_RECEIVE UCA0RXBUF

#define SPI_CS_HIGH() P1OUT |= BIT4
#define SPI_CS_LOW() P1OUT &= ~BIT4

#define SPI_SETUP_USCI() {UCA0CTL0 |= SPI_CTL0_SEQUENCE; UCA0CTL1 |= SPI_CTL1_SEQUENCE;}
#define SPI_SETUP_BAUDRATE() UCA0BR0 |= SPI_CLOCKRATE

void setup_spi();
void transfer_packet(uint8_t *, uint8_t *, uint8_t);

#endif /* COM_H_ */
