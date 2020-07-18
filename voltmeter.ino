/*
* Display5vOrless sketch
* prints the voltage on analog pin to the serial port
* Warning - do not connect more than 5 volts directly to an Arduino pin.
*/

const int batteryPin = 0;         // battery is connected to analog pin 0

const int numReadings = 250;

int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average
int currAverage = 0;
int levelFlag = 3;
void setup() 
{
Serial.begin(9600);
pinMode(batteryPin, INPUT);
pinMode(2, OUTPUT);
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }
  digitalWrite(2, LOW);

}

void loop()
{
  // subtract the last reading:
  total = total - readings[readIndex];
  // read from the sensor:
  readings[readIndex] = analogRead(batteryPin);
  // add the reading to the total:
  total = total + readings[readIndex];
  // advance to the next position in the array:
  readIndex = readIndex + 1;

  // if we're at the end of the array...
  if (readIndex >= numReadings) {
    // ...wrap around to the beginning:
    readIndex = 0;
  }

  // calculate the average:
  average = total / numReadings;
  if (average > 20) {
    if (levelFlag != 1){
      Serial.println("Above 20");
      digitalWrite(2, HIGH);
    }
    levelFlag = 1;
  } else {
    if (levelFlag != 0){
      Serial.println("Below 20");
      digitalWrite(2, LOW);
    }
    levelFlag = 0;
  }
  /*
  if (average != currAverage){
    String barg = "";
      for (int i = 0; i <= average; i++) {
        barg = barg + "+";
      }
    // send it to the computer as ASCII digits
    Serial.println(barg);
  } //average changed
  */
  currAverage = average;
  delay(1);        // delay in between reads for stability
}
