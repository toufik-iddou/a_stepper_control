
void handleRoot() {
  digitalWrite(led, 1);
  server.send(200, "text/html", navigateTo(""));
  digitalWrite(led, 0);
}

void handleGetHome() {
  digitalWrite(led, 1);
  server.send(200, "text/html", homePage());
  digitalWrite(led, 0);
}

void handlePostHome() {
  digitalWrite(led, 1);
  values.mode = server.arg("mode").toFloat();
  values.V = server.arg("V").toFloat();
  values.R = server.arg("R").toFloat();
  values.TSR = server.arg("TSR").toFloat();
  values.theta = server.arg("theta").toFloat();
  writeDataToEEPROM(values.mode, values.V, values.R, values.TSR, values.theta);
  
  server.send(200, "text/html", navigateTo(""));

  digitalWrite(led, 0);
  switch (server.arg("mode").toInt()) {
    case 0 : //alpha
      moveToPosition(angleToPosition(server.arg("alpha").toFloat()));
      break;
    case 1: //theta
      moveToPosition(angleToPosition(server.arg("theta").toFloat()));
      break;
    case 2: //movement
      break;
  }
      dispatch();
}

void handleNotFound() {
  digitalWrite(led, 1);
  server.send(404, "text/plain", "redirect to auther page");
  digitalWrite(led, 0);
}
void handleNotFound2() {
  digitalWrite(led, 1);
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
  digitalWrite(led, 0);
}
