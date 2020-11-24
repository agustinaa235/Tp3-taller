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
   relacion entre ellos. A continuacion se explicaran alguna clases del tp:

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

# Criterios de disenio

  * Se decicio de tener 2 clases que herenden de std::excepcion que son SocketError
    y archivo error. Luego si llega a lanzarse alguna excepcion de std::excepcion
    se la catchea en los dos mains. Estas se las tiene en un mismo .h

  * Se decidio para mayor proligidad crear, lanzar y destruir el hilo aceptador
    dentro del servidor y no en el main. Entonces cuando se invoca a servidor
    cerrar se cierra el socket listener y ahi se deja de aceptar y se liberan
    todos los hilos.

  * Se decidio tener una clase abstracta pura que es metodo de la cual herendan
    los distintos metodos( get, post, invalida) creados por el parceador. Estos
    metodos se crean con el mensaje correspiende que le llega del parecador, ya
    se el body si lo necesita o el recurso, etc.
    Tambien se decicio que el metodo get sin recurso reciba el nombre del archivo
    y esto lo abra y lo lea. Esto no genera race condion ya que solo se trata de
    leer el archivo.
    Se decidio tener los dos casos de get en un mismo .h. Lo mismo sucede para
    post.

  * Se decidio tener una una clase recursos que funcionaria como monitor que se
    encarga de proteger al mapa. Tambien se creo la clase Lock para cumplir con
    RAII

  * El operador () se sobrecargo en la clase parceador cuando el servidor
    le pide la primer linea del petitorio.

# Diagramas de clase

   ![digrama relacion general](https://github.com/agustinaa235/tp3/blob/main/relacion_principal.png)
   ![digrama relacion metodos](https://github.com/agustinaa235/tp3/blob/main/relacion_metodos.png)
   ![digrama relacion sockets](https://github.com/agustinaa235/tp3/blob/main/relacion_socket.png)
   ![digrama relacion herencia threads](https://github.com/agustinaa235/tp3/blob/main/herencia_thread.png)

# Segunda entrega

* se mejoro el uso de excepciones teniendo en los mains principales teniendo
  el catch de  std::exception y de las elipsis.

* SE proferio a los hilos aceptadr y conexion clientes con excepciones, agregandole
  sus correspondiente catchs.

* se quito la race condition que se generaba por el uso sobre de << en el hilo
conexion clientes.

* se modifico la logica de recibir del socket y de recibir petitorio en
  la clase conexion clientes.

* tambien se creo una clase generica Exception  y tanto en esta clase como
  en socketError se sobreesribe el metodo what.

* se agrego el uso de la libreria std::lock_guard y se quito la clase Lock
  implementada por el alumno. 
