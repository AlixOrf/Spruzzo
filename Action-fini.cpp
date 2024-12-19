#include <IRremote.hpp>
 
#define PIN_DIRECTION_RIGHT 3
#define PIN_DIRECTION_LEFT 4
#define PIN_MOTOR_PWM_RIGHT 5
#define PIN_MOTOR_PWM_LEFT 6
#define PIN_SONIC_TRIG 7
#define PIN_SONIC_ECHO 8
#define PIN_IRREMOTE_RECV 9
 
// Updated IR Key Codes
#define IR_REMOTE_KEYCODE_UP 0x40
#define IR_REMOTE_KEYCODE_DOWN 0x19
#define IR_REMOTE_KEYCODE_LEFT 0x7
#define IR_REMOTE_KEYCODE_RIGHT 0x9
#define IR_REMOTE_KEYCODE_CENTER 0x15
 
IRrecv irrecv(PIN_IRREMOTE_RECV);
IRData results;
 
bool obstacleDetected = false;
 
void setup() {
  pinMode(PIN_DIRECTION_LEFT, OUTPUT);
  pinMode(PIN_MOTOR_PWM_LEFT, OUTPUT);
  pinMode(PIN_DIRECTION_RIGHT, OUTPUT);
  pinMode(PIN_MOTOR_PWM_RIGHT, OUTPUT);
  pinMode(PIN_SONIC_TRIG, OUTPUT);
  pinMode(PIN_SONIC_ECHO, INPUT);
 
  irrecv.begin(PIN_IRREMOTE_RECV, ENABLE_LED_FEEDBACK); // Initialize IR receiver
}
 
long measureDistance() {
  digitalWrite(PIN_SONIC_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(PIN_SONIC_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_SONIC_TRIG, LOW);
  long duration = pulseIn(PIN_SONIC_ECHO, HIGH);
  return (duration * 0.0343) / 2; // Convert duration to distance in cm
}
 
void stopMotors() {
  analogWrite(PIN_MOTOR_PWM_LEFT, 0);
  analogWrite(PIN_MOTOR_PWM_RIGHT, 0);
}
 
void moveForward() {
  digitalWrite(PIN_DIRECTION_LEFT, HIGH);
  digitalWrite(PIN_DIRECTION_RIGHT, LOW);
  analogWrite(PIN_MOTOR_PWM_LEFT, 150);
  analogWrite(PIN_MOTOR_PWM_RIGHT, 150);
}
 
void moveBackward() {
  digitalWrite(PIN_DIRECTION_LEFT, LOW);
  digitalWrite(PIN_DIRECTION_RIGHT, HIGH);
  analogWrite(PIN_MOTOR_PWM_LEFT, 150);
  analogWrite(PIN_MOTOR_PWM_RIGHT, 150);
}
 
void turnLeft() {
  digitalWrite(PIN_DIRECTION_LEFT, LOW);
  digitalWrite(PIN_DIRECTION_RIGHT, LOW);
  analogWrite(PIN_MOTOR_PWM_LEFT, 100);
  analogWrite(PIN_MOTOR_PWM_RIGHT, 150);
}
 
void turnRight() {
  digitalWrite(PIN_DIRECTION_LEFT, HIGH);
  digitalWrite(PIN_DIRECTION_RIGHT, HIGH);
  analogWrite(PIN_MOTOR_PWM_LEFT, 150);
  analogWrite(PIN_MOTOR_PWM_RIGHT, 100);
}
 
void spinInPlace() {
  digitalWrite(PIN_DIRECTION_LEFT, LOW);
  digitalWrite(PIN_DIRECTION_RIGHT, HIGH);
  analogWrite(PIN_MOTOR_PWM_LEFT, 150);
  analogWrite(PIN_MOTOR_PWM_RIGHT, 150);
  delay(500); // Spin for a short time
  stopMotors();
}
 
void loop() {
  long distance = measureDistance();
  obstacleDetected = (distance <= 10 && distance > 0); // Obstacle within 10 cm
 
  if (obstacleDetected) {
    spinInPlace();
  } else {
    if (irrecv.decode()) {
      results = irrecv.decodedIRData;
      switch (results.command) {
        case IR_REMOTE_KEYCODE_UP:
          moveForward();
          break;
        case IR_REMOTE_KEYCODE_DOWN:
          moveBackward();
          break;
        case IR_REMOTE_KEYCODE_LEFT:
          turnLeft();
          break;
        case IR_REMOTE_KEYCODE_RIGHT:
          turnRight();
          break;
        case IR_REMOTE_KEYCODE_CENTER:
          stopMotors();
          break;
        default:
          stopMotors();
          break;
      }
      irrecv.resume(); // Prepare to receive the next signal
    }
  }
  delay(100);
}