// Motor pin definitions
const int L_IN1 = 22;
const int L_IN2 = 23;
const int L_ENA = 9;

const int R_IN3 = 24;
const int R_IN4 = 25;
const int R_ENB = 10;

void setup() {
  // Set motor pins as output
  pinMode(L_IN1, OUTPUT);
  pinMode(L_IN2, OUTPUT);
  pinMode(L_ENA, OUTPUT);

  pinMode(R_IN3, OUTPUT);
  pinMode(R_IN4, OUTPUT);
  pinMode(R_ENB, OUTPUT);

  // Start movement sequence
  moveForward();
  delay(2000);  // Move forward for 2 seconds

  turnRight();
  delay(1000);  // Turn right for 1 second

  moveForward();
  delay(2000);  // Move forward for 2 seconds

  turnLeft();
  delay(1000);  // Turn left for 1 second

  stopMotors(); // Stop
}

void loop() {
  // No repeated action
}

void moveForward() {
  digitalWrite(L_IN1, HIGH);
  digitalWrite(L_IN2, LOW);
  analogWrite(L_ENA, 200);

  digitalWrite(R_IN3, HIGH);
  digitalWrite(R_IN4, LOW);
  analogWrite(R_ENB, 200);
}

void turnRight() {
  digitalWrite(L_IN1, HIGH);
  digitalWrite(L_IN2, LOW);
  analogWrite(L_ENA, 200);

  digitalWrite(R_IN3, LOW);
  digitalWrite(R_IN4, HIGH);
  analogWrite(R_ENB, 200);
}

void turnLeft() {
  digitalWrite(L_IN1, LOW);
  digitalWrite(L_IN2, HIGH);
  analogWrite(L_ENA, 200);

  digitalWrite(R_IN3, HIGH);
  digitalWrite(R_IN4, LOW);
  analogWrite(R_ENB, 200);
}

void stopMotors() {
  analogWrite(L_ENA, 0);
  analogWrite(R_ENB, 0);
}
