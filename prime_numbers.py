from copy import deepcopy

# Inicialização
prime_numbers_memoization = {2: [2]}

def p(n: int) -> list[int]:
    # Não existe número primo par maior que 2
    if n > 2 and n % 2 == 0: 
        n = n - 1

    # Reaproveita respotas anteriores
    if n in prime_numbers_memoization:
        return prime_numbers_memoization[n]
    
    # Cálculo de novas respostas recursivamente
    result = deepcopy(p(n - 1))

    n_is_prime = True
    for prime_number in result:
        if n % prime_number == 0:
            n_is_prime = False
            break
    
    if n_is_prime:
        result.append(n)

    prime_numbers_memoization[n] = result

    return result

def main():
    print("Números primos: ")
    while True:
        try:
            n = int(input("Entrada: "))
            if n <= 1:
                raise(ValueError)

            print(f"p({n}) = {p(n)}")

        except ValueError:
            print("Entrada inválida! Insira um número inteiro maior que 1." )

main()