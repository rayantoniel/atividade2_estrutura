# Terceira atividade de Estrutura de Dados - 3º Período
## Sistema de Estacionamento

Dupla: 

Maria Izabel Lemos da Silva

Ray Antoniel Silva Santos

## Objetivo

Repositório criado com o objetivo de realizar a implementação de um sistema na linguagem de programação C, que simula um estacionamento para a fixação dos conteúdos abordados na disciplina de Estrutura de Dados do curso de **bacharelado em Sistemas de Informação** do **IFAL - Instituto Federal de Educação, Ciência e Tecnologia de Alagoas**.

## Regras da atividade:

- A implementação deve ser realizada utilizando a linguagem C;
- Trabalhos iguais e/ou copiados na Internet receberão zero;
- Deverá haver uso de pilhas;
- No envio, além do código, deverá haver um mini tutorial explicando o funcionamento do programa;
- A avaliação será realizada baseada nos seguintes critérios:
  - Corretude: o programa deve fazer o que foi especificado;
  - Estruturas de dados utilizadas: adequação e eficiência;
  - Observação dos “bons modos” da programação: modularidade do código, documentação interna, etc.;
  - Funcionalidades extras implementadas;
  - Uso de outros assuntos vistos na disciplina.
 
## Situação escolhida: Situação 2

Um estacionamento é composto por dois becos que guarda até 10 carros cada. Existe apenas uma entrada/saída para acessar cada beco. Se chegar um cliente para retirar um carro que não seja o que está na saída, todos os carros bloqueando seu caminho sairão do estacionamento, o carro é removido, e os outros carros voltam para mesma sequência. O programa deverá informar toda vez que um carro entrar ou sair. Quando um carro chegar, o programa deverá informar se tem ou não vaga e em qual beco. Se não houver vaga, o usuário pode escolher se quer ou não ficar numa fila de espera. Quando abrir vaga, os carros que estão na fila, serão alocados no beco que houver vaga. Quando o carro sair, o programa deverá informar quantas vezes o carro foi manobrado, se ele ficou na fila de espera.

## Funcionalidades

* Entrar com carro do estacionamento
* Sair com o carro do estacionamento
* Visualizar situação dos carro no estacionamento
* Ver a quantidade de monobras de cada carro

## Considerações Finas

No projeto foram utilizadas estruturas de pilhas dinâmicas para lidar com a entrada e saída de carros nos becos do estacionamento. Dentro dessa utilização é possível abranger conceitos de struct, ponteiros, alocação de memória entre outros conteúdos abordados na disciplina. 
