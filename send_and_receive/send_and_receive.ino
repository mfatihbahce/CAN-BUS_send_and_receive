/*
 * File:   sys_config.h
 * Author: mfatihbahce
 *
 * Created on October 8, 2020, 12:43 AM
 */
 
#include <mcp_can.h>
#include <SPI.h>

long unsigned int rxId;
unsigned char len = 0;
unsigned char rxBuf[8];
char msgString[128];  // Array to store serial string

#define CAN0_INT 2  // Set INT to pin 2
MCP_CAN CAN0(10);   // Set CS to pin 10


void setup() {
  Serial.begin(115200);
  // MCP2515'i 16 MHz'de 500 kb/s baud hızıyla ve maskeler ve filtreler devre dışı olarak çalıştırarak başlatın.
  if (CAN0.begin(MCP_ANY, CAN_500KBPS, MCP_8MHZ) == CAN_OK) Serial.println("MCP2515 Başarıyla Başlatıldı!");
  else Serial.println("MCP2515'i Başlatma Hatası...");

  CAN0.setMode(MCP_NORMAL);  // Change to normal mode to allow messages to be transmitted
  pinMode(CAN0_INT, INPUT);  // Configuring pin for /INT input
  Serial.println("MCP2515 Library Receive Example...");
}

// : 5A 46 4B 4A 83 00 00 BB FF FF 45 4E 44
byte data[14] = { 'Z', 'F', 'K', 'J', 0x00, 0x00, 40, 0xBB, 0x79, 0xFF, 0xFF, 'E', 'N', 'D' };

void loop() {
  // send data:  ID = 0x100, Standard CAN Frame, Data length = 8 bytes, 'data' = array of data bytes to send
  byte sndStat = CAN0.sendMsgBuf(0x100, 1, 14, data);
  if (sndStat == CAN_OK) {
    Serial.println("Mesaj Başarıyla Gönderildi!");
  } else {
    Serial.println("Mesaj Gönderme Hatası...");
  }
  if (CAN0.checkReceive() > 0)  // If CAN0_INT pin is low, read receive buffer
  {
    CAN0.readMsgBuf(&rxId, &len, rxBuf);    // Read data: len = data length, buf = data byte(s)
    if ((rxId & 0x80000000) == 0x80000000)  // Determine if ID is standard (11 bits) or extended (29 bits)
      sprintf(msgString, "Extended ID: 0x%.8lX  DLC: %1d  Data:", (rxId & 0x1FFFFFFF), len);
    else
      sprintf(msgString, "Standard ID: 0x%.3lX  DLC: %1d  Data:", rxId, len);

    Serial.print(msgString);
    if ((rxId & 0x40000000) == 0x40000000) {  // Determine if message is a remote request frame.
      sprintf(msgString, " REMOTE REQUEST FRAME");
      Serial.print(msgString);
    }
    {
      uint16_t data;
      for (byte i = 0; i < len; i += 2) {
        data = rxBuf[i];
        data <<= 8;
        data = rxBuf[i + 1];
        sprintf(msgString, "D[%d]: %d, ", i >> 1, data);
        Serial.print(msgString);
      }
    }
    Serial.println();
    delay(500);
  }
}