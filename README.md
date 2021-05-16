# PIC18F4520_Aprendizaje

> Repositorio para aprendizaje con PIC18F4520, basado en programación ISP via UART. Placa: _SURE DB-DP113V310_

**NOTA:** _Los rangos para ROM han de ser 4-3f00 para que el compilador no sobreescriba direcciones de memoria correspondientes al bootloader_

## Lista de tareas a completar:

- [x] Creación de proyectos en MPLAB y familiarización con el entorno
- [x] Compilación y carga de programa _Hello World_ con leds parpadeando
- [x] Escritura de GPIO
- [x] Lectura de GPIO
- [x] Inicialización de interrupciones
- [x] Instanciación y prueba de ISR y comprobación de que funciona
- [ ] Creación de librerías para uso de UART
  - [ ] Estudio de periférico
  - [ ] Librerías básicas de soporte a escritura por UART
  - [ ] Lectura de UART mediante interrupciones y polling
- [ ] Búsqueda de esquemáticos de placa, y en base a ellos:
  - [ ] Generación de librerías para ISR en fichero independiente, unión mediante _weak_ para poder reinstanciar las funciones como callbacks
  - [ ] Generación de librerías para displays de 7 segmentos (just for fun!)
  - [ ] Generación de librerías para display LCD (just for fun!)
