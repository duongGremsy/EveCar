int in1 = 11;   
int in2 = 10;  
int in3 = 6;   
int in4 = 5;

int buzz = 3;    
int motor_enable = 9;
int l_red = 8;
int l_grn = 7;
int l_blu = 4;

unsigned long previousMillis_motor = 0;
unsigned long previousMillis_led = 0;

uint8_t motor_value = 0;

void setup() {
  // nothing happens in setup
  pinMode(buzz, OUTPUT);
  pinMode(motor_enable, OUTPUT);

  digitalWrite(buzz, HIGH); 
  digitalWrite(motor_enable, LOW);
  digitalWrite(l_blu, HIGH); 
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis_motor >= 10) {
    previousMillis_motor = currentMillis;

    motor_value = 255;
    // sets the value (range from 0 to 255):
    digitalWrite(motor_enable, HIGH);

    // left motor
    analogWrite(in3, motor_value-5);
    analogWrite(in4, 0);

    
    // right motor
    analogWrite(in1, motor_value);
    analogWrite(in2, 0);
    
//    digitalWrite(motor_enable, HIGH);
    
//    motor_value++;
//    if(motor_value >= 254) motor_value = 0;
  }

  if (currentMillis - previousMillis_led >= 300) {
    // save the last time you blinked the LED
    previousMillis_led = currentMillis;

    int red = random(0, 255);
    int grn = random(0, 255);
    int blu = random(0, 255);
    color_change_rgb(red, grn, blu);
  }
}

void color_change_rgb(int red, int grn, int blu){
  analogWrite(l_red, red);
  analogWrite(l_grn, grn);
  analogWrite(l_blu, blu);
}
