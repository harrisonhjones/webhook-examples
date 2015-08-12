/* Includes ------------------------------------------------------------------*/  

/* Function prototypes -------------------------------------------------------*/

// Explicit Declaration of System Mode
SYSTEM_MODE(AUTOMATIC);

/* Preprocessor Defined ------------------------------------------------------*/
#define ALERT_INTERVAL   60000              // Alert every 60 seconds

/* Constants -----------------------------------------------------------------*/
const char webhookName[] = "sendSlack";
const char sendTo[] = "#general";   // Channel (#channel) or user (@username)
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
    
    sprintf(message, "{\"n\":\"%s\", \"m\":\"%s is online\"}", sendTo, coreID);
    Spark.publish(webhookName, message);
    lastAlert = millis();
}

/* Loop Function - Run Indefinitely ------------------------------------------*/
void loop()
{
    // Check if we need to start the next sample
    if((millis() - lastAlert) > ALERT_INTERVAL)
    {
        sprintf(message, "{\"n\":\"%s\", \"m\":\"%s says hello\"}", sendTo, coreID);
    
        Serial.println("Sending out message");
        Serial.print("\tMessage: ");
        Serial.println(message);
        Serial.println();
        
        Spark.publish(webhookName, message);
        lastAlert = millis();
    }
}