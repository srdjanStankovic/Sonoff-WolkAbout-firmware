
#include <ESP8266WiFi.h>

#include "WolkConn.h"
#include "MQTTClient.h"

#define NUM_ACTUATORS 1

const char* ssid = "wifi_ssid";
const char* wifi_pass = "wifi_password";

const char *device_key = "some_key";
const char *device_password = "some_password";
const char* hostname = "api-demo.wolkabout.com";
int portno = 1883;

/* WolkConnect-Arduino Connector context */
static wolk_ctx_t wolk;
outbound_message_t outbound_messages[STORE_SIZE];

const char* actuator_refs[] = {"SW"};

static char actuator_value[NUM_ACTUATORS][READING_SIZE] = {"false"};

WiFiClient espClient;
PubSubClient client(espClient);

static void actuation_handler(const char* reference, const char* value)
{
  Serial.print("Actuation handler - Reference:");
  Serial.println(reference);
  Serial.print("Value:");
  Serial.println(value);

  if (strcmp(reference, "SW") == 0) {
    strcpy(actuator_value[1], value);
  }
  else
    Serial.print("Wrong reference!");  
}

static actuator_status_t actuator_status_provider(const char* reference)
{
  Serial.print("Actuator status provider - Reference:");
  Serial.println(reference);

  actuator_status_t actuator_status;
  actuator_status_init(&actuator_status, "", ACTUATOR_STATE_ERROR);

  if (strcmp(reference, "SW") == 0)
  {
    Serial.print("Hey there SL, your new value is ");
    if (strcmp(actuator_value[0], "true") == 0)
    {
      Serial.println(actuator_value[0]);
      digitalWrite(12, LOW);
      digitalWrite(13, LOW);
    }
    else
    {
      Serial.println(actuator_value[0]);
      digitalWrite(12, HIGH);
      digitalWrite(13, HIGH);
    }
 
    actuator_status_init(&actuator_status, actuator_value[0], ACTUATOR_STATE_READY);
  }
  else
    Serial.print("Wrong reference!");

  return actuator_status;
}

void setup_wifi() {

  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, wifi_pass);

  if ( WiFi.status() != WL_CONNECTED) {
    while (WiFi.begin(ssid, wifi_pass) != WL_CONNECTED) {
      Serial.print(".");
      delay(4000);
    }
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void reconnect_to_platform()
{
  setup_wifi();
  
  wolk_connect(&wolk);
}

void setup() {
  Serial.begin(9600);

  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);

  setup_wifi();

  wolk_init(&wolk, actuation_handler, actuator_status_provider, NULL, NULL,
            device_key, device_password, &client, hostname, portno, PROTOCOL_JSON_SINGLE, actuator_refs, NUM_ACTUATORS);

  //wolk_init_in_memory_persistence(&wolk, &outbound_messages, sizeof(outbound_messages), false);
  
  wolk_connect(&wolk);
  delay(1000);
  
  wolk_publish_actuator_status(&wolk, "SW");
}

void loop() {

  if (Serial.available() > 0)
  {
    wolk_disconnect(&wolk);
    Serial.println("Disconnected!");
    while (true)
    {
      delay(10000);
    };
  }
  if(wolk_process(&wolk, 5) == W_TRUE)
  {
    reconnect_to_platform();
  }

  delay(1000);
}