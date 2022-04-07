import timeit
from fibonacciFunction import fibonacci
from fibonacciFunctionCy import fibonacci
from fibonacciFunctionCyOP import fibonacci


pyTiempo = timeit.timeit('''fb.fibonacci(100000)''',setup='import fibonacciFunction as fb',number=100)
cyTiempo = timeit.timeit('''fbcy.fibonacci(100000)''',setup='import fibonacciFunctionCy as fbcy',number=100)
cyOPTiempo = timeit.timeit('''fbcyOP.fibonacci(100000)''',setup='import fibonacciFunctionCyOP as fbcyOP',number=100)

print(f'Cython es {pyTiempo/cyTiempo} mas rápido ')
print(f'CythonOP es {pyTiempo/cyOPTiempo} mas rápido')