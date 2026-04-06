#include <stdio.h>
#include <string.h> // para poder comprar las cadenas de caracteres del si o SI o si


int main()
{
    int i, ID, stock = 0, unidadesV, prodR = 0, opt, Ureabast = 0, valido = 1; //este valido sirve mas adelante
    float precioU = 0, cantV=0, ganancias = 0, totalPV, costoU = 0;
    float descuento = 0, inversion = 0;
    char nombre[20], confirmacion[10];

    do
    {
        printf("\n"); 
        printf("\nEscribe 1 para registrar un producto: ");
        printf("\nEscribe 2 para vender el producto: ");
        printf("\nEscribe 3 para reabastecer el producto");
        printf("\nEscribe 4 para ver la informacion actual de tu producto");
        printf("\nEscribe 5 para ver las ganancias obtenidas: ");
        printf("\nEscribe 6 para registrar un descuento PERO EN NUMEROS: ");
        printf("\nEscribe 7 para ver cuanto falta para recuperar la inversion: ");
        printf("\nEscribe 8 para salir: ");
        printf("\n:");

        if(scanf("%d", &opt) != 1)
        {
            printf("\nEntrada invalida");
            while(getchar()!='\n');
            continue;
        }

        switch(opt)
        {
            case 1:

            if(prodR == 1)
            {
                printf("\nTu producto ya fue registrado correctamente, elige otra opcion"); 
                break;
            }

            printf("\nIngresa el ID del producto: ");
            while(scanf("%d", &ID)!=1 || ID<=0)
            {
                printf("ID invalido, ingresa numeros o uno valido: ");
                while(getchar()!='\n'); //utilice el getchar para en este caso guardar todo guardado 
                                        // en el buffer de esa opcion hasta que encuentre al \n
            }
            
            printf("\nIngresa el nombre del producto: ");
            scanf("%s", nombre);

            if(strlen(nombre) == 0 || strlen(nombre) >= 20) //con strlen comparo la longitud de las cadenas
            {
                valido = 0; //para esto necesitaba este valido
            }

            
            for(i = 0; nombre[i] != '\0'; i++)
            
            {
                
                if(nombre[i] < 'A' || (nombre[i] > 'Z' && nombre[i] < 'a') || nombre[i] > 'z') //aseguro que todo sea letras
                {
                    
                    valido = 0;
                    break;
                }
            }


            printf("\nIngresa la cantidad en stock: ");
            while(scanf("%d", &stock)!=1 || stock<0) //Utilizo el !=1 para indicar que cuando no sea un numero
                                                     //Entonces no cumpla la condición 
            {
                printf("Stock invalido: ");
                while(getchar()!='\n');
            }

            printf("\nIngresa el costo unitario del producto: ");
            while(scanf("%f", &costoU)!=1 || costoU<0)
            {
                printf("Costo invalido: ");
                while(getchar()!='\n');
            }

            printf("\nIngresa el precio de venta unitario del producto: ");
            while(scanf("%f", &precioU)!=1 || precioU<=0 || precioU<costoU)
            {
                printf("Precio invalido (mayor al costo): ");
                while(getchar()!='\n');
            }

            inversion = stock * costoU;

            prodR = 1;
            printf("\nRegistrado correctamente");
            break;

            case 2:

            if(prodR == 0)
            {
                printf("\nPrimero debes registrar el producto");
                break;
            }

            totalPV = 0;

            printf("\nIngresa cuantas unidades desea vender: ");
            while(scanf("%d", &unidadesV)!=1 || unidadesV<=0)
            {
                printf("Cantidad invalida: ");
                while(getchar()!='\n');
            }

            if(stock >= unidadesV)
            {
                float precioFinal = precioU - (precioU * descuento / 100);
                totalPV = unidadesV * precioFinal;

                printf("Tu total seria de: %.2f, esta bien? si o no: ", totalPV);
                scanf("%s", confirmacion);

                if(strcmp(confirmacion,"si")==0 || // Esto utilizo para poder comparr los si y que acepte varios si
                   strcmp(confirmacion,"SI")==0 || // Para esto necesitaba la libreria string
                   strcmp(confirmacion,"Si")==0)
                {
                    printf("\nExcelente, venta registrada correctamente");
                    cantV += unidadesV;
                    stock -= unidadesV;
                    ganancias += (precioFinal - costoU) * unidadesV;
                }
                else
                {
                    printf("\nVenta cancelada");
                }
            }
            else
            {
                printf("\nNo tienes unidades suficientes");
            }
            break;

            case 3:

            if(prodR == 0)
            {
                printf("\nPrimero debes registrar el producto");
                break;
            }

            printf("\n¿Con cuantas unidades deseas reabastecer tu producto?: ");
            while(scanf("%d", &Ureabast)!=1 || Ureabast<=0)
            {
                printf("Cantidad invalida: ");
                while(getchar()!='\n');
            }

            stock += Ureabast;
            inversion += Ureabast * costoU;

            printf("\nStock actualizado");
            break;

            case 4:

            if(prodR == 0)
            {
                printf("\nPrimero debes registrar el producto");
                break;
            }

            printf("\n-------informacion actual------");
            printf("\nNombre: %s", nombre);
            printf("\nID: %d", ID);
            printf("\nPrecio actual: %.2f", precioU);
            printf("\nStock: %d", stock);
            printf("\nDescuento: %.2f%%", descuento);
            printf("\nCantidad vendida total: %.2f\n", cantV);
            break;

            case 5:

            if(prodR == 0)
            {
                printf("\nPrimero debes registrar el producto");
                break;
            }

            printf("\nLas ganancias obtenidas hasta el momento, son: %.2f", ganancias);
            break;

            case 6:

            if(prodR == 0)
            {
                printf("\nPrimero debes registrar el producto");
                break;
            }

            printf("\nIngresa el porcentaje de descuento: ");
            while(scanf("%f", &descuento)!=1 || descuento<0 || descuento>100)
            {
                printf("Descuento invalido (0-100): ");
                while(getchar()!='\n');
            }

            printf("\nDescuento aplicado correctamente");
            break;

            case 7:

            if(prodR == 0)
            {
                printf("\nPrimero debes registrar el producto");
                break;
            }

            if(ganancias >= inversion)
            {
                printf("\nYa recuperaste toda la inversion");
            }
            else
            {
                printf("\nTe falta recuperar: %.2f", inversion - ganancias);
            }
            break;

            case 8:
            printf("\nSalir");
            break;

            default:
            printf("\nOpcion no valida");
        }

    } while(opt != 8);

    return 0;
}