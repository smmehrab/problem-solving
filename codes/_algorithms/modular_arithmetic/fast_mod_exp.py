class FastModularExponentiation:

    def __init__(self, modulo) -> None:
        self.modulo = modulo

    def calculate(self, base, exponent):
        result = 1
        while exponent>0:
            if exponent & 1 == 1:
                result = (result * base) % self.modulo
            base = (base * base) % self.modulo
            exponent >>= 1
        return result
