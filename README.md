# Ejemplo de una aplicación extendible por plugins en Qt

La aplicación de este repositorio es un ejemplo de como podemos extender las características de nuestra aplicación de Qt mediante plugins.

Un plugin se puede ver como una biblioteca compartida que es cargada en tiempo de ejecución. Esta biblioteca, en términos prácticos, no es mas que una clase QObject que se instancia y se comunica con nuestra aplicación principal mediante una interface. La interface es una clase abstracta (solo tiene métodos virtuales puros) que es implementada por los plugins y utilizada para castear un puntero de instancia QObject para comunicarnos con nuestros plugins.

La aplicación principal se encuentra bajo la carpeta *SensorCapture*, y los plugin en *LightSensorPlugin* y *TempSensorPlugin* respectivamente.