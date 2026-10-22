# Bitácora — Obligatorio 1

**Integrantes:** Nombre Apellido (Nº estudiante), Nombre Apellido (Nº estudiante)

> **Instrucciones** (borrar esta sección antes de entregar): agregar una entrada por
> cada día trabajado, indicando la fecha y quién trabajó (un integrante o "En conjunto").
> Registrar el proceso real: ideas exploradas, decisiones y su justificación, partes de
> implementaciones, bugs encontrados y cómo se corrigieron, resultados de pruebas y dudas
> abiertas. Si se usó IA ese día, indicar herramienta, consulta y qué se hizo con la
> respuesta. Una bitácora escrita íntegramente el día de la entrega implica pérdida de puntos.

## 2026-10-07
- Proceso: se tomó como base el AVL del repositorio de la clase 1 y se convirtió en un template, ya que la letra pide un único TAD instanciado una vez por colección. Agregué el método pertenece para poder buscar bajando un solo camino del árbol, O(log K). Se agregó el método rango, que solo baja al subárbol izquierdo si desde < dato y al derecho si dato < hasta, ya que en el resto no puede haber claves dentro del intervalo. Así se visitan el camino hasta los bordes del rango más los R nodos que se imprimen, O(log K + R). Empecé instanciando el árbol de las monedas como int. Al consultar con Claude, me señaló que el número de catálogo llega a 10^12, así que lo cambié a long long. Para las pinturas se utilizó string, ya que el operador < de string da el orden alfabético.
- Pruebas: ejecuté a mano las pruebas de ejemplo de la letra y Claude generó pruebas con números de catálogo cercanos a 10^12.

## 2026-10-12
- Se completó la justificación del ejercicio 1. Se utilizó IA para entender órdenes y revisar redacción.

## 2026-10-13
- Se tomó como base el hash abierto del repositorio multiestructura, la clase Celda se adaptó como Cajon.
- Proceso: para identificar el cajón de cada palabra se utiliza una etiqueta. Claude me sugirió que los caracteres de las palabras tienen asociado un número, por lo que se puede rellenar un array de 26 lugares recorriéndolo una sola vez, que cumple O(L) en lugar del sort, que es O(L logL).
- Anteriormente, cada Celda guardaba un estado, ahora cada Cajon guarda un contador, así que solo un nodo por cajón y no uno por palabra.
- La función insertar primero busca, si existe hace contador++, si no, agrega el nodo.
- Los contadores de cajones y cajón más grande se actualizan al insertar, cumpliendo con el orden O(1).
- Pruebas: se hicieron a mano las 4 pruebas de ejemplo y Claude probó los casos más grandes, todos pasaron sin bugs.

## 2026-10-21
- Se realizó el ejercicio 3 junto con su autoría y justificación. Se utilizó IA para entender órdenes, ejecutar pruebas y revisar redacción.
- Proceso: empecé usando int, tal cual estaba el MinHeap de clase. Al consultar con Claude, me señaló que tanto el costo total como los archivos consolidados pueden superar 32 bits. Le pregunté la diferencia entre long y long long: long no asegura 64 bits (en Windows, el SO que uso, es de 32 bits; en Linux y Mac es de 64), así que opté por long long. Al probar el código, Claude detectó que el while con !heap.esVacio() quedaba en bucle infinito, porque el heap nunca queda vacío. Lo cambié por heap.tamanio() > 1. También faltaba inicializar costo en 0. Probé con los 5 ejemplos de la letra y, con ayuda de Claude, un caso de N = 2·10⁶.

## 2026-10-22
- Se realizó el ejercicio 4 completo. Se utilizó IA para entender la letra del ejercicio y las estructuras, entender órdenes, ejecutar pruebas y revisar redacción.
- Proceso: por el orden espacial O(V+A) descarté la matriz y utilicé una lista de adyacencia. Como el ejercicio plantea dependencias entre módulos, me decidí por el algoritmo de Kahn. El heap reemplaza a la cola de Kahn, ya que la letra pide el de menor prioridad y, si empatan, el de menor número. Tomé el grafo de la clase 6 de Kahn y lo adapté para el ejercicio. Pensé en convertir el heap existente en template, pero decidí copiarlo y adaptarlo al struct Modulo para no modificar el ejercicio 3.
- main: con Claude adaptamos el main del ejercicio a partir del main de la clase 6 de Kahn.
- Pruebas: ejecuté a mano los ejemplos de la letra y Claude probó un caso de V = 5·10⁵ y A = 10⁶.