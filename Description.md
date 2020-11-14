- La interfaz Handler declara un método para construir la cadena de Handlers. 
  También declara un método para ejecutar una solicitud.
- El comportamiento de encadenamiento predeterminado se puede implementar 
  dentro de una clase de Handler base.
- Todos los Concrete Handlers manejan una solicitud o la pasan al siguiente 
  Handler de la cadena.
- El código de cliente suele ser adecuado para trabajar con un solo Handler. 
  En la mayoría de los casos, ni siquiera es consciente de que el Handler es 
  parte de una cadena.
- La otra parte del código del cliente construye la cadena real.
- El cliente debería poder enviar una solicitud a cualquier Handler, no solo al 
  primero de la cadena.