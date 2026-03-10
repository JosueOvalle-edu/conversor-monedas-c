#include <stdio.h>
#include <stdlib.h>

/* Tasas de cambio aproximadas (basadas en valores reales) */
#define GTQ_A_USD 0.1333  /* 1 GTQ = 0.1333 USD */
#define USD_A_GTQ 7.5     /* 1 USD = 7.5 GTQ */
#define EUR_A_USD 1.10    /* 1 EUR = 1.10 USD */
#define USD_A_EUR 0.9091  /* 1 USD = 0.9091 EUR */
#define EUR_A_GTQ 8.25    /* 1 EUR = 8.25 GTQ */
#define GTQ_A_EUR 0.1212  /* 1 GTQ = 0.1212 EUR */

void mostrarMenu() {
    printf("\n========================================\n");
    printf("   CONVERSOR DE MONEDAS\n");
    printf("========================================\n");
    printf("1. Convertir de Quetzales (GTQ)\n");
    printf("2. Convertir de Dólares (USD)\n");
    printf("3. Convertir de Euros (EUR)\n");
    printf("4. Salir\n");
    printf("========================================\n");
    printf("Selecciona una opción: ");
}

void mostrarOpcionesDestino() {
    printf("\n¿A qué moneda deseas convertir?\n");
    printf("1. Quetzales (GTQ)\n");
    printf("2. Dólares (USD)\n");
    printf("3. Euros (EUR)\n");
    printf("Selecciona una opción: ");
}

float convertir(float cantidad, int monedaOrigen, int monedaDestino) {
    float resultado = cantidad;
    
    /* Primero convertimos a USD como moneda base */
    if (monedaOrigen == 1) { /* De GTQ */
        resultado = cantidad * GTQ_A_USD;
    } else if (monedaOrigen == 3) { /* De EUR */
        resultado = cantidad * EUR_A_USD;
    }
    /* Si es USD, resultado sigue siendo cantidad */
    
    /* Ahora convertimos de USD a la moneda destino */
    if (monedaDestino == 1) { /* A GTQ */
        resultado = resultado * USD_A_GTQ;
    } else if (monedaDestino == 3) { /* A EUR */
        resultado = resultado * USD_A_EUR;
    }
    /* Si es USD, resultado sigue siendo el valor en USD */
    
    return resultado;
}

const char* obtenerNombreMoneda(int moneda) {
    switch (moneda) {
        case 1:
            return "Quetzales (GTQ)";
        case 2:
            return "Dólares (USD)";
        case 3:
            return "Euros (EUR)";
        default:
            return "Moneda desconocida";
    }
}

const char* obtenerSimboloMoneda(int moneda) {
    switch (moneda) {
        case 1:
            return "Q";
        case 2:
            return "$";
        case 3:
            return "€";
        default:
            return "";
    }
}

void realizarConversion() {
    int monedaOrigen, monedaDestino;
    float cantidad, resultado;
    
    mostrarMenu();
    scanf("%d", &monedaOrigen);
    
    if (monedaOrigen == 4) {
        printf("¡Hasta luego!\n");
        exit(0);
    }
    
    if (monedaOrigen < 1 || monedaOrigen > 3) {
        printf("Opción no válida. Intenta de nuevo.\n");
        return;
    }
    
    printf("\nIngresa la cantidad en %s: ", obtenerNombreMoneda(monedaOrigen));
    scanf("%f", &cantidad);
    
    if (cantidad < 0) {
        printf("La cantidad no puede ser negativa.\n");
        return;
    }
    
    mostrarOpcionesDestino();
    scanf("%d", &monedaDestino);
    
    if (monedaDestino < 1 || monedaDestino > 3) {
        printf("Opción no válida. Intenta de nuevo.\n");
        return;
    }
    
    if (monedaOrigen == monedaDestino) {
        printf("\nLa cantidad permanece igual: %.2f %s\n", 
               cantidad, obtenerSimboloMoneda(monedaOrigen));
        return;
    }
    
    resultado = convertir(cantidad, monedaOrigen, monedaDestino);
    
    printf("\n========== RESULTADO ==========\n");
    printf("%.2f %s = %.2f %s\n", 
           cantidad, obtenerSimboloMoneda(monedaOrigen),
           resultado, obtenerSimboloMoneda(monedaDestino));
    printf("================================\n");
}

int main() {
    int opcion;
    
    printf("\n¡Bienvenido al Conversor de Monedas!\n");
    
    while (1) {
        realizarConversion();
    }
    
    return 0;
}
