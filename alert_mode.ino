#include "alert_mode.h"

// sensors ports
const int S1 = 10;
const int S2 = 11;
const int S3 = 12;
const int S4 = 13;
const int S5 = 14;
const int S6 = 15;
const int ALERT = 16;
const int LIGHT1 = 9;

bool alert = false;
int wich_one = -1;

void setup() {
    pinMode(S1, INPUT);
    pinMode(S2, INPUT);
    pinMode(S3, INPUT);
    pinMode(S4, INPUT);
    pinMode(S5, INPUT);
    pinMode(S6, INPUT);
    pinMode(S6, INPUT);

    pinMode(ALERT, OUTPUT);
    pinMode(LIGHT1, OUTPUT);
    
    digitalWrite(ALERT, HIGH);
    digitalWrite(LIGHT1, LOW);
}

void loop() {
    int ck = isOk();
    if (ck != -1 || alert) {
      unsigned long startTime = millis();
      while (millis() - startTime < 10000) { // Getting alert state into 30s
          
          if (wich_one != ck && ck != -1 && alert) {
              digitalWrite(ALERT, LOW);
              turneOnLights();
              releaseAlert();
          } else if (!alert) {
              wich_one = ck;
              alert = true;
          } else
            ck = isOk();
      }
    }
    digitalWrite(ALERT, HIGH);
    releaseAlert();
}

void turneOnLights() {
    unsigned long startTime = millis();
    while (millis() - startTime < 10000) {
        digitalWrite(LIGHT1, HIGH);
    }
    digitalWrite(LIGHT1, LOW);
}

void releaseAlert() {
    alert = false;
    wich_one = -1;
}

int isOk() {
    int rS1 = digitalRead(S1);
    if (rS1 == LOW && wich_one != 1) {
        delay(500);
        while (digitalRead(S1) == LOW);
        return 1;
    }
    int rS2 = digitalRead(S2);
    if (rS2 == LOW && wich_one != 2) {
        delay(500);
        while (digitalRead(S2) == LOW);
        return 2;
    }
    int rS3 = digitalRead(S3);
    if (rS3 == LOW && wich_one != 3) {
        delay(500);
        while (digitalRead(S3) == LOW);
        return 3;
    }
    int rS4 = digitalRead(S4);
    if (rS4 == LOW && wich_one != 4) {      
        delay(500);
        while (digitalRead(S4) == LOW);
        return 4;
    }
    int rS5 = digitalRead(S5);
    if (rS5 == LOW && wich_one != 5) {
        delay(500);
        while (digitalRead(S5) == LOW);
        return 5;
    }
    int rS6 = digitalRead(S6);
    if (rS6 == LOW && wich_one != 6) {
        delay(500);
        while (digitalRead(S6) == LOW);
        return 6;
    }
    return -1;
}
