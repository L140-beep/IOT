#define ROW_0 5
#define ROW_1 6
#define COL_0 3
#define COL_1 4

void setup() {
  Serial.begin(9600);
  Serial.println("Started!");
  pinMode(ROW_0, OUTPUT);
  pinMode(ROW_1, OUTPUT);
  pinMode(COL_0, OUTPUT);
  pinMode(COL_1, OUTPUT);
}

long num = 0;
bool switcher = false;
uint8_t thresh[20];

void loop() {
  if (Serial.available()) {
    num = Serial.parseInt();
    Serial.println(num);
    Serial.readBytes(thresh, 20);
  }
  if (num == 0) {
    turn_off();
  } else if (num == 1) {
    turn_on_first_led();
  } else if (num == 2) {
    turn_on_second_led();
  } else if (num == 3) {
    turn_on_third_led();
  } else if (num == 4) {
    turn_on_fourth_led();
  } else if (num == 12 || num == 21) {
    if (switcher) {
      turn_on_first_led();
      Serial.println("1");
    } else {
      turn_on_second_led();
      Serial.println("2");
    }
    switcher = !switcher;
  } else if (num == 34 || num == 43) {
    if (switcher) {
      turn_on_third_led();
      Serial.println("3");
    } else {
      turn_on_fourth_led();
      Serial.println("4");
    }
    switcher = !switcher;
  } else if (num == 31 || num == 13) {
    if (switcher) {
      turn_on_first_led();
      Serial.println("1");
    } else {
      turn_on_third_led();
      Serial.println("3");
    }
    switcher = !switcher;
  } else if (num == 24 || num == 42) {
    if (switcher) {
      turn_on_second_led();
      Serial.println("2");
    } else {
      turn_on_fourth_led();
      Serial.println("4");
    }
    switcher = !switcher;
  } else if (num == 14 || num == 41) {
    if (switcher) {
      turn_on_first_led();
      Serial.println("1");
    } else {
      turn_on_fourth_led();
      Serial.println("4");
    }
    switcher = !switcher;
  } else if (num == 23 || num == 32) {
    if (switcher) {
      turn_on_second_led();
      Serial.println("2");
    } else {
      turn_on_third_led();
      Serial.println("3");
    }
    switcher = !switcher;
  } else if (num == 124 || num == 241 || num == 412) {
    Serial.println("1");
    turn_on_first_led();
    Serial.println("2");
    turn_on_second_led();
    Serial.println("4");
    turn_on_fourth_led();
  } else if (num == 123 || num == 213 || num == 321) {
    Serial.println("1");
    turn_on_first_led();
    Serial.println("2");
    turn_on_second_led();
    Serial.println("3");
    turn_on_third_led();
  } else if (num == 134 || num == 314 || num == 431) {
    Serial.println("1");
    turn_on_first_led();
    Serial.println("3");
    turn_on_third_led();
    Serial.println("4");
    turn_on_fourth_led();
  } else if (num == 234 || num == 324 || num == 432) {
    Serial.println("2");
    turn_on_second_led();
    Serial.println("3");
    turn_on_third_led();
    Serial.println("4");
    turn_on_fourth_led();
  } else if (num == 1234 || num == 2134 || num == 3124 || num == 4321) {
    Serial.println("1");
    turn_on_first_led();
    Serial.println("2");
    turn_on_second_led();
    Serial.println("3");
    turn_on_third_led();
    Serial.println("4");
    turn_on_fourth_led();
  }
}

void turn_off() {
  digitalWrite(ROW_0, LOW);
  digitalWrite(ROW_1, LOW);
  digitalWrite(COL_0, LOW);
  digitalWrite(COL_1, LOW);
}

void turn_on_first_led() {
  digitalWrite(ROW_0, HIGH);
  digitalWrite(ROW_1, LOW);
  digitalWrite(COL_0, LOW);
  digitalWrite(COL_1, HIGH);
}

void turn_on_second_led() {
  digitalWrite(ROW_0, HIGH);
  digitalWrite(ROW_1, LOW);
  digitalWrite(COL_0, HIGH);
  digitalWrite(COL_1, LOW);
}

void turn_on_third_led() {
  digitalWrite(ROW_0, LOW);
  digitalWrite(ROW_1, HIGH);
  digitalWrite(COL_0, LOW);
  digitalWrite(COL_1, HIGH);
}

void turn_on_fourth_led() {
  digitalWrite(ROW_0, LOW);
  digitalWrite(ROW_1, HIGH);
  digitalWrite(COL_0, HIGH);
  digitalWrite(COL_1, LOW);
}
