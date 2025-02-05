# _Temporidazor Oneshot EmbarcaTech - Atividade EmbarcaTech 29-02-25_

Este repositório foi desenvolvido para fins educativos e apresenta um sistema de controle de LEDs utilizando o microcontrolador Raspberry Pi Pico W. O projeto explora a função add_alarm_in_ms() do Pico SDK e com funções de callback do temporizador. O sistema é acionado quando o usuário pressiona o botão, iniciando uma sequência programada de desligamento dos LEDs em intervalos de tempo definidos.

# Como utilizar?

- Você pode baixar este repositório no GitHub ou clonar o link na sua IDE(VsCode) utilizando o Git/Github Desktop.
Ex.: Com o git e o gitHub instalados no seu computador, você irá abrir sua IDE e inserir no terminal:
 ```sh
   git clone https://github.com/Lana-Ramos/Temporidazor-Oneshot-EmbarcaTech.git
```
- Abrir a pasta Temporizador-Oneshot-EmbarcaTech na sua IDE
- Instalar um compilador para C/C++ e as extensões: C/C++, Cmake, Raspberry Pi Pico e Wokwi.
- Compilar o código pelo ícone da Raspberry Pi (considerando o VSCode como IDE padrão) e enviar o código para sua placa
- Se não possuir o Raspberry Pi Pico W, você pode utilizar a simulação do Wokwi para testar o funcionamento do programa.

# Componentes

- Raspberry Pi pico W(ou extensão Wokwi para simular os componentes)
- 3 LEDs RGB
- 3 resistores de 330 Ohms
- Botão (Push Button)

# Linguagem Utilizada

**C**
  
# Funcionamento 

- Aguarda o usuário apertar o botão
- Assim que o botão é pressionado todos os 3 LEDs se acendem;
- A cada 3 segundos (3.000ms), um LED será desligado até que todos estejam apagados.

# Autor 

Lana Ramos Gomes
