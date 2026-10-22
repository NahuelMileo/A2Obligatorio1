# Justificación de órdenes — Obligatorio 1

## Ejercicio 1
- ALTA y BUSCAR en orden temporal O(logK) en el peor caso: cumple ya que se utiliza un árbol AVL, este se mantiene siempre balanceado por lo que su altura es log K. Insertar y buscar recorren un solo camino hacia abajo.
- RANGO en orden temporal O(logK+R) en el peor caso: cumple, ya que se visitan los nodos que se imprimen (R) más los del camino para encontrar los bordes del rango. Ese camino mide como mucho la altura del árbol (log K).

## Ejercicio 2
- Registrar y consultar en orden temporal O(L) promedio: cumple. Primero se obtiene la etiqueta de la palabra contando cuántas veces aparece cada letra, lo que recorre la palabra una vez (O(L)) y luego las 26 letras del alfabeto, que es constante. Después se calcula el hash recorriendo la etiqueta una vez (O(L)). Por último se busca en el bucket: como el factor de carga es como mucho 1, en promedio hay O(1) cajones por bucket, y comparar dos etiquetas cuesta O(L). Además se guarda un solo nodo por cajón con un contador, en vez de un nodo por palabra, por lo que el costo no depende de cuántas palabras comparten cajón.
- Factor de carga: la tabla se crea con tamaño igual al primo siguiente a N. Como hay como mucho N cajones distintos, el factor de carga se mantiene siempre menor o igual a 1, sin necesidad de hacer rehash y sin reservar memoria de más. Se usa un número primo para que la función de hash distribuya mejor.
- Última línea en O(1) peor caso: cumple, ya que la cantidad de cajones y la cantidad de palabras del cajón más grande se actualizan en cada inserción con O(1) extra. Al final solo se devuelven esos valores, sin recorrer la tabla.
- Orden total lineal en promedio: cumple, ya que cada palabra registrada o consultada cuesta O(L), y la suma de todos los largos es el tamaño total de la entrada.

## Ejercicio 3
- Orden temporal O(N log N) en el peor caso: cumple. Se utiliza un min-heap binario sobre un arreglo. Como el heap es un árbol binario completo, su altura es log N, y flotar y hundir recorren a lo sumo esa altura, por lo que insertar y eliminarMinimo son O(log N) en el peor caso.
  1. Carga: se realizan N inserciones de O(log N) cada una, por lo que la carga es N · O(log N) = O(N log N).
  2. Consolidación: cada iteración del while ejecuta dos veces eliminarMinimo y una vez insertar, por lo que el heap tiene un elemento menos en cada vuelta. Como pasa de N elementos a 1, el while da N−1 vueltas, cada una O(log N), y la consolidación es (N−1) · O(log N) = O(N log N).
  En total: O(N log N) + O(N log N) = O(N log N).
- Orden espacial O(N): cumple. Se utiliza un solo arreglo de long long de tamaño N, que nunca se llena más allá de N porque cada vuelta saca dos elementos y agrega uno. El resto son variables sueltas (a, b, nuevo, costo) que ocupan O(1).
- El costo total puede superar el rango de un entero de 32 bits: se utilizó long long (64 bits) en la variable costo, en a, b y nuevo, y en el arreglo del heap. No alcanza con el acumulador, porque los archivos consolidados también crecen (el último puede pesar 2·10¹²) y se vuelven a insertar en el heap, así que superarían el rango de un int.

## Ejercicio 4
- Orden temporal O((V+A) log V) en el peor caso: cumple. Se utiliza el algoritmo de Kahn sobre una lista de adyacencia, con un min-heap binario en lugar de la cola.
  1. Lectura: las prioridades son O(V). Cada arista se agrega al grafo en O(1) y en el mismo momento se suma el grado del destino, así que todas las aristas son O(A).
  2. Heap: cada módulo entra una sola vez (cuando su grado llega a 0) y sale una sola vez. Insertar y eliminarMinimo son O(log V) porque recorren a lo sumo la altura del heap, así que en total es O(V log V).
  3. Vecinos: cada arista se recorre una sola vez, cuando sale su origen, así que es O(A).
  En total: O(V + A + V log V), que está dentro de O((V+A) log V).
- Orden espacial O(V+A): cumple. La lista de adyacencia ocupa O(V+A), y los arreglos prioridad, grado y orden y el heap ocupan O(V) cada uno.
- El heap compara primero por prioridad y, si empatan, por número, así que siempre sale el módulo que pide la letra. Si al final se procesaron menos de V módulos hay un ciclo y se imprime "imposible". Como el orden se imprime recién al final, en ese caso no sale ningún módulo.

## Ejercicio 5
- Orden temporal O(E log E) en el peor caso: cumple. Se utiliza el algoritmo de Kruskal con un min-heap binario de aristas y un MFSet.
  1. Carga: se realizan E inserciones en el heap. Como el heap es un árbol binario completo, su altura es log E, y flotar recorre a lo sumo esa altura, así que cada inserción es O(log E) y la carga es E · O(log E) = O(E log E).
  2. Kruskal: el while saca a lo sumo E aristas del heap, cada una con eliminarMinimo en O(log E), así que es O(E log E). Por cada arista se llama a unir, que hace dos llamadas a representante. Con unión por altura, el árbol más bajo se cuelga del más alto y la altura solo crece en el empate, así que la altura de cada árbol del MFSet es a lo sumo log V y representante es O(log V). Además, la compresión de caminos acorta los caminos en cada búsqueda, así que en la práctica cuesta casi O(1) amortizado.
  3. Para que el grafo sea conexo hace falta E ≥ V−1, así que log V = O(log E), y las llamadas a unir son E · O(log V) = O(E log E).
  En total: O(E log E) + O(E log E) = O(E log E).
- Orden espacial O(V+E): cumple. El heap guarda las E aristas en un arreglo, O(E). El MFSet tiene dos arreglos (padre y altura) de tamaño V+1, O(V). El resto son variables sueltas, O(1).
- El costo total puede superar el rango de un entero de 32 bits: se utilizó long long en costoTotal. Con V−1 = 10⁵−1 senderos de costo 10⁶, el total llega a ~10¹¹. El costo de cada arista se guarda en int porque es como mucho 10⁶.
- El while corta cuando se eligen V−1 senderos, porque con esa cantidad ya están todos los refugios conectados. Si al terminar se eligieron menos de V−1 senderos, el grafo no es conexo y se imprime "imposible". Con un solo refugio, V−1 = 0, el while no entra y se imprime 0.