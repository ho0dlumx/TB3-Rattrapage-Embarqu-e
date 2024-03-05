#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#define LED 26

// WiFi settings - Based on project code
const char* ssid = "Wi-Fi Maison des Élèves"; // Replace with network name
const char* password = "w1f1delaME139"; // Replace with password
const char* backend_url = "http://backend-url/api/v1/questions"; // Backend URL (won't be used) - Replace with real URL

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  
  // Wait for WiFi connection - Based on project code
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("Connecting to WiFi...");
    delay(1000);
  }
  Serial.println("Connected to WiFi");

  // Configure LED pin as output
  pinMode(LED, OUTPUT);

  // Simulate fetching and processing a question - Structure based on https://docs.arduino.cc/learn/programming/functions/
  String mockQuestion = generateMockQuestion(); // To fetch from API, replace with: String questionFromAPI = fetchQuestionFromAPI();
  processQuestion(mockQuestion); // To fetch from API, replace with: processQuestion(questionFromAPI);
}

// Function to generate a mock question, simulating a Json file that receives question title, answers, user answer and correct answer
// Reference 1 (Json file): https://arduinojson.org/v6/api/dynamicjsondocument/ 
// Reference 2 (Random): https://www.arduino.cc/reference/en/language/functions/random-numbers/random/
String generateMockQuestion() {
  DynamicJsonDocument doc(1024);
  doc["title"] = "Mock Question Title";
  
  JsonArray answers = doc.createNestedArray("answers");
  answers.add("Answer 1");
  answers.add("Answer 2");
  answers.add("Answer 3");
  answers.add("Answer 4");

  // Simulate user answer
  int userAnswer = random(4);
  doc["userAnswer"] = userAnswer;

  // Choose a random answer as correct for the simulation, to test different results
  doc["correctAnswerIndex"] = random(4);

  String questionJson;
  serializeJson(doc, questionJson);

  return questionJson;
}

// Check if the answer is correct
bool checkAnswer(int userAnswer, int correctAnswerIndex) {
  return userAnswer == correctAnswerIndex;
}

// Process the question
// Reference 1 (Json file): https://arduinojson.org/v6/api/dynamicjsondocument/ 
// Reference 2 (Print array): https://forum.arduino.cc/t/trying-to-print-elements-of-a-string-array/393090/3
// Part of the code (LEDs) based on project code
void processQuestion(String questionJson) {
  DynamicJsonDocument doc(1024);
  deserializeJson(doc, questionJson);

  String title = doc["title"];
  JsonArray answers = doc["answers"];
  int userAnswer = doc["userAnswer"];
  int correctAnswerIndex = doc["correctAnswerIndex"];

  // Print question information
  Serial.println("Question Title: " + title);
  Serial.println("Possible Answers:");
  for (int i = 0; i < answers.size(); i++) {
    Serial.println("- " + answers[i].as<String>());
  }
  Serial.println("User Answer Index: " + String(userAnswer));
  Serial.println("Correct Answer Index: " + String(correctAnswerIndex));

  // Check and react according to the answer
  bool isCorrect = checkAnswer(userAnswer, correctAnswerIndex);
  if (isCorrect) {
    digitalWrite(LED, HIGH);
    delay(10000); // Blink slowly for correct answer
    digitalWrite(LED, LOW);
  } else {
    digitalWrite(LED, HIGH);
    delay(1000); // Blink quickly for wrong answer
    digitalWrite(LED, LOW);
  }  
}

// Function to fetch data from API (for illustrative purposes only)
// Reference: https://github.com/instanceofMA/arduino-fetch/blob/main/examples/esp32/sync/get/get.ino
String fetchQuestionFromAPI() {
  HTTPClient http;
  String questionJson;

  http.begin(backend_url);
  int httpCode = http.GET();

  if (httpCode > 0) {
    if (httpCode == HTTP_CODE_OK) {
      questionJson = http.getString();
    }
  } else {
    Serial.println("Error on HTTP request");
  }

  http.end();
  return questionJson;
}

void loop() {
  
}
