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

    if (motionDetected == 1) {       // Motion detected
        digitalWrite(LED_BUILTIN, HIGH);
        Serial.println("Interrupted");
    
        delay(500); 
    }
    else {                // Motion not detecte4d
        digitalWrite(LED_BUILTIN, LOW); 
        Serial.println("No Movement!");
    }
}


/*


Code Explaination: 
This is a simple Arduino program that uses a passive infrared (PIR) sensor to detect motion and turn on an LED if motion is detected. 
The program sets up a constant integer variable "PIR_PIN" to pin 2, which is connected to the PIR sensor. Another integer variable "motionDetected" is 
used to store the value detected by the PIR sensor (0 for no motion and 1 for motion).

The setup function sets the pinMode for the PIR_PIN and LED_BUILTIN to INPUT and OUTPUT, respectively. It also initializes the serial communication 
at a baud rate of 9600.

The loop function reads the value from the PIR sensor using the digitalRead function and stores it in the "motionDetected" variable. If the "motionDetected" 
variable is equal to 1, it means that motion has been detected and the LED_BUILTIN is turned on using digitalWrite function, and the message "Interrupted" is
printed to the serial monitor. There is also a delay of 500ms to avoid multiple detections of the same motion. If the "motionDetected" variable is not equal to 1,
it means that no motion has been detected and the LED_BUILTIN is turned off using digitalWrite function, and the message "No Movement!" is printed to the serial
monitor.

In summary, this program continuously monitors the PIR sensor to detect motion and turns on an LED when motion is detected, and prints appropriate messages to the
serial monitor based on the motion detection status.


*/
