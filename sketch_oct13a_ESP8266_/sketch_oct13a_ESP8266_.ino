#include <ESP8266WebServer.h>
/* Set these to your desired credentials. */

  const char *ssid = "burbujero";
  ESP8266WebServer server(80);

  int valor_motor = 0;
  int valor_ventilador = 0;

  String valor_motorS = valor_motor + "";
  String valor_ventiladorS = valor_ventiladorS + "";

  /*const char INDEX_HTML[] =*/
  String INDEX_HTML =                                                        
     "<!DOCTYPE html>"                           
   "<html>"                                     
    "<head>"                                     
      "<meta charset=utf-8>"                       
      "<title>Menu Burbujero</title>"  
        "<meta name='viewport' content='width=device-width, initial-scale=1' />"                                                
    "</head>"                                     
    "<body>"
      "<style>"
//Configuración del fondo del html
        "body {"       
"background-image: url('https://dbdzm869oupei.cloudfront.net/img/sticker/preview/21450.png');"
          "background-repeat: no-repeat;"
          "background-attachment: fixed;"
          "background-size: cover;"
          "min-width:600px;"
        "}"
        // Se crea la burbuja que contiene los botones y las barras de velocidad
        ".circle {"
          "position:relative;"
          "left:10px;"
          "width:400px;"
          "height:400px;"
          "border-radius:250px;"
          "font-size:50px;"
          "color:#fff;"
          "vertical-align: middle;"
          "display: table-cell;"
          "text-align:center;"
          "background:#00a5d1;"
          "border: 3px solid white;"
        "}"

 ".button {"
     "background-color: #4CAF50; "
     "border: none;"
     "color: white;"
     "padding: 10px 25px;"
     "text-align: center;"
     "text-decoration: none;"
     "display: inline-block;"
     "font-size: 12.5px;"
     "margin: 4px 2px;"
     "cursor: pointer;"
     "border-radius: 10px;"
  "}"

  ".button2 {"
  "background-color: #f44336;"
  "}" 

  ".button3 {"
  "background-color: #555555;"
  "}"


        "form-label{"
        "form-range-track-width:50%;"
        "}"
        
        "H2 {  margin-bottom: 1em }"
        
        //Se posicionan los objetos dentro de la burbuja principal
        "* {"
        "box-sizing: border-box;"
        "margin: 0;"
        "padding: 0;"
        "}"
        
        ".inputDiv {"
          "width: 250px;"
          "margin: 20px auto;"
          "position: relative;"
        "}"
        
        "input[type='range'] {"
          "display: block;"
          "width: 250px;"
        "}"
        
        "input[type='range']:focus {"
          "outline: none;"
        "}"
        
        "input[type='range'],"
        "input[type='range']::-webkit-slider-runnable-track,"
        "input[type='range']::-webkit-slider-thumb {"
          "-webkit-appearance: none;"
        "}"
        
        "input[type=range]::-webkit-slider-thumb {"
          "background-color: #777;"
          "width: 20px;"
          "height: 20px;"
          "border: 3px solid white;"
          "border-radius: 50%;"
          "margin-top: -9px;"
        "}"
        
        "input[type=range]::-moz-range-thumb {"
          "background-color: #777;"
          "width: 15px;"
          "height: 15px;"
          "border: 3px solid #333;"
          "border-radius: 50%;"
        "}"
        
        "input[type=range]::-ms-thumb {"
          "background-color: #777;"
          "width: 2px;"
          "height: 2px;"
          "border: 3px solid #333;"
          "border-radius: 50%;"
        "}"
        
        "input[type=range]::-webkit-slider-runnable-track {"
          "background-color: #777;"
          "height: 3px;"
        "}"
        
        "input[type=range]:focus::-webkit-slider-runnable-track {"
          "outline: none;"
        "}"
        
        "input[type=range]::-moz-range-track {"
          "background-color: #777;"
          "height: 3px;"
        "}"
        
        "input[type=range]::-ms-track {"
          "background-color: #777;"
          "height: 3px;"
        "}"
        
        "input[type=range]::-ms-fill-lower {"
          "background-color: HotPink"
        "}"
        
        "input[type=range]::-ms-fill-upper {"
          "background-color: white;"
        "}"
        
        "</style>" 
        "<script>"
          "let $valorMotor=valor_motor;"
          "let $valorVentilador=valor_ventilador;"
        "</script>"
      /*-----------------------------------------------------------------------------------------*/
    "<div class='circle'>"
      "<div class='inputDiv'>" 
        "<span id='demo1'></span>"                           
        "<form action='valorMot' method='get' margin: 0 auto;>"                       
        //Inicio del formulario. Método de envío GET                                                                                                                       
         "<FONT SIZE=4>Seleccione velocidad del Motor:</font>"
            "<input type='range' id='valorM' class='slider' name='valorM' min='23' max='53' value='1' autocomplete='off'>"                
            "<button type='submit' class='button button3'>ENVIAR</button>"                          
        "</form>"
      "</div>"
      "<div class='inputDiv'>"
        "<span id='demo2'></span>"
        "<form action='valorVent' method='get'  margin: 0 auto;>"                    
       //Inicio del formulario. Método de envío GET                                                                                                                     
          "<FONT SIZE=4>Seleccione velocidad del Ventilador:</font>"
            "<input type='range' id='valorV' class='slider' name='valorV' min='0' max='255' value='0' autocomplete='off'>"           //no muestra la velocidad actual
            "<button type='submit' class='button button3'>ENVIAR</button>"             
        "</form>"
      "</div>"                                             
   "<button type='button' onClick=location.href='/on' class='button'>ENCENDER</button>"
   "<button type='button' onClick=location.href='/off' class='button button2'>APAGAR</button>"
    "</div>"
    "</body>"
  "</html>";
  
  /*---------------------*/
  void burb_on(){
   Serial.println("ON");
   /*server.send(200, "text/plain", "Burbujero encendido");*/
   handleRoot();
  }
  
  void burb_off(){
   Serial.println("OFF");
   /*server.send(200, "text/plain", "Burbujero apagado");*/
   handleRoot();
  }
  
  void no_encontrado() {
   server.send(404,"text/plain","<h1>Error en la petición</h1>");
  }

  void handleRoot(){
    server.send(200, "text/html", INDEX_HTML);
  }
  /*---------------------*/
  
  void setup(){
    delay(1000);
    Serial.begin(9600);
    WiFi.softAP(ssid);
    
    //definimos los paths
    server.on("/", handleRoot);
    server.on("/on",burb_on);
    server.on("/off",burb_off);
    server.on("/valorMot",[](){
      valor_motor=server.arg("valorM").toInt();
      valor_motorS = valor_motor + "";
      Serial.print("M");
      Serial.println(valor_motor);
      handleRoot();
    });
    server.on("/valorVent",[](){
      valor_ventilador=server.arg("valorV").toInt();
      valor_ventiladorS + "";
      Serial.print("V");
      Serial.println(valor_ventilador);
      handleRoot();
    });
    server.onNotFound(no_encontrado);    
    server.begin();       //inicializa el servidor web
  }
  
  
  void loop(){
    server.handleClient();
  } 
