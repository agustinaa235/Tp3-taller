# tp3

# Informacion Alumno

    Nombre: Agustina Segura

    Padron: 104222

# Introduccion

    El tp consta de procesar protocolos http. El cliente envia el un
    petitorio al servidor este lo procesa y le devuelve la informacion
    ya porcesada al cliente.
    En este tp se atenderan a multiples clientes por lo que se hara uso
    de hilos.

# Disenio

    El disenio del tp consta de modelar una clase cliente y una clase
    servidor y todas sus correspondiente clases para implemnetar la
    relacion entre ellos. Para ello se crearon distintas clases:

    * Servidor

      Esta clase por dentro realizara un bine and listen y luego lanzara
      un hilo aceptador en donde este manejara el aceptado de clientes. A su
      vez tiene como atributo un servidor de recursos donde se guardara lo que
      manda el cliente.

    * Cliente

      Esta clase se encarga de mandar los petitorios que recibe por entrada
      estandar y una vez que el servidor proceso los datos, este lo recibe y
      los imprime.

    * Aceptador

      Esta clase es la encargada de manejar el acepto de cada conexion de
      un cliente que llega. Esta crea a los hilos conexion clientes y los lanza.
      Tambien es la encargada de ir limpeando y liberando lso recursos de un hilo
      si es que termino. Si llega un -1 cuando se invoca a la funcion aceptar
      se la cachea y se liberan a todos los hilos.

    * Conexion clientes

      En esta clase se maneja el procesamiento del servidor con cada mensaje
      que le llega del cliente. Recibe un mensaje donde este es procesado
      por el parceador y luego se encarga de enviarselo al cliente.

    * Parceador

      Se encarga de parcear el mensaje creando y devolviendo 5 metodos en base
      a lo que le llega. Estos pueden ser Get con y sin recurso, Post con y sin
      recurso y una instruccion invalida. En esta clase fue en donde se
      implemnto la sobrecarga del operador () cuando se le pide que procese
      el petitorio y devuelva la primer linea.

    * Servidor Recursos

      Esta clase es la encargada de almacenar el request con el body del mensaje
      en un mapa. Tambien es la encragada de manjera el raice condition que se
      genera cuando se esta  ingresando un request y a la vez se lo esta pidiendo.
      Esto lo hace por medio de mutex.

    * Metodo - Get- Post - Invalidad

      La clase metodo es una clase abstarcta pura en la cual los dos formatos
      gets, los dos formatos post y la clase invalida herendan.
      En esas clases se encargan de obtener la respuesta generada por el servidor
      de manera poliforfica.

      
