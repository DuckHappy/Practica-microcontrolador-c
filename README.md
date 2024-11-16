# Practica-microcontrolador-c
Practica que fue tomada y evaluada, donde se le debia conectar con un microcontrolador dado y realizar el programa para que este cumpla las condiciones de los puntos

Objetivo del Parcial: Diseñar programas que soporte manejo de interrupciones (externas o timers) y ejecuten en un microcontrolador ESP32 utilizando el entorno ESP-IDF
Desarrollo: Se realiza una demo de un proyecto que cubre los siguientes temas:

● Inicialización del ESP-IDF
  ○ get_idf
  
● Creación de proyecto con ESP-IDF
  ○ idf.py create-project LedPulse
  ○ cd LedPulse
  
● Configuración del hardware
  ○ idf.py set-target esp32c3
  
● Apagado del watchdog
  ○ idf.py menuconfig
    ■ Opción ESP System Settings > Interrupt Watchdog (apagado),Enable Task Watchdog Timer (apagado)
    
![Descripción de la imagen](Github/photo.png)

● Agregamos una biblioteca para el componente LED RGB (https://components.espressif.com/components/espressif/led_strip )
  ○ idf.py add-dependency "espressif/led_strip^3.0.0"
  
● Editamos el código fuente de LedPulse.c
  ○ geany main/LedPulse.c

● Compilamos el código
  ○ idf.py build
  
● Una vez compilado , grabamos el código en la memoria flash
  ○ idf.py flash




  
