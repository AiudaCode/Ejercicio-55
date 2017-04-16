
import javax.swing.JOptionPane;

public class Main
{
    // método para mostrar el vector
    public static void mostrar(Estatuas obj, String cadena)
    {
        String datos = cadena;
        // recorremos el vector con el ciclo for
        for (int i = 0; i < obj.getTamañoVector(); i++)
        {
            // si el llegamos a la ultima posicion del vector cerramos con un corchete
            if (i == obj.getTamañoVector()-1)
            {
                datos += obj.getVector(i) + "]";
            }
            else
            {
                // sino separamos cada valor del vector con una ,
                datos += obj.getVector(i) + ", ";
            }
        }
        JOptionPane.showMessageDialog(null, datos);
    }

    // método para mostrar todas estatuas ordenadas de 1 en 1
    public static void mostrarTodo(Estatuas obj)
    {
        String datos = "Todas las estatuas ordenadas de 1 en 1: [";
        // inicializamos una variable de tipo entera llamada tam en la suma del tamaño del vector mas las estatuas requeridas
        int tam = obj.getTamañoVector()+obj.estatuasRequeridas();
        // recorremos el vector ordenado con el ciclo for
        for (int i = 0; i < tam; i++)
        {
            // si llegamos a la ultima posicion
            if (i == tam-1)
            {
                // si el llegamos a la ultima posicion del vector cerramos con un corchete
                datos += obj.getVectorOrdenado(i) + "]";
            }
            else
            {
                // sino separamos cada valor del vector con una ,
                datos += obj.getVectorOrdenado(i) + ", ";
            }
        }
        JOptionPane.showMessageDialog(null, datos);
    }
    
    public static void main(String[] args)
    {
        // creamos un objeto de la clase Estatuas (Instanciación)
        Estatuas obj = new Estatuas();
        // pedimos el tamaño del vector
        int tam = Integer.parseInt(JOptionPane.showInputDialog("Digite tamaño del vector:"));
        // encapsulamos la variable tam
        obj.setTamañoVector(tam);
        // creamos el vector
        obj.crearVector();
        // declaramos una variable de tipo entero llamada dato
        int dato;
        // recorremos el vector con el ciclo for
        for (int i = 0; i < obj.getTamañoVector(); i++)
        {
            do
            {
                // pedimos el tamaño de la estatua en la posicion i
                dato = Integer.parseInt(JOptionPane.showInputDialog("Digite tamaño de la estatua " + i));
                // encapsumalos en la posicion la variable dato
                obj.setVector(i, dato);
            }
            while (dato < 0); // repetiremos esto hasta si el dato es menor a 0
        }
        //mostramos en pantalla el vector
        mostrar(obj, "Tamaño de las estatuas de Timmy: [");
        // si el tamaño es mayor 1
        if (obj.getTamañoVector() > 1)
        {
            // mostramos las estatuas ordenas y todas las estatuas ordenadas de 1 en 1
            obj.ordenar();
            mostrar(obj, "Estatuas ordenadas: [");
            obj.crearVectorOrdenado();
            obj.llenarEstatuasFaltantes();
            mostrarTodo(obj);
        }
        // mostramos la cantidad de estatuas necesitadas
        JOptionPane.showMessageDialog(null, "Se necesitaron " + obj.estatuasRequeridas() + " estatuas para ordenarlas de 1 en 1.");
    }
}
