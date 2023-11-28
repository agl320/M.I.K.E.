// Motor A connections
const int enA = 9;
const int in1 = 8;
const int in2 = 7;

// 2-pin; one to ground, one to pin2
const int buttonPin = 7;

// max: 255
int speed = 50;

int buttonState = 0;

void setup() {
  Serial.begin(9600);
  Serial.println(" START ");

	// Set all the motor control pins to outputs
	pinMode(enA, OUTPUT);
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);

  // Button pinning
  pinMode(buttonPin, INPUT);

	// Turn off motors - Initial state
  // both LOW or both HIGH to turn off
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed
  // - if pressed, will specify direction and go at speed
  // - else, will stop motor
  if (buttonState == LOW) {
    Serial.println(" LOW ");

    // turn on and specify motor direction
    digitalWrite(in1, HIGH);
	  digitalWrite(in2, LOW);

    // go in specified direction
    analogWrite(enA, speed);
  } else {
    Serial.println(" HIGH ");

    // set speed 0 
    analogWrite(enA, 0);

    // turn off motors
    digitalWrite(in1, LOW);
	  digitalWrite(in2, LOW);
  }

  // delay 1s
	delay(1000);
}



