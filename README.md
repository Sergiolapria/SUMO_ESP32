# SUMO


##  Descripción

Robot de sumo sencillo para que el alumnado de ESO se introduzca en la robotica de manera natural.

---

##  Características

-Lenguaje natural
-Sencillo

---

## Materiales
 -ESP32
 - 2 servomotores sg 9g de rotación continua
 - Portapilas de 4 pilas AA
 - 2 juntas toricas de Diametro 40 mm
 - Un interruptor.
 - tira de pines
---

## Programacion
El lenguaje a usar en el void loop son 3 ordenes:
-Medir_distancia(); la cual nos devuelve una valor en la variable distance
-MotorI(sentido);
-MotorD(sentido);
    Segun sea el valor de sentido( -1, 0, 1) el motor girara en un sentido, parara, o girara en sentido contrario.

Se combinara con intruccion if, condicional, for o while para darle poder de decision al robot.