// Set Board to "Adafruit Trinket (ATtiny85 @ 8 MHz)"
// Set Programmer to "USBtinyISP"
// Mke sure red LED is blinking before hitting upload
  // If not blinking hit button on Trinket

// Identify Trinket pins for controlling motors
const int motorPin0 = 0;
const int motorPin1 = 1;
const int motorPin4 = 4;
// Identify Trinket pin for reading in IR sensor data
int IRSensor2 = 2;

// Actually set up which pins will do which on the Trinket
void setup() {
  pinMode(motorPin0, OUTPUT);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  pinMode(IRSensor2, INPUT);
}

void loop() {
  // An initial example of using the robot...
  // We will make the robot do one thing when the IR sensor senses nothing ahead
  // It will so something else when an obstacle is detected (sensorStatus = 0)
  
  // Read the current sensor data
  int sensorStatus = digitalRead(IRSensor2);
  
  // Do one thing if an obstacle is detected
  // Note - depending on the IR sensor you are using, these states could be reversed
  // If so, just flip the sensorStatus values accordingly!
  if (sensorStatus == 0) {
    // WALK STRAIGHT
    analogWrite(motorPin0, 100);
    analogWrite(motorPin4, 100);
    analogWrite(motorPin1, 100);
  }

  // Do a different thing if an obstacle is not detected
  if (sensorStatus == 1) {
    // WALK FASTER
    analogWrite(motorPin0, 200);
    analogWrite(motorPin1, 200);
    analogWrite(motorPin4, 200);
  }

  // Load this initial example as a beginning test, and make sure it runs as expected
  // From there, you can play with what the robot does in response to a sensed obstacle
  // Can you accomplish sophistocated behavior just from this simple sensing? 
  // For example, try to make a robot that follows a wall, or navigates a maze!
  
}
