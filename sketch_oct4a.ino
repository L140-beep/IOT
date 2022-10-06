#define btn_pin 12
#define led_pin 3
#define check_time 20

long prev = 0;
bool flag = false;
bool is_full_brightness = false;
bool is_btn_pressed = false;
int brightness = 0;

void setup() {
  pinMode(led_pin, OUTPUT);
  pinMode(btn_pin, INPUT);
  Serial.begin(9600);
}

void loop(){
  int val = digitalRead(btn_pin);

  if(val == 0){
    if(millis() - prev > check_time){
      is_btn_pressed = true;
    }
  } else {
    is_btn_pressed = false;
    prev = millis();
  }

  if(is_btn_pressed){
    if (millis() - prev > 300){
        
        Serial.println("PRESSED!");

        if(brightness < 255 && !is_full_brightness){
          brightness += 1;
        }else{
          brightness -= 1;
        }
        if(brightness == 255){
          is_full_brightness = true;
        }
        if(brightness == 0){
          is_full_brightness = false;
        }

        analogWrite(led_pin, brightness);
    } else{
      Serial.println("Click");
      flag = !flag;
    }
  }else{
    brightness = 0;
    
    if(flag){
      digitalWrite(led_pin, HIGH);
    } else{
      digitalWrite(led_pin, LOW);      
    }
  }
}
