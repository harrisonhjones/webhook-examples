/* Includes ------------------------------------------------------------------*/  

/* Function prototypes -------------------------------------------------------*/

// Explicit Declaration of System Mode
SYSTEM_MODE(AUTOMATIC);

/* Preprocessor Defined ------------------------------------------------------*/
#define ALERT_INTERVAL   60000              // Alert every 60 seconds

/* Constants -----------------------------------------------------------------*/
const char webhookName[] = "sendSMS";
const char cellNumber[] = "+15555555555";   // Cell Phone Number (Ex: +15555555555)

/* Objects -------------------------------------------------------------------*/

/* Global Variables ----------------------------------------------------------*/
char message[200];
char coreID[30];
unsigned long lastAlert = 0;

/* Setup Function - Run One @ Startup ----------------------------------------*/
void setup()
{
    Serial.begin(9600);
    
    Spark.deviceID().toCharArray(coreID, Spark.deviceID().length());
    
    sprintf(message, "{\"n\":\"%s\", \"m\":\"%s is online\"}", cellNumber, coreID);
    Spark.publish(webhookName, message);
    lastAlert = millis();
}

/* Loop Function - Run Indefinitely ------------------------------------------*/
void loop()
{
    // Check if we need to start the next sample
    if((millis() - lastAlert) > ALERT_INTERVAL)
    {
        sprintf(message, "{\"n\":\"%s\", \"m\":\"%s says hello\"}", cellNumber, coreID);
        
        Serial.println("Sending out message");
        Serial.print("\tMessage: ");
        Serial.println(message);
        Serial.println();
        
        Spark.publish(webhookName, message);
        lastAlert = millis();
    }
}