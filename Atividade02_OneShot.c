// Bibliotecas necessárias para o projeto
#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h"

// Definição dos pinos dos LEDs e do botão
#define LED_G_PIN 11
#define LED_B_PIN 12
#define LED_R_PIN 13
#define BUTTON_PIN 5

// Variáveis de controle
int ciclo_em_execucao = 0; // 0 = pronto para novo ciclo, 1 = ciclo em andamento

// Função para inicializar os LEDs e o botão
void inicializacaocomponentes() {
    gpio_init(LED_G_PIN);
    gpio_set_dir(LED_G_PIN, GPIO_OUT);
    gpio_put(LED_G_PIN, 0);

    gpio_init(LED_B_PIN);
    gpio_set_dir(LED_B_PIN, GPIO_OUT);
    gpio_put(LED_B_PIN, 0);

    gpio_init(LED_R_PIN);
    gpio_set_dir(LED_R_PIN, GPIO_OUT);
    gpio_put(LED_R_PIN, 0);

    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_PIN); // Resistor pull-up interno
}

// Funções de callback para desligar LEDs em sequência
int64_t desligar_led_vermelho_callback(alarm_id_t id, void *user_data) {
    gpio_put(LED_R_PIN, 0); // Desliga o LED vermelho
    ciclo_em_execucao = 0;  // Finaliza o ciclo
    return 0;
}

int64_t desligar_led_azul_callback(alarm_id_t id, void *user_data) {
    gpio_put(LED_B_PIN, 0); // Desliga o LED azul
    add_alarm_in_ms(3000, desligar_led_vermelho_callback, NULL, false);
    return 0;
}

int64_t desligar_led_verde_callback(alarm_id_t id, void *user_data) {
    gpio_put(LED_G_PIN, 0); // Desliga o LED verde
    add_alarm_in_ms(3000, desligar_led_azul_callback, NULL, false);
    return 0;
}

// Função principal
int main() {
    stdio_init_all();
    inicializacaocomponentes();

    while (true) {
        // Verifica se o botão foi pressionado e o ciclo não está em execução
        if (gpio_get(BUTTON_PIN) == 0 && ciclo_em_execucao == 0) {
            sleep_ms(50); // Debounce
            if (gpio_get(BUTTON_PIN) == 0) { // Confirmação da leitura
                // Liga os LEDs na ordem inversa: azul, vermelho, verde
                gpio_put(LED_B_PIN, 1);
                gpio_put(LED_R_PIN, 1);
                gpio_put(LED_G_PIN, 1);

                ciclo_em_execucao = 1; // Ciclo em andamento

                // Inicia o ciclo de desligamento com o LED verde após 3 segundos
                add_alarm_in_ms(3000, desligar_led_verde_callback, NULL, false);
            }
        }

        sleep_ms(10); // Reduz o uso da CPU
    }
    return 0;
}