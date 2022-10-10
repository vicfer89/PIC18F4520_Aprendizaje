# PIC18F4520_Aprendizaje

> Repositorio para aprendizaje con PIC18F4520, basado en programación ISP via UART. Placa: _SURE DB-DP113V310_

### Elementos empleados
- Bootloader _TinyBootloader_ en web [TinyBootloader](http://www.etc.ugal.ro/cchiculita/software/picbootloader.htm)
  - Descargar de _TinyBootloader_ la versión de 2008 y la de 2011, ya que en la de 2008 viene el Bootloader a cargar en el microcontrolador.
- Tutorial de uso [Tutorial PIC con Tiny Bootloader](http://tecbolivia.com/index.php/articulos-y-tutoriales-microcontroladores/57-tutorial-pic-con-tiny-bootloader) y [Video de uso y carga de Bootloader](https://www.youtube.com/watch?v=jfz5XRaPo98)

### Troubleshooting
- Problemas con TinyBootloader: [PIC16F4550 tinybootloader](https://www.microchip.com/forums/m917450.aspx)

### Notas Importantes

**NOTA:** _Los rangos para ROM han de evitar ser 4-3f00 para que el compilador no sobreescriba direcciones de memoria correspondientes al bootloader_

Para esto, en las opciones del proyecto, en XC8 Linker > "Option Categories" > Memory Model, establecer en ROM Ranges 4 - 3f00 para evitar sobrescribir ese rango.

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
