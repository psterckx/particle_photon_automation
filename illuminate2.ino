int desk = D3;
int bed = D2;
int lamp = D1;
int MR = D0;
int hour = 0;
int minute = 0;
int wake_hour = 8;
int wake_minute = 0;
bool morning_routine = FALSE;
int test;

void setup() {

    Particle.function("light_on",light_on);
    Particle.function("wake_up_time",wake_up_time);
    Particle.variable("morning_routine",morning_routine);
    Particle.variable("test",test);

    pinMode(desk,OUTPUT);
    pinMode(bed,OUTPUT);
    pinMode(lamp,OUTPUT);
    pinMode(MR,OUTPUT);
    
    digitalWrite(desk, HIGH);
    digitalWrite(bed, HIGH);
    digitalWrite(lamp,HIGH);
    
    Time.zone(-4);
}
    
void loop() {
    
    while (morning_routine) {
   
        hour = Time.hour();
        minute = Time.minute();
        
        if (hour == wake_hour && minute == wake_minute) {
    
            digitalWrite(bed,LOW);
        }
        
        delay(50000);
    }
}

int wake_up_time(String wake_time) {
    
    if (wake_time.substring(1,2) == ":") {
        wake_hour = wake_time.substring(0,1).toInt();
        wake_minute = wake_time.substring(2,4).toInt();
    } else {
        wake_hour = wake_time.substring(0,2).toInt();
        wake_minute = wake_time.substring(3,5).toInt();
    }
}


int light_on(String command) {
    
    if(command.indexOf("on") >= 0) {
        if(command.indexOf("bed") >= 0) {
            digitalWrite(bed,LOW);
            delay(500);
        }
        if(command.indexOf("lamp") >= 0) {
            digitalWrite(lamp,LOW);
            delay(500);
        }
        if(command.indexOf("desk") >= 0) {
            digitalWrite(desk,LOW);
            delay(500);
        }
        if(command.indexOf("all") >= 0) {
            digitalWrite(desk,LOW);
            delay(500);
            digitalWrite(lamp,LOW);
            delay(500);
            digitalWrite(bed,LOW);
        }
        if(command.indexOf("routine") >= 0) {
            morning_routine = TRUE;
            digitalWrite(MR,HIGH);
        }
    } else if (command.indexOf("off") >= 0) {
        if(command.indexOf("bed") >= 0) {
            digitalWrite(bed,HIGH);
            delay(500);
        }
        if(command.indexOf("lamp") >= 0) {
            digitalWrite(lamp,HIGH);
            delay(500);
        }
        if(command.indexOf("desk") >= 0) {
            digitalWrite(desk,HIGH);
            delay(500);
        }
        if(command.indexOf("all") >= 0) {
            digitalWrite(desk,HIGH);
            delay(500);
            digitalWrite(lamp,HIGH);
            delay(500);
            digitalWrite(bed,HIGH);
        }
        if(command.indexOf("routine") >= 0) {
            morning_routine = FALSE;
            digitalWrite(MR,LOW);
        }
    }

}

