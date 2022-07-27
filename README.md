# Burbujero2021

El proyecto pertenece al área de juegos y entretenimientos, cubriendo la necesidad de ocio del 
usuario. Se trata de un burbujero compuesto por un aro con agujeros montado en una pequeña estructura 
y movilizado por un motor de corriente continua, mientras un ventilador genera las burbujas.

# Objetivo

El objetivo principal del proyecto es optimizar la generación de burbujas de un burbujero
manual, llevando a cabo las funcionalidades descritas en el inciso de introducción. Se
propone un burbujero automatizado, el cual podría utilizarse como juguete infantil, como
dispositivo para fiestas o como pasatiempo para el usuario.
Las aspas del aro deben pasar por un recipiente con agua y detergente mientras reciben
viento proveniente de un ventilador (generando las burbujas). En la bibliografía del presente
informe se puede encontrar un enlace que muestra las partes de la estructura a realizar.
El burbujero debe poder iniciar y detener el movimiento del aro y del cooler, así como
también aumentar y disminuir la potencia de los mismos (generando más o menos
burbujas). Esto se realiza a través de Wifi, utilizando como interfaz un sitio web sencillo,
proveniente de un servidor local.
En el caso de un pronto buen funcionamiento del sistema con los elementos mencionados,
se propondría una versión portátil. Para esto se reemplazaría la fuente cableada por
baterías para alimentar el sistema. Además, se implementaría una mejora gráfica y
funcional a la interfaz del servidor HTTP.

<img src="Imagen Conexionado.png">

# Identificación de Partes

a) Partes de hardware:
- Arduino UNO para el manejo del hardware.
- Módulo ESP8266 para enviar/recibir instrucciones a través de un access point Wifi.
- Aro de burbujero de 360 grados.
- Motor de corriente continua para el movimiento del aro.
- Ventilador/Cooler para generar el aire de las burbujas.
- Fuente Multi Voltaje 12v 5v 3.3v Step Down para alimentar el Arduino.
- Doble Puente H Driver L9110s para alimentar los motores de CC.
- Estructura plástica o de madera para sostener el motor y el cooler.
- Recipiente para almacenar el agua jabonosa.

b) Partes de software:
- Código ingresado a la placa Arduino Uno utilizando como software intermediario
Arduino IDE para manejo de pines los cuales se conectan todos los dispositivos a
utilizar.
- Código ingresado al módulo ESP8266 utilizando como software intermediario
Arduino IDE para recibir información de un servidor local.
- El desarrollo de la página utilizada en el servidor local estará incluida en el código
ingresado al módulo ESP8266.
- Se utilizará HTML para estructurar y desarrollar la página web.

c) Sistema web:
- Sitio web sencillo en servidor local generado por el módulo ESP8266. El sitio incluye
un botón para encender y apagar el dispositivo y un campo para indicarle la potencia
del ventilador y del motor del aro del burbujero.
