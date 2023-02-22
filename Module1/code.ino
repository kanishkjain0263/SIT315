// Constants
const int PIR_PIN = 2; // Pin 2 is set to sensor pin

// Variables
int motionDetected = 0; // This variable tells if the motion is detected or not by setting value by 0 (off)/1 (on)

void setup() {
    pinMode(PIR_PIN, INPUT); // Setting PIR pin as input
    pinMode(LED_BUILTIN, OUTPUT); // Setting LED pin as output
    Serial.begin(9600);
}

void loop() {
    motionDetected = digitalRead(PIR_PIN); // reading the value from sensor to detect motion

    if (motionDetected == HIGH) {       // Motion detected
        digitalWrite(LED_BUILTIN, HIGH);
        Serial.println("Motion Detected");
    
        delay(500); 
    }
    else {                // Motion not detecte4d
        digitalWrite(LED_BUILTIN, LOW); 
        Serial.println("No Movement!");
    }
}
