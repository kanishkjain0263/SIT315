// Assigning the pins to the sensors and push button
#define LED_PIN 13
#define BUTTON_PIN 8
#define PIR_PIN 2
#define PINOUT_SOIL A0


// Variables for the Timer
const int userTime = 7000; // 5 seconds
int timerVar = 0;

// initializing the variables for the push button and sensors
float volt = 0;
int led_State = LOW;
int pir_Value = LOW;
int button_State = LOW;
int soil_Moisture = 0;


void setup() {
    
    pinMode(PIR_PIN, INPUT);        // Setting PIR pin as input
    pinMode(BUTTON_PIN, INPUT_PULLUP);          // Setting Button pin as input
    pinMode(LED_PIN, OUTPUT);       // Setting LED pin as output



  // PCINT library for PIR sensor
    PCICR |= (1 << PCIE2);
    PCMSK2 |= (1 << PCINT18);


  // PCINT library for soil moisture sensor
    PCICR |= (1 << PCIE1);
    PCMSK1 |= (1 << PCINT8);

  // PCINT library for push button
    PCICR |= (1 << PCIE0);
    PCMSK0 |= (1 << PCINT0);

  // Initializing timer interrupt
    TCCR1A = 0;
    TCCR1B = 0;
    TCNT1 = 0;
    OCR1A = 15624;      // (16MHz / (prescaler * desired interrupt frequency)) - 1
    TCCR1B |= (1 << WGM12);
    TCCR1B |= (1 << CS12) | (1 << CS10); // Prescaler is set to 1024
    TIMSK1 |= (1 << OCIE1A);


    Serial.begin(9600);
}

void loop()         // Loop is empty as all the functionality of the program is taken care by the Interrupt Routines 
{

}

// Interrupt routine for PIR sensor
ISR(PCINT2_vect) {
    pir_Value = digitalRead(PIR_PIN);
    if (pir_Value == HIGH) {
        Serial.println("Is someone there? Motion recorded");
    }
}

// Interrupt routine for TMP36 sensor
ISR(PCINT1_vect) {
	soil_Moisture = analogRead(PINOUT_SOIL);
    if (soil_Moisture < 500) {
        digitalWrite(LED_PIN, HIGH);
        led_State = HIGH;
        Serial.println("Water Tank is empty!");
    } else {
        digitalWrite(LED_PIN, LOW);
        led_State = LOW;
    }
}

// Interrupt routine for PUSH BUTTON
ISR(PCINT0_vect) {
    button_State = digitalRead(BUTTON_PIN);
    if (button_State == LOW) {
        led_State = !led_State;
        digitalWrite(LED_PIN, led_State);
        Serial.println("Button pressed!");
    }
}

// Interrupt routine for the TIMER
ISR(TIMER1_COMPA_vect) {
    timerVar++;
    if (timerVar == (userTime / 1000)) {
        Serial.println("Time expired.. Alarm is ON!");
        led_State =!led_State;
        digitalWrite(LED_PIN, led_State);
        timerVar = 0;
    }
}
