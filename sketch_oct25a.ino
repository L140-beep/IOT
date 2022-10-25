#include <SoftwareSerial.h>

#define A 8
#define B 7
#define C 6
#define D 5
#define E 4
#define F 3
#define G 2
#define DP 9 // decimal
#define common_cathode 0
#define common_anode 1
bool segMode = common_cathode; // set this to your segment type, my segment is common_cathode
int seg[] {A,B,C,D,E,F,G,DP}; // segment pins
byte chars = 10; // max value in the array "Chars"

byte Chars[10][9] { 
  {'0',1,1,1,1,1,1,0,0},
  {'1',0,1,1,0,0,0,0,0},
  {'2',1,1,0,1,1,0,1,0},
  {'3',1,1,1,1,0,0,1,0},
  {'4',0,1,1,0,0,1,1,0},
  {'5',1,0,1,1,0,1,1,0},
  {'6',1,0,1,1,1,1,1,0},
  {'7',1,1,1,0,0,0,0,0},
  {'8',1,1,1,1,1,1,1,0},
  {'9',1,1,1,1,0,1,1,0},
};

SoftwareSerial mySerial(10, 11);

void setup() {
  pinMode(seg[0], OUTPUT);
  pinMode(seg[1], OUTPUT);
  pinMode(seg[2], OUTPUT);
  pinMode(seg[3], OUTPUT);
  pinMode(seg[4], OUTPUT);
  pinMode(seg[5], OUTPUT);
  pinMode(seg[6], OUTPUT);
  pinMode(seg[7], OUTPUT);

  Serial.begin(9600);
  mySerial.begin(9600);
  while(!Serial) {}
}

void setState(bool mode){
  for(int i = 0; i <= 6; i++){
    digitalWrite(seg[i], mode);
  }
}

void Print(int num){ 
  setState(segMode); //turn off the segment
 
  if(segMode == 0) { //for segment mode
    for(int i = 0; i < 8; i++){
      digitalWrite(seg[i], Chars[num][i+1]);
    }
  } else {
    for(int i = 0; i < 8; i++){
      digitalWrite(seg[i], !Chars[num][i+1]);
    }
  }
}

void loop() {
  //if(mySerial.available() > 0){
    //mySerial.print(mySerial.read());
    //int message = mySerial.readString().toInt();
    //Print(message);
    //delay(1000);
  //}

  for(int i = 0; i < chars; i++){
    Print(i);
    delay(1000);
  }

  // Print(5);
  // delay(1000);
}
