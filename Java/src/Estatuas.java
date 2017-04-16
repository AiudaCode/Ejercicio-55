public class Estatuas
{
    private int tamaño;
    private int [] vector;
    private int [] vector_ordenado;
    
    public Estatuas()
    {
        // le asignamos valores por defecto a los atributos de la clase en el constructor
        tamaño = 0;
        vector = null;
        vector_ordenado = null;
    }
    
    // métodos Setters y Getters
    public void setTamañoVector(int val)
    {
        tamaño = val;
    }

    public int getTamañoVector()
    {
        return tamaño;
    }

    public void setVector(int pos, int val)
    {
        vector[pos] = val;
    }

    public int getVector(int pos)
    {
        return vector[pos];
    }
    
    public void setVectorOrdenado(int pos, int val)
    {
        vector_ordenado[pos] = val;
    }

    public int getVectorOrdenado(int pos)
    {
        return vector_ordenado[pos];
    }

    // método para crear el vector
    public void crearVector()
    {
        // le asignamos al vector de tipo entero un tamaño del valor de la variable tamano
        vector = new int[tamaño];
    }

    // método para crear el vector donde estaran todas estatuas que se requieren ordenadas de 1 en 1
    public void crearVectorOrdenado()
    {
        // inicializamos una variable de tipo entero llamada tam en el valor de la variable tam mas
        // el valor del método estatuasRequeridas
        int tam = tamaño+estatuasRequeridas();
        vector_ordenado = new int[tam];
    }

    // método para calcular el mayor tamaño entre todas las estatuas
    public int mayorTamaño()
    {
        // inicializamos una variable de tipo entero llamada may en 0
        int may = 0;
        // declaramos una variable de tipo entero llamada temp
        int temp;
        // recorremos el vector con el ciclo for
        for (int i = 0; i < getTamañoVector(); i++)
        {
            // le asignamos a la variable temp el valor de la posicion i del vector
            temp = getVector(i);
            // si el valor de temp es mayor al valor de la variable may
            if (temp > may)
            {
                // le asignamos a la variable may el valor de temp
                may = temp;
            }
        }
        // retornamos el valor de may
        return may;
    }

    // método para calcular el menor tamaño entre todas las estatuas
    public int menorTamaño()
    {
        // inicializamos una variable de tipo entero llamada men en el valor que retorne el metodo mayorTamano
        int men = mayorTamaño();
        // declaramos una variable de tipo entero llamada temp
        int temp;
        // recorremos el vector con el ciclo for
        for (int i = 0; i < getTamañoVector(); i++)
        {
            // le asignamos a la variable temp el valor de la posicion i del vector
            temp = getVector(i);
            // si el valor de temp es menor al valor de la variable men
            if (temp < men)
            {
                // le asignamos a la variable men el valor de temp
                men = temp;
            }
        }
        // retornamos el valor de men
        return men;
    }

    // método para cambiar dos posiciones del vector
    public void cambiar(int p1, int p2)
    {
        // inicializamos una variable de tipo entero llamada temp en el valor que hay en posicion p1 del vector
        int temp = getVector(p1);
        // en la posicion p1 del vector le asignamos el valor de la posicion p2 del vector
        setVector(p1, getVector(p2));
        // en la posicion p2 del vector le asignamos el valor de la variable temp
        setVector(p2, temp);
    }

    // método para ordenar los tamaños de las estatuas
    public void ordenar()
    {
        // recorremos con el ciclo for el vector
        for (int i = 0; i < getTamañoVector(); i++)
        {
            // con este otro ciclo recorremos la siguiente posicion del vector
            for (int j = i+1; j < getTamañoVector(); j++)
            {
                // si la posicion i es mayor a la posicion j del vector
                if (getVector(i) > getVector(j))
                {
                    // entonces cambiamos esas dos posiciones
                    cambiar(i, j);
                }
            }
        }
    }

    // método para calcular las estatuas requeridas
    public int estatuasRequeridas()
    {
        // retornamos el valo
        return (mayorTamaño() - menorTamaño() + 1) - getTamañoVector();
    }

    // método para llenar las estatuas faltantes al nuevo vector ordenado
    public void llenarEstatuasFaltantes()
    {
        // inicializamos una variable de tipo entero llamada tam en el tamaño del vector mas las estatuas requeridas
        int tam = getTamañoVector()+estatuasRequeridas();
        // inicializamos una variable de tipo entero llamada temp en el valor de la posicion  0 del vector
        int temp = getVector(0);
        // recorremos el nuevo vector con el ciclo for
        for (int i = 0; i < tam; i++)
        {
            // si estamos en la primera posicion del vector
            if (i == 0)
            {
                // le asignamos en la posicion i el valor de temp
                setVectorOrdenado(i, temp);
            }
            else
            {
                // sino incrementamos el valor de la variable temp
                temp++;
                // le asignamos en la posicion i el valor de temp
                setVectorOrdenado(i, temp);
            }
        }
    }
}