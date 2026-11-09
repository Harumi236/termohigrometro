# termohigrometro


- Registrar Temperatura y Humedad cada 5 minutos
- Reproducir en pantalla la información
- Almacenar la información temporalmente
- Transmitir la información al siguiente nodo o a la central


Se necesita:
- Controlador Arduino central
- Sensores de temperatura y humedad
- Reloj de tiempo real
- Pantalla led
- Transmisor de señal innalambrica


Funciones que debe tener:

func LeerDatos:
    t = sensor.temperatura
    h = sensor.humedad
    time = reloj.datetime.now


func MostrarPantalla(t, h, time):
    pantalla.show(self.id, t, h, time)

func AlmacenarDatos(t, h, time):
    almacenador.guardar(self.id, t, h, time)

func EnviarDatos(t, h, time)
    transmisor.enviar(self.id, t, h, time)


