# Métodos Numérios - Trabalho I
Prof. João B. Oliveira

Seu primeiro trabalho nesta disciplina onsiste em explorar o padrão IEEE-754. Voce deve
implementar um programa que umpra as seguintes tarefas:
1. Ele recebe pela linha de comando uma expressao no formato `val1 op val2` onde *op* é uma operação (+,−, ∗,/) e *val1* e *val2* são dois valores em ponto futuante, NaN ou ±∞.
2. Depois de reeber a expressão seu programa deve realizar a operação op e mostrar o resultado dela;
3. Seu programa também deve mostrar a configuração de bits das duas variáveis e do resultado. Tome cuidado om a endianness do seu proessador para que a saída seja apresentada corretamente;
4. Seu programa também deve informar se alguma exeção do padrão IEEE-754 foi sinalizada quando a operação foi feita. Por exemplo, seu programa poderia funionar assim:
```
> python3 meualuleitor.py 21 / -0

    Recebi 21.000000 / -0.000000 e resultado deu -inf

    val1 = 0 10000011 01010000000000000000000 = 21
    val2 = 1 00000000 00000000000000000000000 = -0
    res = 1 11111111 00000000000000000000000 = -inf

    Exeção FE_INEXACT: 0
    Exeção FE_DIVBYZERO: 4
    Exeção FE_UNDERFLOW: 0
    Exeção FE_OVERFLOW: 0
    Exeção FE_INVALID: 0
```
