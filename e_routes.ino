
void handleRoot() {
  server.sendHeader("Set-Cookie", "access_token=123"); // Set a cookie
  String cookie = server.header("Cookie");  
  // server.send(200, "text/html", navigateTo(""));
  server.send(200,"text/plain",cookie);
  // digitalWrite(led, 0);
}

void handleReadCookie() {
    if (server.hasHeader("Cookie")) {
    String cookie = server.header("Cookie");
    Serial.print("Received cookies: ");
    //Serial.println(cookie);

    // Split the cookies string into individual cookies
    int start = cookie.indexOf("access_token=");
    if (start != -1) {
      int end = cookie.indexOf(";", start);
      if (end == -1) {
        end = cookie.length();
      }
      String idValue = cookie.substring(start + 3, end);
      String cookie = server.header("Cookie");
      server.send(200, "text/plain","Cookie value: " + cookie);
      server.send(200, "text/plain", "Value of cookie 'id': " + idValue);
    } else {
      server.send(200, "text/plain", "No 'id' cookie found");
    }
  } else {
    Serial.println("No 'Cookie' header found in the request.");
    server.send(200, "text/plain", "No cookie found");
  }
}

void handleGetController() {
 
  server.send(200, "text/html", controlePage());

}

void handleSetController() {
  response=true;
  pidC.p = server.arg("p").toFloat();
  pidC.i = server.arg("i").toFloat();
  pidC.d = server.arg("d").toFloat();
  
  writeDataToContorleEEPROM(pidC.p,pidC.i,pidC.d);
  dispatch();
  server.send(200, "text/html", navigateTo("http://192.168.4.1/controller"));

}

void handleSetParams() {
  response=true;
  StaticJsonDocument<200> doc;
  DeserializationError error = deserializeJson(doc, server.arg("plain"));
  if (error) {
    server.send(400, "application/json", "Invalid JSON");
    return;
  }
  values.a =doc["a"];
  values.f =doc["f"];
  values.ph =doc["ph"];
  pidC.p =doc["p"];
  pidC.i =doc["i"];
  pidC.d =doc["d"];
  writeDataToParamsEEPROM(values.a,values.f,values.ph);
  writeDataToContorleEEPROM(pidC.p,pidC.i,pidC.d);
  dispatch();
  server.send(200, "text/plain", "data sent");
}


void handleNotFound() {

  server.send(404, "text/plain", "redirect to auther page");

}
void handleNotFound2() {

  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);

}
