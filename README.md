Em nosso projeto nos fizemos um Exchange de Criptomoedas, isto é, um menu onde se pode interagir com as criptomoedas, mas de forma imaginária, usamos o Bitcoin, o Ethereum e o Ripple de referência. 
Nele nós adicionamos diversas caracteristícas, como consultar seu saldo atual de cada criptomoeda e em R$ (reais), a compra e a venda de cripto, o deposito e o saque de R$, e podendo atualizar a cotação também por exemplo.

O programa funciona com 3 arquivos principais: main.c , funcoes.c e funcoes.h ; Esses arquivos são os que contém todo o código em c e suas bases para funcionamento, porém é necessário ter ao menos um dos arquivos binários de armazenamento de dados do usuário para funcionamento completo do programa, já que é neles que se localizam os valores das variáveis do programa (cada arquivo binário é completo, contendo informações do saldo, extrato e cotação), mas ficara limitado ao usuário do arquivo baixado(para a experiencia completa baixe todos os arquivos).

Os usuários e suas senhas seguem um padrão, os primeiros 10 dígitos são a sequência da base decimal a partir do 1, ou seja: 123.456.789-0 (não é necessário a utilização de pontos [.] e sinais [-] na hora de preencher os campos do programa); o último digito vai de 0 a 9, sendo esse digito utilizado na senha três vezes (Ex: senha: 222); os usuários do programa seguem esses padrões. (Ex: cpf: 12345678902 senha:222)

Para colocar nosso código para funcionar é simples, e pode ser feito pelos seguintes passos:
1. Com o código aberto e todos os arquivos na mesma pasta, crie um terminal.
2. No terminal digite o seguinte comando, "gcc main.c funcoes.c -o Programa" (A palavra programa pode ser subistituida pela palavra de sua preferência), para este passo você precisa ter o gcc baixado em seu computador, caso não tenha veja no YouTube como instalar, é rápido e gratuito.
3. Por fim, digite o seguinte comando: "./Programa" (Ou a palavra que tenha escolhido no Passo 2). 

Bruno Budano Mello RA: 22.124.006-2
Gabriel Andrade Rosa Oliveira RA: 22.124.075-7
Daniel Borrachina Clemente RA: 22.124.078-1
