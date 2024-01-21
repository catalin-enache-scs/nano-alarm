// Define the digital pins that will be used for input
const int inputPin1 = 2;
const int inputPin2 = 3;
const int inputPin3 = 4;
const int inputPin4 = 5;

// Define the PWM output pin
const int outputPin = 6;

void setup() {
  // Set the input pins as inputs
  pinMode(inputPin1, INPUT);
  pinMode(inputPin2, INPUT);
  pinMode(inputPin3, INPUT);
  pinMode(inputPin4, INPUT);

  // Set the output pin as an output
  pinMode(outputPin, OUTPUT);
}

void loop() {
  // Read the state of each input pin
  bool state1 = digitalRead(inputPin1);
  bool state2 = digitalRead(inputPin2);
  bool state3 = digitalRead(inputPin3);
  bool state4 = digitalRead(inputPin4);

  // Initialize variables for the ON and OFF times
  long onTime = 0;
  long offTime = 2000; // Default OFF time is the full cycle time (2 seconds)

  // Adjust ON and OFF times based on the input states
  if (state1 && !state2 && !state3 && !state4) {
    // First input is active: 25% duty cycle
    onTime = 500; // 25% of 2000ms
  } else if (!state1 && state2 && !state3 && !state4) {
    // Second input is active: 50% duty cycle
    onTime = 1000; // 50% of 2000ms
  } else if (!state1 && !state2 && state3 && !state4) {
    // Third input is active: 75% duty cycle
    onTime = 1500; // 75% of 2000ms
  } else if (!state1 && !state2 && !state3 && state4) {
    // Fourth input is active: 100% duty cycle
    onTime = 2000; // 100% of 2000ms
  }

  // Calculate the OFF time
  offTime -= onTime;

  // Generate the PWM signal
  digitalWrite(outputPin, HIGH); // Turn the output HIGH
  delay(onTime); // Wait for the ON time
  digitalWrite(outputPin, LOW); // Turn the output LOW
  delay(offTime); // Wait for the OFF time
}
