/*
 * source.c
 *
 *  Created on: 10 Dec 2016
 *      Author: Reaktor Space Lab
 */
#include "com.h"

#include <stdint.h>
#include "main.h"

#if PLATFORM_MSP430
#include <msp430.h>
#elif PLATFORM_PSOC
#endif

uint8_t * tx_buf;
uint8_t phase;

void init_pins() {
#if PLATFORM_MSP430
  SPI_SELECT_TX(); // Init TX pin
  SPI_SELECT_RX(); // Init RX pin
  SPI_SELECT_CLK(); // Init CLK pin
  SPI_SELECT_CS(); // Init CS pin
  SPI_CS_HIGH();
#elif PLATFORM_PSOC #error "Pins not conf'd for PSOC"
#endif
}

void setup_spi() {
#if PLATFORM_MSP430
  SPI_RESET_USCI(); // Keep module reset
  SPI_SETUP_USCI(); // Setup the USCI general settings
  SPI_SETUP_BAUDRATE(); // Setup the baudrate for the module

  init_pins();

  SPI_RELEASE_USCI(); // Release module for operation
#elif PLATFORM_PSOC #error "SPI setup not done for PSOC"
#endif
}

void spi_begin() {
  SPI_CS_LOW(); // Pull chip select low to init communication
}

void spi_end() {
  SPI_CS_HIGH(); // Release chip select to end communication
}
void transmit_byte (uint8_t byte){
  SPI_TRANSMIT = byte;
}

uint8_t receive_byte(void) {
  return SPI_RECEIVE;
}

void transmit_packet (uint8_t * buf) {
  tx_buf = buf;
  spi_begin();
  __delay_cycles(20000); // Allow slave 20ms to settle
  phase = 1; // init state machine to track 4 bytes (32 bits)
  transmit_byte(tx_buf[0]); // transmit first byte
  __bis_SR_register(LPM0_bits + GIE); // enter low power mode to handle the rest of the communication
}

void transfer_packet(uint8_t * buf, uint8_t * out, uint8_t read) {
  transmit_packet(buf);
  if (read) {

  }
  else spi_end();
}

#pragma vector = USCIAB0TX_VECTOR // Handle SPI comms for the rest of the bytes
__interrupt void tx_vector(void) {

  if (phase < 4) transmit_byte(tx_buf[phase++]);
  else __bic_SR_register_on_exit(LPM0_bits);
}

#pragma vector = USCIAB0RX_VECTOR
__interrupt void rx_vector(void) {


}
