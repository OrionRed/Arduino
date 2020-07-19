int value = 0;

  // the setup function runs once when you press reset or power the board
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.begin(9600);
  pinMode(8, INPUT_PULLUP);
 
  }

// the loop function runs over and over again forever
void loop() {
  //read the pushbutton value into a variable
  int sensorVal = digitalRead(8);
  if (sensorVal == LOW) {
    Serial.println("OFF5");
    delay(10000);
  }
}
