import msvcrt

class Limpar:

        def limpa():
            while msvcrt.kbhit():
                msvcrt.getch()

