#include <SPI.h>
#include <Gamebuino.h>
Gamebuino gb = Gamebuino();
int ball_x = LCDWIDTH/2; //set the horizontal position to the middle of the screen
int ball_y = LCDHEIGHT/2;
int ball_size = 8;
int an = 0;
String str = "";
String rot = "NOROT";
String flip = "FLIPH";
int command = 0;
static unsigned char PROGMEM pacmano[]=
{
  8,8,
  B00011111,
  B00110110,
  B01111100,
  B01111000,
  B01111100,
  B00111110,
  B00011111,
  B00000000,
};

static unsigned char PROGMEM pacmanc[]=
{
  8,8,
  B00011100,
  B00110110,
  B01111111,
  B01111111,
  B01111111,
  B00111110,
  B00011100,
  B00000000,
};
void setup() {
  gb.begin(F("caP naM"));
  gb.battery.show = false; //hide the battery indicator
  Serial.begin(115200);

}

void loop() {
  if(gb.update()){
    char c = (char)Serial.read(); // Gets one byte from serial buffer

    str = str + c; // Makes the string readString

    if(str == "v"){ 
      command = 7;
    }    




    if(str == "z"){

      command = 8;

    }
    
    if(str == "l"){

      command = 6;


    }
    
    if(str == "r"){

      command = 5;

    }

    if(ball_x < 0){
      //bring it back in the screen
      ball_x = 0;
    }
    //if the pac is touching the right side
    if((ball_x + ball_size) > LCDWIDTH){
      ball_x = LCDWIDTH - ball_size;
    }
    //if the pac is touching the top side
    if(ball_y < 0){
      ball_y = 0;
    }
    //if the pac is touching the down side
    if((ball_y + ball_size) > LCDHEIGHT){
      ball_y = LCDHEIGHT - ball_size;
    }

    switch(command){
    case 1:
      ball_x = ball_x + 3;
      gb.display.drawBitmap(ball_x, ball_y, pacmano, NOROT, NOFLIP);
      command = 5;
      break;
    case 2:
      ball_x = ball_x - 3;
      gb.display.drawBitmap(ball_x, ball_y, pacmano, NOROT, FLIPH);
command = 6;
      break;
    case 3:
      ball_y = ball_y - 3;
      gb.display.drawBitmap(ball_x, ball_y, pacmano, ROTCCW, NOFLIP);
command = 7;
      break;
    case 4:
      ball_y = ball_y + 3;
      gb.display.drawBitmap(ball_x, ball_y, pacmano, ROTCW, NOFLIP);
command = 8;
      break;
    case 5:
      ball_x = ball_x + 3;
      gb.display.drawBitmap(ball_x, ball_y, pacmanc, NOROT, NOFLIP);
command = 1;
      break;
    case 6:
      ball_x = ball_x - 3;
      gb.display.drawBitmap(ball_x, ball_y, pacmanc, NOROT, FLIPH);
command = 2;
      break;
    case 7:
      ball_y = ball_y - 3;
      gb.display.drawBitmap(ball_x, ball_y, pacmanc, ROTCCW, NOFLIP);
command = 3;
      break;
    case 8:
      ball_y = ball_y + 3;
      gb.display.drawBitmap(ball_x, ball_y, pacmanc, ROTCW, NOFLIP);
command = 4;
      break;
    }
    str = "";
  }

}







