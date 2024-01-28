//L293D
//Motor left
const int enA = 3;
const int leftIn1  = 5;  // Pin 14 of L293
const int leftIn2  = 4;  // Pin 10 of L293
//Motor right
const int enB = 9;
const int rightIn1  = 8; // Pin  7 of L293
const int rightIn2  = 7;  // Pin  2 of L293

bool motorHigh;
bool motorLow;

int leftMotor;
int rightMotor;
/*
int leftMotorVal = 0;
int rightMotorVal = 0;
int leftMotorMoveVal = 0;
int rightMotorMoveVal = 0;
int leftMotorTurnVal = 0;
int rightMotorTurnVal = 0;

double xDegreeVal;
double yDegreeVal;
*/
int serVal = 0;

//This will run only one time.
void setup(){
 
    //Set pins as outputs
    pinMode(enA, OUTPUT);
    pinMode(enB, OUTPUT);
    pinMode(leftIn1, OUTPUT);
    pinMode(leftIn2, OUTPUT);
    pinMode(rightIn1, OUTPUT);
    pinMode(rightIn2, OUTPUT);

    //Serial.begin(9600);
    
    //Motor Control - Motor A: motorPin1,motorpin2 & Motor B: motorpin3,motorpin4

    //This code  will turn Motor A clockwise for 2 sec.
    //Serial.print("1");
    digitalWrite(leftIn1, LOW);
    digitalWrite(leftIn2, LOW);
    digitalWrite(rightIn1, LOW);
    digitalWrite(rightIn2, LOW);

    Serial.begin(9600);
    /*delay(2000); 
    //This code will turn Motor A counter-clockwise for 2 sec.
    Serial.print("2");
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    //digitalWrite(motorPin3, LOW);
    //digitalWrite(motorPin4, LOW);
    delay(2000);
    
    //This code will turn Motor B clockwise for 2 sec.
    Serial.print("3");
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    //digitalWrite(motorPin3, HIGH);
    //digitalWrite(motorPin4, LOW);
    delay(2000); 
    //This code will turn Motor B counter-clockwise for 2 sec.
    Serial.print("4");
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    //digitalWrite(motorPin3, LOW);
    //digitalWrite(motorPin4, HIGH);
    delay(2000);    
    
    //And this code will stop motors
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    //digitalWrite(motorPin3, LOW);
    //digitalWrite(motorPin4, LOW);
  */
}


void loop(){
  /*directionControl();
	delay(1000);
	speedControl();
	delay(1000);
  */
  if(Serial.available() > 0) {
    serVal = Serial.read();
  }
  /*
  leftMotorVal = leftMotorMoveVal + leftMotorTurnVal;
  rightMotorVal = rightMotorMoveVal + rightMotorTurnVal;

  if (fabs(leftMotorVal) > 1) {
    leftMotorVal /= fabs(leftMotorVal);
  }
  else if (fabs(rightMotorVal) > 1) {
    rightMotorVal /= fabs(rightMotorVal); 
  }
  //determine turning
  if(xDegrees > 3000) {
    leftMotorTurnVal = 1;
    rightMotorTurnVal = -1;
    LOG_PORT.print("right, ");
  }
  else if(xDegrees < -3000) {
    leftMotorTurnVal = -1;
    rightMotorTurnVal = 1;
    LOG_PORT.print("left, ");
  }
  else {
    leftMotorTurnVal = 0;
    rightMotorTurnVal = 0;
    LOG_PORT.print("constant, ");
  }

  if(yDegrees > 3000) {
    leftMotorMoveVal = -1;
    rightMotorMoveVal = -1;
    LOG_PORT.print("back, ");
  }
  else if(yDegrees < -3000) {
    leftMotorMoveVal = 1;
    rightMotorMoveVal = 1;
    LOG_PORT.print("forward, ");
  }
  else {
    leftMotorMoveVal = 0;
    rightMotorMoveVal = 0;
    LOG_PORT.print("constant, ");
  }
  */
  switch(serVal) {
    case 0:
      leftMotor = -1;
      rightMotor = -1;
      break;
    case 1:
      leftMotor = -1;
      rightMotor = 0;
      break;
    case 2:
      leftMotor = -1;
      rightMotor = 1;
      break;
    case 3:
      leftMotor = 0;
      rightMotor = -1;
      break;
    case 4:
      leftMotor = 0;
      rightMotor = 0;
      break;
    case 5:
      leftMotor = 0;
      rightMotor = 1;
      break;
    case 6:
      leftMotor = 1;
      rightMotor = -1;
      break;
    case 7:
      leftMotor = 1;
      rightMotor = 0;
      break;
    case 8:
      leftMotor = 1;
      rightMotor = 1;
      break;
    default:
      break;
  }
  motorState(leftMotor, rightMotor);
}

void directionControl() {
	// Set motors to maximum speed
	// For PWM maximum possible values are 0 to 255
	analogWrite(enA, 255);
	analogWrite(enB, 255);

	// Turn on motor A & B
	digitalWrite(leftIn1, HIGH);
	digitalWrite(leftIn2, LOW);
	digitalWrite(rightIn1, HIGH);
	digitalWrite(rightIn2, LOW);
	delay(2000);
	
	// Now change motor directions
	digitalWrite(leftIn1, LOW);
	digitalWrite(leftIn2, HIGH);
	digitalWrite(rightIn1, LOW);
	digitalWrite(rightIn2, HIGH);
	delay(2000);
	
	// Turn off motors
	digitalWrite(leftIn1, LOW);
	digitalWrite(leftIn2, LOW);
	digitalWrite(rightIn1, LOW);
	digitalWrite(rightIn2, LOW);
}

void speedControl() {
	// Turn on motors
	digitalWrite(leftIn1, LOW);
	digitalWrite(leftIn2, HIGH);
	digitalWrite(rightIn1, LOW);
	digitalWrite(rightIn2, HIGH);
	
	// Accelerate from zero to maximum speed
	for (int i = 0; i < 256; i++) {
		analogWrite(enA, i);
		analogWrite(enB, i);
		delay(20);
	}
	
	// Decelerate from maximum speed to zero
	for (int i = 255; i >= 0; --i) {
		analogWrite(enA, i);
		analogWrite(enB, i);
		delay(20);
	}
	
	// Now turn off motors
	digitalWrite(leftIn1, LOW);
	digitalWrite(leftIn2, LOW);
	digitalWrite(rightIn1, LOW);
	digitalWrite(rightIn2, LOW);
}

void motorOff() {
  digitalWrite(leftIn1, LOW);
	digitalWrite(leftIn2, LOW);
	digitalWrite(rightIn1, LOW);
	digitalWrite(rightIn2, LOW);
}

void motorForward() {
  digitalWrite(leftIn1, HIGH);
	digitalWrite(leftIn2, LOW);
	digitalWrite(rightIn1, HIGH);
	digitalWrite(rightIn2, LOW);
}

void motorBackward() {
  digitalWrite(leftIn1, LOW);
	digitalWrite(leftIn2, HIGH);
	digitalWrite(rightIn1, LOW);
	digitalWrite(rightIn2, HIGH);
}

void motorState(int left, int right) {
  if (left < 0) {
    analogWrite(leftIn1, 0);
    analogWrite(leftIn2, int(-left * 255));
  } 
  else if (left >= 0) {
    analogWrite(leftIn1, int(left * 255));
    analogWrite(leftIn2, 0);
  }

  if (right < 0) {
    analogWrite(rightIn1, 0);
    analogWrite(rightIn2, int(-right * 255));
  } 
  else if (right >= 0) {
    analogWrite(rightIn1, int(right * 255));
    analogWrite(rightIn2, 0);
  }
}