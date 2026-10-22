# Bitácora — Obligatorio 1

**Integrantes:** Nombre Apellido (Nº estudiante), Nombre Apellido (Nº estudiante)

> **Instrucciones** (borrar esta sección antes de entregar): agregar una entrada por
> cada día trabajado, indicando la fecha y quién trabajó (un integrante o "En conjunto").
> Registrar el proceso real: ideas exploradas, decisiones y su justificación, partes de
> implementaciones, bugs encontrados y cómo se corrigieron, resultados de pruebas y dudas
> abiertas. Si se usó IA ese día, indicar herramienta, consulta y qué se hizo con la
> respuesta. Una bitácora escrita íntegramente el día de la entrega implica pérdida de puntos.

## 2026-09-03
- Se crearon los archivos AVL.h y AVLImp.cpp

## 2026-09-13
- Se agregaron los metodos del tad en AVL.h

## 2026-10-07
- Empecé de cero. Los profesores de práctico dijeron que no era necesario crear archivos .h. Se realizó completamente el ejercicio 1.

## 2026-10-12
- Se completó la justificación del ejercicio 1. Se utilizó IA para entender órdenes y revisar redacción.

## 2026-10-13
- Se realizó el ejercició 2 junto con su autoría y justificación. Se utilizó IA para entender órdenes y revisar redacción.

## 2026-10-21
- Se realizó el ejercicio 3 junto con su autoría y justificación. Se utilizó IA para entender órdenes, ejecutar pruebas y revisar redacción.
- Proceso: empecé usando int, tal cual estaba el MinHeap de clase. Al consultar con Claude, me señaló que tanto el costo total como los archivos consolidados pueden superar 32 bits. Le pregunté la diferencia entre long y long long: long no asegura 64 bits (en Windows, el SO que uso, es de 32 bits; en Linux y Mac es de 64), así que opté por long long. Al probar el código, Claude detectó que el while con !heap.esVacio() quedaba en bucle infinito, porque el heap nunca queda vacío. Lo cambié por heap.tamanio() > 1. También faltaba inicializar costo en 0. Probé con los 5 ejemplos de la letra y un caso con ayuda de Claude de N = 2·10⁶.