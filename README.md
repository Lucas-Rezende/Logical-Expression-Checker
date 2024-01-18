# Logical-Expression-Checker

## Introdução
Este programa se trata de um trabalho prático desenvolvido nas aulas de Estruturas de Dados, lecionadas pela UFMG. Foi proposto que fosse implementado um avaliador de expressões lógicas - afirma se ela é verdadeira ou falsa -  e um verificador de satisfabilidade - tal qual o anterior, afirma se é verdadeira ou não, porém, se for verdadeira, também mostra uma valoração satisfazível para a expressão diante dos operadores "EXISTE"(∃) e "PARA TODO"(∀). Como solução, para interpretar as expressões lógicas, foram criados métodos para compreender o que cada caractere significa, aplicar a precedência de operação e converter a expressão de infix para postfix. Em suma, esse programa avalia a veracidade de expressões lógicas e verifica a satisfabilidade. Se a expressão for verdadeira, o programa também fornece uma valoração satisfatória. O programa interpreta expressões lógicas e aplica a precedência de operação.

## Como usar
Os inputs devem ser dados da seguinte maneira:
<pre><code>[1] = ./tp1.out; [2] = ‘-a’ ou ‘-s’; [3] = ‘expressão’; [4]=’valoração’</code></pre>

## Instruções de Compilação
Para utilizar este código é necessário que, ao estar na raíz do projeto via terminal, você crie manualmente as pastas ‘obj’ e ‘bin’ e, após isso, seja dado o comando:
<pre><code>make all</code></pre>
Dessa maneira o programa será devidamente compilado e estará disponpivel para uso.
