#define btn_pin 12
#define led_pin 3
#define check_time 20
#define size 100

long prev = 0;
int arr[size];
int counter = 0;
bool flag = false;

void setup() {
  pinMode(led_pin, OUTPUT);
  pinMode(btn_pin, INPUT);
  Serial.begin(9600);
}

void loop(){
  int val = digitalRead(btn_pin);
  if (val == 1){    
    if(millis() - prev > check_time){
      flag = !flag;
      Serial.println("PRESSED!");
    }
    prev = millis();
  }

  if(flag){
    digitalWrite(led_pin, HIGH);
  }
  else{
    digitalWrite(led_pin, LOW);        
  }

}