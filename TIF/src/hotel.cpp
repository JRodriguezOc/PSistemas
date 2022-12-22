#include "../headers/hotel.h"
#include <iostream>
#include <stdexcept>
#include <limits>

using namespace std;

// Inicializa un hotel
void initHotel(Hotel& hotel) {
  // Limpia la lista de huéspedes
  hotel.guests.clear();
}

// Agrega un huésped al hotel
void addGuest(Hotel& hotel, const Guest& guest) {
  // Agrega el huésped a la lista de huéspedes
  hotel.guests.push_back(guest);
}

// Elimina a un huésped del hotel
void checkOut(Hotel& hotel, int room) {
  // Recorre la lista de huéspedes buscando el huésped con el número de habitación especificado
  for (auto it = hotel.guests.begin(); it != hotel.guests.end(); it++) {
    if (it->room == room) {
      // Elimina el huésped de la lista
      hotel.guests.erase(it);
      cout << "El huésped de la habitación " << room << " ha sido registrado como salido." << endl;
      return;
    }
  }

  throw runtime_error("No se ha encontrado ningún huésped en la habitación " + to_string(room) + ".");
}

// Muestra una lista de huéspedes actuales en el hotel
void listGuests(const Hotel& hotel) {
  cout << "Lista de huéspedes:" << endl;
  // Recorre la lista de huéspedes y muestra el nombre y número de habitación de cada huésped
  for (const Guest& guest : hotel.guests) {
    cout << guest.name << ", habitación " << guest.room << endl;
  }
}

// Muestra el menú principal y permite al usuario seleccionar una opción
int mainMenu() {
  cout << "Seleccione una opción:" << endl;
  cout << "1. Ingresar nuevo huésped" << endl;
  cout << "2. Registro de salida de huésped" << endl;
  cout << "3. Ver lista de huéspedes" << endl;
  cout << "4. Salir" << endl;
  int selection;
  cin >> selection;
  if (cin.fail()) {
    // Limpia y resetea el flujo de entrada
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // Vuelve a pedir la selección al usuario
    cout << "Por favor, seleccione una opción válida: ";
    cin >> selection;
  }
  return selection;
}

// Pide al usuario que ingrese la información de un huésped y la devuelve en una estructura Guest
Guest getGuestInfo() {
  string name, address, phone;
  int room;
  cout << "Ingrese el nombre del huésped: ";
  cin.ignore();
  getline(cin, name);
  cout << "Ingrese la dirección del huésped: ";
  getline(cin, address);
  cout << "Ingrese el número de teléfono del huésped: ";
  getline(cin, phone);
  cout << "Ingrese el número de habitación del huésped: ";
  cin >> room;
  return {name, address, phone, room};
}