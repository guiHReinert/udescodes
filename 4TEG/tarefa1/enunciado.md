
# Tarefa 1

Equipes com MÁXIMO de 3 MEMBROS.

## Especificação

Implementação de um grafo com carga primária a partir de um arquivo CSV.

O grafo será representado na forma de uma lista de adjacências primariamente carregado
a partir de uma base de dados no formato CSV (valores separados por vírgulas). No caso,
a base utilizada será a “teste2.csv” disponível no Moodle.

## Requisitos

1. Implementação em linguagem C;

2. O sistema tem que permitir a carga primária do grafo a partir da base CSV, a qual
corresponde a uma lista de adjacências. Cada linha do arquivo possui dois campos que
correspondem ao par de vértices de uma aresta;
Ex: a linha contendo “100 200” indica uma aresta entre o V100 e V200

3. O sistema deve fornecer o grau máximo e o mínimo de vértice do grafo;

4. O sistema deve informar se o grafo é simples ou multigrafo. Se for multigrafo deve
informar quantos laços e/ou arestas múltiplas ocorrem;

5. O sistema deve informar quantos componentes conexos existem no grafo.

> *OBS: Determinar a distribuição dos componentes conexos, quantidade de componentes e seus respectivos tamanhos.*

## Critérios de Correção

1. Implementação em ‘C’ (o trabalho será testado no ambiente Ubuntu);

2. Correção (ausência de bugs, ausência de erros de execução e de lógica, etc...);

3. Funcionamento de acordo com as especificações;

4. Entrega no formato solicitado (veja descrição no link de upload no Moodle);

5. Pode ser aplicada uma entrevista.

## Formato da Entrega

Upload de TODOS os recursos utilizados na implementação da solução bem como de um relatório;

Utilize compactação contendo todo o conteúdo da solução e nomeie o arquivo com os nomes dos autores (ou do autor único, se for o caso), por exemplo: RobertoC_ErasmoC.zip para a dupla Roberto Carlos e Erasmo Carlos.

### Estrutura do relatório

1. Identificação da equipe;

2. Identificação da tarefa;

3. Explicação conceitual sobre a solução fornecida: entrada, processo, saída;

4. Instruções sobre a compilação: usou IDE/projeto? Usou linha de comando? carregou alguma lib específica?

5. Descrição/análise de resultados.

### Atenção sobre Descontos

1. "Data de entrega": limite para entrega sem desconto de nota, a partir desta data há aplicação de desconto na nota;  

2. "Data limite" (firm deadline):  limite para entrega em atraso e com desconto de nota;

3. Para as entregas atrasadas haverá desconto de no máximo 10 pontos. O desconto é proporcional ao atraso, conforme é explicado a seguir:
    > 0 <= d <= 10;
    >
    > A nota final "N1" será N1=10-d;
    >
    > "d"  proporcional à quantidade de horas de atraso "h", segundo a relação d=round(h/12).
    >
    > Exemplos de descontos:
    >
    > 1. Subiu a solução 3 horas depois da data de entraga: atraso=3 horas, d=round(3/12)
    > 2. Subiu a solução com atraso=20 horas, d=round(20/12)=round(1,6666)=2,0
    > 3. Subiu a solução às 23:59:59 do último dia da data limite (quinto dia), atraso=120 horas, d=round(120/12)=10

4. Lembrem-se que, além da correção das soluções, também se aplica o critério comparativo entre soluções na determinação da nota da avaliação. Bem como a dupla pode ser chamada para uma entrevista que corrobore a solução apresentada.

<!--
Source - https://stackoverflow.com/a/15422454
Posted by creativecoder, modified by community. See post 'Timeline' for change history
Retrieved 2026-05-05, License - CC BY-SA 4.0
-->

<style type="text/css">
    ol { list-style-type: upper-alpha; }
</style>
