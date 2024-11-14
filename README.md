# Código para los Kits del Semillero de Robótica
### Sobre el código
----------------------------------

- Este es un codigo creado para los kits vendidos en el año 2024 por el semillero de robótica
- La versión del IDE de Arduino utilizada fue la 2.3.3
- La versión de la libreria de Espressif para programación es la 2.0.11
- El Link para programar tarjetas Esp32:
`<link>` : https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json


### Importante
----------------------------------

* Se utilizó la libreria BluetoothSerial para la conexión bluetooth de la esp32

* Se cuenta con un Buzzer que sonará al oprimir el ícono correspondiente.

<p align="center">
  <img src="https://raw.githubusercontent.com/AnaOrozco122002/Kits_Robotica_2024-2/master/images/bocina.jpg" alt="Bocina" width="100" height="100">
</p>

* La aplicación de controlar el robot solo está disponible en Android para versiones mayores a 5.1

### Pines Usados
----------------------------------

Se utilizan los siguientes pines

* Pin para el Buzzer: 27 
* Pines de control de Dirección: Motor A: 33 y 32, Motor B: 25 y 26

### Aplicación
----------------------------------

* ### Instalación

    - Para la instalación de la aplicación es necesario tener un dispositivo Android, se debe pasar el archivo .APK que se encuentra en la carpeta raiz del repositorio al dispositivo

    <p align="center">
    <img src="https://raw.githubusercontent.com/AnaOrozco122002/Kits_Robotica_2024-2/master/images/kits-carpeta-ubicacion.jpg" alt="Bocina">
    </p>

    - Posterior a esto al tratar de abrir el archivo se debe aceptar la instalación de fuentes desconocidas (se debe esperar los 10 segundos necesarios y darle a aceptar).

    - Si para instalar la aplicación google play pide que se debe analizar la aplicación debe darle analizar y posterior a esto instalar.

    <p align="center">
    <img src="https://raw.githubusercontent.com/AnaOrozco122002/Kits_Robotica_2024-2/master/images/googlepermiso.jpg" alt="Bocina" height="300">
    </p>

    - Despues de la instalación se debe conectar mediante bluetooth (la interfaz de Android) al kit correspondiente. Una vez conectado mediante la interfaz de android el Kit ya aparecerá en la pestaña de lista bluetooth de la aplicación

* ### Botones

    La aplicación posee distintos botones que provocarán diferentes acciones en el kit

    - Los botones hacia los lados indican que el robot girará al lado correspondiente.

    <p align="center">
    <img src="https://raw.githubusercontent.com/AnaOrozco122002/Kits_Robotica_2024-2/master/images/lados.jpg" alt="Bocina" width="120" height="100">
    </p>

    - El boton superior indica al carro que se moverá hacia adelante, el boton hacia inferior indica que el carro se moverá hacia atrás.

    <p align="center">
    <img src="https://raw.githubusercontent.com/AnaOrozco122002/Kits_Robotica_2024-2/master/images/adatr.jpg" alt="Bocina" width="100" height="120">
    </p>

    - El boton de lista bluetooth mostrará una interfaz con los dispositivos cercanos (que esten enlazados) a los cuales se puede conectar (se debe conectar al kit correspondiente)

    <p align="center">
    <img src="https://raw.githubusercontent.com/AnaOrozco122002/Kits_Robotica_2024-2/master/images/conect.jpg" alt="Bocina" width="350" height="100">
    </p>

    - El boton de la bocina provocará que suene el Buzzer.

    <p align="center">
    <img src="https://raw.githubusercontent.com/AnaOrozco122002/Kits_Robotica_2024-2/master/images/bocina.jpg" alt="Bocina" width="100" height="100">
    </p>

* ### Importante

    - Precionar Varios botones a la vez provocará que la aplicación no funcione correctamente.
    - Al hacer sonar el buzzer el carro no responderá a ningun otro movimiento por la duración de 500 milisegundos.



