#ifndef HOTEL_H
#define HOTEL_H

#include <list>
#include <string>

using namespace std;

// Estructura para almacenar la información de un huésped
struct Guest {
  string name;
  string address;
  string phone;
  int room;
};

// Estructura para almacenar la información de un hotel
struct Hotel {
  list<Guest> guests;
};

// Inicializa un hotel
void initHotel(Hotel& hotel);

// Agrega un huésped al hotel
void addGuest(Hotel& hotel, const Guest& guest);

// Elimina a un huésped del hotel
void checkOut(Hotel& hotel, int room);

// Muestra una lista de huéspedes actuales en el hotel
void listGuests(const Hotel& hotel);

// Muestra el menú principal y permite al usuario seleccionar una opción
int mainMenu();

// Pide al usuario que ingrese la información de un huésped y la devuelve en una estructura Guest
Guest getGuestInfo();
#endif