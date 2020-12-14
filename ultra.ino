// defines pins numbers
const int trigPinLs = 23;
const int echoPinLs = 22;

const int trigPinMs = 25;
const int echoPinMs = 24;

const int trigPinRs = 27;
const int echoPinRs = 26;

// defines variables
float durationLs=0.000;
float distanceLs=0.000;

float durationMs=0.000;
float distanceMs=0.000;

float durationRs=0.000;
float distanceRs=0.000;

void setup() {
pinMode(trigPinLs, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPinLs, INPUT); // Sets the echoPin as an Input

pinMode(trigPinMs, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPinMs, INPUT); // Sets the echoPin as an Input

pinMode(trigPinRs, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPinRs, INPUT); // Sets the echoPin as an Input

Serial.begin(9600); // Starts the serial communication
}
void loop() {
// Clears the trigPin
digitalWrite(trigPinLs, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPinLs, HIGH);
delayMicroseconds(10);
digitalWrite(trigPinLs, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
durationLs = pulseIn(echoPinLs, HIGH);
// Calculating the distance
distanceLs= durationLs*0.034/2.000;
// Prints the distance on the Serial Monitor
//Serial.print("DistanceLs: ");
//Serial.println(distanceLs);

// Clears the trigPin
digitalWrite(trigPinMs, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPinMs, HIGH);
delayMicroseconds(10);
digitalWrite(trigPinMs, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
durationMs = pulseIn(echoPinMs, HIGH);
// Calculating the distance
distanceMs= durationMs*0.034/2.00;
// Prints the distance on the Serial Monitor
Serial.print("DistanceMs: ");
Serial.println(distanceMs);
delay(1000);

// Clears the trigPin
digitalWrite(trigPinRs, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPinRs, HIGH);
delayMicroseconds(10);
digitalWrite(trigPinRs, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
durationRs = pulseIn(echoPinRs, HIGH);
// Calculating the distance
distanceRs= durationRs*0.034/2.000;
// Prints the distance on the Serial Monitor
//Serial.print("DistanceRs: ");
//Serial.println(distanceRs);

}
