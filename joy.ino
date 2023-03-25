//Mario's Ideas
//MAX7219 - using Led Control library to display 8x8 bitmap
#include <LedControl.h>

int DIN = 11;
int CS = 7;
int CLK = 13;
LedControl lc=LedControl(DIN, CLK, CS,0);
const uint8_t IMAGES[8] = {B00000000,B11100111,B10100101,B00000000,B00000000,B01111110,B01100110,B01111110};
const int IMAGES_LEN = sizeof(IMAGES)/8;
const uint8_t D[8] = {
  0b00000000,
  0b00000000,
  0b00111000,
  0b00100100,
  0b00100100,
  0b00100100,
  0b00111000,
  0b00000000
};
const int D_LEN = sizeof(D)/8;
const uint8_t A[8] = {
  0b00000000,
  0b00000000,
  0b00111100,
  0b00100100,
  0b00111100,
  0b00100100,
  0b00100100,
  0b00000000
};


const int A_LEN = sizeof(A)/8;

const uint8_t R[8] = {
  0b00000000,
  0b00000000,
  0b00111100,
  0b00100100,
  0b00111100,
  0b00110000,
  0b00101000,
  0b00100100
};
const int R_LEN = sizeof(R)/8;


const uint8_t U[8] = {
  0b00000000,
  0b00000000,
  0b00100100,
  0b00100100,
  0b00100100,
  0b00100100,
  0b00111100,
  0b00000000
};
const int U_LEN = sizeof(U)/8;

const uint8_t I[8] = {
  0b00000000,
  0b00000000,
  0b00111110,
  0b00001000,
  0b00001000,
  0b00001000,
  0b00111110,
  0b00000000
};
const int I_LEN = sizeof(I)/8;

const uint8_t N[8] = {
 0b00000000,
  0b00000000,
  0b00100010,
  0b00110010,
  0b00101010,
  0b00100110,
  0b00100010,
  0b00000000
};
const int N_LEN = sizeof(N)/8;

const uint8_t O[8] = {
0b00000000,
  0b00000000,
  0b00111100,
  0b00100100,
  0b00100100,
  0b00100100,
  0b00111100,
  0b00000000
};
const int O_LEN = sizeof(O)/8;




void setup() {
  lc.shutdown(0,false);
  lc.setIntensity(0,0);
  lc.clearDisplay(0);
}
  
void loop(){
  
   for(int i=0;i<8;i++) lc.setRow(0,i,A[i]);
  delay(1000);
  lc.clearDisplay(0);
  for(int i=0;i<8;i++) lc.setRow(0,i,R[i]);
  delay(1000);
  lc.clearDisplay(0);
     for(int i=0;i<8;i++) lc.setRow(0,i,D[i]);
  delay(1000);
  lc.clearDisplay(0);
  for(int i=0;i<8;i++) lc.setRow(0,i,U[i]);
  delay(1000);
  lc.clearDisplay(0);
     for(int i=0;i<8;i++) lc.setRow(0,i,I[i]);
  delay(1000);
  lc.clearDisplay(0);
  for(int i=0;i<8;i++) lc.setRow(0,i,N[i]);
  delay(1000);
  lc.clearDisplay(0);
     for(int i=0;i<8;i++) lc.setRow(0,i,O[i]);
  delay(1000);
  lc.clearDisplay(0);
 
}
