# Milestone2 Push Swap

Este projeto faz parte do currículo da 42 e tem como objetivo ordenar uma lista de inteiros utilizando apenas duas pilhas (`a` e `b`) e um conjunto limitado de operações.  

O desafio principal não é apenas ordenar corretamente, mas **encontrar uma solução eficiente com o menor número de operações possível**.  

## 🔧 Regras do Projeto  

- Entrada: uma lista de números inteiros (positivos, negativos ou zero).  
- O programa deve imprimir **a sequência de operações** necessárias para ordenar a pilha `a` em ordem crescente, utilizando `b` como auxiliar.  
- Apenas as seguintes operações são permitidas:

sa sb ss → swap
pa pb → push
ra rb rr → rotate
rra rrb rrr → reverse rotate

- Erros devem ser tratados corretamente: entradas inválidas, números fora do range `int`, duplicados, etc.  
- Caso a pilha já esteja ordenada, nenhuma operação deve ser realizada.  

## 🚀 Minha Solução  

A minha implementação segue estes passos:  

1. **Validação de entrada**  
   - Verifico se não existem argumentos, e/ou strings vazias.  
   - Se o input for inválido, o programa encerra com `Error` na saída de erro.  

2. **Parsing**  
   - Caso o número de argumentos seja maior que 2, junto tudo em uma string única e depois separo com `split`.  
   - Converto cada item para `int` usando `atoi`.  

3. **Construção da Stack A**  
   - Cada número é armazenado já com o **índice da posição esperada** (indexação).  
   - Antes de começar, verifico se a pilha já está ordenada — se sim, o programa termina imediatamente.  

4. **Separação em containers (chunk sorting adaptativo)**
  - Devem sobrar apenas 3 itens em A: os 3 maiores para organiza-los manualmente e depois trazer os containers de B.
   - Divido os índices em **containers de tamanhos decrescentes**:  
     - 0 a 100  
     - 100 a 170  
     - 170 a 200  
     - … e assim por diante.  
   - Envio os números de `a` para `b` respeitando a seguinte regra:  
     - Se o índice está na **metade superior do container**, o número vai para o topo de `b`.  
     - Se está na **metade inferior**, aplico `rb` para empurrá-lo para baixo.

6. **Reconstrução da Stack A**  
   - Os elementos são devolvidos da pilha `b` para `a` do **maior para o menor**, garantindo que `a` seja reconstruída já em ordem crescente.  

7. **Limpeza**  
   - Ao final, libero toda a memória utilizada pelas pilhas `a` e `b`.  

## 📈 Estratégia  

Essa abordagem aproveita o conceito de **chunk sorting**, mas com uma adaptação: os containers diminuem progressivamente, o que melhora a eficiência e reduz a quantidade de operações.  

- O uso da divisão em duas metades ao empilhar em `b` garante que os maiores números estejam mais acessíveis ao voltar para `a`.  
- O retorno organizado (maiores para menores) assegura que `a` já fique em ordem crescente sem necessidade de passos adicionais.  

## 🛠️ Como usar  

```bash
make
./push_swap 2 1 3 6 5 8
Saída esperada (sequência de operações):
pb
pb
sa
pa
pa
