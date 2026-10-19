# Justificación de órdenes — Obligatorio 1

> **Instrucciones** (borrar esta sección antes de entregar): para cada ejercicio cuya
> letra plantea restricciones de órdenes (tiempo o espacio), justificar brevemente por
> qué la solución cumple, indicando qué estructuras de datos o algoritmos se utilizaron.
> Ejemplo: "La letra exige inserción en O(log n); usamos un min-heap sobre arreglo,
> donde flotar/hundir recorren a lo sumo la altura del árbol". Si un ejercicio no tiene
> restricciones de órdenes, indicarlo.

## Ejercicio 1
- ALTA y BUSCAR en orden temporal O(logK) en el peor caso: cumple ya que se utiliza un árbol AVL, este se mantiene siempre balanceado por lo que su altura es log K. Insertar y buscar recorren un solo camino hacia abajo.
- RANGO en orden temporal O(logK+R) en el peor caso: cumple, ya que se visitan los nodos que se imprimen (R) más los del camino para encontrar los bordes del rango. Ese camino mide como mucho la altura del árbol (log K).

## Ejercicio 2
- Registrar y consultar en orden temporal O(L) promedio: cumple. Primero se obtiene la etiqueta de la palabra contando cuántas veces aparece cada letra, lo que recorre la palabra una vez (O(L)) y luego las 26 letras del alfabeto, que es constante. Después se calcula el hash recorriendo la etiqueta una vez (O(L)). Por último se busca en el bucket: como el factor de carga es como mucho 1, en promedio hay O(1) cajones por bucket, y comparar dos etiquetas cuesta O(L). Además se guarda un solo nodo por cajón con un contador, en vez de un nodo por palabra, por lo que el costo no depende de cuántas palabras comparten cajón.
- Factor de carga: la tabla se crea con tamaño igual al primo siguiente a N. Como hay como mucho N cajones distintos, el factor de carga se mantiene siempre menor o igual a 1, sin necesidad de hacer rehash y sin reservar memoria de más. Se usa un número primo para que la función de hash distribuya mejor.
- Última línea en O(1) peor caso: cumple, ya que la cantidad de cajones y la cantidad de palabras del cajón más grande se actualizan en cada inserción con O(1) extra. Al final solo se devuelven esos valores, sin recorrer la tabla.
- Orden total lineal en promedio: cumple, ya que cada palabra registrada o consultada cuesta O(L), y la suma de todos los largos es el tamaño total de la entrada.

## Ejercicio 3
- Sin restricciones de órdenes. / Justificación: ...

## Ejercicio 4
- Sin restricciones de órdenes. / Justificación: ...

## Ejercicio 5
- Sin restricciones de órdenes. / Justificación: ...

