// for teensy 3.1

int input[10] = {3, 4, 5, 6, 7, A8, A7, A6, A5, A4};
unsigned long lastDebounceTime[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
unsigned long debounceDelay = 20;
int reading[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int i = 0;

void setup() {
  pinMode(8, OUTPUT); // led right
  pinMode(A3, OUTPUT); // led left
  digitalWrite(8, LOW);
  digitalWrite(A3, LOW);
  Joystick.X(512);
  Joystick.Y(512);
  Joystick.Z(512);
  Joystick.Zrotate(512);
  Joystick.sliderLeft(512);
  Joystick.sliderRight(512);
  Joystick.hat(-1);
  Joystick.useManualSend(true);

  for (i = 0; i < 10; i++) {
    pinMode(input[i], INPUT_PULLUP);
  }
}


void loop() {
  for (i = 0; i < 10; i++) {
    if ((millis() - lastDebounceTime[i]) > debounceDelay) {  
      if (i == 4) {
        digitalWrite(8, !digitalRead(7));
      } else if (i == 9) {
        digitalWrite(A3, !digitalRead(A4));
      }
      
      Joystick.button(i + 1, !digitalRead(input[i]));
      lastDebounceTime[i] = millis();
    }
  }
  Joystick.send_now();
}
