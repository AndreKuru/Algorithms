# Inicialização
fibonacci_memoization = {0: 0, 1: 1}

def fib(n: int) -> int:
    # Reaproveita respotas anteriores
    if n in fibonacci_memoization:
        return fibonacci_memoization[n]
    
    # Cálculo de novas respostas recursivamente
    result = fib(n - 1) + fib(n - 2)
    fibonacci_memoization[n] = result

    return result

def main():
    print("Fibonacci: ")
    while True:
        try:
            n = int(input("Entrada: "))
            if n < 0:
                raise(ValueError)

            print(f"fib({n}) = {fib(n)}")

        except ValueError:
            print("Entrada inválida! Insira um número inteiro não negativo." )

main()