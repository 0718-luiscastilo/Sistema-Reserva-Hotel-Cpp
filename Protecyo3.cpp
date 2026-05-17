#include <iostream>
#include <string>
#include <cctype> 

std::string tipoHabitacion(char habitacion);
double calcularReserva(char habitacion, int noches);

int pedirReserva(){
  int numeroReserva =0;
  do{
    std::cout << "Cantidad de reservas: " << std::endl;
    std::cin >> numeroReserva;
    if(numeroReserva <=0){
      std::cout << "Cantidad de reservas debe de ser mayor a 0: " << std::endl;
    }
  } while (numeroReserva <= 0);

  return numeroReserva;
}
void salidaClientes(std::string arr1[], char arr2[], int arr3[], int num){

    for(int i = 0; i < num; i++){
      double total = calcularReserva(arr2[i], arr3[i]);
      std::cout << arr1[i] << " - " << tipoHabitacion(arr2[i]) << " - " << arr3[i] << " noches. - Total: "<< total << std::endl;
    }
}

std::string tipoHabitacion(char habitacion){

    if(habitacion == 'S'){
        return "Simple";
    }
    else if(habitacion == 'D'){
        return "Doble";
    }
    else{
        return "Lujo";
    }
}
double calcularReserva(char habitacion, int noches){

    if(habitacion == 'S'){
        return noches * 500;
    }
    else if(habitacion == 'D'){
        return noches * 900;
    }
    else{
        return noches * 1500;
    }
}
double calculoHotel(int noches[], char habitaciones[], int num){

    double total = 0;

    for(int i = 0; i < num; i++){
        total += calcularReserva(habitaciones[i], noches[i]);
    }

    return total;
}
double calcularPromedio(double total, int num){
  double promedio = total / num;

  return promedio;
}
void habitacionesReservadas(char habitaciones[], int num){

    int simples = 0;
    int dobles = 0;
    int lujo = 0;

    for(int i = 0; i < num; i++){

        if(habitaciones[i] == 'S'){
            simples++;
        }
        else if(habitaciones[i] == 'D'){
            dobles++;
        }
        else if(habitaciones[i] == 'L'){
            lujo++;
        }
    }

    std::cout << "Habitaciones reservadas:" << std::endl;
    std::cout << "Simple: " << simples << std::endl;
    std::cout << "Doble: " << dobles << std::endl;
    std::cout << "Lujo: " << lujo << std::endl;
}
int main() {
  std::cout << "Bienvenido al Hotel" << std::endl << std::endl;
  
  int reservas = pedirReserva();
  std::string clientes[100];
  char habitaciones[100];
  int noches[100];

  for (int i = 0; i < reservas;i++){
    //std::cout << "Reserva: " + (i+1) << std::endl;
    std::cout << "Nombre: " << std::endl;
    std::string nom;
    std::getline(std::cin >> std::ws, nom);
    clientes[i] = nom;

    std::cout << "Tipo de Habitacion : " << std::endl;
    char habitacion;
    std::cin >> habitacion;
    habitacion = toupper(habitacion);

    while(habitacion != 'S' && habitacion != 'D' && habitacion != 'L'){
        std::cout << "Tipo invalido. Intente nuevamente: ";
        std::cin >> habitacion;
        habitacion = toupper(habitacion);
    }
    habitaciones[i] = habitacion;

    std::cout << "Noches: " << std::endl;
    int noche;
    std::cin >> noche;
    noches[i] = noche;
    while(noche <= 0){
      std::cout << "Las noches deben ser mayores a 0: ";
      std::cin >> noche;
      }

    }
    salidaClientes(clientes, habitaciones, noches, reservas);
    double totalHotel = calculoHotel(noches, habitaciones, reservas);
    double promedioHotel = calcularPromedio(totalHotel, reservas);
    std::cout << "Ingreso Total del Hotel: " << totalHotel << std::endl;
    std::cout << "Promedio por huesped: " << promedioHotel << std::endl;
    habitacionesReservadas(habitaciones, reservas);

    return 0;

}
